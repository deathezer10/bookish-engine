#pragma once

#include <string>

using std::string;

class GameObject {


public:
	~GameObject();
	string getName();
	int getCount();

protected:
	GameObject(const string&);
	const string kName;


private:
	int count;

};

