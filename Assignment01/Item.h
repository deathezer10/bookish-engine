#pragma once

#include "GameObject.h"

class Item : public GameObject {


public:
	Item(const string&, const int&);
	~Item();
	void receiveDamage(const int& = 0);
	const int getDurability();


};

