#include "Enemy.h"

Enemy::Enemy(const std::string& name, int health, int damage) : name(name), health(health), damage(damage) {
    if (health < 0 || damage < 0) {
        throw std::invalid_argument("Health and damage must be non-negative.");
    }
}



Boss::Boss(const std::string& name, int health, int damage, const std::string& weapon)
    : Enemy(name, health, damage), weapon(weapon) {
    if (weapon.empty()) {
        throw std::invalid_argument("Weapon cannot be empty.");
    }
}

void Boss::attack() const {
    std::cout << "Boss attacks with " << weapon << " and deals " << damage << " damage." << std::endl;
}

void Boss::displayInfo() const {
    std::cout << "Boss - Name: " << name << ", Health: " << health << ", Damage: " << damage << ", Weapon: " << weapon << std::endl;
}


Monster::Monster(const std::string& name, int health, int damage, const std::string& specialAbility)
    : Enemy(name, health, damage), specialAbility(specialAbility) {
    if (specialAbility.empty()) {
        throw std::invalid_argument("Special ability cannot be empty.");
    }
}

void Monster::attack() const {
    std::cout << "Monster attacks with special ability: " << specialAbility << " and deals " << damage << " damage." << std::endl;
}

void Monster::displayInfo() const {
    std::cout << "Monster - Name: " << name << ", Health: " << health << ", Damage: " << damage << ", Special Ability: " << specialAbility << std::endl;
}
