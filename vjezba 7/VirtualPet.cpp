#include "VirtualPet.h"
#include <iostream>
#include <string.h>


VirtualPet::VirtualPet(std::string ime, std::string vrsta, Food& hrana)
    : ime(ime), vrsta(vrsta), glad(20), sreca(20), budan(true), hrana(hrana) {
}


std::string VirtualPet::getIme()const {
    return this->ime;
}

std::string VirtualPet::getVrsta()const {
    return this->vrsta;
}

int VirtualPet::getGlad()const {
    return this->glad;
}

int VirtualPet::getSreca() const{
    return this->sreca;
}

bool VirtualPet::getBudan()const {
    return this->budan;
}


void VirtualPet::setIme(std::string name)
{
    this->ime=name;
}
void VirtualPet::setVrsta(std::string type)
{
    this->vrsta = type;
}
void VirtualPet::setGlad(int glad)
{
    this->glad = glad;
}
void VirtualPet::setSreca(int sreca)
{
    this->sreca = sreca;
}
void VirtualPet::setBudan(bool budan)
{
    this->budan = budan;
}


void VirtualPet::eat() {
    hrana.consumeFood();
    setBudan(true);
    setGlad(getGlad() - 12);
    setSreca(getSreca() + 10);
}

void VirtualPet::sleep() {
    if (glad == 10) {
        setBudan(false);
        setGlad(getGlad() + 10);
        setSreca(getSreca() + 15);
    }
}

void VirtualPet::play() {
    setBudan(true);
    setSreca(getSreca() + 20);
    setGlad(getGlad() + 10);
}



bool VirtualPet::operator==(const VirtualPet& other) const {
    return (getIme() == other.getIme() && (getVrsta() == other.getVrsta()) &&
        (getGlad() == other.getGlad()) && (getSreca() == other.getSreca()) &&
        (getBudan() == other.getBudan()));
}

bool VirtualPet::operator!=(const VirtualPet& other) const {
    return !(*this == other);
}

VirtualPet& VirtualPet::operator=(const VirtualPet& other) {
    if (this != &other) {
        setIme(other.getIme());
        setVrsta(other.getVrsta());
        setGlad(other.glad);
        setSreca(other.sreca);
        setBudan(other.budan);
    }
    return *this;
}

VirtualPet& VirtualPet::operator++() {
    setGlad(getGlad() + 5);
    return *this;

}

VirtualPet VirtualPet::operator++(int) {
    VirtualPet temp = *this;
    this->glad += 5;
    return temp;
}


bool VirtualPet::operator<(const VirtualPet& other) const {
    return getSreca() < other.getSreca();
}

bool VirtualPet::operator>(const VirtualPet& other) const {
    return getSreca() > other.getSreca();
}

bool VirtualPet::operator<=(const VirtualPet& other) const {
    return getSreca() <= other.getSreca();
}

bool VirtualPet::operator>=(const VirtualPet& other) const {
    return getSreca() >= other.getSreca();
}

std::ostream& operator<<(std::ostream& os, const VirtualPet& pet)
{
    os << "Pet: " << pet.getIme() << " (" << pet.getVrsta() << "), "
        << "Glad: " << pet.getGlad() << ", Sreca: " << pet.getSreca()
        << ", Budan: " << (pet.getBudan() ? "Da" : "Ne");
    return os;
}