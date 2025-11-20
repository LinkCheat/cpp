#ifndef ENERGY_CARD_H
#define ENERGY_CARD_H
#include "card.h"

class EnergyCard : public Card {
    private:
        string energyType;
    public:
        EnergyCard(string eType) : Card("Energy"), energyType(eType) {
        }
        virtual void displayInfo() override {
            cout << "Energy Card - Type: " << energyType << endl;
        }
        string getEnergyType() {
            return energyType;
        }
};

#endif // ENERGY_CARD_H