#include "calc_exception.h"
#include <iostream>
#include <fstream>

calc_exception::calc_exception(int line_number, std::string current_line, std::string message):
    std::logic_error(message), cur_line_num(line_number), cur_line(current_line){

    std::ofstream outlog("calculator.log");
    std::clog.rdbuf(outlog.rdbuf());
}
