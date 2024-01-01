#include <iostream>
#include <algorithm>

template <typename T>
void customSort(T arr[], int size) {
    std::sort(arr, arr + size);
}

template <>
void customSort<char>(char arr[], int size) {
    std::sort(arr, arr + size, [](char a, char b) {
        return std::tolower(a) < std::tolower(b);
    });
}

int main() {
    int intArray[] = {5, 2, 8, 1, 3};
    int intSize = sizeof(intArray) / sizeof(int);
    
    customSort(intArray, intSize);

    std::cout << "Sorted int array: ";
    for (int i = 0; i < intSize; ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    // niz charova
    char charArray[] = {'u', 'A', 'b', 'D', 'g'};
    int charSize = sizeof(charArray) / sizeof(char);

    customSort(charArray, charSize);

    std::cout << "Sorted char array: ";
    for (int i = 0; i < charSize; ++i) {
        std::cout << charArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
