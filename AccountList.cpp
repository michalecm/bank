/*The definitions for the AccountList header file. */
#include <iostream>
#include "AccountList.h"


//Takes in a account number and puts out a reference to the account object that has it.
Account* AccountList :: findAcc(int accNum){


    if(nodeCount == 0){
        return 0;
    }
    node *curr = head;
    while(curr != tail){
		if (curr->getAcc()->getAcctNum() == accNum) {
			return curr->getAcc();
		}
		else
            curr = curr->getNext();
    }
    return 0;
}

bool AccountList :: addCustAcc()
{
    int acctNum, pin, phone, acctBalance;
    string firstName, lastName, city, state;
	cout << endl << "Enter Account Num: "; cin >> acctNum;
    cout << endl << "Enter PIN: "; cin >> pin;
    cout << endl << "Enter First Name: "; cin >> firstName;
    cout << endl << "Enter Last Name: "; cin >> lastName;
    cout << endl << "Enter City: "; cin >> city;
    cout << endl << "Enter State: "; cin >> state;
    cout << endl << "Enter Phone Number: "; cin >> phone;
    cout << endl << "Enter Account Balance: "; cin >> acctBalance;
    Account* cust = new CustomerAccount(acctNum, pin, firstName, lastName, city, state, phone, acctBalance);

	node* newNode = new node(head, cust);
    head = newNode;
    nodeCount++;
	return true;
}

//Adds a customer account to the list. returns false if it wasn't able to add it.
//NOTE: can't pass messages back if you put in a value that doesn't meet the criteria
//for the account constructor. It just won't add it to the account. So be careful.
bool AccountList :: addCustAcc(int acctNum, int pin, string firstName, string lastName, string city, string state, int phone, double acctBalance){
    Account* cust = new CustomerAccount(acctNum, pin, firstName, lastName, city, state, phone, acctBalance);
    if(head == 0){
		node* newNode = new node(tail, cust);
        head = newNode;
        nodeCount++;
        return true;
    }
    else{
		node* newNode = new node(head, cust);
        head = newNode;
        nodeCount++;
        return true;
    }

    return false;
}

//Adds an Admin account, same as the Customer account. Also same deal with
//not being able to notify errors.
bool AccountList :: addAdminAcc(int acc, int pin){
    Account* cust = new AdminAccount(acc, pin);
    if(head == 0){
		node* newNode = new node(tail, cust);
        head = newNode;
        nodeCount++;
        return true;
    }
    else{
		node* newNode = new node(head, cust);
        head = newNode;
        nodeCount++;
        return true;
    }

    return false;
}

//Pass in a account number to have that account removed from the list.
//It'll pass back 'true' if it found the account, and 'false' if it didn't.
//From top to bottom, the first case is if theres no nodes in the list.
//the second is if theres one node in the list.
//the third case is if the head node is the node to be deleted.
//the fourth is just a regular walk through of the list.
bool AccountList :: delAcc(int accNum){
    if(nodeCount == 0){
        return false;
    }
    if(nodeCount == 1){
        if(head->getAcc()->getAcctNum() == accNum){
            head = 0;
            nodeCount--;
            return true;
        }
        else
            return false;
    }
    node *curr = head->getNext();
    node *prev = head;
    if(prev->getAcc()->getAcctNum() == accNum){
        //The head is the target for deleting.
        head = curr;
        nodeCount--;
        return true;
    }
    for(int i = 0; i < nodeCount; i++){
        if(curr->getAcc()->getAcctNum() == accNum){
            node *newCurr = curr->getNext();
            prev->setNext(newCurr);
            nodeCount--;
            return true;
        }
        else
            prev = prev->getNext();
            curr = curr->getNext();
    }
    return false;
}
