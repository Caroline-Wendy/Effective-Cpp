/*
 * test.cpp
 *
 *  Created on: 2014.04.18
 *      Author: Spike
 */

/*eclipse cdt, gcc 4.8.1*/

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class CompanyCaroline {
public:
	void sendCleartext(const std::string& msg) {
		std::cout << "Cleartext: " << msg << std::endl;
	}
	void sendEncrypted(const std::string& msg) {
		std::cout << "Encrypted: " << msg << std::endl;
	}
};

struct MsgInfo {
	std::string cleartext;
	std::string encrypted;
};

template<typename Company>
class MsgSender {
public:
	void sendClear(const MsgInfo& info) {
		std::string msg = info.cleartext;
		Company c;
		c.sendCleartext(msg);
	}
	void sendSecret(const MsgInfo& info) {
		std::string msg = info.encrypted;
		Company c;
		c.sendEncrypted(msg);
	}
};

template<typename Company>
class LoggingMsgSender : public MsgSender<Company> {
public:
	//using MsgSender<Company>::sendClear; //方法二
	void sendClearMsg(const MsgInfo& info) {
		std::cout << "Log Begin : ";
		//sendClear(info);
		this->sendClear(info); //方法一
		//MsgSender<Company>::sendClear(info); //方法三, 会关闭虚绑定的行为, 不建议
	}
};


int main() {
	MsgInfo mi = {"Clear", "Encrypted"};
	LoggingMsgSender<CompanyCaroline> lms;
	lms.sendClearMsg(mi);

	return 0;
}










