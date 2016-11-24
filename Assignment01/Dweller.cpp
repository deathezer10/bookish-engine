#include "Dweller.h"


Dweller::Dweller(const string& name, const int& special) : GameObject(name) {
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
	return SPECIAL_;
}

const int Dweller::getCurrentHealth() {
	return health_;
}

const int Dweller::getCurrentRadDamage() {
	return radiation_;
}

const int Dweller::getAttackDmg() {
	if (weapon_ == NULL)
		return 0;
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

	receiveHealthDamage(0); // Clamp the health with new rad damage
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