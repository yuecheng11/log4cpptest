#define _MYLOG4CPP_

#include "mylog.h"

using namespace std;

int main(void)
{

	cout<<"this is test log4cpp"<<endl;
#if 0
	plog->fatal("fatal log, ");
	plog->error("error log ");
	plog->info("info log ");
	plog->debug("debug log");
#endif

	LOG_FATAL("this test log1");
	LOG_ERROR("this test log2");
	LOG_INFO("this is test log3");
	LOG_DEBUG("THIS IS test log4");
	
	return 0;
}