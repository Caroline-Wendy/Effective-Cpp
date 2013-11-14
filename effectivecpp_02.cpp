/*
 * effectivecpp.cpp
 *
 *  Created on: 2013.11.13
 *      Author: Caroline
 */

/*eclipse cdt ; gcc 4.7.1*/

#include <iostream>
#include <vector>

int main (void) {

	std::vector<int> iv = {1, 2, 3, 4, 5};
	const auto it = iv.begin(); //const 迭代器 相当于 T* const, 指针自身(地址)是固定的;
	std::cout << "*it = " << *it << std::endl;
	//++it; //错误
	*it = 10;
	std::cout << "*it = " << *it << std::endl;

	 iv = {1, 2, 3, 4, 5};
	 auto cit = iv.cbegin(); //cbegin, 相当于const_iterator, 指针所指物是固定的;
	 //std::vector<int>::const_iterator cit = iv.begin();
	 std::cout << "*cit = " << *cit << std::endl;
	 ++cit;
	 //*cit = 10; //错误
	 std::cout << "*cit = " << *cit << std::endl;

	return 0;

}
