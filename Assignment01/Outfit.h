#ifndef OUTFIT_H
#define OUTFIT_H


#include "Item.h"

class Outfit : public Item {


public:
	Outfit(const string& outfitName, const int& durability, const int& special);
	~Outfit();
	const int getSPECIAL();
	virtual void receiveDamage(const int& damage);

protected:
	const int kSPECIAL;

};

#endif