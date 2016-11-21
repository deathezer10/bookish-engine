#pragma once


#include "Item.h"

class Outfit : public Item {


public:
	Outfit(const string&, const int&, const int&);
	~Outfit();
	const int getSPECIAL();

protected:
	const int kSPECIAL;

};