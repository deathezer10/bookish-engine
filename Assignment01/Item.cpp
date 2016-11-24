#include "Item.h"

Item::Item(const string& itemName, const int& durability) : GameObject(itemName){
	durability_ = durability;
}

void Item::receiveDamage(const int&) {

}

const int Item::getDurability() {

}
