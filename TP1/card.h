#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>
using namespace std;

class Card {
    private:
        string cardName;
    public:
        Card(string cName) : cardName(cName) {
        }
        virtual void displayInfo()=0;
        string getCardName() {
            return cardName;
        }
};

#endif // CARD_H