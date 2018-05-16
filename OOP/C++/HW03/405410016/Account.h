#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
/*
1. Account class (20%)
內含ID, amount, deductAmount, amountToTransfer，型態皆為int。 (Account 之間的 ID 不可重複)
AccountOfB：記錄交易對象

constructor:
Account(int amount, int ID) (amount 為帳戶初始金額)

其中包含的函數有:
(1)bool withdraw()：提取一定金額，成功回傳true，否則回傳false
(2)bool deposit()：存入一定金額，成功回傳true
(3)bool transferMoney(Account &AccountOfB, int amountToTransfer)：
把一定金額(amountToTransfer) 轉到另一個帳戶(AccountOfB)
(4)int getAmount()：查詢目前帳戶金額
*/
using namespace std;

class Account
{
  public:
    Account(int, int);
    ~Account();

    bool withdraw(int);
    bool deposit(int);
    bool transferMoney(Account *, int);
    int getAmount();
    int getID();
    vector<string> getTrans();
    int getk();
    Account &getAccountOfB();

  private:
    int ID;
    int amount;
    int deductAmount;
    int amountToTransfer;
    int k;
    Account *AccountOfB;

    vector<string> trans;
};

#endif