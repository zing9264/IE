#include "User.h"

static int setZeroID = 0;

User::User(const string name)
{
    k = 0;
    ID = setZeroID;
    setZeroID++;
    pacc = new Account(0, ID);
    _name = name;
    cout << "New User " << _name << " created successful" << endl;
}

string User::getUsername()
{
    return _name;
}

Account &User::getAccount()
{
    return *pacc;
}
int User::getID()
{
    return ID;
}
void User::printTrans()
{

    _trans = (*pacc).getTrans();
    k = (*pacc).getk();
    for (int i = 0; i < k; i++)
    {
        cout << "Detail>>>" << _trans[i] << endl;
    }
    return;
}

User::~User()
{
    delete pacc;
    cout << "User " << _name << " Delete successful" << endl;
}