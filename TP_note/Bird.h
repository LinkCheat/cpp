#ifndef BIRD_H
#define BIRD_H
#include "Animal.h"

class Bird : public Animal {
    private:
        double wingSpan; // in centimeters
    public:
        Bird() : Animal(), wingSpan(0.0) {}

        Bird(const std::string& name, const std::string& color, const std::string& diet,
             const std::string& habitat, const std::string& sounds, bool isPet,
             int age, double weight, double height, double wingSpan)
            : Animal(name, color, diet, habitat, sounds, isPet, age, weight, height),
              wingSpan(wingSpan) {}

        Bird(const Bird& other) = default;

        void setWingSpan(double wingSpan) { this->wingSpan = wingSpan; }
        double getWingSpan() const { return wingSpan; }

        void printInfo() const override {
            std::cout << "Bird Information:" << std::endl;
            animalInfo();
            std::cout << "Wing Span: " << wingSpan << " cm" << std::endl;
        }
};

#endif // BIRD_H