#include<string>
#include<sstream>
#include<iterator>
#include<vector>
#include "menu_txts.h"


template<char delimiter>
class delimited_by_char: public std::string{};


std::vector <std::string> splitted_by_char(std::string &str){
    std::istringstream iss(str);
    const char delimiter = ','; //puedes cambiar el valor para que separe por otras cosas
    std::vector<std::string> splitted ((std::istream_iterator<delimited_by_char<delimiter>>(iss)), std::istream_iterator<delimited_by_char<delimiter>>());

    return splitted;

} 