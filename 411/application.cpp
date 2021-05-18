#include "Application.h"

void Application::start()
{
	std::string root, obj_name;
	std::cin >> root;
	object_name = root;
	BaseClass* base;
	while (true)
	{ 
		std::cin >> root;
		std::cin >> obj_name;
		base = new BaseClass(getObjectPtr(root), obj_name);
		if (root == obj_name)
		{
			break;
		}
	}
}

void Application::printResults()
{
	printTree(this, 0);
	std::cout << std::endl;
	std::cout << this->getName() << std::endl;
	showOutput(this);
}