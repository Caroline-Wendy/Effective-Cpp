/*
 * test.cpp
 *
 *  Created on: 2014.04.20
 *      Author: Spike
 */

/*eclipse cdt, gcc 4.8.1*/

#include <iostream>

using namespace std;

class Base{};

class Derived : public Base {};

template<typename T>
class SmartPtr {
public:
	SmartPtr() = default;
	template<typename U>
	SmartPtr(const SmartPtr<U>& other)
		: heldPtr(other.get()) {
		std::cout << "SmartPtr:CopyConstructor" << std::endl;
	}
	T* get() const {return heldPtr;}
private:
	T* heldPtr;
};

int main() {

	SmartPtr<Derived> spd;
	SmartPtr<Base> spb(spd);

	//SmartPtr<Base> spb1;
	//SmartPtr<Derived> spd1(spb1); //无法进行隐身转换
	return 0;
}

