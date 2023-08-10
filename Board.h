#include <string>
using namespace std;

#ifndef THE5_BOARD_H
struct Node {
    string owner;
    Node* next;
    Node();
    Node (string o, Node * p)
            : owner(o), next(p)
    {};
};

class Board
{
private:
    Node * first;
public:
    Board(int); //parametric constructor
    ~Board(); // destructor
    void display() const;
    string who_owns(Node *) const;
    Node * get_First() const;
};
#define THE5_BOARD_H

#endif //THE5_BOARD_H
