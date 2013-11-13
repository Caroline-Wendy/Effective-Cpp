/*
 * effectivecpp.cpp
 *
 *  Created on: 2013.11.13
 *      Author: Caroline
 */

/*eclipse cdt ; gcc 4.7.1*/

#include <iostream>
#include <string>
#include <array>

#include <algorithm>

using namespace std;

#define ASPECT_RATIO 1.653 //长宽比

#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))

class GamePlayer {
public:
	static const int NumTurns = 5;
	static const double PI ; //不能内类初始化非整型
	enum {eNumTurns = 5}; //枚举类型
	std::array<int, NumTurns> scores;
	std::array<int, eNumTurns> escores;
};
const double GamePlayer::PI = 3.14;

template<typename T>
void f (T a) {
	std::cout << "f : " << a ;
}

template<typename T>
inline void callWithMax(const T& a, const T& b)
{
	f(a>b ? a : b);
}

int main (void) {

	//预处理器定义
	std::cout << "ASPECT_RATIO = " << ASPECT_RATIO << std::endl;

	//常量定义
	const double AspectRatio = 1.653;
	std::cout << "AspectRatio = " << AspectRatio << std::endl;

	//常量指针
	const char* const authorName = "Caroline";
	std::cout << "authorName = " << authorName << std::endl;

	//常量指针
	const std::string sAuthorName("Caroline");
	std::cout << "sAuthorName = " << sAuthorName << std::endl;

	//class专属常量
	GamePlayer gp;
	std::array<int, GamePlayer::NumTurns> scores = { {1, 2, 3, 4, 5} };
	gp.scores = scores;
	std::cout << "gp.scores : ";
	for(const auto s : gp.scores)
		std::cout << s << " ";
	std::cout << std::endl;
	std::cout << "GamePlayer::PI = " << GamePlayer::PI << std::endl;

	//测试宏
	int a = 5, b = 0;
	CALL_WITH_MAX(++a, b); //a, ++两次
	std::cout << " ; a = " << a <<std::endl;
	a = 5, b = 0;
	CALL_WITH_MAX(++a, b+10); //a, ++一次
	std::cout << " ; a = " <<  a <<std::endl;

	//template inline
	a = 5, b = 0;
	callWithMax(++a, b);
	std::cout << " ; a = " << a <<std::endl;

	return 0;

}
