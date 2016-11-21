#pragma once


#include "Item.h"

class Weapon : public Item {


public:
	Weapon(const string&, const int&, const int&);
	~Weapon();
	const int getAttackDmg();


protected:
	const int kAttackDmg;





};