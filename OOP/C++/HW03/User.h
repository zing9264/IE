#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include <vector>
#include "Account.h"

using namespace std;
/*2. User class (20%)
內含name, ID, account, trans[]。
其中name為一個字串
ID : 型態為int，User 之間的 ID 不可以重複。
account : 上述的 account class
trans[] : 紀錄交易資訊，陣列大小可以自訂。
(提示: 你可以用 array of Transaction pointers 儲存交易資訊，或是利用不同的 constructor 來讓 array 可以成功初始化，
或利用其他資料結構儲存(例如再開一個 class)也可以)

constructor:
User(const char &name[])
你可以視情況自行修正成 只用 const char &input_name，或是改用 pointer 也可以。
(包含 User, Account, Transaction 的 constuctor，都可以自行修改參數類型)

其中包含的函數為:
(1)char *getUsername()： 回傳username
(2)Account &getAccount()：回傳user Account
(3)int getID()：回傳 user ID*/

class User
{
  public:
    User(const string);
    ~User();
    string getUsername();
    Account &getAccount();
    int getID();
    void printTrans();

  private:
    int k;
    string _name;
    int ID;

    Account *pacc;
    vector<string> _trans;
};

#endif