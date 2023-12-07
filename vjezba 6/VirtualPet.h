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
    void jedi();
    void spavaj();
    void igraj();
    std::string getIme();
    std::string getVrsta();
    int getGlad();
    int getSreca();
    bool jebudan();
};