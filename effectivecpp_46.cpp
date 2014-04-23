/*
 * test.cpp
 *
 *  Created on: 2014.04.22
 *      Author: Spike
 */

/*eclipse cdt, gcc 4.8.1*/

#include <iostream>

template<typename T> class Rational;

template<typename T>
const Rational<T> doMultiply (const Rational<T>& lhs,
	const Rational<T>& rhs);

//有理数
template<typename T>
class Rational {
	/*friend const Rational<T> operator* (const Rational<T>& lhs,
		const Rational<T>& rhs) {
		return Rational<T>(lhs.numerator()*rhs.numerator(),
				lhs.denominator()*rhs.denominator());
	} //方法1*/
	friend const Rational<T> operator* (const Rational<T>& lhs,
		const Rational<T>& rhs) {
		return doMultiply(lhs, rhs);
	} //方法2
public:
	Rational(const T& numerator = 0, const T& denominator = 1) :
		m_n(numerator), m_d(denominator) {}
	const T numerator() const {return m_n;};
	const T denominator() const {return m_d;};
	const T value() {return (m_n/m_d);}
private:
	T m_n;
	T m_d;
};

template<typename T>
const Rational<T> doMultiply (const Rational<T>& lhs,
		const Rational<T>& rhs) {
	return Rational<T>(lhs.numerator()*rhs.numerator(),
			lhs.denominator()*rhs.denominator());
}

int main(void) {
	Rational<double> oneFourth(1, 4);
	Rational<double> result;
	result = oneFourth * 3.5;
	result = 3.5 * oneFourth;
	std::cout << "result = " << result.value() << std::endl;

	return 0;
}
