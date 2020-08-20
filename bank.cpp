#include<iostream>
#include<cstring>
using namespace std;

class account{
    private:
    string name;
    double accountnumber;
    long accounttype;
    float balance;
    int count=0;
    public:
    account(string name, double accountname, char accounttype, float balance);   //constructor
    void deposit(void);
    void withdraw(void);
    void display(void);
};
   
   account::account(string name, double accountnumber, char accounttype, float balance){
        this->name=name;
        this->accountnumber=accountnumber;
        this->accounttype=accounttype;
        this-> balance= balance;
   }

   void account::deposit(void){
        double amount=0;
        cout<<"enter the balance to be deposited= ";
        cin>>amount;
            balance = balance+amount;
        
        cout<<" the balance amount after deposited is= "<<balance<<endl;

   }
   void account::withdraw(void){
       int withdraw=0;
       cout<<" total balance= "<<balance<<endl;
       cout<<"enter withdraw amount= ";
       cin>>withdraw;
       if(balance>=50000){
           balance=balance-withdraw;
       }
       cout<<"the total balance in the account is: "<<balance<<endl;
   }

   void account::display(void){
       cout<<"name: "<<name<<endl;
       cout<<"total balance: "<<balance<<endl;

   }

   int main(){
       account A1("Aditya",122345667,'S',100000);
       A1.deposit();
       A1.withdraw();
       A1.display();
       

       return 0;

   }
   









   






