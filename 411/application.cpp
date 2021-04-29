#include "application.h"

void Application::start()
{
	BaseClass* base;
	BaseClass* subObj;
	std::string par, child;
	std::cin >> par;
	base = new BaseClass(par, nullptr);
	while (par != "end" && child != "end")
	{
		std::cin >> par >> child;
		subObj = new Application(child, base);
	}
	base->ShowTree(0);
}