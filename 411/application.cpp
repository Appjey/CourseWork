#include "Application.h"
#include "SecondClass.h"

void Application::start()
{
	std::string parent_name, sub_name;
	std::string prev_sub_name; //Имя предыдущего подчинённого объекта
	BaseClass* parent_object;
	SecondClass* sub_object = nullptr;
	int next_objects_number;

	std::cin >> parent_name;
	this->setName(parent_name);
	parent_object = this;
	while (true)
	{
		std::cin >> parent_name;
		std::cin >> sub_name;
		//std::cout << parent_name << "->" << sub_name << "->" << prev_sub_name << '\n';

		if (parent_name == sub_name)
		{
			break;
		}
		if (parent_name == prev_sub_name)
		{
			parent_object = sub_object;
		}
		sub_object = new SecondClass(parent_object, sub_name);
		prev_sub_name = sub_name;
	};
}

void Application::printResults()
{
	std::cout << this->getName() << std::endl;
	printTree();
}