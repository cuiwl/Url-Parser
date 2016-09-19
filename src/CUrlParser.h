/**
* @file     CUrlParser.h
* @author   cuiwl<cwllinux@126.com>
*
*/


#ifndef urlparser_CUrlParser_h
#define urlparser_CUrlParser_h

#include "../api/TParserResult.h"

namespace urlparser {

class CUrlParser
{
	// constructor / destructor
	public:
		CUrlParser();

		virtual ~CUrlParser();

	// command 
	public:
		bool parser(const std::string& url);

	// getter
	public:
		TParsedUrl& getParsedResult() { return mParsedUrl; }

	// debugger
	public:
		void dump();

	// helper
	private:
		// Check whether the character is permitted in scheme string
		bool is_scheme_char(int c);

		const char* logPrefix() const { return spLogPrefix; }

	private:
		TParsedUrl	mParsedUrl;

		static const char*   spLogPrefix;

}; // CUrlParser

} // namespace urlparser

#endif // urlparser_CUrlParser_h