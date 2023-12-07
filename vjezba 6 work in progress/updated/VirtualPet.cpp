#include "VirtualPet.h"

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