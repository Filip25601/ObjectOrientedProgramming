#pragma once
#include <vector>
#include "VirtualPet.h"
#include "Food.h"

class Owner{
private:
    std::string name;
    std::vector<VirtualPet> pets;
    Food& hrana;
public:
    Owner (std::string name, Food& hrana);

    void setName(std::string name);
    std::string getName()const;

    void setPets(std::vector<VirtualPet> pets);
    std::vector<VirtualPet> getPets()const;
    void Add(VirtualPet pet);
    void Action();

    void copyOwner(Owner& other);
    void transferOwnership(Owner&& other);

    VirtualPet getHappiest();

};