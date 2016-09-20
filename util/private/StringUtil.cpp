/**
* @file     StringUtil.h
* @author   cuiwl<cwllinux@126.com>
*
*/

/**
	version history:

	2016-09-20        0.1.2       cuiwl        fixed issue that split string lost last one element

	2016-09-19        0.1.1       cuiwl        add string split functionality

	2016-08-18        0.1.0       cuiwl        initial implementation
**/

#include <algorithm>
#include <ctype.h>
#include "../StringUtil.h"


namespace util {
namespace strings  {

std::string toLower(std::string s)
{
   std::string result = s;
   std::transform(result.begin(), result.end(), result.begin(), ::tolower);
   return result;
}

std::string toUpper(std::string s)
{
   std::string result = s;
   std::transform(result.begin(), result.end(), result.begin(), ::toupper);
   return result;
}

void split(std::vector<std::string>& out, const std::string& in, const std::string& separator, bool compress)
{
	std::size_t curPos = 0;
	std::size_t found = in.find(separator, curPos);

	while (found < in.length() && found != std::string::npos)
	{
		if (compress)
		{
			if (curPos != found)
			{
				out.push_back(in.substr(curPos, found - curPos));
			}
		}
		else
		{
			out.push_back(in.substr(curPos, found - curPos));
		}
		
		/* Skip 'separator' */
		found++;
		
		curPos = found;
		found = in.find(separator, curPos);
		if (found == std::string::npos)
		{
			out.push_back(in.substr(curPos, in.length() - curPos));
			break;
		}
		
	}
}


} // namespace strings
} // namespace util
