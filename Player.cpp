#include <string>
#include <iostream>
#include "Player.h"
using namespace std;

int Player::move(int steps) // moves the player steps times
{
    int result = 0;
    Node * temp = curr_pos;
    for(int i = 0; i < steps; i++)
    {
        temp = temp->next; // moves temp until desired slot is reached
        if(temp == myboard.get_First()) // checking if player stops on or goes through the first
        {
            result = 1; // makes result 1 if so
        }
    }
    curr_pos = temp; // makes current position temp
    return result;
}

Node * Player::where_am_I() const // returns the current position
{
    return curr_pos;
}

void Player::pay_to_player(Player & myPlayer, int money) // pays money amount of money from the current player to myPlayer
{
    balance = balance - money; // withdrawing money from current player
    myPlayer.balance += money; // adding money to myPlayer
}

int Player::get_balance() const // returns the balance of the player
{
    return balance;
}

void Player::deposit_money(int money) // adds money to the balance of the player
{
    balance += money;
}

void Player::buy_slot(int price)
{
    curr_pos->owner = name; // makes the owner of the current position name
    balance = balance - price; // withdraw price from the balance of player
}

bool Player::is_bankrupt() const
{
    if(balance < 0)
    {
        return true; // returning true if balance is negative
    }
    else
    {
        return false; // returning false if balance is not negative
    }
}

void Player::display() const // displays the name and balance according to the current position
{
    int count = 0;
    Node * temp = myboard.get_First();
    while(temp != curr_pos) // counting how many places from the first the player has moved
    {
        count++;
        temp = temp->next;
    }
    for(int i = 0; i < count; i++) // printing spaces to indicate the place of the player
    {
        cout << "      ";
    }
    cout << name << " " << balance << endl;
}