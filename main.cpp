#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <queue>

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
public:
    int value;
    int suit;

public:
    void add_card(int given_value, int suit_given ){
        value = given_value;
        suit = suit_given;
    }

    void display(){
        cout<<card_value[value]<<", "<<card_suit[suit]<<"\n";
    }
};

class Deck {
public:
    vector<Card> cards;
    queue<Card> player_1;
    queue<Card> player_2;

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

    void split(){
        for (int i = 0; i < AMOUNT_OF_CARDS; ++i) {
            if(AMOUNT_OF_CARDS/2>i){
                player_1.push(cards[i]);
            }else{
                player_2.push(cards[i]);
            }
        }
    }


};

vector <Card> war;


int main() {
    Deck Deck;
    Deck.create();
    Deck.mix();
    Deck.split();

    while(1){
        cout<<"player 1: "; Deck.player_1.front().display();
        cout<<"player 2: ";Deck.player_2.front().display();

        if(Deck.player_1.front().value>Deck.player_2.front().value){
            cout<<"player 1 wins"<<"\n";


            while (!war.empty()) {
                Deck.player_1.push(war.back());
                war.pop_back();
            }


            Deck.player_1.push(Deck.player_1.front()); // pushing to back of payer 1
            Deck.player_1.push(Deck.player_2.front()); // pushing to back of payer 1

            Deck.player_1.pop();
            Deck.player_2.pop();
        }
        if(Deck.player_1.front().value<Deck.player_2.front().value){
            cout<<"player 2 wins"<<"\n";

            Deck.player_2.push(Deck.player_1.front()); // pushing to back of payer 2
            Deck.player_2.push(Deck.player_2.front()); // pushing to back of payer 2

            Deck.player_1.pop();
            Deck.player_2.pop();
        }
        if(Deck.player_1.front().value==Deck.player_2.front().value){
            cout<<"war!"<<"\n";

            war.push_back(Deck.player_1.front()); // pushing to war
            war.push_back(Deck.player_2.front()); // pushing to war
            Deck.player_1.pop();
            Deck.player_2.pop();
            war.push_back(Deck.player_1.front()); // pushing to war
            war.push_back(Deck.player_2.front()); // pushing to war
        }

        system("pause");
        //end
        if(Deck.player_2.empty()==1){
            cout<<"player 1 wins!!! "<<"\n";
            break;
        }
        if(Deck.player_1.empty()==1){
            cout<<"player 2 wins!!! "<<"\n";
            break;
        }
    }
}


