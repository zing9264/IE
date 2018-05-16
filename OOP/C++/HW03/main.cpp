#include "Account.h"
#include "User.h"
#include "Transaction.h"
#include <iostream>

int main()
{

    //(1)創造帳號、存款、提款、ID查詢
    Transaction allDetail; //Type :Created,Deposit,Withdraw,Transfer

    User u1("john"); // should print: New user john created
    allDetail.inputnewTrans("Created", 0, &u1.getAccount());
    User u2("mary"); // should print: New user mary created
    allDetail.inputnewTrans("Created", 0, &u2.getAccount());

    u1.getAccount().deposit(400);
    allDetail.inputnewTrans("Deposit", 400, &u1.getAccount());
    u1.getAccount().withdraw(100);
    allDetail.inputnewTrans("Withdraw", 100, &u1.getAccount());

    cout << "Balance of " << u1.getUsername() << " account is " << u1.getAccount().getAmount()
         << endl; // 300 = 400 - 100

    cout << "Balance of " << u2.getUsername() << " account is " << u2.getAccount().getAmount()
         << endl; // 0

    cout << "john ID " << u1.getID() << " John get Account ID " << u1.getAccount().getID()
         << endl;

    cout << "mary ID " << u2.getID() << " mary get Account ID " << u2.getAccount().getID()
         << endl;

    //(2)轉帳交易，並記錄交易明細(交易的類型、帳戶、金額)
    u1.getAccount().transferMoney(&u2.getAccount(), 200);
    allDetail.inputnewTrans("Transfer", 200, &u1.getAccount());

    cout << "Balance of " << u1.getUsername() << " account is " << u1.getAccount().getAmount()
         << endl; // 100 = 300 - 200

    cout << "Balance of " << u2.getUsername() << " account is "
         << u2.getAccount().getAmount() << endl; // 200 = 0 + 200

    //(3)明細查詢 (應列出使用者帳號的交易明細)
    cout << "----------u1 John details----------" << endl;
    u1.printTrans();
    cout << "----------Total details----------" << endl;
    allDetail.print();

    return 0;
}

/*你可以直接利用投影片上的範例，並補上缺少的部分，或是自己寫一個也可以。
你的主程式要執行
(1)存款、提款
(2)轉帳交易，並記錄交易明細(交易的類型、帳戶、金額)
(3)明細查詢 (應列出使用者帳號的交易明細) */