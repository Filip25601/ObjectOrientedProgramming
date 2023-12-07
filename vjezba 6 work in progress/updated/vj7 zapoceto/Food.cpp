#include "Food.h"
#include <iostream>

int Food::counter = 0;

Food::Food() {
    counter++;
}

Food::~Food() {
    counter--;
}

void Food::changeCounter(int newValue) {
    counter = newValue;
}

int Food::getCounter() {
    return counter;
}
