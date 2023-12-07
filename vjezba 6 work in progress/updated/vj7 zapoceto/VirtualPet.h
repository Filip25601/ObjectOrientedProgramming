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

    void feed(Food& food);

    bool operator==(const VirtualPet& other) const;
    bool operator!=(const VirtualPet& other) const;
    VirtualPet& operator=(const VirtualPet& other);
    VirtualPet& operator++();       // Prefiksni inkrement
    VirtualPet operator++(int);     // Postfiksni inkrement
    bool operator<(const VirtualPet& other) const;
    bool operator>(const VirtualPet& other) const;
    bool operator<=(const VirtualPet& other) const;
    bool operator>=(const VirtualPet& other) const;

    friend std::ostream& operator<<(std::ostream& os, const VirtualPet& pet);

};