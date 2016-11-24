#include "Outfit.h"


Outfit::Outfit(const string& outfitName, const int& durability, const int& special) : Item(outfitName, durability), kSPECIAL(special) {

};

const int Outfit::getSPECIAL() {

}

void  Outfit::receiveDamage(const int&) {

}