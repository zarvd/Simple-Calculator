#ifndef PARSER_H
#define PARSER_H

#include <algorithm>
#include <string>

namespace helper {

    /**
     * Remove all whitespace from std::string
     */
    void removeAllSpace(std::string& str) {
        remove_if(str.begin(), str.end(), isspace);
    }

    /**
     * Check if all character of string are decimal digit
     */
    bool isAllDigit(std::string& str) {
        for(char c : str) {
            if( ! isdigit(c)) {
                return false;
            }
        }
        return true;
    }
}

#endif /* PARSER_H */
