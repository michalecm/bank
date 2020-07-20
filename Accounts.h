/* the header file for the Account class, Customer Account class, & the Admin Account class.
    See the definition file for specifics on what all the functions do, but they generally
    do what they're name describes. */

#include <string>
#include <memory>
#ifndef ACCOUNTS_H
#define ACCOUNTS_H
using namespace std;

class Account
{
protected:
    int acctNum;                //The account number.
    int pin;                    //The pin number.
public:
    Account(){ setAcctNum(0); setPin(0);} //default constructor.
    Account(int acctNum, int pin){setAcctNum(acctNum); setPin(pin);} //Constructor for when both pin and account number are provided.
    bool setAcctNum(int actNum);       //Basic function for setting account number. returns true when successful.
    bool setPin(int pinNum);               //Basic function for setting pin number. returns true when successful.
    int getAcctNum();                   //getter for the account number.
    int getPin();                       //getter for the pin number.
};

class CustomerAccount : public Account
{
private:
        string firstName;
        string lastName;
        string city;
        string state;
        int phone;
        double acctBalance;             //the balance in the account.
public:
        CustomerAccount();
        CustomerAccount(int newAcctNum, int newPin, string newFirstName, string newLastName, string newCity, string newState, int newPhone, double newAcctBalance);
        bool setFirstName(string newFirstName);
        bool setLastName(string newLastName);
        bool setCity(string newCity);
        bool setState(string newState);
        bool setPhone(int newPhone);
        bool setAcctBalance(double newAcctBalance);
        string getFirstName();
        string getLastName();
        string getCity();
        string getState();
        int getPhone();
        double getAcctBalance();
};

class AdminAccount : public Account
{
public:
    AdminAccount();
    AdminAccount(int acctNum, int pin);
    bool setFirstName(CustomerAccount cust, string name);
    bool setLastName(CustomerAccount cust, string name);
    bool setCity(CustomerAccount cust, string name);
    bool setState(CustomerAccount cust, string state);
    bool setPhone(CustomerAccount cust, int phone);
    bool setAcctBalance(CustomerAccount cust, double acctBalance);
    string getFirstName(CustomerAccount cust);
    string getLastName(CustomerAccount cust);
    string getCity(CustomerAccount cust);
    string getState(CustomerAccount cust);
    int getPhone(CustomerAccount cust);
    double getAcctBalance(CustomerAccount cust);
    int getAcctNumCust(CustomerAccount cust);      //pulls the account number from a customer object.
    int getPinCust(CustomerAccount cust);
    bool setAcctNumCust(CustomerAccount cust, int actNum);
    bool setPinCust(CustomerAccount cust, int pinNum);
};
#endif // ACCOUNTS_H
