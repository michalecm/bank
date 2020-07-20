/*The header for the node file. It stores references to the account it points to, and the next file in the list,
and has getters and setters for changing both. It can be created with the default constructor, or with
a account and next node already in mind. */

#include <string>
#include <memory>
#include "Accounts.h"
#ifndef NODE_H
#define NODE_H
using namespace std;

class node{
    protected:
        node *next;
        Account *acc;
    public:
        node(){next = 0;
         acc = NULL;}
        node(node *newNext, Account *newAcc){next = newNext; acc = newAcc;}
        bool setNext(node *newNext);
        bool setAcc(Account *newAcc);
        node* getNext();
        Account* getAcc();
};
#endif // NODE_H
