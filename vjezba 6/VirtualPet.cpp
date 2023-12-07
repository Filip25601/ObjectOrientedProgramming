#include "VirtualPet.h"

VirtualPet::VirtualPet(std::string ime,std::string vrsta):
 ime(ime),vrsta(vrsta),glad(20),sreca(20),budan(true) {}


void VirtualPet::jedi(){
    budan=true;
    glad-=15;
    sreca+=10;
}

void VirtualPet::spavaj(){
    if (glad<=15){
        budan=false;
        glad+=10;
        sreca+=15;
        }
}

void VirtualPet::igraj(){
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