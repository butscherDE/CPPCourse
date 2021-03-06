// CPPCourse_05.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <vector>
#include "Point.h"
#include <math.h>
#include <algorithm>
#include <iostream>

template<typename T>
struct reference_point {
	Point<T> ref;
};

template<typename T>
struct sortStruct {
	bool operator() 
};

template<typename T>
T euclidianDistance(Point<T> a) {
	return sqrt(pow(reference_point::ref.get_x() - a.get_x(), 2) + pow(reference_point::ref.get_y() - a.get_y(), 2));
}

template<typename T>
bool sortFunction(Point<T> a, Point<T> b) {
	return euclidianDistance(a) < euclidianDistance(b);
}

template<typename T>
std::vector<Point<T>> sort_by_distance(std::vector<Point<T>> vec, Point<T> ref) {
	std::sort(vec.begin(), vec.end(), sortFunction);

	return vec;
}

int main()
{
	std::vector<Point<int>> vec;
	vec.push_back(Point<int>(-1, 1));
	vec.push_back(Point<int>(1, 1));
	vec.push_back(Point<int>(1, -1));
	vec.push_back(Point<int>(-1, -1));

	Point<int> ref(-2, -2);

	vec = sort_by_distance(vec, ref);

	std::cout << "Press any key to quit..." << std::endl;
	std::cin.ignore();
	

    return 0;
}

