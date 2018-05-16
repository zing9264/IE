#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include <string>
#include <vector>
#include "Account.h"
using namespace std;
/*3. Transaction class (20%)
內含type, account, amount 三個變數。其中type為一個字串，紀錄交易的類型
amount 為 int，紀錄交易金額。
account 為一個 reference，指向執行交易的 account。

constructor:
Transaction(Account &account, char type[])

其中包含的函數為:
(1)void print()：印出交易詳細資料 */

class Transaction
{
  public:
    Transaction();
    ~Transaction();
    void inputnewTrans(string, int, Account *);
    void print();

  private:
    int k;
    vector<string> _type; //Created,Deposit,Withdraw,Transfer
    int _amount[300];
    Account *every[300];
    int transferTOB[300];
};
#endif