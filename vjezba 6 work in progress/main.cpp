#include "Owner.h"
#include <iostream>

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    // Create owners and pets
    Owner owner1("John");
    Owner owner2("Alice");

    VirtualPet pet1("Buddy", "Pas");
    VirtualPet pet2("Dante", "Macka");

    owner1.Add(pet1);
    owner1.Add(pet2);

    //  copy constructor
    Owner owner3 = owner1;
    owner3.Action(); 

    //  move constructor
    Owner owner4("Mike");
    owner4.Add(VirtualPet("Fido", "Dog"));
    owner4.transferOwnership(std::move(owner1));

    // Simulate actions on owners
    owner1.Action();
    owner2.Action();
    owner3.Action();
    owner4.Action();

    // Find and print the owner with the happiest pet
    Owner happiestOwner = owner1.getHappiest().getSreca() > owner2.getHappiest().getSreca() ?
                          owner1 : owner2;

    std::cout << "The owner with the happiest pet is: " << happiestOwner.getName() << std::endl;

    return 0;
}
