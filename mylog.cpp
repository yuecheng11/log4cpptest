#include "mylog.h"
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Priority.hh>

using namespace std;

Mylog* Mylog::_pInstance = NULL;

Mylog* Mylog::getInstance()
{
	if(_pInstance == NULL)
	{
		_pInstance = new Mylog();
	}

	return _pInstance;
}

Mylog::Mylog()
	:_cat(log4cpp::Category::getRoot().getInstance("Mycat"))
{
	log4cpp::PatternLayout* ptnLayout1 = new log4cpp::PatternLayout();
	ptnLayout1->setConversionPattern("%d: %p %c %x: %m%n");

	log4cpp::PatternLayout* ptnLayout2 = new log4cpp::PatternLayout();
	ptnLayout1->setConversionPattern("%d: %p %c %x: %m%n");

	log4cpp::OstreamAppender* appender1 = new log4cpp::OstreamAppender("ostream",&cout);
	appender1->setLayout(ptnLayout1);
		
	log4cpp::FileAppender* appender2 = new log4cpp::FileAppender("FileAppender","testyc.log");
	appender2->setLayout(ptnLayout2);

	_cat.addAppender(appender1);
	_cat.addAppender(appender2);
	_cat.setPriority(log4cpp::Priority::DEBUG);
	
}

void Mylog::fatal(const char * msg)
{
	_cat.fatal(msg);
}

void Mylog::error(const char * msg)
{
	_cat.error(msg);
}

void Mylog::info(const char * msg)
{
	_cat.info(msg);
}

void Mylog::debug(const char * msg)
{
	_cat.debug(msg);
}
