//---------------------------------------------------------------------------
#include <iostream.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class Account {
public:
   Account( double d ) { _balance = d; }
   virtual double GetBalance() { return _balance; }
   virtual void PrintBalance()
   { cerr << "Error. Balance not available for base type." << endl; }
private:
    double _balance;
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class CheckingAccount : public Account {
public:
   CheckingAccount(double d) : Account(d) {}
   void PrintBalance() { cout << "Checking account balance: " << GetBalance() << endl; }
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class SavingsAccount : public Account {
public:
   SavingsAccount(double d) : Account(d) {}
   void PrintBalance() { cout << "Savings account balance: " << GetBalance()<<endl; }
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int main()
{
        CheckingAccount *pChecking = new CheckingAccount( 100.00 );
        pChecking->Account::PrintBalance();//  Explicit qualification.

        Account *pAccount = pChecking;  //Call Account::PrintBalance
        pAccount->Account::PrintBalance();//  Explicit qualification.

        cout<<endl;

        system("PAUSE");

        delete pChecking;
        delete pAccount;

	return 0;
}

