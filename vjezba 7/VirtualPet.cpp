#include "VirtualPet.h"
#include <iostream>


VirtualPet::VirtualPet(std::string ime,std::string vrsta):
 ime(ime),vrsta(vrsta),glad(20),sreca(20),budan(true) {}


void VirtualPet::eat(){
    budan=true;
    glad-=10;
    sreca+=10;
}

void VirtualPet::sleep(){
    if (glad==10){
        budan=false;
        glad+=10;
        sreca+=15;
        }
}

void VirtualPet::play(){
    budan=true;
    sreca+=20;
    glad+=10;
}

std::string VirtualPet::getIme(){
    return ime;
}

std::string VirtualPet::getVrsta(){
    return vrsta;
}

int VirtualPet::getGlad(){
    return glad;
}

int VirtualPet::getSreca(){
    return sreca;
}

bool VirtualPet::jebudan(){
    return budan;
}


void VirtualPet::feed(Food& food) {
    eat();
    food.changeCounter(food.getCounter() - 1); // Smanjivanje porcija hrane
}




bool VirtualPet::operator==(const VirtualPet& other) const {
    return (ime == other.ime) && (vrsta == other.vrsta) &&
        (glad == other.glad) && (sreca == other.sreca) &&
        (budan == other.budan);
}

bool VirtualPet::operator!=(const VirtualPet& other) const {
    return !(*this == other);
}

VirtualPet& VirtualPet::operator=(const VirtualPet& other) {
    if (this != &other) {
        ime = other.ime;
        vrsta = other.vrsta;
        glad = other.glad;
        sreca = other.sreca;
        budan = other.budan;
    }
    return *this;
}

VirtualPet& VirtualPet::operator++() {
    glad -= 5;
    return *this;
}

VirtualPet VirtualPet::operator++(int) {
    VirtualPet temp = *this;
    glad -= 5;
    return temp;
}

bool VirtualPet::operator<(const VirtualPet& other) const {
    return sreca < other.sreca;
}

bool VirtualPet::operator>(const VirtualPet& other) const {
    return sreca > other.sreca;
}

bool VirtualPet::operator<=(const VirtualPet& other) const {
    return sreca <= other.sreca;
}

bool VirtualPet::operator>=(const VirtualPet& other) const {
    return sreca >= other.sreca;
}

std::ostream& operator<<(std::ostream& os, const VirtualPet& pet)
{
    os << "Pet: " << pet.ime << " (" << pet.vrsta << "), "
        << "Glad: " << pet.glad << ", Sreca: " << pet.sreca
        << ", Budan: " << (pet.budan ? "Da" : "Ne");
    return os;
}