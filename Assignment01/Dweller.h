#ifndef DWELLER_H
#define DWELLER_H


#include "GameObject.h"
#include "Vec2D.h"
#include "Outfit.h"
#include "Weapon.h"


class Dweller : public GameObject {



public:
	Dweller(const string& name, const int& special);
	~Dweller();

	const int getSPECIAL();
	const int getCurrentHealth();
	const int getCurrentRadDamage();
	const int getAttackDmg();

	const Vec2D getPosition();
	void setPosition(const Vec2D& pos);

	void receiveHealthDamage(const int& damage);
	void receiveRadDamage(const int& damage);
	void receiveEquipmentDamage(const int& damage);

	void addStimpak(const int& count);
	void addRadAway(const int& count);

	void useStimpak();
	void useRadAway();

	Outfit* assignOutfit(Outfit* outfit);
	Weapon* assignWeapon(Weapon* weapon);

	bool isDead();


protected:
	Vec2D position_;
	int SPECIAL_;
	int health_;
	int radiation_;
	int stimpak_;
	int radaway_;
	Outfit* outfit_;
	Weapon* weapon_;



};

#endif