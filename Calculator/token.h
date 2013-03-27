#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <iostream>
#include <ostream>
 enum class Type{
            ADDOP, MULTOP, NUMBER, EOL, FRACTION
        };

class Token
{
    public:
        Token(Type kind, std::string val);
        Type GetType() const {return _type;}
        std::string GetValue(){return _value;}
        void type(Type);
        void value(std::string);
        friend std::ostream& operator<<(std::ostream& os, const Token token);
    protected:
    private:
        Type _type;
        std::string _value;
};

#endif // TOKEN_H
