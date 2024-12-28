#include <map>

using namespace std;


#define LEVEL_WIDTH 32
#define LEVEL_HEIGHT 16
#define GUI_WIDTH 12
#define GUI_HEIGHT 16
#define SCREEN_WIDTH 44
#define SCREEN_HEIGHT 16
#define GUI_TILE_UNDER_CURSOR_YPOS static_cast<int>(floor(GUI_HEIGHT / 2) - 1)


enum States {
    DEFAULT = 0,
};

enum Tiles {
    EMPTY = 0,
    TRACK_V = 1,
    TRACK_H = 2,
};

// Each number represents a level tile that can be placed and is replaced with the corresponding character when printed.
map<int, char> Tile_Map = {
    { 0, ' ' },
    { 1, 'H' },
    { 2, 'I' },
    { 3, 'O' },
};




//// Game Variables ////
bool Running = true;

enum States Game_State = States::DEFAULT;

enum Tiles Level_Tiles[LEVEL_HEIGHT][LEVEL_WIDTH];

int selected_tile = Tiles::EMPTY;

char Level_Screen[LEVEL_HEIGHT][LEVEL_WIDTH];
char Gui_Screen[GUI_HEIGHT][GUI_WIDTH];
char Game_Screen[SCREEN_HEIGHT][SCREEN_WIDTH];


//// Classes ////
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

class Item {
    int pos[2] = {0, 0};
    void update() {
        if (Level_Tiles[pos[1]][pos[0]] == Tiles::TRACK_V) {
            pos[1] += 1;
        }
        else if (Level_Tiles[pos[1]][pos[0]] == Tiles::TRACK_H) {
            pos[0] += 1;
        }
    }
};


Cursor cursor;