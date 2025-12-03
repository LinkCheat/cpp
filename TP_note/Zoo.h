#ifndef ZOO_H
#define ZOO_H
#include <vector>
#include "Mammal.h"
#include "Bird.h"
#include "Reptile.h"
#include "Knn_double.h"
#include "Knn_string.h"
#include <algorithm>
#include <map>

class Zoo {
    private:
        std::string name;
        static const int MAX_CAPACITY=100;
        std::vector<Animal*> animals;
    public:
        Zoo() : name("Unnamed Zoo") {}

        Zoo(const std::string& name) : name(name) {}

        Zoo(const Zoo& other): name(other.name), animals(other.animals) {}

        ~Zoo() {
            for (Animal* animal : animals) {
                delete animal;
            }
        }

        void setName(const std::string& name) { this->name = name; }
        std::string getName() const { return name; }

        bool addAnimal(Animal* animal) {
            if (std::any_of(animals.begin(), animals.end(),
                            [&](const Animal* a){ return a->getName() == animal->getName(); })) {
                std::cout << "An animal with the name \"" << animal->getName() << "\" already exists." << std::endl;
                return false;
            }
            if (animals.size() < MAX_CAPACITY) {
                auto it = std::lower_bound(animals.begin(), animals.end(), animal,
                    [](const Animal* a, const Animal* b) {
                        return a->getName() < b->getName();
                    });
                animals.insert(it, animal);
                return true;
            } else {
                std::cout << "Zoo is at full capacity!" << std::endl;
                return false;
            }
        }

        void listAnimals() const {
            std::cout << "Animals in " << name << " Zoo:" << std::endl;
            for (const Animal* animal : animals) {
                animal->printInfo();
                std::cout << "------------------------" << std::endl;
            }
        }

        Animal* SearchAnimalByName(const std::string& name) const {
            auto it = std::lower_bound(animals.begin(), animals.end(), name,
                [](const Animal* a, const std::string& name) {
                    return a->getName() < name;
                });
            if (it != animals.end() && (*it)->getName() == name) {
                return *it;
            }
            return nullptr;
        }

        bool removeAnimalByName(const std::string& name) {
            auto it = std::lower_bound(animals.begin(), animals.end(), name,
                [](const Animal* a, const std::string& name) {
                    return a->getName() < name;
                });
            if (it != animals.end() && (*it)->getName() == name) {
                delete *it; // Free the memory
                animals.erase(it);
                return true;
            } else {
                std::cout << "No animal found with the name \"" << name << "\"." << std::endl;
                return false;
            }
        }

        int averageAgeForType(const std::string& type) const {
            int totalAge = 0;
            int count = 0;
            for (const Animal* animal : animals) {
                if (type == "Mammal" && dynamic_cast<const Mammal*>(animal)) {
                    totalAge += animal->getAge();
                    count++;
                } else if (type == "Bird" && dynamic_cast<const Bird*>(animal)) {
                    totalAge += animal->getAge();
                    count++;
                } else if (type == "Reptile" && dynamic_cast<const Reptile*>(animal)) {
                    totalAge += animal->getAge();
                    count++;
                }
            }
            if (count == 0) return 0;
            return totalAge / count;
        }

        void predictTypeWithKNN(const Animal& unknownAnimal, int k, std::string informationType) const {
            if (informationType == "numerical"){
                KNN_Double knn(k);
                std::vector<std::pair<double, double>> trainData;
                std::vector<std::string> labels;
                for (const Animal* animal : animals) {
                    trainData.push_back({animal->getWeight(), animal->getHeight()});
                    if (dynamic_cast<const Mammal*>(animal)) {
                        labels.push_back("Mammal");
                    } else if (dynamic_cast<const Bird*>(animal)) {
                        labels.push_back("Bird");
                    } else if (dynamic_cast<const Reptile*>(animal)) {
                        labels.push_back("Reptile");
                    } else {
                        labels.push_back("Unknown");
                    }
                }
                std::pair<double, double> target = {unknownAnimal.getWeight(), unknownAnimal.getHeight()};
                std::vector<int> neighbors = knn.findNearestNeighbors(trainData, target);
                std::map<std::string, int> typeCount;
                for (int idx : neighbors) {
                    typeCount[labels[idx]]++;
                }
                std::string predictedType;
                int maxCount = 0;
                for (const auto& pair : typeCount) {
                    if (pair.second > maxCount) {
                        maxCount = pair.second;
                        predictedType = pair.first;
                    }
                }
                std::cout << "Predicted Type (Numerical): " << predictedType << std::endl;
            } else if (informationType == "categorical") {
                KNN_String knn(k);
                std::vector<std::vector<std::string>> trainData;
                std::vector<std::string> labels;
                for (const Animal* animal : animals) {
                    trainData.push_back({animal->getColor(), animal->getDiet(), animal->getHabitat(), animal->getSounds()});
                    if (dynamic_cast<const Mammal*>(animal)) {
                        labels.push_back("Mammal");
                    } else if (dynamic_cast<const Bird*>(animal)) {
                        labels.push_back("Bird");
                    } else if (dynamic_cast<const Reptile*>(animal)) {
                        labels.push_back("Reptile");
                    } else {
                        labels.push_back("Unknown");
                    }
                }
                std::vector<std::string> target = {unknownAnimal.getColor(), unknownAnimal.getDiet(), unknownAnimal.getHabitat(), unknownAnimal.getSounds()};
                std::vector<int> neighbors = knn.findNearestNeighbors(trainData, target);
                std::map<std::string, int> typeCount;
                for (int idx : neighbors) {
                    typeCount[labels[idx]]++;
                }
                std::string predictedType;
                int maxCount = 0;
                for (const auto& pair : typeCount) {
                    if (pair.second > maxCount) {
                        maxCount = pair.second;
                        predictedType = pair.first;
                    }
                }
                std::cout << "Predicted Type (Categorical): " << predictedType << std::endl;
            }
        }
};

#endif // ZOO_H