#pragma once


#include "Item.h"

class Outfit : public Item {


public:
	Outfit(const string& outfitName, const int& durability, const int& special);
	~Outfit();
	const int getSPECIAL();
	virtual void receiveDamage(const int&);

protected:
	const int kSPECIAL;

};