// Course_04.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <vector>
#include <list>
#include <iostream>
#include "Point.h"

template <typename T>
struct is_container {
	static const bool value = false;
};

template <typename T>
struct is_container<std::vector<T>> {
	static const bool value = true;
};

template <typename T>
struct is_container<std::list<T>> {
	static const bool value = true;
};

template <typename T>
struct is_vector {
	static const bool value = false;
};

template <typename T>
struct is_vector<std::vector<T>> {
	static const bool value = true;
};

template <typename T>
struct is_list {
	static const bool value = false;
};

template <typename T>
struct is_list<std::vector<T>> {
	static const bool value = true;
};

template<typename T>
T multiply_by_two(T container) {
	static_assert(is_container<T>::value || is_container<T>::value, "T must be a vector or a list");

	T newContainer;

	for (auto it = container.begin(); it != container.end(); it++) {
		newContainer.push_back((*it) * 2);
	}

	return newContainer;
}

template<typename S, template<typename, typename> typename T>
S get_maximum_number_anytype(T<S, std::allocator<S>> container) {
	S maximum = container[0];

	for (auto it = container.begin(); it != container.end(); it++) {
		if (maximum < *it) {
			maximum = *it;
		}
	}

	return maximum;
}

template<typename S, typename T>
void convert_container_type(T &container, S &convContainer) {
	static_assert(is_container<T>::value && is_container<S>::value, "T must be a vector or a list");
	for (auto it = container.begin(); it != container.end(); it++) {
		convContainer.push_back(*it);
	}
}

template<typename S, typename T>
T multiply_by_value(T container, S value) {
	T newContainer;

	for (auto it = container.begin(); it != container.end(); it++) {
		newContainer.push_back((*it) * value);
	}

	return newContainer;
}

int main()
{
	std::vector<int> vec;
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(0);
	vec.push_back(-3);

	// Aufgabe 2
	std::cout << "Aufgabe 2" << std::endl;
	for (auto it = vec.begin(); it != vec.end(); it++) {
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	std::vector<int> newVec = multiply_by_two(vec);
	for (auto it = newVec.begin(); it != newVec.end(); it++) {
		std::cout << *it << std::endl;
	}

	// Aufgabe 3 (inkl. 1)
	std::cout << std::endl;
	std::cout << "Aufgabe 3" << std::endl;
	std::cout << get_maximum_number_anytype(vec) << std::endl;

	// Aufgabe 5 (inkl. 4)
	std::cout << std::endl;
	std::cout << "Aufgabe 5" << std::endl;
	std::list<int> list;
	convert_container_type(vec, list);
	for (auto it = list.begin(); it != list.end(); it++) {
		std::cout << *it << std::endl;
	}

	// Aufgabe 6
	std::cout << std::endl;
	std::cout << "Aufgabe 6" << std::endl;
	std::vector<int> newVecMul = multiply_by_value(vec, 3.f);
	for (auto it = newVecMul.begin(); it != newVecMul.end(); it++) {
		std::cout << *it << std::endl;
	}

	// Aufgabe 7
	std::cout << std::endl;
	std::cout << "Aufgabe 7" << std::endl;
	Point<int> a(1, 2);
	Point<int> b(3, 4);	
	Point<int> sum = a.add_point(b);
	std::cout << a.get_x() << ":" << a.get_y() << std::endl;
	std::cout << b.get_x() << ":" << b.get_y() << std::endl;
	std::cout << sum.get_x() << ":" << sum.get_y() << std::endl;


	// End
	std::cout << "Press any key..." << std::endl;
	std::cin.ignore();

    return 0;
}

