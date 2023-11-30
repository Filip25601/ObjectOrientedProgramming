#include "Owner.h"
#include <algorithm>
#include <iostream>

Owner::Owner(std::string& name) : name(name){}

void Owner::Add(VirtualPet& pet){
    pets.push_back(pet);
}

void Owner::Action(){
   for (size_t i = 0; i < pets.size(); ++i) {
        auto& pet = pets[i];
        int randomAction = rand() % 3; 
        if (randomAction == 0) {
            pet.eat();
        } else if (randomAction == 1) {
            pet.sleep();
        } else {
            pet.play();
        }
    }
}

void Owner::copyOwner(Owner& other){
    name= other.name;
    pets = other.pets;
}

void Owner::transferOwnership(Owner&& other) {
    name = std::move(other.name);
    pets = std::move(other.pets);
}

std::string Owner::getName()  {
    return name;
}

VirtualPet Owner::getHappiest()  {
    auto happiestPet = std::max_element(pets.begin(), pets.end(),
        []( VirtualPet& pet1,  VirtualPet& pet2) {
            return pet1.getSreca() < pet2.getSreca();
        });

    return *happiestPet;
}