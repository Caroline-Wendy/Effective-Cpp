#include <iostream>

class Widget {
public:
	Widget () = default;
	Widget (const Widget& rhs) {
		std::cout << "Hello girl, this is a copy constructor! " << std::endl;
	}
	Widget& operator= (const Widget& rhs) {
		std::cout << "Hello girl, this is a copy-assignment operator! " << std::endl;
		return *this;
	}
};

int main (void) {
	Widget w1;
	Widget w2(w1); //使用copy构造器
	w1 = w2; //使用copy-assignment操作符
	Widget w3 = w2; //使用copy构造器
}
