/*
 * test.cpp
 *
 *  Created on: 2014.04.22
 *      Author: Spike
 */

/*eclipse cdt, gcc 4.8.1*/

#include <iostream>

//有理数
class Rational {
public:
	Rational(double numerator = 0, double denominator = 1) :
		m_n(numerator), m_d(denominator) {}
	double numerator() const {return m_n;};
	double denominator() const {return m_d;};
	double value() {return (m_n/m_d);}
private:
	double m_n;
	double m_d;
};

const Rational operator* (const Rational& lhs,
		const Rational& rhs) {
	return Rational(lhs.numerator()*rhs.numerator(),
			lhs.denominator()*rhs.denominator());
}

int main(void) {
	Rational oneFourth(1, 4);
	Rational result;
	result = oneFourth * 3.5;
	result = 3.5 * oneFourth;
	std::cout << "result = " << result.value() << std::endl;

	return 0;
}
