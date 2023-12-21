#pragma once
#include <string>
#include <iostream>
#include "Food.h"
class VirtualPet{
private:
    std::string ime;
    std::string vrsta;
    int glad;
    int sreca;
    bool budan;
    Food& hrana;
public:
  
    VirtualPet (std::string ime,std::string vrsta, Food& hrana);
    void eat();
    void sleep();
    void play();

    std::string getIme()const;
    std::string getVrsta()const;
    int getGlad()const;
    int getSreca() const;
    bool getBudan()const;

    void setIme(std::string name);
    void setVrsta(std::string type);
    void setGlad(int glad );
    void setSreca(int sreca) ;
    void setBudan(bool budan);


    bool operator==(const VirtualPet& other) const;
    bool operator!=(const VirtualPet& other) const;
    VirtualPet& operator=(const VirtualPet& other);
    VirtualPet& operator++();       
    VirtualPet operator++(int);     
    bool operator<(const VirtualPet& other) const;
    bool operator>(const VirtualPet& other) const;
    bool operator<=(const VirtualPet& other) const;
    bool operator>=(const VirtualPet& other) const;

    friend std::ostream& operator<<(std::ostream& os, const VirtualPet& pet);

};