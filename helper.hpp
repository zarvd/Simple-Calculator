#ifndef HELPER_H
#define HELPER_H

#include <algorithm>
#include <vector>
#include <map>
#include <string>

namespace helper {

    /**
     * Remove all whitespace from std::string
     */
    inline void removeAllSpace(std::string& str) {
        remove_if(str.begin(), str.end(), isspace);
    }

    /**
     * Check if all character of string are decimal digit
     */
    inline bool isAllDigit(const std::string& str) {
        for(const char& c : str) {
            if( ! isdigit(c)) {
                return false;
            }
        }
        return true;
    }

    inline unsigned max(const unsigned& x, const unsigned& y) {
        return x > y ? x : y;
    }

    inline unsigned min(const unsigned& x, const unsigned& y) {
        return x < y ? x : y;
    }

    inline bool isOperator(const char& sym) {
        if(sym == '+' || sym == '-' || sym == '*' || sym == '/') {
            return true;
        } else {
            return false;
        }
    }

    inline unsigned findChars(const std::string& str, const std::vector<char>& cs, const unsigned& pos = -1) {
        unsigned short idx;
        for(idx = pos + 1; idx < str.length(); ++ idx) {
            for(const char& c : cs) {
                if(str[idx] == c) {
                    return idx;
                }
            }
        }
        return str.length();  // return str's length when c dose not exist in str
    }
}

#endif /* HELPER_H */
