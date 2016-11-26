#include "Weapon.h"


Weapon::Weapon(const string& weaponName, const int& durability, const int& weaponDamage) : Item(weaponName, durability), kAttackDmg(weaponDamage) {
}


const int Weapon::getAttackDmg() {
	if (getDurability() <= 0)
		return 0;
	else
		return kAttackDmg;
}

void Weapon::receiveDamage(const int& damage) {
	durability_ -= (damage / 2); // Half the damage intake
}

Weapon::~Weapon() {
}