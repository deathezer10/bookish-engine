#include "Outfit.h"
#include <exception>

Outfit::Outfit(const string& outfitName, const int& durability, const int& special) : Item(outfitName, durability), kSPECIAL(special) {
	if ((kSPECIAL > 9999999 || kSPECIAL < 1000000) && kSPECIAL != 0) // Must have only 7 digits or just Zero
		throw std::out_of_range("Invalid special specified in Outfit");
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