/**
* @file     CUrlParser.h
* @author   cuiwl<cwllinux@126.com>
*
*/

/**
	version history:

	2016-08-05        0.1.0       cuiwl        initial implementation
**/

#include <algorithm>
#include "../../util/StringUtil.h"
#include "../CUrlParser.h"


namespace urlparser {

const char* CUrlParser::spLogPrefix = "UrlParser";

// constructor / destructor
CUrlParser::CUrlParser()
: mParsedUrl()
{
}

CUrlParser::~CUrlParser()
{
}

// command
bool CUrlParser::parser(const std::string& url)
{
	bool ret = false;
	std::string tmpStr = url;
	std::size_t curPos = 0;

	/*
	* <scheme>:<scheme-specific-part>
	* <scheme> := [a-z\+\-\.]+
	*             upper case = lower case for resiliency
	*/
	/* Read scheme */
	std::size_t found = tmpStr.find_first_of(":");
	if (found != std::string::npos)
	{
		/* Make the character to lower if it is upper case. */
		mParsedUrl.setScheme(util::strings::toLower(tmpStr.substr(curPos, found)));
		/* Skip ':' */
		curPos = ++found;
	}
	else
	{
		return ret;
	}
	
	/*
	* //<user>:<password>@<host>:<port>/<url-path>
	* Any ":", "@" and "/" must be encoded.
	*/
	/* Eat "//" */
	for (size_t i = curPos; i < curPos + 2; i++)
	{
		if ('/' != tmpStr[i])
		{
			return ret;
		}
	}
	curPos += 2;

	bool bracket_flag = false;
	if ('[' == tmpStr[curPos])
	{
		bracket_flag = true;
	}
	/* Proceed on by delimiters with reading host */
	found = curPos;
	while (found < tmpStr.length())
	{
		if (bracket_flag && ']' == tmpStr[found])
		{
			/* End of IPv6 address. */
			found++;
			break;
		}
		else if (!bracket_flag && (':' == tmpStr[found] || '/' == tmpStr[found]))
		{
			/* Port number is specified. */
			break;
		}
		found++;
	}
	mParsedUrl.setHost(tmpStr.substr(curPos, found - curPos));
	curPos = found;

	/* Is port number specified? */
	if (':' == tmpStr[curPos])
	{
		curPos++;
		/* Read port number */
		found = curPos;
		while (found < tmpStr.length() && '/' != tmpStr[found])
		{
			found++;
		}
		mParsedUrl.setPort(tmpStr.substr(curPos, found - curPos));
		curPos = found;
	}

	/* End of the string */
	if (curPos < tmpStr.length())
	{
		/* Skip '/' */
		if ('/' != tmpStr[curPos])
		{
			return false;
		}
		curPos++;

		/* Read path */
		found = curPos;
		while (found < tmpStr.length() && '#' != tmpStr[found] && '?' != tmpStr[found])
		{
			found++;
		}
		mParsedUrl.setPath(tmpStr.substr(curPos, found - curPos));
		curPos = found;

		/* Is query specified? */
		if ('?' == tmpStr[curPos])
		{
			/* Skip '?' */
			curPos++;

			/* Read query */
			found = curPos;
			while (found < tmpStr.length() && '#' != tmpStr[found])
			{
				found++;
			}
			mParsedUrl.setQuery(tmpStr.substr(curPos, found - curPos));
			curPos = found;
		}

		/* Is fragment specified? */
		if ('#' == tmpStr[curPos])
		{
			/* Skip '#' */
			curPos++;

			/* Read fragment */
			found = curPos;
			while (found < tmpStr.length())
			{
				found++;
			}
			mParsedUrl.setFragment(tmpStr.substr(curPos, found - curPos));
			curPos = found;

			// parse finish, set ret flag is true
			ret = true;
		}
	}

	return ret;
}

void CUrlParser::dump()
{
	printf("dump parse result:\n");
	printf("Scheme: %s\n",		mParsedUrl.getScheme().c_str());
	printf("Host: %s\n",		mParsedUrl.getHost().c_str());
	printf("Port: %s\n",		mParsedUrl.getPort().c_str());
	printf("Path: %s\n",		mParsedUrl.getPath().c_str());
	printf("Query: %s\n",		mParsedUrl.getQuery().c_str());
	printf("Fragment: %s\n",	mParsedUrl.getFragment().c_str());
	printf("Username: %s\n",	mParsedUrl.getUsername().c_str());
	printf("Password: %s\n",	mParsedUrl.getPassword().c_str());
}

// helper
bool CUrlParser::is_scheme_char(int c)
{
	return (!isalpha(c) && '+' != c && '-' != c && '.' != c) ? false : true;
}

} // namespace urlparser
