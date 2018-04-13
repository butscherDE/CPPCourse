// Course_04.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <vector>
#include <list>
#include <iostream>

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

int main()
{
	std::vector<int> vec;
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(0);

	// Aufgabe 2
	for (auto it = vec.begin(); it != vec.end(); it++) {
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	std::vector<int> newVec = multiply_by_two(vec);
	for (auto it = newVec.begin(); it != newVec.end(); it++) {
		std::cout << *it << std::endl;
	}

	// Aufgabe 3
	std::cout << std::endl;
	std::cout << get_maximum_number_anytype(vec) << std::endl;

	// Aufgabe 4
	std::cout << std::endl;
	std::list<int> list;
	convert_container_type(vec, list);
	for (auto it = list.begin(); it != list.end(); it++) {
		std::cout << *it << std::endl;
	}

	std::cout << "Press any key..." << std::endl;
	std::cin.ignore();

    return 0;
}

