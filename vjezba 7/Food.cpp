#include"Food.h"
#include<iostream>
#include <algorithm>

int Food::counter = 20;

Food::Food() { 
	++counter;
}

Food::~Food() {
	--counter; 
}

void Food::changeCounter(int value) {
	counter += value;
	counter = std::max(0, counter);
}

void Food::printCounter() {
	std::cout << "Broj raspolozivih porcija je: " << counter << std::endl;
}

int Food::getCounter() {
	return counter;
}

int get_counter() {
	return Food::getCounter();
}

void Food::consumeFood() {
	if (counter > 0) {
		counter--;
	}
}