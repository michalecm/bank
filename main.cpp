/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: arminius
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
#include <array>
#include "AccountList.h"
#include "Accounts.h"
#include "node.h"

using namespace std;
/*
 * 
 */
int main() 
{
    AccountList bankList;
    //bankList.addAdminAcc(181818, 113456);
    struct custData
    {
        int accID;
        int accPin;
        string name;
        string lastname;
        string city;
        string state;
        int phone;
        double bankNum;
        
    };
    custData x;
    x.accID = 123456;
    x.accPin = 101010;
    x.name = "John";
    x.lastname = "John";
    x.city = "Nac";
    x.state = "TX";
    x.phone = 9792246;
    x.bankNum = 1.1;
    
    bankList.addCustAcc(x.accID, x.accPin, x.name, x.lastname, x.city, x.state, x.phone, x.bankNum);
    bool terminateLogin = false;
    char input; 
    while(terminateLogin != true){
        cout << endl << "===========================================================";
        cout << endl << "Welcome to the BestBank ATM" << endl;
        cout << endl << "Enter \"C\" for Customer or \"A\" for Administrator Menu, or \"E\" to exit the program: ";
        cin >> input;
        if(input == 'C')
        {
            int in;
            cout << endl << "Enter your Customer ID: ";
            cin >> in;
            Account *temp;
            temp = (bankList.findAcc(in));
            cout << temp->getPin();
            cout << endl << "Enter your Customer Pin: ";
            cin >> in;
            if((temp)->getPin() == in){
                bool terminateCustomerAccess = false;
                while(terminateCustomerAccess != true)
                {
                    cout << "lol";
                }
            }
        }
        //cout << endl << "Enter your Pin#: ";
        //cin >> pinNum;
       // cout << endl << endl;
        //if((accountNum == TESTACCNTNUM) && (pinNum == TESTPINNUM)){
         //   cout << "Successful ATM Login! " << accountNum <<endl;
          //  cout << "===========================================================";
          //  terminateLogin = true;
       // }
        //else if(accountNum == "E"){
        //    cout << "E received. Terminating Session.";
         //   return 0;
      //  }
       // else{
          //  cout << "Incorrect ATM Login. Please try again.";
          //  cout << "===========================================================";

        //}
    }
    
    return 0;
}

