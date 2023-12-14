#include"Food.h"
#include<iostream>

int Food::counter = 0;

void Food::Increase() {
	counter++;
}

void Food::Decrease() {
	counter--;
}

void Food::Print() {
	std::cout << "Broj raspolozivih porcija je: " << counter << std::endl;
}

int Food::getCounter() {
	return counter;
}

int get_counter() {
	return Food::getCounter();
}
