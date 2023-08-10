#include "Board.h"
#include <string>
using namespace std;

#ifndef THE5_PLAYER_H
class Player
{
private:
    string name; // name of the player
    int balance; // balance of the player
    Node * curr_pos; // current position on the board
    Board & myboard; // the shared board object
public:
    Player(Board & board1, const string & player_name, int init_capital) // parametric constructor
    : myboard(board1), name(player_name), balance(init_capital)
    {
        curr_pos = myboard.get_First();
    }
    int move(int);
    Node * where_am_I() const;
    void pay_to_player(Player &, int);
    int get_balance() const;
    void deposit_money(int);
    void buy_slot(int);
    bool is_bankrupt() const;
    void display() const;
};
#define THE5_PLAYER_H

#endif //THE5_PLAYER_H
