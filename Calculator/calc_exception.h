#ifndef CALC_EXCEPTION_H
#define CALC_EXCEPTION_H

#include <stdexcept>
#include <string>

class calc_exception : public std::logic_error
{
    public:
    calc_exception(int line_number, std::string current_line, std::string message);
    protected:
    private:
        int cur_line_num;
        std::string cur_line;
        //std::string txt;
};

#endif // CALC_EXCEPTION_H
