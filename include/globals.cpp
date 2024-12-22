#include <map>

using namespace std;


#define LEVEL_WIDTH 32
#define LEVEL_HEIGHT 16
#define GUI_WIDTH 10
#define GUI_HEIGHT 16
#define SCREEN_WIDTH 42
#define SCREEN_HEIGHT 16


enum States {
    DEFAULT = 0,
};

enum Tiles {
    EMPTY = 0,
    TRACK_V = 1,
    TRACK_H = 2,
    ITEM = 3,
};

// Each number represents a level tile that can be placed and is replaced with the corresponding character when printed.
map<int, char> Tile_Map = {
    { 0, ' ' },
    { 1, 'H' },
    { 2, 'I' },
    { 3, 'O' },
};


class Cursor {
    public:
        int pos[2] = {static_cast<int>(LEVEL_WIDTH * 0.5), static_cast<int>(LEVEL_HEIGHT * 0.5)};
        char face = 'X';
    bool visible = true;
};

class Track {
    int pos[2] = {0, 0};
    int type = 0;
    int dir = 0;
    char face = '?';
};

int gui_tile_under_cursor_position() {
    return floor(GUI_HEIGHT / 2) - 1;
};



//// Game Variables ////
bool Running = true;

enum States Game_State = States::DEFAULT;

enum Tiles Level_Tiles[LEVEL_HEIGHT][LEVEL_WIDTH];

char Level_Screen[LEVEL_HEIGHT][LEVEL_WIDTH];
char Gui_Screen[GUI_HEIGHT][GUI_WIDTH];
char Game_Screen[SCREEN_HEIGHT][SCREEN_WIDTH];

Cursor cursor;