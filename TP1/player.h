#ifndef PLAYER_H
#define PLAYER_H
#include "pokemon_card.h"
#include "trainer_card.h"
#include "energy_card.h"

class Player {
    private:
        string playerName;
        vector<Card*> benchCards;
        vector<Card*> actionCards;

    public:

        Player(string pName) : playerName(pName) {
        }
        void addCardToBench(Card* card) {
            benchCards.push_back(card);
        }
        void activatePokemonCard(int index) {
            if (index >= 0 && index < benchCards.size()) {
                cout << playerName << " is activating a Pokemon Card: " << benchCards[index]->getCardName() << endl;
                actionCards.push_back(benchCards[index]);
                benchCards.erase(benchCards.begin() + index); 
            }
        }
        void attachEnergyCard(int pokemonIndex, int energyIndex) {
            if (pokemonIndex >= 0 && pokemonIndex < actionCards.size() &&
                energyIndex >= 0 && energyIndex < benchCards.size()) {
                PokemonCard* pCard = dynamic_cast<PokemonCard*>(actionCards[pokemonIndex]);
                EnergyCard* eCard = dynamic_cast<EnergyCard*>(benchCards[energyIndex]);
                if (pCard && eCard) {
                    pCard->addEnergy();
                    benchCards.erase(benchCards.begin() + energyIndex);
                    cout << playerName << " is attaching an Energy Card of type " << eCard->getEnergyType() << " to the Pokemon " << pCard->getCardName() << endl;
                }
            }
        }
        void displayBench(){
            cout << "Bench cards for Player " << playerName << endl;
            for (const auto& card : benchCards) {
                card->displayInfo();
            }
        }
        void displayAction(){
            cout << "Action cards for Player " << playerName << endl;
            for (const auto& card : actionCards) {
                card->displayInfo();
            }
        }
        void attack(int attackerIndex, int defenderIndex, Player& opponent,int attackIndex){
            if (attackerIndex >= 0 && attackerIndex < actionCards.size() &&
                defenderIndex >= 0 && defenderIndex < opponent.actionCards.size()) {
                PokemonCard* attackerCard = dynamic_cast<PokemonCard*>(actionCards[attackerIndex]);
                PokemonCard* defenderCard = dynamic_cast<PokemonCard*>(opponent.actionCards[defenderIndex]);
                if (attackerCard && defenderCard) {
                    if (attackIndex >= 0 && attackIndex < static_cast<int>(attackerCard->getAttacks().size())) {
                        auto attackTuple = attackerCard->getAttacks()[attackIndex];
                        int energyCost = std::get<0>(attackTuple);
                        int currentEnergy = std::get<1>(attackTuple);
                        std::string attackName = std::get<2>(attackTuple);
                        int damage = std::get<3>(attackTuple);
                        if (currentEnergy >= energyCost) {
                            cout << playerName << " attacking " << opponent.getPlayerName() << "'s Pokemon " << defenderCard->getCardName()
                                 << " with the Pokemon " << attackerCard->getCardName() << " with its attack: " << attackName << endl;
                            defenderCard->reduceHP(damage);
                            cout << "Reducing " << damage << " from " << opponent.getPlayerName() << "'s Pokemon " << defenderCard->getCardName()
                                 << "'s HP" << endl;
                        } else {
                            cout << attackerCard->getCardName() << " does not have enough energy to perform the attack " << attackName << endl;
                        }
                    }
                }
            }
        }
        void useTrainer(int index) {
            if (index >= 0 && index < benchCards.size()) {
                TrainerCard* tCard = dynamic_cast<TrainerCard*>(benchCards[index]);
                if (tCard->getEffect() == "heal all your action pokemon") {
                    for(const auto& card : actionCards) {
                        PokemonCard* pCard = dynamic_cast<PokemonCard*>(card);
                        if (pCard) {
                            pCard->fullHeal();
                        }
                    }
                }
                cout << playerName << " is using the Trainer Card to " << tCard->getEffect() << endl;
            }
        }
        string getPlayerName() {
            return playerName;
        }
};
#endif // PLAYER_H