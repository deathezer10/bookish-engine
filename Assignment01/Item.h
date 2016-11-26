#ifndef ITEM_H
#define ITEM_H


#include "GameObject.h"

class Item : public GameObject {


public:
	Item(const string& name, const int& durability);
	~Item();
	const int getDurability();

	virtual void receiveDamage(const int& damage) = 0;

protected:
	int durability_;

};

#endif