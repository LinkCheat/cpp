#ifndef TRAINER_CARD_H
#define TRAINER_CARD_H
#include "card.h"

class TrainerCard : public Card {
    private:
        string effect;
    public:
        TrainerCard(string tName, string eff) : Card(tName), effect(eff) {
        }
        virtual void displayInfo() override {
            cout << "Trainer Card - Name: " << getCardName() << ", Effect: " << effect << endl;
        }
        string getEffect() {
            return effect;
        }
};

#endif // TRAINER_CARD_H