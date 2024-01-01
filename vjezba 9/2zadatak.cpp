#include <iostream>
#include <unordered_set>

template <typename T>
class Skup {
private:
    std::unordered_set<T> elementi;

public:
    void dodajElement(const T& element) {
        elementi.insert(element);
    }
    void izbaciElement(const T& element) {
        auto it = elementi.find(element);
        if (it != elementi.end()) {
            elementi.erase(it);
        } else {
            std::cout << "Element " << element << " nije prisutan u skupu." << std::endl;
        }
    }
    bool provjeriPrisutnost(const T& element) const {
        return elementi.find(element) != elementi.end();
    }
};

int main() {
    Skup<int> mojSkup;

    mojSkup.dodajElement(1);
    mojSkup.dodajElement(5);
    mojSkup.dodajElement(4);
    mojSkup.dodajElement(7);
    mojSkup.dodajElement(2);


if (mojSkup.provjeriPrisutnost(2))
        std::cout << "Broj 2 se nalazi u skupu." << std::endl;
    else
        std::cout << "Broj 2 se ne nalazi u skupu." << std::endl;

    mojSkup.izbaciElement(2);

    if (mojSkup.provjeriPrisutnost(2))
        std::cout << "Broj 2 se nalazi u skupu." << std::endl;
    else
        std::cout << "Broj 2 se ne nalazi u skupu." << std::endl;

    return 0;
}
