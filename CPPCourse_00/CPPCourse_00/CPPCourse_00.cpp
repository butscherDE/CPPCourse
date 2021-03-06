// CPPCourse_00.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

void foo(int lala) {
	lala++;
}

int main()
{
	//Write to standard output stream
	std::cout << "Hello, World!" << std::endl;

	//Pointergedöns
	int i = 10;
	int* iP = &i;
	int& iPi = *iP;
	std::cout << i << std::endl;
	std::cout << &i << std::endl;
	std::cout << iP << std::endl;
	std::cout << *iP << std::endl;
	std::cout << iPi << std::endl;
	std::cout << &iPi << std::endl;

	std::string aString = "abc";
	std::cout << aString[0] << std::endl;
	std::cout << aString[1] << std::endl;
	std::cout << aString[2] << std::endl;
	std::cout << (int) aString[3] << std::endl;

	foo(i);
	std::cout << i << std::endl;

	//Keep console open
	std::cout << "Press enter to continue...";
	std::cin.ignore();
	return 0;
}