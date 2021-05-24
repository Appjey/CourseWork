#ifndef BASECLASS_H
#define BASECLASS_H
#include <iostream>
#include <string>
#include <vector>

class BaseClass
{
protected:
	std::vector <BaseClass*> children;
	std::string object_name;
	BaseClass* parent;

public:

	BaseClass(BaseClass* parent, std::string object_name);

	~BaseClass();

	void setName(std::string object_name);

	std::string getName();

	void printTree();

	BaseClass* getParent();

	void setParent(BaseClass* parent_p);

};

#endif