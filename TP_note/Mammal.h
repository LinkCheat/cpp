#ifndef MAMMAL_H
#define MAMMAL_H
#include "Animal.h"

class Mammal : public Animal {
    private:
        std::string furColor;
    public:
        Mammal() : Animal(), furColor("Unknown") {}

        Mammal(const std::string& name, const std::string& color, const std::string& diet,
               const std::string& habitat, const std::string& sounds, bool isPet,
               int age, double weight, double height, const std::string& furColor)
            : Animal(name, color, diet, habitat, sounds, isPet, age, weight, height),
              furColor(furColor) {}

        Mammal(const Mammal& other) = default;

        void setFurColor(const std::string& furColor) { this->furColor = furColor; }
        std::string getFurColor() const { return furColor; }

        void printInfo() const override {
            std::cout << "Mammal Information:" << std::endl;
            animalInfo();
            std::cout << "Fur Color: " << furColor << std::endl;
        }
};
#endif // MAMMAL_H