#include "Transaction.h"

string static str;
int static i;
Transaction::Transaction()
{
    k = 0;
    _type.clear();
    for (i = 0; i < 100; i++)
    {
        _amount[i] = 0;
        every[i] = NULL;
        transferTOB[i] = -1;
    }
    cout << "Transaction is constructed " << endl;
}

void Transaction::inputnewTrans(string type, int amount, Account *pac)
{
    if (type == "Created" || type == "Deposit" || type == "Withdraw" || type == "Transfer")
    {
        _type.push_back(type);
        _amount[k] = amount;
        every[k] = pac;
        if (type == "Transfer")
        {
            transferTOB[k] = pac->getAccountOfB().getID();
        }
        k++;
    }
}

void Transaction::print()
{
    for (i = 0; i < k; i++)
    {
        if (_type[i] == "Created")
        {
            cout << "Type: Created ID:" << every[i]->getID() << endl;
        }
        if (_type[i] == "Deposit")
        {
            cout << "Type: Deposit ID:" << every[i]->getID() << " -- " << _amount[i] << endl;
        }
        if (_type[i] == "Withdraw")
        {
            cout << "Type: Withdraw ID:" << every[i]->getID() << " -- " << _amount[i] << endl;
        }
        if (_type[i] == "Transfer")
        {
            cout << "Type: Transfer ID:" << every[i]->getID() << " -- " << _amount[i] << " transfer to " << transferTOB[i] << endl;
        }
    }
}

Transaction::~Transaction()
{
    cout << "Transaction is destructed " << endl;
}