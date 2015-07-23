#include "helper.hpp"

#include <map>
#include <string>

/**
 * Check if expression is valid
 */
bool helper::isValidExpr(const std::string& expr) {
    unsigned short idx;
    unsigned short parentheseCount = 0;
    enum Symbol {
        digit,
        plus,
        minus,
        multiple,
        divide,
        open,
        close
    };

    std::map<Symbol, bool> nextSym = {
        {digit, true},
        {plus, false},
        {minus, true},
        {multiple, false},
        {divide, false},
        {open, true},
        {close, false}
    };
    std::map<char, Symbol> op = {
        {'+', plus},
        {'-', minus},
        {'*', multiple},
        {'/', divide}
    };
    for(idx = 0; idx < expr.size(); ++ idx) {
        const char& sym = expr[idx];
        if(sym == '(') {
            if( ! nextSym[open]) return false;
            ++ parentheseCount;
            nextSym[digit] = nextSym[minus] = nextSym[open] = nextSym[close] = true;
            nextSym[plus] = nextSym[multiple] = nextSym[divide] = false;
        } else if(sym == ')') {
            if(parentheseCount == 0 || ! nextSym[close]) {
                return false;
            } else {
                -- parentheseCount;
            }
            nextSym[digit] = nextSym[open] = false;
            nextSym[plus] = nextSym[minus] = nextSym[multiple] = nextSym[divide] = nextSym[close] = true;
        } else if(isdigit(sym)) {
            if( ! nextSym[digit]) return false;
            nextSym[digit] = nextSym[plus] = nextSym[minus] = nextSym[multiple] = nextSym[divide] = nextSym[close] = true;
            nextSym[open] = false;
        } else if(isOperator(sym)) {
            if( ! nextSym[op[sym]]) return false;
            nextSym[digit] = nextSym[open] = true;
            nextSym[plus] = nextSym[minus] = nextSym[multiple] = nextSym[divide] = nextSym[close] = false;
        } else {
            return false;
        }
    }
    if(parentheseCount > 0) return false;
    return true;
}
