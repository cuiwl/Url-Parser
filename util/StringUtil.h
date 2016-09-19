/**
* @file     StringUtil.h
* @author   cuiwl<cwllinux@126.com>
*
*/

#ifndef util_strings_StringUtil_h
#define util_strings_StringUtil_h

#include <string>
#include <vector>

namespace util {
namespace strings {

/// returns the lowercase-transformed
std::string toLower(std::string s);

/// returns the lowercase-transformed
std::string toUpper(std::string s);

/**
* Split a given sequence of characters at separator tokens.
*
* @param out The sequence of string tokens.
* @param in The string to tokenized.
* @param separator tokens.
* @param compress Remove empty tokens from sequence if true. Keep empty tokens if false (default).
*
* @code
*   std::vector<std::string> vec;
*   StringUtil::split(vec, "Hallo;Welt;Toll;Super", ";");
*   // will yield a vec containing [ "Hallo", "Welt", "Toll", "Super" ]
* @endcode
*/
void split(std::vector<std::string>& out, const std::string& in, const std::string& separator, bool compress = false);

} // namespace strings
} // namespace util

#endif // util_strings_StringUtil_h
