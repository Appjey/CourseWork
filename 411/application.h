#ifndef APPLICATION_H
#define APPLICATION_H

#include "BaseClass.h"

class Application : public BaseClass
{
public:
	using BaseClass::BaseClass;
	void start();
	void printResults();
};
#endif