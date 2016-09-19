/**
* @file     TParserResult.h
* @author   cuiwl<cwllinux@126.com>
*
*/

#ifndef urlparser_TParserResult_h
#define urlparser_TParserResult_h

#include <string>

namespace urlparser {

// type define
class TParsedUrl
{
	public:
		/// Default constructor
		TParsedUrl()
			: mScheme()
			, mHost()
			, mPort()
			, mPath()
			, mQuery()
			, mFragment()
			, mUsername()
			, mPassword() { }

		/// Copy constructor
		TParsedUrl(const TParsedUrl& src)
			: mScheme(src.mScheme)
			, mHost(src.mHost)
			, mPort(src.mPort)
			, mPath(src.mPath)
			, mQuery(src.mQuery)
			, mFragment(src.mFragment)
			, mUsername(src.mUsername)
			, mPassword(src.mPassword) { }

	// accessor
	public:
		void setScheme(std::string scheme)			{ mScheme = scheme;  }
		void setHost(std::string host)				{ mHost = host; }
		void setPort(std::string port)				{ mPort = port; }
		void setPath(std::string path)				{ mPath = path; }
		void setQuery(std::string query)			{ mQuery = query; }
		void setFragment(std::string fragment)		{ mFragment = fragment; }
		void setUsername(std::string username)		{ mUsername = username; }
		void setPassword(std::string password)		{ mPassword = password; }
		
		const std::string& getScheme() const		{ return mScheme; }
		const std::string& getHost() const			{ return mHost; }
		const std::string& getPort() const			{ return mPort; }
		const std::string& getPath() const			{ return mPath; }
		const std::string& getQuery() const			{ return mQuery; }
		const std::string& getFragment() const		{ return mFragment; }
		const std::string& getUsername() const		{ return mUsername; }
		const std::string& getPassword() const		{ return mPassword; }

	// attributes
	private:
		std::string mScheme;               // mandatory		
		std::string mHost;                 // mandatory		
		std::string mPort;                 // optional		
		std::string mPath;                 // optional		
		std::string mQuery;                // optional
		std::string mFragment;             // optional
		std::string mUsername;             // optional
		std::string mPassword;             // optional
}; // TParsedUrl


} // namespace urlparser

#endif // urlparser_TParserResult_h