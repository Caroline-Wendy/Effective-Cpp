/*
 * BInsertSort.cpp
 *
 *  Created on: 2014.4.17
 *      Author: Spike
 */

#include <iostream>
#include <vector>

using namespace std;

struct Number {
	Number(int x) {
		std::cout << "Number = " << x << std::endl;
	}
};

template<typename T>
struct Base{
	typedef Number Nested;
};

template<typename T>
class Derived: public Base<T>::Nested { //不用typename
public:
	explicit Derived(int x) : Base<T>::Nested(x) { //不用typename
		typename Base<T>::Nested temp(7); //必须使用
	}
};

int main () {
	Derived<int> d(5);

	return 0;
}
