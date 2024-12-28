#include <iostream>
#include "../include/console_string_functions.hpp"

bool is_partial_word(std::string str, std::string word) {
    if (str == word.substr(0, str.length())) {
        return true;
    }
    return false;
}



void write_text_on_screen(char *screen, int screen_width, int pos_x, int pos_y, std::string text) {
    for (int i = 0; i < text.length(); i++) {
        screen[pos_x + pos_y * screen_width + i] = text[i];
    }
}
