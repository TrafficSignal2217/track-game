#include <iostream>

#ifndef CONSOLE_STRING_FUNCTIONS_HPP // Include guard
#define CONSOLE_STRING_FUNCTIONS_HPP

bool is_partial_word(std::string str, std::string word);

// write_text_on_screen: writes text onto the screen
// *screen: pass in a pointer for the 2D array
// screen_width: the width of the screen
// pos: the x and y position of where to start writing the text on the screen
// text: the text to write to the screen
void write_text_on_screen(char *screen, int screen_width, int pos_x, int pos_y, std::string text);


#endif
