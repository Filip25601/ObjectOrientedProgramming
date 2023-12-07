#include "Owner.h"
#include <iostream>
#include <ctime>

int main() {
	srand(time(0));
	std::string ime1;
	std::string ime2;
	int akcija1;
	int akcija2;
	std::cout << "Unesi ime prvog vlasnika\n";
	std::getline(std::cin, ime1);

	std::cout << "Unesi ime drugog vlasnika\n";
	std::getline(std::cin, ime2);

	Owner owner1(ime1);
	Owner owner2(ime2);

	VirtualPet pet1("dog", "Pas");
	VirtualPet pet2("Dante", "Macka");

	VirtualPet pet3("gato", "mackaaa");
	VirtualPet pet4("cato", "Mackaa");

	owner1.Add(pet1);
	owner1.Add(pet2);

	owner2.Add(pet3);
	owner2.Add(pet4);

	std::cout << "Koliko akcija zeli prvi vlasnik uciniti?\n";
	std::cin >> akcija1;
	for (int i = 0; i < akcija1; ++i) {
				owner1.Action();
	}
	std::cout << "Koliko akcija zeli drugi vlasnik uciniti?\n";
	std::cin >> akcija2;
	
	for (int i = 0; i < akcija2; ++i) {
		owner2.Action();
	}

	
    Owner owner3 = owner1;
    owner3.Action(); 
    Owner owner4("Luka");
    owner4.Add(VirtualPet("snoop", "Dog"));
    owner4.transferOwnership(std::move(owner1));

    
    owner3.Action();
    owner4.Action();

    Owner happiestOwner = owner4.getHappiest().getSreca() > owner2.getHappiest().getSreca() ?
                          owner4 : owner2;

    std::cout << "owner with the happiest pet is: " << happiestOwner.getName() << std::endl;

    return 0;
}
