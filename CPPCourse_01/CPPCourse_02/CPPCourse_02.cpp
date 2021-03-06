// CPPCourse_02.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//
#include "stdafx.h"
#include "Tool.h"
#include "Rock.h"
#include "Paper.h"
#include "Scissor.h"
#include <iostream>


int main()
{
	Scissor s = Scissor(10, 's');
	Rock r = Rock(10, 'r');
	Paper p = Paper(10, 'p');

	std::cout << s.fight(p) << " " << p.fight(s) << std::endl; // 1 0
	std::cout << p.fight(r) << " " << r.fight(p) << std::endl; // 1 0
	std::cout << r.fight(s) << " " << s.fight(r) << std::endl; // 1 0

	std::cout << "Press enter to continue...";
	std::cin.ignore();
}

