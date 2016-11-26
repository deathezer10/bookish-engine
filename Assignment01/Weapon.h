#ifndef WEAPON_H
#define WEAPON_H


#include "Item.h"

class Weapon : public Item {


public:
	Weapon(const string& weaponName, const int& durability, const int& weaponDamage);
	~Weapon();
	const int getAttackDmg();
	virtual void receiveDamage(const int& damage);

protected:
	const int kAttackDmg;





};

#endif