#include "token.h"


Token::Token(Type kind, std::string val):
    _type(kind),
    _value(val){}

void Token::value(std::string val){
    _value=val;
}

void Token::type(Type kind){
    _type=kind;
}

std::ostream& operator<<(std::ostream& os, const Token token){
    return os<<token._value;
}
