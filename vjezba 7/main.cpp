#include "VirtualPet.h"
#include "Owner.h"
#include "Food.h"

#include <iostream>
#include <ctime>

int get_counter();


int main() {
	srand(time(0));
	std::string ime1;
	std::string ime2;
	int akcija1;
	int akcija2;
    Food hrana;
	std::cout << "Unesi ime prvog vlasnika\n";
	std::getline(std::cin, ime1);

	std::cout << "Unesi ime drugog vlasnika\n";
	std::getline(std::cin, ime2);

	Owner owner1(ime1, hrana);
	Owner owner2(ime2, hrana);

	VirtualPet pet1("Medo", "Pas", hrana);
	VirtualPet pet2("Dante", "Macka", hrana);

	VirtualPet pet3("Sarena", "Macka", hrana);
	VirtualPet pet4("Neo", "Macka", hrana);

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
    int nesto = get_counter();
    std::cout << "Counter je:" << nesto << std::endl;
    hrana.printCounter();

    Owner owner3("Ante", hrana);
    owner3.copyOwner(owner1);

    // Owner owner4("Luka");
    //owner4.Add(VirtualPet("snoop", "Dog"));
    //  owner4.transferOwnership(std::move(owner1));

    
    owner3.Action();
  //  owner4.Action();
    std::cout << "Pet5: " << owner1.getPets()[0] << std::endl;


    Owner happiestOwner = owner1.getHappiest().getSreca() > owner2.getHappiest().getSreca() ?
                          owner1 : owner2;

    std::cout << "owner with the happiest pet is: " << happiestOwner.getName() << std::endl;


    
    if (owner1.getPets()[0] == owner2.getPets()[0]) {
        std::cout << "Pet1 i Pet3 su isti.\n" << std::endl;
    }
   
    if (owner1.getPets()[0] != owner1.getPets()[1]) {
        std::cout << "Pet1 and Pet2 nisu isti.\n" << std::endl;
    }
    
    VirtualPet pet5 = owner1.getPets()[0];
    std::cout << "\nprije inkrementa Pet5: " << pet5 << std::endl;

    pet5++;
    std::cout << "\nposlije inkrementa Pet5: " << pet5 << std::endl;

    ++pet5;

    std::cout << "poslije drugog inkrementa Pet5: " << pet5 << std::endl;
    std::cout << "\n ";


    if (owner1.getPets()[0] >= owner1.getPets()[1]) {
        std::cout << "Pet1 is happier than Pet2." << std::endl;
    }
    if (owner1.getPets()[0] <= owner1.getPets()[1]) {
        std::cout << "Pet1 is not happier than Pet2." << std::endl;
    }

    std::cout << "Pet3: " << owner2.getPets()[0] << std::endl;
    
    return 0;
}
