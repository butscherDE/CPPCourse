// CPPCourse_01_2.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>

void readStream(std::vector<int>& numbers) {
}

int digitAtPos(long long number, int pos)
{
	return (number / (long long)pow(10.0, pos - 1)) % 10;
}

bool isTidyNumber(long long number) {
	long long digits = 0;
	long long digitizeNumber = number;
	while (digitizeNumber) {
		digitizeNumber /= 10;
		digits++;
	}

	for (long long i = digits; i > 1; i--) {
		long long before = digitAtPos(number, i);
		long long further = digitAtPos(number, i - 1);
		if (further < before) {
			return false;
		}
	}

	return true;
}

int tidyNumber(long long lastNumber) {
	for (long long i = lastNumber; i >= 0; i--) {
		if (isTidyNumber(i)) {
			return i;
		}
	}
}

int main()
{
	std::ifstream file;
	file.open("input_large.txt");
	long long testCase = 0;

	long long numCases;
	if (file.is_open()) {
		file >> numCases;

		while (!file.eof()) {
			long long lastNumber;
			file >> lastNumber;
			int lastTidyNumber = tidyNumber(lastNumber);

			std::cout << "Case #" << testCase++ << ": " << lastTidyNumber << std::endl;
		}
	}

	std::cout << numCases << std::endl;

	std::cout << std::endl << "Press enter to continue...";
	std::cin.ignore();

    return 0;
}