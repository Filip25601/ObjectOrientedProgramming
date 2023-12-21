#include <iostream>
#include <vector>
#include "Enemy.h"

int main() {
    try {
        std::vector<Enemy*> enemies;

        enemies.push_back(new Boss("Jinx", 200, 30, "Mega Rocket"));
        enemies.push_back(new Monster("Blue Sentinel", 50, 10, "Poison Spit"));
        enemies.push_back(new Boss("Morgana", 180, 25, "Soul Shackles"));
        enemies.push_back(new Monster("Red Brambleback", 80, 15, "Berserker Rage"));

        for (const auto& enemy : enemies) {
            enemy->attack();
            enemy->displayInfo();
            std::cout << std::endl;
        }

        for (auto& enemy : enemies) {
            delete enemy;
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
