#include "Outfit.h"


Outfit::Outfit(const string& outfitName, const int& durability, const int& special) : Item(outfitName, durability), kSPECIAL(special) {

};

const int Outfit::getSPECIAL() {
	if (getDurability() <= 0)
		return 0;
	else
		return kSPECIAL;
}

void Outfit::receiveDamage(const int& damage) {
	durability_ -= damage;
}

Outfit::~Outfit() {
}