#ifndef REPTILE_H
#define REPTILE_H
#include "Animal.h"

class Reptile : public Animal {
    private:
        std::string scalePattern;
    public:
        Reptile() : Animal(), scalePattern("Unknown") {}

        Reptile(const std::string& name, const std::string& color, const std::string& diet,
                const std::string& habitat, const std::string& sounds, bool isPet,
                int age, double weight, double height, const std::string& scalePattern)
            : Animal(name, color, diet, habitat, sounds, isPet, age, weight, height),
              scalePattern(scalePattern) {}

        Reptile(const Reptile& other) = default;

        void setScalePattern(const std::string& scalePattern) { this->scalePattern = scalePattern; }
        std::string getScalePattern() const { return scalePattern; }

        void printInfo() const override {
            std::cout << "Reptile Information:" << std::endl;
            animalInfo();
            std::cout << "Scale Pattern: " << scalePattern << std::endl;
        }
};
    
#endif // REPTILE_H