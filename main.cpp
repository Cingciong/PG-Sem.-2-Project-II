#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

#define AMOUNT_OF_CARDS 52
#define AMOUNT_OF_CARDS_IN_SUITE 13
#define AMOUNT_OF_SUITS 4

using namespace std;

string card_suit[AMOUNT_OF_SUITS] {
        "hearts",
        "diamonds",
        "spades",
        "clubs"
};

string card_value[AMOUNT_OF_CARDS_IN_SUITE]{
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "10",
    "Jack",
    "Queen",
    "King",
    "Ace"
};


class Card{
    int value;
    int suit;

public:
    void add_card(int given_value, int suit_given ){
        value = given_value;
        suit = suit_given;
        cout<<card_value[value]<<", "<<card_suit[suit]<<"\n";
    }

    void display(){
        cout<<card_value[value]<<", "<<card_suit[suit]<<"\n";
    }
};

class Deck {
public:
    vector<Card> cards;

public:
    void create() {
        for (int i = 0; i < AMOUNT_OF_SUITS; ++i) {
            for (int j = 0; j < AMOUNT_OF_CARDS_IN_SUITE; ++j) {
                Card tmp;
                tmp.add_card(j, i);
                cards.push_back(tmp);
            }
        }
    }

    void display(){
        for (int i = 0; i < AMOUNT_OF_CARDS; ++i) {
            cards[i].display();
        }
    }

    void mix(){
        Card tmp1, tmp2;
        int tmp_place_1, tmp_place_2;
        srand (time(NULL));
        for (int i = 0; i < AMOUNT_OF_CARDS; ++i) {
            tmp_place_1= rand() % AMOUNT_OF_CARDS;
            tmp1 = cards[tmp_place_1];
            tmp_place_2= rand() % AMOUNT_OF_CARDS;
            tmp2 = cards[tmp_place_2];
            cards[tmp_place_1] = tmp2;
            cards[tmp_place_2] = tmp1;
        }
    }

};





int main() {
    Deck Deck;
    Deck.create();
    Deck.mix();

}
