#include<conio.h>
#include<iostream>
#include<string>
using namespace std;
/*
  -> check Balance
  -> user information
  -> case withdrow
  ->update Mobile No.
*/
class atm{                                                                 // class atam
    private:                                                              // private data member 
        long int account_No;
        string name;
        int PIN;
        double balance;
        string mobile_Number;
    public:
        void setData(long int account_No_a, string name_a, int PIN_a, double balance_a,string mobile_Number_a){
            account_No = account_No_a;
            name = name_a;
            PIN = PIN_a;
            balance = balance_a;
            mobile_Number = mobile_Number_a;
        }
        long int getAccountNo(){
            return account_No;
        }
        string getName(){
            return name;
        }
        int getPin(){
            return PIN;
        }
        double getBalance(){
            return balance;
        }
        string getMobileNumber(){
            return mobile_Number;
        }
        void setMobileNumber(string pre_mobile_number, string new_mobile_number){
            if(pre_mobile_number == new_mobile_number){
                pre_mobile_number = new_mobile_number;
                cout<<endl<<"Mobile number is updated successfully.";
                _getch();
            }
            else{
                cout<<endl<<"Incorrect !!! old Mobile Number";
                _getch();
            }
        }
        void cashWithdraw(int amount_a){
            if(amount_a > 0 && amount_a <= balance){
                balance -= amount_a;
                cout<<endl<<"Please collect your case";
                cout<<endl<<"Available Balance is : " << balance;
                _getch();
            }
            else{
                cout<<endl<<"You entered a incorrect amount : "<< amount_a;
                _getch();
            }
        }
};
int main(){
    int choice = 0, enterPIN;
    long int enterAccountNumber;
    system("cls");
    atm user1;
    user1.setData(7920944,"shahbaz",2546,124730.75,"7055920944");

    do{
        system("cls");
        cout<<endl<<"******* Welcome To ATM ********"<<endl;
        cout<<endl<<"Enter your Account Number"<<endl;
        cin>>enterAccountNumber;
        cout<<endl<<"Enter PIN "<<endl;
        cin>>enterPIN;

        if(enterAccountNumber == user1.getAccountNo() && enterPIN == user1.getPin()){
            do{
                int amount = 0;
                string oldMobile,newMobile;

                cout<<endl<<"******* Welcome To ATM *******"<<endl;
                cout<<endl<<"Select Options ";
                cout<<endl<<"1. Check Balance";
                cout<<endl<<"2. Cash withdraw";
                cout<<endl<<"3. Show User Detail";
                cout<<endl<<"4. Update Mobile Number";
                cout<<endl<<"5. Exit";
                cin>>choice;

                switch (choice){
                    case 1: 
                       cout<<endl<<"Your bank balance is : " << user1.getBalance();
                       _getch();
                       break;
                    case 2:
                        cout<<endl<<"Enter the amount :";
                        cin>>amount;
                        user1.cashWithdraw(amount);
                        break;
                    case 3: 
                        cout<<endl<<"** User Details are :- ";
                        cout<<endl<<"-> Account Number is :-  "<<user1.getAccountNo();
                        cout<<endl<<"-> Name                  "<<user1.getName();
                        cout<<endl<<"-> Account Balance       "<<user1.getBalance();
                        cout<<endl<<"-> MObil Number          "<<user1.getMobileNumber();
                        _getch();
                        break;
                    case 4: 
                        cout<<endl<<"Enter your Old Mobile Number";
                        cin>>oldMobile;
                        cout<<endl<<"Enter your new Mobile Number";
                        cin>>newMobile;
                        user1.setMobileNumber(oldMobile,newMobile);
                        break;
                    case 5:
                        exit(0);
                    default:
                        cout<<endl<<"Enter Valid Data !!!";
    
                }

        }
        while(1);
        }
        else{
            cout<<endl<<"Incorrect PIN"<<endl;
        };
    }while(1);

    return 0;
}