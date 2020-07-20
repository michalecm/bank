/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 *
 *
 * Created on December 6, 2018, 3:32 PM
 */
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include <cmath>
#include <iomanip>
#include "AccountList.h"
#include "Accounts.h"
#include "node.h"

using namespace std;
static AccountList bankList;
void AdminMenu();
void CustomerMenu();
void InvalidInput();
/*
 *
 */
int main()
{
    bankList.addAdminAcc(555555, 1212);
    bankList.addCustAcc(123000, 111, "Mason", "Mich", "nac", "sd", 8675309, 1345.66);
    bankList.addCustAcc(123010, 111111, "Mason", "Mich", "nac", "sd", 8675309, 1345.66);
    bool terminateLogin = false;
    char input;
    while(terminateLogin != true){
		system("CLS");
        cout << endl << "===========================================================";
        cout << endl << "Welcome to the BestBank ATM" << endl;
        cout << endl << "Enter \"C\" for Customer or \"A\" for Administrator Menu, or \"E\" to exit the program: ";
        cin >> input;

		switch (input)
		{
		case 'C': CustomerMenu(); break;
		case 'A': AdminMenu(); break;
		case 'E': return 0; break;
		}
    }
    return 0;
}

void CustomerMenu()
{
	int in, input;
	char inn;
	Account *tmp;
	CustomerAccount *temp;
	while (true)
	{
		cout << endl << "Enter your Customer ID: ";
		cin >> input;
		tmp = bankList.findAcc(input);
		temp = static_cast<CustomerAccount *>(tmp);
		cout << endl << endl << "Enter your Customer Pin: ";
		cin >> in;
		if (temp != 0)
			if ((*temp).getPin() == in)
			{
				{
				    system("CLS");
					cout << endl << "Successful ATM Login! " << temp->getAcctNum() << endl;
					cout << "===========================================================";
					break;
				}
			}
		cout << endl << "Invalid ID or PIN!! Try again (Y) or exit ATM (E)?";
		cin >> inn;
		if (inn == 'E') { return; }
	}
	cout << endl << "---------------------------------------------";
    cout << endl << setw(26) << "Customer Menu";
    cout << endl << "---------------------------------------------";
    cout << endl << setw(5) << "a) " << setw(5) << "View Balance";
    cout << endl << setw(5) << "b) " << setw(5) << "Withdraw Money";
    cout << endl << setw(5) << "c) " << setw(5) << "Deposit Money";
    cout << endl << setw(5) << "d) " << setw(5) << "View All Info";
    cout << endl << setw(5) << "e) " << setw(5) << "Change PIN";
    cout << endl << setw(5) << "f) " << setw(5) << "Exit" << endl;
    cin >> inn;
    while(inn!='f')
        {
        switch (inn)
        {
        case 'a':
        {
            cout << endl << "Your account Balance is: $"  << temp->getAcctBalance();
            cout << endl << "Press Enter to continue . . . ";
            cin.ignore();
            cin.ignore();
            system("CLS");
            break;
        }
        case 'b':
        {
            cout << endl << "Amount to Withdraw? ";
            cin >> input;
            if (temp->getAcctBalance() > input)
            {
                temp->setAcctBalance(temp->getAcctBalance() - input);
            }
            cout << endl << "Your account Balance is: "  << temp->getAcctBalance();
            cout << endl<< endl << "Press Enter to continue . . . ";
            cin.ignore();
            cin.ignore();
            system("CLS");
            break;
        }
        case 'c':
        {
            cout << endl << "Amount to Deposit? ";
            cin >> input;
            temp->setAcctBalance(temp->getAcctBalance() + input);
            cout << endl << "Your account Balance is: $"  << temp->getAcctBalance();
            cout << endl << endl << "Press Enter to continue . . . ";
            cin.ignore();
            cin.ignore();
            system("CLS");
            break;
        }
		case 'd': 
		{
			temp->toString();
			cout << endl << endl << "Press Enter to continue . . . ";
			cin.ignore();
			cin.ignore();
			system("CLS");
			break;
		}
        case 'e':
        {
            cout << endl << "Enter your new PIN: ";
            cin >> input; temp->setPin(input);
            cout << endl << "PIN has been changed to " << input;
            cout << endl<< endl << "Press Enter to continue . . . ";
            cin.ignore();
            cin.ignore();
            system("CLS");
            break;
        }
        case 'f': 
		{
			cout << endl << endl << "Logged out! Press enter to continue . . . ";
			cin.ignore();
			cin.ignore();
			system("CLS");
			break;
		}
        default:
        {
            cout << endl << "Invalid input. Please choose again";
            cout << endl<< endl << "Press Enter to continue . . . ";
            cin.ignore();
            cin.ignore();
            system("CLS");
            break;
        }
        }
        cout << endl << "---------------------------------------------";
        cout << endl << setw(26) << "Customer Menu";
        cout << endl << "---------------------------------------------";
        cout << endl << setw(5) << "a) " << setw(5) << "View Balance";
        cout << endl << setw(5) << "b) " << setw(5) << "Withdraw Money";
        cout << endl << setw(5) << "c) " << setw(5) << "Deposit Money";
        cout << endl << setw(5) << "d) " << setw(5) << "View All Info";
        cout << endl << setw(5) << "e) " << setw(5) << "Change PIN";
        cout << endl << setw(5) << "f) " << setw(5) << "Exit" << endl;
        cin >> inn;
    }
}

void AdminMenu()
{
	int in, input;
	char inn;
	Account *tmp;
	AdminAccount *temp;
	CustomerAccount *cust;
        struct custstruct{
            string fname;
            string lname;
            int accnum;
            int pin;
        };
	while (true)
	{
		cout << endl << "Enter your ADMIN ID: ";
		cin >> input;
		tmp = bankList.findAcc(input);
		temp = static_cast<AdminAccount *>(tmp);
		cout << endl << endl << "Enter your ADMIN Pin: ";
		cin >> in;
		if (temp != 0)
			if ((*temp).getPin() == in)
			{
				{
				    system("CLS");
					cout << endl << "Successful ADMIN Login! " << temp->getAcctNum() << endl;
					cout << "===========================================================";
					break;
				}
			}
		cout << endl << "Invalid ID or PIN!! Try again (Y) or exit ATM (E)?";
		cin >> inn;
		if (inn == 'E') { return; }
	}
	cout << endl << "---------------------------------------------";
    cout << endl << setw(26) << "ADMIN Menu";
    cout << endl << "---------------------------------------------";
    cout << endl << setw(5) << "a) " << setw(5) << "Create Customer Account";
    cout << endl << setw(5) << "b) " << setw(5) << "Change Own Password";
    cout << endl << setw(5) << "c) " << setw(5) << "View Customer Info";
    cout << endl << setw(5) << "d) " << setw(5) << "Change Customer Info";
    cout << endl << setw(5) << "e) " << setw(5) << "Delete Customer Account";
    cout << endl << setw(5) << "f) " << setw(5) << "Show Top 5 Savings Accounts by Balance";
    cout << endl << setw(5) << "g) " << setw(5) << "Show total $ in all Accounts";
    cout << endl << setw(5) << "h) " << setw(5) << "Exit";
    cin >> inn;
    while(inn!='f')
    {
        switch (inn)
        {
        case 'a':
        {
            custstruct s;
            cin.ignore();
            cout << endl << "Creating Customer account . . . ";
            cout << endl << "Please enter customer first name: ";
            cin >> s.fname;
            cout << endl << "Please enter customer last name: ";
            cin >> s.lname;
            cout << endl << "Please enter customer account number: ";
            cin >> s.accnum;
            cout << endl << "Please enter customer pin: " << endl;
            cin >> s.pin;
            bankList.addCustAcc(s.accnum, s.pin, s.fname, s.lname, " ", " ", 0, 0);
            cout << endl << endl << "Done! Press Enter to continue . . . ";
            cin.ignore();
            cin.ignore();
            system("CLS");
            break;
        }
        case 'b':
        {
            cout << endl << "Enter new PIN: "; cin >> in;
            if(temp->setPin(in))
            {
                cout << endl << "PIN was changed to " << in;
            }
            else{cout << endl << "PIN could not be changed!";}
            cout << endl<< endl << "Press Enter to continue . . . ";
            cin.ignore();
            cin.ignore();
            system("CLS");
            break;
        }
        case 'c':
        {
            cout << endl << "Enter the account number: ";
            cin >> input;
			tmp = bankList.findAcc(input);
			cust = static_cast<CustomerAccount *>(tmp);
			cust->toString();
            cout << endl << endl << "Press Enter to continue . . . ";
            cin.ignore();
            cin.ignore();
            system("CLS");
            break;
        }
        case 'd': 
		{
			cout << endl << "Enter the account number: ";
			cin >> input;
			if (!(tmp = bankList.findAcc(input))) { cout << endl << "Account not found!"; }
			else
			{ 
				cout << endl << "Account Found!"; 
				cout << endl << "What info would you like to edit?";
				cout << endl << "a) Account Number\nb) Account PIN\n";
				cin >> inn;
				if(inn=='a')
				{
					cout << endl << "Enter the new Account Number: ";
					cin >> input;
					tmp->setAcctNum(input);
				}
				if (inn == 'b')
				{
					cout << endl << "Enter the new PIN Number: ";
					cin >> input;
					tmp->setPin(input);
				}
			}
			cout << endl << endl << "Press Enter to continue . . . ";
			cin.ignore();
			cin.ignore();
			system("CLS");
			break;
		}
        case 'e':
        {
			cout << endl << "Enter the account number: ";
			cin >> input;
			if (bankList.delAcc(input))
			{
				cout << endl << "The account has been deleted!";
			}
			else { cout << endl << "The account was not deleted."; }
			cout << endl << endl << "Press Enter to continue . . . ";
			cin.ignore();
			cin.ignore();
			system("CLS");
			break;
        }
        case 'f':
		{

		}
		case 'g':
		{

		}
		case 'h':
		{

		}
        default:
        {
            cout << endl << "Invalid input. Please choose again";
            cout << endl<< endl << "Press Enter to continue . . . ";
            cin.ignore();
            cin.ignore();
            system("CLS");
            break;
        }
	}
    cout << endl << "---------------------------------------------";
    cout << endl << setw(26) << "ADMIN Menu";
    cout << endl << "---------------------------------------------";
    cout << endl << setw(5) << "a) " << setw(5) << "Create Customer Account";
    cout << endl << setw(5) << "b) " << setw(5) << "Change Own Password";
    cout << endl << setw(5) << "c) " << setw(5) << "View Customer Info";
    cout << endl << setw(5) << "d) " << setw(5) << "Change Customer Info";
    cout << endl << setw(5) << "e) " << setw(5) << "Delete Customer Account";
    cout << endl << setw(5) << "f) " << setw(5) << "Show Top 5 Savings Accounts by Balance";
    cout << endl << setw(5) << "g) " << setw(5) << "Show total $ in all Accounts";
    cout << endl << setw(5) << "h) " << setw(5) << "Exit";
    cin >> inn;
    }
}
