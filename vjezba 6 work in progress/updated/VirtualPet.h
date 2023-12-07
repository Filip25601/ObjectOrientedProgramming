#pragma once
#include <string>

class VirtualPet{
private:
    std::string ime;
    std::string vrsta;
    int glad;
    int sreca;
    bool budan;
public:
    VirtualPet (std::string ime,std::string vrsta);
    void eat();
    void sleep();
    void play();
    std::string getIme();
    std::string getVrsta();
    int getGlad();
    int getSreca();
    bool jebudan();
};