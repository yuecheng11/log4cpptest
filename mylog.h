#ifndef _MYLOG_H_
#define _MYLOG_H_

#include <iostream>
#include <string>
#include <log4cpp/Category.hh>
#include <sstream>

using namespace std;

inline string int2str(int num)
{
	ostringstream oss;
	oss<<num;
	return oss.str();
}

class Mylog
{
public:
	void fatal(const char* msg);
	void error(const char* msg);
	void info(const char* msg);
	void debug(const char* msg);
	static Mylog* getInstance();
private:
	Mylog();

private:
	log4cpp::Category &_cat;
	static Mylog* _pInstance;
};

#ifdef _MYLOG4CPP_
Mylog* plog = Mylog::getInstance();
#else
extern Mylog* plog;
#endif


#define postfix(msg) string(msg).append("{").append(__FILE__)\
						.append("-").append(__func__)\
						.append("-").append(int2str(__LINE__))\
						.append("}").c_str()
						
#define LOG_FATAL(msg) plog->fatal(postfix(msg))
#define LOG_ERROR(msg) plog->error(postfix(msg))
#define LOG_INFO(msg) plog->info(postfix(msg))
#define LOG_DEBUG(msg) plog->debug(postfix(msg))


#endif



