#ifndef POKEMON_CARD_H
#define POKEMON_CARD_H
#include "card.h"
#include <vector>
#include <tuple> 

class PokemonCard : public Card {
    private:
        string pokemonType;
        string familyName;
        int evolutionLevel;
        int maxHP;
        int hp;
        vector<tuple<int,int,string,int>> attacks;
    public:
        PokemonCard(string cName, string pType, string fName, int evoLevel, int maximumHP, vector<tuple<int,string,int>> atkList)
        : Card(cName), pokemonType(pType), familyName(fName), evolutionLevel(evoLevel), maxHP(maximumHP), hp(maximumHP) {
            for (const auto& atk : atkList) {
                int energyCost;
                string attackName;
                int damage;
                tie(energyCost, attackName, damage) = atk;
                attacks.push_back(make_tuple(energyCost,0, attackName, damage));
            }
        }
        PokemonCard(string cName, string pType, string fName, int evoLevel, int maximumHP, int energyCost1, string attackName1, int damage1, int energyCost2, string attackName2, int damage2)
        : Card(cName), pokemonType(pType), familyName(fName), evolutionLevel(evoLevel), maxHP(maximumHP), hp(maximumHP) {
            attacks.push_back(make_tuple(energyCost1,0, attackName1, damage1));
            attacks.push_back(make_tuple(energyCost2,0, attackName2, damage2));
        }

        virtual void PokemonCard::displayInfo() override {
            cout << "Pokemon Card - Name : " << getCardName() << ", Type: " << pokemonType << ", Evolution Level: " << evolutionLevel << ", of the family: " << familyName << ", HP: " << hp << endl;
            cout << "Attacks:" << endl;
            int numAtk = 0;
            for (const auto& atk : attacks) {
                int energyCost, damage, currentEnergy;
                string attackName;
                tie(energyCost, currentEnergy, attackName, damage) = atk;
                cout << "Attack #" << numAtk << endl;
                cout << "Attack cost: " << energyCost << endl;
                cout << "Attack current energy storage: " << currentEnergy << endl;
                cout << "Attack description: " << attackName << endl;
                cout << "Attack damage: " << damage << endl;
                numAtk++;
            }
        }
        vector<tuple<int,int,string,int>> getAttacks() {
            return attacks;
        }
        void reduceHP(int damage) {
            hp -= damage;
            if (hp < 0) {
                hp = 0;
            }
        }
        int getHP() {
            return hp;
        }
        void fullHeal() {
            hp = maxHP;
        }
        void addEnergy() {
            for (auto& atk : attacks) {
                std::get<1>(atk) += 1;
            }
        }
};

#endif // POKEMON_CARD_H
