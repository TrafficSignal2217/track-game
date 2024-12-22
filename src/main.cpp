#include <iostream>
#include <map>
#include "../include/console_string_functions.hpp"
#include "../include/helper_functions.hpp"
#include "../include/globals.cpp"
using namespace std;





///////////////////////////////////////////////////////////// Update ////////////////////////////////////////////////////////////////////////////
void update() {
    //------------------------------ Render the Game ------------------------------//
    // Render the gui surface
    Gui_Screen[gui_tile_under_cursor_position()][0] = Tile_Map[Level_Tiles[cursor.pos[1]][cursor.pos[0]]];
    for (int i = 0; i < GUI_HEIGHT; i++) {
        if (i == gui_tile_under_cursor_position()) {
            Gui_Screen[i][0] = Tile_Map[Level_Tiles[cursor.pos[1]][cursor.pos[0]]];
        }
    }

    // Render the level surface
    for (int i = 0; i < LEVEL_HEIGHT; ++i) {
        for (int j = 0; j < LEVEL_WIDTH; ++j) {
            Level_Screen[i][j] = Tile_Map[Level_Tiles[i][j]];
        }
    }


    // Render the whole game screen by combining the level and gui surfaces
    for (int i = 0; i < SCREEN_HEIGHT; ++i) {
        for (int j = 0; j < SCREEN_WIDTH; ++j) {
            if (j < LEVEL_WIDTH) {
                Game_Screen[i][j] = Level_Screen[i][j];
            }
            else {
                Game_Screen[i][j] = Gui_Screen[i][j - LEVEL_WIDTH];
            }
        }
    }
    Game_Screen[cursor.pos[1]][cursor.pos[0]] = cursor.face;


    //------------------------------ Print the Screen ------------------------------//
    for (int i = 0; i < SCREEN_HEIGHT; ++i) {
        for (int j = 0; j < SCREEN_WIDTH; ++j) {
            cout << Game_Screen[i][j];
        }
        cout << endl;
    }



    //------------------------------ Take Input ------------------------------//
    string input;
    cout << "input: ";
    cin >> input;


    //------------------------------ Interpret Input ------------------------------//
    if (is_partial_word(input, "quit")) {
        Running = false;
        return;
    }

    for (int i = 0; i < input.length(); i++) {
        if ((input[i] == 'd') || (input[i] == ';')) {
            cursor.pos[0] = clamp(cursor.pos[0] + 1, 0, LEVEL_WIDTH - 1);
        }
        else if ((input[i] == 'a') || (input[i] == 'j')) {
            cursor.pos[0] = clamp(cursor.pos[0] - 1, 0, LEVEL_WIDTH - 1);
        }
        else if ((input[i] == 'w') || (input[i] == 'k')) {
            cursor.pos[1] = clamp(cursor.pos[1] - 1, 0, LEVEL_HEIGHT - 1);
        }
        else if ((input[i] == 's') || (input[i] == 'l')) {
            cursor.pos[1] = clamp(cursor.pos[1] + 1, 0, LEVEL_HEIGHT - 1);
        }
    }
}



///////////////////////////////////////////////////////////// Main ////////////////////////////////////////////////////////////////////////////
int main() {
    //------------------------------ Initialize the game ------------------------------//
    //// Initialize the level ////
    for (int i = 0; i < LEVEL_HEIGHT; ++i) {
        for (int j = 0; j < LEVEL_WIDTH; ++j) {
            Level_Tiles[i][j] = Tiles::EMPTY;
        }
    }

    //// Initialize the GUI ////
    for (int i = 0; i < GUI_HEIGHT; i++) {
        for (int j = 0; j < GUI_WIDTH; j++) {
            if (i == 0) {
                Gui_Screen[i][j] = 'I';
            }
            else if (i == GUI_HEIGHT - 1) {
                Gui_Screen[i][j] = '_';
            }
            else {
                Gui_Screen[i][j] = ' ';
            }
            if (j == 0) {
                if (i == gui_tile_under_cursor_position() - 1) {
                    Gui_Screen[i][0] = 'v';
                }
                else if (i == gui_tile_under_cursor_position()) {
                    Gui_Screen[i][0] = '?';
                }
                else if (i == gui_tile_under_cursor_position() + 1) {
                    Gui_Screen[i][0] = '^';
                }
                else {
                    Gui_Screen[i][0] = '|';
                }
            }
            else if (j == GUI_WIDTH - 1) {
                Gui_Screen[i][j] = '|';
            }
        }
    }


    //------------------------------ Run the game ------------------------------//
    while (Running) {
        update();
    }

    cout << "Goodbye";
    return 0;
}

