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

BaseClass* BaseClass::getObjectPtr(std::string name)
{
	BaseClass* temp = nullptr;
	if (name == this->getName())
	{
		temp = this;
	}
	else if (!children.empty())
	{
		for (int i = 0; i < children.size(); i++)
		{
			temp = children[i]->getObjectPtr(name);
			if (temp != nullptr)
				break;
		}
	}
	return temp;
}

BaseClass* BaseClass::getParentPtr(std::string name)
{
	return (!getObjectPtr(name)->children.empty()) ? getObjectPtr(name) : nullptr;
}

void BaseClass::showOutput(BaseClass* root)
{
	if (getParentPtr(this->getName()))
	{
		if (this != root)
		{
			std::cout << '\n';
		}
		std::cout << this->getName();
		for (int i = 0; i < this->children.size(); i++)
		{
			std::cout << "  " << this->children[i]->getName();
		}
	}
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->showOutput(root);
	}
}