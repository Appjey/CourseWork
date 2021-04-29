#include "BaseClass.h"

BaseClass::BaseClass(std::string object_name, BaseClass* parent)
{
	if (parent)
	{
		this->parent = parent;
		this->parent->children.push_back(this);
	}
	else
	{
		this->parent = nullptr;
	}
	this->object_name = object_name;
}

BaseClass::~BaseClass()
{
	for (unsigned int i = 0; i < children.size(); i++)
	{
		delete children[i];
	}
}

BaseClass* BaseClass::getParent() 
{
	return this->parent;
}

/*void BaseClass::SetParent(BaseClass* parent)
{
	if(parent)
	{
		if(this->parent)
		{
			for(size_t i = 0; i < this->parent->children.size(); i++)
			{
				if(this->parent->children[i] == this)
				{
					this->parent->children.erase(this->parent->children.begin() + i);
					break;
				}
			}
			this->parent = parent;		
			parent->children.push_back(this);
		}
	}
}*/

void BaseClass::setName(std::string object_name)
{
	this->object_name = object_name;
}

std::string BaseClass::getName()
{
	return this->object_name;
}

void BaseClass::ShowTree(int level)
{
	std::string Space;
	unsigned int StringLength = getName().length();
	if (level > 0)
	{
		Space.append(StringLength * level, ' ');
	}
	std::cout << Space << getName();
	for (unsigned int i = 0; i < children.size(); i++)
	{
		std::cout << std::endl;
		children[i]->ShowTree(level + 1);
	}
}