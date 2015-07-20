#ifndef HELPER_H
#define HELPER_H

#include <algorithm>
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
        for(char c : str) {
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
}

#endif /* HELPER_H */
