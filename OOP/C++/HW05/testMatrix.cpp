#include "TriangularMatrix.h"
#include <iostream>
#include <fstream>
#include <sstream>

int main()
{
    Matrix M1, M2, M3, T1, U1;

    std::cout << "* Assign values for matrix M1 *" << std::endl;
    std::stringbuf sb("3 0 3.2 7 5 9 6.3 11");
    std::streambuf *backup = std::cin.rdbuf();
    std::cin.rdbuf(&sb);
    M1.readMatrix();
    std::cin.rdbuf(backup);

    std::cout << "* Assign values for matrix M2 *" << std::endl;
    std::stringbuf sb2("3 0 2 8 4 5 19 6.1");
    std::cin.rdbuf(&sb2);
    M2.readMatrix();

    std::cout << "* Assign values for matrix T1 *" << std::endl;
    std::stringbuf sb3("4 0 1 2 3 4 5 6 7 8 9 -1");
    std::cin.rdbuf(&sb3);
    T1.readMatrix();
    std::cin.rdbuf(backup);

    std::cout << "* Assign values for matrix U1 *" << std::endl;
    std::stringbuf sb4("3 1 13 15 17 19 21 23");
    std::cin.rdbuf(&sb4);
    U1.readMatrix();
    std::cin.rdbuf(backup);

    std::cout << "[test 1: readMatrix AND operator <<]" << std::endl;
    std::cout << "[expected]" << std::endl;
    std::cout << "3.2  0  0" << std::endl;
    std::cout << "7  5  0" << std::endl;
    std::cout << "9  6.3  11" << std::endl;
    std::cout << "[result]" << std::endl;
    std::cout << M1 << std::endl
              << std::endl;

    std::cout << "[test 2: copy constructor and Operator =]" << std::endl;
    std::cout << "[expected]" << std::endl;
    std::cout << "3.2  0  0" << std::endl;
    std::cout << "7  5  0" << std::endl;
    std::cout << "9  6.3  11" << std::endl;
    std::cout << "[result]" << std::endl;
    Matrix M4(U1);
    M4 = M1;
    std::cout << M4 << std::endl
              << std::endl;

    std::cout << "[test 3: size()]" << std::endl;
    std::cout << "[expected] 3" << std::endl;
    std::cout << "[result] size of M2 is: " << M2.size() << std::endl;

    std::cout << "[test4: operator()]" << std::endl;
    std::cout << "[expected] 5" << std::endl;
    double d = M1(2, 2);
    std::cout << "d is: " << d << std::endl
              << std::endl;

    std::cout << "[test5: operator+-*(Matrix to Matrix)(part1)]" << std::endl;
    std::cout << "[expected]" << std::endl;
    std::cout << "5.2  0  0" << std::endl;
    std::cout << "15  9  0" << std::endl;
    std::cout << "14  25.3  17.1" << std::endl;
    M3 = M1 + M2;
    std::cout << "[result]" << std::endl;
    std::cout << M3 << std::endl
              << std::endl;

    std::cout << "[test5: operator+-* (Matrix to Matrix) (part2)]" << std::endl;
    std::cout << "[expected]" << std::endl;
    std::cout << "6.4  0  0" << std::endl;
    std::cout << "53.6  20  0" << std::endl;
    std::cout << "203.9  133.43  67.1" << std::endl;
    M3 = M2 * M1;
    std::cout << "[result]" << std::endl;
    std::cout << M3 << std::endl
              << std::endl;

    std::cout << "[test5: operator+-* (Matrix to Matrix) (part3)]" << std::endl;
    std::cout << "[expected]" << std::endl;
    std::cout << "169  480  927" << std::endl;
    std::cout << "0  361  882" << std::endl;
    std::cout << "0  0  529" << std::endl;
    M3 = U1 * U1;
    std::cout << "[result]" << std::endl;
    std::cout << M3 << std::endl
              << std::endl;

    std::cout << "[test5: operator+-* (Matrix to Matrix) (part4)]" << std::endl;
    std::cout << "[expected] print error message" << std::endl;
    std::cout << "[result]" << std::endl;
    M3 = M1 * T1;
    std::cout << std::endl
              << std::endl;

    std::cout << "[test5: operator+-* (Matrix to Matrix) (part5)]" << std::endl;
    std::cout << "[expected] print error message" << std::endl;
    std::cout << "[result]" << std::endl;
    M3 = M1 - U1;
    std::cout << std::endl
              << std::endl;

    std::cout << "[test6: operator* (Matrix to double)]" << std::endl;
    std::cout << "[expected]" << std::endl;
    std::cout << "-26.88  0  0" << std::endl;
    std::cout << "-23.8  -35  0" << std::endl;
    std::cout << "-339.5  933.8  -377.3" << std::endl;
    M3 = M1 * 7 * (M2 - M1);
    std::cout << "[result]" << std::endl;
    std::cout << M3 << std::endl
              << std::endl;

    std::cout << "[test7: operator *= (Matrix to double)]" << std::endl;
    std::cout << "[expected]" << std::endl;
    std::cout << "10  0  0" << std::endl;
    std::cout << "40  20  0" << std::endl;
    std::cout << "25  95  30.5" << std::endl;
    M3 = M2 * 5;
    std::cout << "[result]" << std::endl;
    std::cout << M3 << std::endl
              << std::endl;

    std::cout << "[test8: operator += -= *= (Matrix to Matrix)]" << std::endl;
    std::cout << "[expected]" << std::endl;
    std::cout << "6.8  0  0" << std::endl;
    std::cout << "33  15  0" << std::endl;
    std::cout << "16  88.7  19.5" << std::endl;
    M3 -= M1;
    std::cout << "[result]" << std::endl;
    std::cout << M3 << std::endl
              << std::endl;

    std::cout << "---------- END PROGRAM ----------" << std::endl
              << std::endl;
    return 0;
}