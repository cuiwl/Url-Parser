

#include "CUrlParser.h"
#include "../util/StringUtil.h"

int main(int argc, char** argv)
{
	std::string urlstr;

	urlstr = "http://www.cplusplus.com/reference/string/string/?kw=string";
	//http://www.jd.com/?cu=true&utm_source=baidu-pinzhuan&utm_medium=cpc
	urlparser::CUrlParser urlParser;
	urlParser.parser(urlstr);
	urlParser.dump();

	std::string testStr = "dv=2.1.3&&st=4&sAddr=bbkfgleh,fhhalfl&toAddr=bbknalfb,fhhbnak&tmc=1&flag=2,3,4,5,6,7,10,11&mrn=3&nopid=1";
	std::vector<std::string> vec;
	util::strings::split(vec, testStr, "&", true);
	printf("vec size: %d", vec.size());
	return 0;
}
