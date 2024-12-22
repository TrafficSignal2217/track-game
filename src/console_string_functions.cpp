#include <iostream>
#include "../include/console_string_functions.hpp"

bool is_partial_word(std::string str, std::string word) {
    if (str == word.substr(0, str.length())) {
        return true;
    }
    return false;
}
