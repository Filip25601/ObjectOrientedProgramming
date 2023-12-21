#pragma once

#include <stdexcept>
#include <iostream>

class Enemy {
protected:
    std::string name;
    int health;
    int damage;

public:
    Enemy(const std::string& name, int health, int damage);
    virtual ~Enemy() = default;

    virtual void attack() const = 0;
    virtual void displayInfo() const = 0;
};


class Boss : public Enemy {
private:
    std::string weapon;

public:
    Boss(const std::string& name, int health, int damage, const std::string& weapon);
    void attack() const override;
    void displayInfo() const override;
};

class Monster : public Enemy {
private:
    std::string specialAbility;

public:
    Monster(const std::string& name, int health, int damage, const std::string& specialAbility);
    void attack() const override;
    void displayInfo() const override;
};
