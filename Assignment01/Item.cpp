#include "Item.h"

Item::Item(const string& itemName, const int& durability) : GameObject(itemName), durability_(durability) {
}

const int Item::getDurability() {
	return durability_;
}