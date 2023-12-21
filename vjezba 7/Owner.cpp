#include "Owner.h"
#include <iostream>

Owner::Owner(std::string name,Food& hrana) : name(name), hrana(hrana) {}


void Owner::Add(VirtualPet pet){
    pets.push_back(pet);
}

void Owner::setName(std::string name)
{
    this->name = name;
}
std::string Owner::getName()const {
    return this->name;
}

void Owner::setPets(std::vector<VirtualPet> pets)
{
    this->pets = pets;
}
std::vector<VirtualPet> Owner::getPets()const
{
    return this->pets;
}

void Owner::Action(){
   for (size_t i = 0; i < pets.size(); ++i) {
        VirtualPet& pet = pets[i];
        int randomAction = rand() % 3 ; 
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
    setName(other.getName());
    setPets((other.getPets()));
}

void Owner::transferOwnership(Owner&& other) {
    setName(std::move(other.getName()));
    setPets(std::move(other.getPets()));
}

VirtualPet Owner::getHappiest()  {
    auto happiestPet = std::max_element(pets.begin(), pets.end(),
        [](const VirtualPet& pet1, const VirtualPet& pet2) {
            return pet1.getSreca() < pet2.getSreca();
        });

    return *happiestPet;
}


