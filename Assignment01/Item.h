#pragma once

#include "GameObject.h"

class Item : public GameObject {


public:
	Item(const string&, const int&);
	~Item();
	const int getDurability();

	virtual void receiveDamage(const int&) = 0;

protected:
	int durability_;

};