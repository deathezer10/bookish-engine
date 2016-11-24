#include "GameObject.h"


int GameObject::count = 0; // first-time initialization



GameObject::GameObject(const string& objName) : kName(objName) {
	count++;
}

int GameObject::getCount() {
	return count;
}

string GameObject::getName() {
	return kName;
}

GameObject::~GameObject() {
	count--;
}