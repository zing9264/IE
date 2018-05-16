#include "TriangularMatrix.h"

Matrix::Matrix(int n)
{
    int i = 0;
    arrSize = 0;
    LorU = 0; //0=lower 1=upper
    matrixSize = n;
    for (i = 1; i <= matrixSize; i++)
    {
        arrSize = arrSize + i;
    }
    element = new double[arrSize];
}
Matrix::Matrix(const Matrix &m)
{
    arrSize = m.arrSize;
    LorU = m.LorU; //0=lower 1=upper
    matrixSize = m.matrixSize;
    element = new double[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        element[i] = m.element[i];
    }
}
Matrix::~Matrix()
{
    delete[] element;
}

void Matrix::readMatrix()
{
    int i = 0;
    int j = 0;
    cout << "<prompt> specify number of rows:" << endl;
    cout << "<user input> ";
    cin >> matrixSize;

    delete[] element;
    arrSize = 1;
    for (i = 2; i <= matrixSize; i++)
    {
        arrSize = arrSize + i;
    }
    element = new double[arrSize];
    cout << "<prompt> is upper or lower triangular: (upper: 1, lower:0)" << endl;
    cout << "<user input> ";
    cin >> LorU;
    cout << "<prompt> input elements of the matrix:" << endl
         << "<prompt> for example, if you want to create a lower-triangular matrix with following elements:" << endl
         << "<prompt> 4    0    0" << endl
         << "<prompt> 3    2.5  0" << endl
         << "<prompt> 1    2    2" << endl
         << "<prompt> please type: 4 3 2.5 1 2 2" << endl;
    cout << "<user input> ";
    for (i = 0; i < arrSize; i++)
    {
        cin >> element[i];
    }
}

int Matrix::size() const
{
    return matrixSize;
}
// operator------------------------operator--------------------------operator---------------------operator---------------------operator

const Matrix &Matrix::operator=(const Matrix &m)
{
    delete[] element;
    arrSize = m.arrSize;
    LorU = m.LorU; //0=lower 1=upper
    matrixSize = m.matrixSize;
    element = new double[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        element[i] = m.element[i];
    }
    return *this;
}

ostream &operator<<(ostream &out, const Matrix &x)
{

    int i = 0;
    int j = 0;
    int k = 0;

    out << endl;
    if (x.matrixSize == 1)
    {
        out << "[" << x.element[k] << "]" << endl;
    }
    else if (x.LorU == 0)
    {

        for (i = 1; i <= x.matrixSize; i++)
        {
            if (i == 1)
            {
                out << "┌\t";
            }
            else if (i == x.matrixSize)
            {
                out << "└\t";
            }
            else
                out << "|\t";
            for (j = 0; j < i; j++)
            {
                out << x.element[k] << "\t";
                k++;
            }
            for (j = 0; j < x.matrixSize - i; j++)
            {
                out << "0\t";
            }
            if (i == 1)
            {
                out << "┐";
            }
            else if (i == x.matrixSize)
            {
                out << "┘";
            }
            else
                out << "|";
            out << endl;
        }
    }
    else if (x.LorU == 1)
    {
        for (i = 1; i <= x.matrixSize; i++)
        {
            if (i == 1)
            {
                out << "┌\t";
            }
            else if (i == x.matrixSize)
            {
                out << "└\t";
            }
            else
                out << "|\t";
            for (j = 0; j < i - 1; j++)
            {
                out << "0\t";
            }
            for (j = 0; j < x.matrixSize - i + 1; j++)
            {
                out << x.element[k] << "\t";
                k++;
            }
            if (i == 1)
            {
                out << "┐";
            }
            else if (i == x.matrixSize)
            {
                out << "┘";
            }
            else
                out << "|";
            out << endl;
        }
    }
    return out;
}

Matrix operator*(double s, const Matrix &rt)
{
    Matrix tmp;
    tmp = rt;
    tmp *= s;
    return tmp;
}

double Matrix::operator()(int i, int j) const
{
    int k = 0;
    int z = 0;
    int x = 0;
    if (i > matrixSize || j > matrixSize || i <= 0 || j <= 0)
    {
        return 0;
    }
    else if (LorU == 0)
    {
        if (i < j)
        {
            return 0;
        }
        else
        {
            z = 0;
            k = 0;
            for (k = 1; k < i; k++)
            {
                z += k;
            }
            return element[z + j - 1];
        }
    }
    else if (LorU == 1)
    {
        if (i > j)
        {
            return 0;
        }
        else
        {
            z = 0;
            x = matrixSize;
            for (k = 1; k < i; k++)
            {
                z += x;
                x--;
            }
            j = j - i + 1;
            return element[z + j - 1];
        }
    }
    return 0;
}

Matrix &Matrix::operator+=(const Matrix &m)
{
    int i = 0;
    if (LorU != m.LorU)
    {
        cout << "You cannot add an upper triangular matrix with a lower triangular matrix" << endl;
        return *this;
    }
    else if (matrixSize != m.matrixSize)
    {
        cout << "You cannot add two matrix whth different size" << endl;
        return *this;
    }
    for (i = 0; i < arrSize; i++)
    {
        element[i] += m.element[i];
    }
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &m)
{
    if (LorU != m.LorU)
    {
        cout << "You cannot subtract  an upper triangular matrix with a lower triangular matrix" << endl;
        return *this;
    }
    else if (matrixSize != m.matrixSize)
    {
        cout << "You cannot subtract two matrix whth different size" << endl;
        return *this;
    }
    for (int i = 0; i < arrSize; i++)
    {
        element[i] -= m.element[i];
    }
    return *this;
}

Matrix &Matrix::operator*=(const Matrix &m)
{
    double sum = 0;
    int z = 0;
    double *tmp;
    tmp = new double[arrSize];
    if (LorU != m.LorU)
    {
        cout << "You cannot multiply  an upper triangular matrix with a lower triangular matrix" << endl;
        return *this;
    }
    else if (matrixSize != m.matrixSize)
    {
        cout << "You cannot multiply two matrix whth different size" << endl;
        return *this;
    }
    z = 0;
    for (int i = 1; i <= matrixSize; i++)
    {
        for (int j = 1; j <= matrixSize; j++)
        {
            sum = 0;
            for (int k = 1; k <= matrixSize; k++)
            {
                sum += operator()(i, k) * m(k, j);
            }
            if (LorU == 1)
            {
                if (i <= j)
                {
                    tmp[z] = sum;
                    z++;
                }
            }
            else if (LorU == 0)
            {
                if (i >= j)
                {
                    tmp[z] = sum;
                    z++;
                }
            }
        }
    }
    delete[] element;
    element = tmp;
    return *this;
}

Matrix Matrix::operator+(const Matrix &rt)
{
    Matrix tmp;
    tmp = *this;
    tmp.operator+=(rt);
    return tmp;
}
Matrix Matrix::operator-(const Matrix &rt)
{
    Matrix tmp;
    tmp = *this;
    tmp.operator-=(rt);
    return tmp;
}
Matrix Matrix::operator*(const Matrix &rt)
{
    Matrix tmp;
    tmp = *this;
    tmp.operator*=(rt);
    return tmp;
}

//常數部份
Matrix &Matrix::operator*=(double s)
{
    int i = 0;
    for (i = 0; i < arrSize; i++)
    {
        element[i] *= s;
    }
    return *this;
}

Matrix Matrix::operator*(double s)
{
    Matrix tmp;
    tmp = *this;
    tmp.operator*=(s);
    return tmp;
}