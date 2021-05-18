#include "BaseClass.h"

BaseClass::BaseClass(BaseClass* parent, std::string object_name)
{
	this->parent = parent;
	if (parent != nullptr)
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

void BaseClass::printTree(BaseClass* parent, int space)
{
	for (int i = 0; i < space; i++)
	{
		std::cout << " ";
	}
	std::cout << parent->getName();
	for (int i = 0; i < parent->children.size(); i++)
	{
		std::cout << std::endl;
		children[i]->printTree(this->children[i], space + 4);
	}
}

BaseClass* BaseClass::getPtr(std::string name)
{
	BaseClass* temp = nullptr;
	if (name == this->getName())
	{
		temp = this;
	}
	else if (children.size() > 0)
	{
		for (int i = 0; i < children.size(); i++)
		{
			temp = children[i]->getPtr(name);
			if (temp != nullptr)
			{
				break;
			}
		}
	}
	return temp;
}

void BaseClass::showOutput(BaseClass* parent)
{
	std::cout << std::endl;
	std::cout << parent->getName() << "  ";
	for (int i = 0; i < parent->children.size(); i++)
	{
		std::cout << parent->children[i]->getName() << "  ";
		//parent->children[i]->showOutput(parent->children[i]);
	}
}