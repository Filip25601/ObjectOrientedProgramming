#pragma once
#include <vector>
#include "VirtualPet.h"
#include "Food.h"

class Owner{
private:
    std::string name;
    std::vector<VirtualPet> pets;

public:
    Owner (std::string name);

    void Add(VirtualPet pet);
    void Action();

    void copyOwner(Owner& other);
    void transferOwnership(Owner&& other);

    std::string getName();
    VirtualPet getHappiest();

    void feedPets(Food& food);

};