#pragma once


#include "Item.h"

class Outfit : public Item {


public:
	Outfit(const string&, const int&, const int&);
	~Outfit();
	const int getSPECIAL();
	virtual void receiveDamage(const int&);

protected:
	const int kSPECIAL;

};