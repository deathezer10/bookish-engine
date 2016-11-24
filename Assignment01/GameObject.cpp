#include "GameObject.h"



GameObject::GameObject(const string& objName) : kName(objName) {
	count = 0; // first static initialization
	count++;
}

GameObject::~GameObject() {
	count--;
}

int GameObject::getCount() {
	return count;
}

string GameObject::getName() {
	return kName;
}