#include "Dweller.h"

using std::to_string;
using std::stoi;

Dweller::Dweller(const string& name, const int& special) : GameObject(name) {
	if ((special > 9999999 || special < 1000000) && special != 0) // Must have only 7 digits or just Zero
		throw std::out_of_range("Invalid special specified in Dweller");

	setPosition(Vec2D(0, 0));
	SPECIAL_ = special;
	health_ = 100;
	radiation_ = 0;
	stimpak_ = 0;
	radaway_ = 0;
	outfit_ = NULL;
	weapon_ = NULL;
}

const int Dweller::getSPECIAL() {
	if (SPECIAL_ == 0)
		return ((outfit_ == NULL) ? 0 : outfit_->getSPECIAL());

	if (outfit_ == NULL)
		return SPECIAL_;

	string dwellerStr = to_string(SPECIAL_);
	string outfitStr = (outfit_->getDurability() == 0) ? "0000000" : to_string(outfit_->getSPECIAL()); // check if durability is 0
	string outputStr = "0000000";

	for (unsigned i = 0; i < outputStr.length(); i++) {
		int sum = ((dwellerStr[i] - '0') + (outfitStr[i] - '0'));

		// Prevent over 9
		if (sum > 9)
			sum = 9;

		outputStr[i] = sum + '0';
	}

	return stoi(outputStr);
}

const int Dweller::getCurrentHealth() {
	return health_;
}

const int Dweller::getCurrentRadDamage() {
	return radiation_;
}

const int Dweller::getAttackDmg() {
	if (weapon_ == NULL)
		return 1; // 1 damage if the Dweller has no weapon
	else
		return weapon_->getAttackDmg();
}

const Vec2D Dweller::getPosition() {
	return position_;
}

void Dweller::setPosition(const Vec2D& pos) {
	position_ = Vec2D(pos.x, pos.y);
}


void Dweller::receiveHealthDamage(const int& damage) {
	health_ -= damage;

	// Clamp the value
	if (health_ < 0)
		health_ = 0;

	if (health_ > (100 - radiation_))
		health_ = (100 - radiation_);
}

void Dweller::receiveRadDamage(const int& damage) {
	radiation_ += damage;

	if (radiation_ < 0)
		radiation_ = 0;

	if (radiation_ > 100)
		radiation_ = 100;
}

void Dweller::receiveEquipmentDamage(const int& damage) {
	if (weapon_ != NULL)
		weapon_->receiveDamage(damage);

	if (outfit_ != NULL)
		outfit_->receiveDamage(damage);
}

void Dweller::addStimpak(const int& count) {
	stimpak_ += count;
}

void Dweller::addRadAway(const int& count) {
	radaway_ += count;
}

void Dweller::useStimpak() {
	if (stimpak_ > 0 && health_ > 0 && health_ < 100) {
		stimpak_--;
		receiveHealthDamage(-20);
	}
}

void Dweller::useRadAway() {
	if (radaway_ > 0 && radiation_ > 0) {
		radaway_--;
		receiveRadDamage(-10);
	}
}

Outfit* Dweller::assignOutfit(Outfit* outfit) {
	outfit_ = outfit;
	return outfit_;
}

Weapon* Dweller::assignWeapon(Weapon* weapon) {
	weapon_ = weapon;
	return weapon_;
}

bool Dweller::isDead() {
	if (health_ <= 0)
		return true;
	else
		return false;
}

Dweller::~Dweller() {
}