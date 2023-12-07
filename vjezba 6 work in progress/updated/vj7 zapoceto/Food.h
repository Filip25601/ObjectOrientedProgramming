#pragma once

class Food {
private:
    static int counter;

public:
    Food();  // Konstruktor za inicijalizaciju porcije hrane
    ~Food(); // Destruktor za oslobađanje resursa (ako je potrebno)

    // Funkcija za mijenjanje counter vrijednosti
    static void changeCounter(int newValue);

    // Getter funkcija za counter vrijednost
    static int getCounter();
};
