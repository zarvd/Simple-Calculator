#ifndef PARSER_H
#define PARSER_H

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
    inline bool isAllDigit(std::string& str) {
        for(char c : str) {
            if( ! isdigit(c)) {
                return false;
            }
        }
        return true;
    }

    inline unsigned max(unsigned x, unsigned y) {
        return x > y ? x : y;
    }

    inline unsigned min(unsigned x, unsigned y) {
        return x < y ? x : y;
    }
}

#endif /* PARSER_H */
