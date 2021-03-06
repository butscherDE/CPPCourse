// CPPCourse_01.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

void readStream(std::vector<int>& randNums) {
	std::ifstream file("rand_50.txt");
	int i = 0;

	if (file.is_open()) {
		while (!file.eof()) {
			file >> randNums[i++];
		}
	}
}

void printLine(int start, int end, std::vector<int>& values, bool ascending) {
	if (ascending) {
		for (int i = start; i <= end; i++) {
			std::cout << values[i] << " ";
			if (values[i] < 10) {
				std::cout << " ";
			}
		}
	}
	else {
		for (int i = end; i >= start; i--) {
			std::cout << values[i] << " ";
			if (values[i] < 10) {
				std::cout << " ";
			}
		}
	}
}

void printLinesSnake(int lineLength, int totalValues, std::vector<int>& values) {
	int start = totalValues - 7;
	int end = totalValues - 1;
	bool ascending = totalValues % 2 != 0;

	while (start > 0) {
		printLine(start, end, values, ascending);
		std::cout << std::endl;

		start = start - lineLength;
		end = end - lineLength;
		ascending = !ascending;
	}
}

void printLinesStrangeSnake(int lineLength, int totalValues, std::vector<int>& values) {
	int numPreValues = 2 * lineLength - 1; //Length of the bottom-right sourrounding bla bla
	int preValuesCounter = numPreValues - 1;

	int start = numPreValues;
	int end = start + 5;
	bool ascending = false; // totalValues % 2 != 0;

	while (end <= totalValues) {
		printLine(start, end, values, ascending);
		std::cout << values[preValuesCounter--];
		std::cout << std::endl;

		start = start + lineLength - 1;
		end = end + lineLength - 1;
		ascending = !ascending;
	}

	printLine(0, lineLength - 1, values, true);
	std::cout << std::endl;
}

int main()
{
	// length of file
	int length = 50;

	//read values in
	std::vector<int> randNums(length);
	readStream(randNums);

	std::sort(randNums.begin(), randNums.end());

	// length of rows / columns
	int squareRoot = sqrt(length);
	int quad = squareRoot * squareRoot;

	printLinesSnake(squareRoot, quad, randNums);

	std::cout << std::endl;

	printLinesStrangeSnake(squareRoot, quad, randNums);

	std::cout << std::endl << "Press enter to continue...";
	std::cin.ignore();
    return 0;
}

