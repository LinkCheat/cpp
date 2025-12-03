#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include <iostream>
class Animal {
    private:
        std::string name;
        std::string color;
        std::string diet;
        std::string habitat;
        std::string sounds;
        bool isPet;
        int age;
        double weight;
        double height;

    public:
        Animal(): name("Unknown"), color("Unknown"), diet("Unknown"), habitat("Unknown"),
              sounds("Unknown"), isPet(false), age(0), weight(0.0), height(0.0) {}

        Animal(const std::string& name, const std::string& color, const std::string& diet,
               const std::string& habitat, const std::string& sounds, bool isPet,
               int age, double weight, double height): name(name), color(color), diet(diet),
               habitat(habitat), sounds(sounds), isPet(isPet), age(age), weight(weight), height(height) {}

        Animal(const Animal& other) = default;

        void setName(const std::string& name) { this->name = name; }
        std::string getName() const { return name; }
        void setColor(const std::string& color) { this->color = color; }
        std::string getColor() const { return color; }
        void setDiet(const std::string& diet) { this->diet = diet; }
        std::string getDiet() const { return diet; }
        void setHabitat(const std::string& habitat) { this->habitat = habitat; }
        std::string getHabitat() const { return habitat; }
        void setSounds(const std::string& sounds) { this->sounds = sounds; }
        std::string getSounds() const { return sounds; }
        void setIsPet(bool isPet) { this->isPet = isPet; }
        bool getIsPet() const { return isPet; }
        void setAge(int age) { this->age = age; }
        int getAge() const { return age; }
        void setWeight(double weight) { this->weight = weight; }
        double getWeight() const { return weight; }
        void setHeight(double height) { this->height = height; }
        double getHeight() const { return height; }

        void makeSound() const {
            if (sounds != "Unknown") {
                std::cout << name << " makes a sound: " << sounds << std::endl;
            } else {
                std::cout << name << " is silent." << std::endl;
            }
        }

        virtual void printInfo() const {
            std::cout << "Animal of unknown type:" << std::endl;
            animalInfo();
        }

        void animalInfo() const {
            std::cout << "Name: " << name << std::endl;
            std::cout << "Color: " << color << std::endl;
            std::cout << "Diet: " << diet << std::endl;
            std::cout << "Habitat: " << habitat << std::endl;
            std::cout << "Age: " << age << " years" << std::endl;
            if (isPet) {
                std::cout << "This animal is a pet." << std::endl;
            } else {
                std::cout << "This animal is not a pet." << std::endl;
            }
            std::cout << "Weight: " << weight << " kg" << std::endl;
            std::cout << "Height: " << height << " m" << std::endl;
        }
};
#endif // ANIMAL_H