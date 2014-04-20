/*
 * test.cpp
 *
 *  Created on: 2014.04.20
 *      Author: Spike
 */

/*eclipse cdt, gcc 4.8.1*/

#include <iostream>

#include <boost/scoped_array.hpp>

using namespace std;

template <typename T>
class SquareMatrixBase {
protected:
	SquareMatrixBase(std::size_t n, T* pMem)
	: size(n), pData(pMem) {}
	void setDataPtr(T* ptr) { pData = ptr; }
	void invertBase() {
		std::cout << " pData[0] = " << pData[0];
		std::cout << std::endl;
	}
private:
	std::size_t size;
	T* pData;
};

template <typename T, std::size_t n>
class SquareMatrix : private SquareMatrixBase<T> {
public:
	SquareMatrix() : SquareMatrixBase<T>(n, 0),
	pData(new T[n*n]) { this->setDataPtr(pData.get()); }
	void setData() { for (int i=0; i<n*n; ++i) pData[i] = 9; }
	void invert() { this->invertBase(); }
private:
	boost::scoped_array<T> pData;
};

int main() {
	SquareMatrix<int, 3> sm;
	sm.setData();
	sm.invert();

	SquareMatrix<int, 5> sm2;
	sm2.setData();
	sm2.invert();

	return 0;
}

