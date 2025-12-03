#include "Zoo.h"

int main() {
    Zoo myZoo("My Awesome Zoo");

    // Add some animals
    myZoo.addAnimal(new Mammal("Lion", "Golden", "Carnivore", "Savannah", "Roar", false, 5, 190.5, 1.2, "Golden"));
    myZoo.addAnimal(new Bird("Parrot", "Green", "Herbivore", "Tropical", "Squawk", true, 2, 1.5, 0.3, 25.0));
    myZoo.addAnimal(new Reptile("Iguana", "Green", "Herbivore", "Rainforest", "Hiss", false, 3, 4.0, 0.5, "Spotted"));
    myZoo.addAnimal(new Mammal("Elephant", "Gray", "Herbivore", "Savannah", "Trumpet", false, 10, 5400.0, 3.3, "Gray"));
    myZoo.addAnimal(new Bird("Eagle", "Brown", "Carnivore", "Mountains", "Screech", false, 4, 6.5, 0.8, 200.0));
    myZoo.addAnimal(new Reptile("Crocodile", "Green", "Carnivore", "Swamp", "Growl", false, 7, 500.0, 0.4, "Rough"));
    myZoo.addAnimal(new Mammal("Dog", "Various", "Omnivore", "Domestic", "Bark", true, 3, 20.0, 0.6, "Various"));
    myZoo.addAnimal(new Bird("Penguin", "Black and White", "Carnivore", "Antarctica", "Honk", false, 6, 30.0, 0.5, 80.0));
    myZoo.addAnimal(new Reptile("Tortoise", "Brown", "Herbivore", "Desert", "Silent", false, 50, 100.0, 0.3, "Hard"));

    // List animals
    myZoo.listAnimals();

    // Predict type of an unknown animal using KNN
    Animal unknownAnimal("Unknown", "Green", "Herbivore", "Jungle",
                                    "Chirp", false, 2, 2.0, 0.4);
    myZoo.predictTypeWithKNN(unknownAnimal, 3, "numerical");
    myZoo.predictTypeWithKNN(unknownAnimal, 3, "categorical");
    
    return 0;
}