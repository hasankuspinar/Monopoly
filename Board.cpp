#include <iostream>
#include <string>
#include "Board.h"
using namespace std;

Board::Board(int num) // parametric constructor
{
    first = new Node("None", NULL); // creating the first node
    Node * temp = first;
    for(int i = 0; i < num-1; i++)
    {
        temp->next = new Node("None", NULL); // adding a new node to the next of the current one
        temp = temp->next;
    }
    temp->next = first; // linking the last node in the list to the first
}

Board::~Board() //destructor
{
    Node * temp = first->next;
    while(temp != first)
    {
        Node * deleted = temp;
        temp = temp->next;
        delete deleted; // deleting the slots except the first
    }
    delete temp; // deleting the first
    first = NULL; // assigning first to null
}

Node * Board::get_First() const
{
    return first;
}

string Board::who_owns(Node * owned) const // returns the owner of the given slot node
{
    string result;
    if(first == owned) // if the first node is the wanted one
    {
        result = first->owner; // make result the owner
    }
    else
    {
        Node * temp = first->next;
        while (temp != first) // checking all the nodes until we return to first
        {
            if(temp == owned) // if it is the wanted one
            {
                result = temp->owner; // make result the owner
            }
            temp = temp->next; // moving the temp to the next
        }
    }
    return result; // return result which is the owner
}

void Board::display() const // displays the contents of the board
{
    int count = 0;
    Node *temp = first;
    do {
        cout << temp->owner;
        if(temp->owner != "None")
        {
            cout << " ";
        }
        count += 1;
        temp = temp->next;
        if (temp != first) { // display the contents
            cout << "->";
        }
    } while (temp != first); // iterating over the list until we return to first
    cout << endl << "^    ";
    for(int i = 0; i < count - 2; i++)
    {
        cout << "      ";
    }
    cout << "    |" << endl << "|----";
    for(int a = 0; a < count - 2; a++)
    {
        cout << "<-----";
    }
    cout << "<---v" << endl;
}
