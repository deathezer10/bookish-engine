#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


#include <string>

using std::string;

class GameObject {


public:
	virtual ~GameObject(); // Virtual to allow derived classes to have proper deletion of memory
	string getName();
	static int getCount();

protected:
	GameObject(const string& objName);
	const string kName;


private:
	static int count;

};

#endif