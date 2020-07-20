/*The Accounts definition. Already slightly commented, but I'll include quick summaries of each
of the functions. Keep in mind the bits about inheritance. Account, Customer Account, and Admin Account are all in
this file. Customer Account can use the bits from Account, and Admin Account can use the bits from Account,
but Account can use anything from Customer Account or Admin Account, nor can Admin or Customer use anything from eachother.*/
#include <iostream>
#include "Accounts.h"
using namespace std;

//Sets the account number for the file. returns true if it succeeded,
//false if it didn't. Only criteria for an account number at the moment is it has to be
//greater then 0.
bool Account :: setAcctNum(int actNum)
{
    if((actNum > 0)){
        acctNum = actNum;
        return true;
    }
    else{
        return false;
    }
}

//Sets the pin number for an account. returns true if it succeeded,
//The criteria for a pin number is it has to be greater then 0, less then
//99999, and can't contain certain patterns (repeating digits, a straight, etc.).
bool Account :: setPin(int pinNum)
{
    //Patterns are disallowed
    if(((pinNum < 99999) && (pinNum > 0)) && (pinNum != 11111) && (pinNum != 12345) && (pinNum != 22222) && (pinNum != 33333) && (pinNum != 44444) && (pinNum != 55555) && (pinNum != 66666) && (pinNum != 77777) && (pinNum != 88888) && (pinNum != 99999)){
        pin = pinNum;
        return true;
    }
    else{
        return false;
    }
}

//Returns the account number for an account.
int Account :: getAcctNum()
{
    return acctNum;
}

//returns the pin number for an account.
int Account :: getPin()
{
    return pin;
}


//End of Account class.
//Start of CustomerAccount class.

//Default constructor. Be careful with this one. You don't want to have a bunch of customer accounts with the same
//account number.
CustomerAccount :: CustomerAccount()
{
    setAcctNum(1);
    setPin(1);

}
//Full constructor. Takes in a LOT of information, but creates it in full. won't return any kind of error statement if you screw it up though.
CustomerAccount :: CustomerAccount(int newActNum, int newPinNum, string newFirstName, string newLastName, string newCity, string newState, int newPhone, double newAcctBalance)
{
        setAcctNum(newActNum);
        setPin(newPinNum);
        setFirstName(newFirstName);
        setLastName(newLastName);
        setCity(newCity);
        setState(newState);
        setPhone(newPhone);
        setAcctBalance(newAcctBalance);
}

//Sets the first name of the customer object. Returns true if successful, false if it wasn't.
//Only criteria is it has to be 8 characters or less.
bool CustomerAccount :: setFirstName(string newFirstName){
    if(newFirstName.length() <= 8){
        firstName = newFirstName;
        return true;
    }
    else
        return false;
}

//Sets the last name of the customer object. Returns true if successful, false if it wasn't.
//Only criteria is it has to be 8 characters or less.
bool CustomerAccount :: setLastName(string newLastName){
    if(newLastName.length() <= 8){
        lastName = newLastName;
        return true;
    }
    else
        return false;
}

//Sets the city of the customer object. Returns true if successful, false if it wasn't.
//Only criteria is it has to be 9 characters or less.
bool CustomerAccount :: setCity(string newCity){
    if(newCity.length() < 10){
        city = newCity;
        return true;
    }
    else
        return false;
}

//Sets the state of the customer object. Returns true if successful, false if it wasn't.
//Only criteria is it has to be 2 characters (use the state code).
bool CustomerAccount :: setState(string newState){
    if(newState.length() == 2){
        state = newState;
        return true;
    }
    else
        return false;
}

//Sets the phone number of the customer object. Returns true if successful, false if it wasn't.
//Only criteria is it has to be 7 digits, and can't start with 0.
bool CustomerAccount :: setPhone(int newPhone){
    if(newPhone >= 1000000 && newPhone <= 9999999){
        phone = newPhone;
        return true;
    }
    else
        return false;
}

//Sets account balance of the customer object. Returns true.
bool CustomerAccount :: setAcctBalance(double newAcctBalance){
    acctBalance = newAcctBalance;
    return true;
}

//Below are the Getters.

string CustomerAccount :: getFirstName(){
    return firstName;
}

string CustomerAccount :: getLastName(){
    return lastName;
}

string CustomerAccount :: getCity(){
    return city;
}

string CustomerAccount :: getState(){
    return state;
}

int CustomerAccount :: getPhone(){
    return phone;
}

double CustomerAccount :: getAcctBalance(){
    return acctBalance;
}
//End of Customer class
//Start of Admin class.

//Same deal as the Customer Account default constructor, be careful with it.
AdminAccount :: AdminAccount()
{
    setAcctNum(1);
    setPin(1);
}

//takes in a pin and account number to create it. Much safer to use. Has the same issues the customer one does.
AdminAccount :: AdminAccount(int actNum, int pinNum)
{
    setAcctNum(actNum);
    setPin(pinNum);
}

//So all of the below functions perform identically to the one in Customer Account class,
//With the exception that they take in a Customer account, and call that customer accounts
//function, passing the below value. In retrospect there were probably better ways to implement this, but eh.
bool AdminAccount :: setFirstName(CustomerAccount cust, string newName){
    return cust.setFirstName(newName);
}

bool AdminAccount :: setLastName(CustomerAccount cust, string newName){
    return cust.setLastName(newName);
}

bool AdminAccount :: setCity(CustomerAccount cust, string newCity){
    return cust.setCity(newCity);
}

bool AdminAccount :: setState(CustomerAccount cust, string newState){
    return cust.setState(newState);
}

bool AdminAccount :: setPhone(CustomerAccount cust, int newPhone){
    return cust.setPhone(newPhone);
}

bool AdminAccount :: setAcctBalance(CustomerAccount cust, double newActBalance){
    return cust.setAcctBalance(newActBalance);
}

//Getters are similar. Pass it a Customer account and it'll retrieve that customers information.
string AdminAccount :: getFirstName(CustomerAccount cust){
    return cust.getFirstName();
}

string AdminAccount :: getLastName(CustomerAccount cust){
    return cust.getLastName();
}

string AdminAccount :: getCity(CustomerAccount cust){
    return cust.getCity();
}

string AdminAccount :: getState(CustomerAccount cust){
    return cust.getState();
}

int AdminAccount :: getPhone(CustomerAccount cust){
    return cust.getPhone();
}

double AdminAccount :: getAcctBalance(CustomerAccount cust){
    return cust.getAcctBalance();
}

int AdminAccount :: getAcctNumCust(CustomerAccount cust){
    return cust.getAcctNum();
}

int AdminAccount :: getPinCust(CustomerAccount cust){
    return cust.getPin();
}

//The two below are the only exceptions in that they have a little extra error checking, but otherwise,
//will call the Customer Accounts setters if they fit the criteria.
bool AdminAccount :: setAcctNumCust(CustomerAccount cust, int actNum)
{
    if(actNum > 0)
        {
         return cust.setAcctNum(actNum);
        }
    else
        return false;
}

bool AdminAccount :: setPinCust(CustomerAccount cust, int pinNum)
{
    if(pinNum > 0)
        {
         return cust.setPin(pinNum);
        }
    else
        return false;
}

void CustomerAccount::toString()
{
	std::cout << endl << "Account Number: " << getAcctNum();
	std::cout << endl << "Pin Number: " << getPin();
	std::cout << endl << "Name: " << getFirstName() << " " << getLastName();
	std::cout << endl << "City: " << getCity();
	std::cout << endl << "State: " << getState();
	std::cout << endl << "Phone: " << getPhone();
	std::cout << endl << "Balance: " << getAcctBalance();
}