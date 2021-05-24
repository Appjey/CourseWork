#include "BaseClass.h"

BaseClass::BaseClass(BaseClass* parent, std::string object_name)
{
	this->parent = parent;
	if (this->parent != nullptr)
	{
		parent->children.push_back(this);
	}
	this->object_name = object_name;
}

BaseClass::~BaseClass()
{
	for (int i = 0; i < children.size(); i++)
	{
		delete children[i];
	}
}

void BaseClass::setName(std::string name)
{
	this->object_name = name;
}

std::string BaseClass::getName()
{
	return this->object_name;
}

void BaseClass::printTree()
{
	std::cout << this->getName();
	if (this->children.size() > 0)
	{
		for (int i = 0; i < this->children.size(); i++)
		{
			std::cout << "  " << children[i]->getName();
		}
		if (this->children[this->children.size() - 1]->children.size() > 0)
		{
			std::cout << '\n';
			this->children[this->children.size() - 1]->printTree();
		}
	}
}

BaseClass* BaseClass::getParent()
{
	return this->parent;
}

void BaseClass::setParent(BaseClass* parent_p)
{
	if (this->parent)
	{
		for (int i = 0; i < this->parent->children.size(); i++)
		{
			if (parent_p->children[i] == this)
			{
				parent->children.erase(parent->children.begin() + i);
				break;
			}
		}
	}
	parent = parent_p;
	if (parent_p)
	{
		parent->children.push_back(this);
	}
}