#ifndef BASECLASS_H
#define BASECLASS_H
#include <iostream>
#include <string>
#include <vector>

class BaseClass
{
private:
	std::vector <BaseClass*> children; // ������ ���������� ��������
	std::string object_name; // ��� �������
	BaseClass* parent; // ��������� �� ������������ ������

public:

	BaseClass(std::string object_name, BaseClass* parent);

	~BaseClass();

	BaseClass* getParent();

	void setName(std::string object_name);

	std::string getName();

	void ShowTree(int level);
};

#endif