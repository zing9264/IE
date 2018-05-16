#include "Account.h"
string str;
stringstream ss;
static int setZeroID = 0;

Account::Account(int amountN, int IDN)
{
    k = 0;
    trans.clear();
    ss.str("");
    ss.clear();
    str = "";
    amount = amountN;
    ID = IDN;
    deductAmount = 0;
    cout << "construct Account successful" << endl;
}

bool Account::withdraw(int dA)
{
    deductAmount = dA;
    if (amount >= deductAmount)
    {
        amount -= deductAmount;
        ss << ID;
        str = "ID:" + ss.str();
        ss.str("");
        ss.clear();
        ss << deductAmount;
        str = str + " withdraw :" + ss.str();
        ss.str("");
        ss.clear();
        trans.push_back(str);
        k++;

        return true;
    }
    else
        return false;
}

bool Account::deposit(int iA)
{
    if (iA >= 0)
    {
        amount += iA;
        ss << ID;
        str = "ID:" + ss.str();
        ss.str("");
        ss.clear();
        ss << iA;
        str = str + " deposit :" + ss.str();
        ss.str("");
        ss.clear();
        trans.push_back(str);
        k++;
        return true;
    }
    else
        return false;
}

bool Account::transferMoney(Account *AccOfB, int amountToTransfer)
{
    AccountOfB = AccOfB;
    if (amount >= amountToTransfer)
    {
        AccountOfB->deposit(amountToTransfer);
        cout << "ID: " << ID << " amount is:" << amount << endl;
        amount -= amountToTransfer;
        cout << "after Transfer :" << amountToTransfer << endl
             << "ID: " << ID << " amount is:" << amount << endl
             << "Transfer to " << AccountOfB->getID() << endl;
        ss << ID;
        str = "ID:" + ss.str();
        ss.str("");
        ss.clear();
        ss << AccountOfB->getID();
        str = str + " transfers to " + ss.str();
        ss.str("");
        ss.clear();
        ss << amountToTransfer;
        str = str + ":" + ss.str();
        ss.str("");
        ss.clear();
        trans.push_back(str);
        k++;
        return true;
    }
    else
    {
        cout << "ID: " << ID << " amount is:" << amount << "  Not enough to transfer" << endl;
        return false;
    }
}

int Account::getAmount()
{
    return amount;
}
int Account::getID()
{
    return ID;
}
int Account::getk()
{
    return k;
}

vector<string> Account::getTrans()
{
    return trans;
}

Account &Account::getAccountOfB()
{
    return *AccountOfB;
}

Account::~Account()
{
    cout << "destruct Account successful" << endl;
}