/*
 * BInsertSort.cpp
 *
 *  Created on: 2014.4.17
 *      Author: Spike
 */

#include <array>
#include <iostream>

using namespace std;

template<typename T>
void workWithIter(T iter) {
	typedef typename std::iterator_traits<T>::value_type value_type; //使用typename
	value_type temp(*iter);
	std::cout << "temp = " << temp << std::endl;

}

int main () {
	std::array<int, 5> ai = {1,2,3,4,5};
	std::array<int, 5>::iterator aiIter = ai.begin();
	workWithIter(aiIter);
	return 0;
}
