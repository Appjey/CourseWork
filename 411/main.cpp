#include "Application.h"

int main(int argc, char* argv[])
{

	Application app(nullptr, "Obj");
	app.start();
	app.printResults();
	return 0;
}	