#include <keyname.h>
#include <cstring>

static const char *charList[] = {UNKNOWN_KEY, "<ESC>", "1", "2", "3", "4", "5",
                                    "6", "7", "8", "9", "0", "-", "=",
                                    "<Backspace>", "<Tab>", "q", "w", "e", "r",
                                    "t", "y", "u", "i", "o", "p", "[", "]", "<Enter>",
                                    "<L-Ctrl>", "a", "s", "d", "f", "g", "h", "j", "k",
                                    "l", ";", "'", "`", "<L-SHIFT>", "\\", "z", "x",
                                    "c", "v", "b", "n", "m", ",", ".", "/", "<R-SHIFT>",
                                    "PAD-*", "<L-ALT>", "<SPACE>", "<CAPSLOCK>", "F1", "F2",
                                    "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", 
                                    "NUMLOCK", "SCROLLOCK", "PAD-7", "PAD-8", "PAD-9", "PAD--",
                                    "PAD-4", "PAD-5", "PAD-6", "PAD-+", "PAD-1", "PAD-2",
                                    "PAD-3", "PAD-0", "PAD-.", UNKNOWN_KEY, UNKNOWN_KEY, UNKNOWN_KEY,
                                    "F11", "F12", UNKNOWN_KEY, UNKNOWN_KEY, UNKNOWN_KEY, UNKNOWN_KEY,
                                    UNKNOWN_KEY, UNKNOWN_KEY, UNKNOWN_KEY, "<PAD-ENTER>",
                                    "<R-CTRL>", "PAD-/", "PRTSCR", "<R-ALT>", UNKNOWN_KEY,
                                    "HOME", "UP", "PG-UP", "LEFT", "RIGHT", "END", "DOWN",
                                    "PG-DOWN", "INSERT", "DEL", UNKNOWN_KEY, UNKNOWN_KEY, 
                                    UNKNOWN_KEY, UNKNOWN_KEY, UNKNOWN_KEY, UNKNOWN_KEY, UNKNOWN_KEY,
                                    "PAUSE"};

static const char *shiftCharList[] = {UNKNOWN_KEY, "<ESC>", "!", "@", "#", "$", "%",
                                    "^", "&", "*", "(", ")", "_", "+",
                                    "<Backspace>", "<Tab>", "Q", "W", "E", "R",
                                    "T", "Y", "U", "I", "O", "P", "{", "}", "<Enter>",
                                    "<L-Ctrl>", "A", "S", "D", "F", "G", "H", "J", "K",
                                    "L", ":", "\"", "~", "<L-SHIFT>", "|", "Z", "X",
                                    "C", "V", "B", "N", "M", "<", ">", "?", "<R-SHIFT>",
                                    "PAD-*", "<L-ALT>", "<SPACE>", "<CAPSLOCK>", "F1", "F2",
                                    "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", 
                                    "NUMLOCK", "SCROLLOCK", "PAD-7", "PAD-8", "PAD-9", "PAD--",
                                    "PAD-4", "PAD-5", "PAD-6", "PAD-+", "PAD-1", "PAD-2",
                                    "PAD-3", "PAD-0", "PAD-.", UNKNOWN_KEY, UNKNOWN_KEY, UNKNOWN_KEY,
                                    "F11", "F12", UNKNOWN_KEY, UNKNOWN_KEY, UNKNOWN_KEY, UNKNOWN_KEY,
                                    UNKNOWN_KEY, UNKNOWN_KEY, UNKNOWN_KEY, "<PAD-ENTER>",
                                    "<R-CTRL>", "PAD-/", "PRTSCR", "<R-ALT>", UNKNOWN_KEY,
                                    "HOME", "UP", "PG-UP", "LEFT", "RIGHT", "END", "DOWN",
                                    "PG-DOWN", "INSERT", "DEL", UNKNOWN_KEY, UNKNOWN_KEY, 
                                    UNKNOWN_KEY, UNKNOWN_KEY, UNKNOWN_KEY, UNKNOWN_KEY, UNKNOWN_KEY,
                                    "PAUSE"};

/**
 * Function: getkey
 * Arguments: change keyword hardware code to real number
 * return: real keystroke for the place of number
 * use: at line no. 37 in main.cpp
**/
const char *getKey(int a, bool shiftPressed)
{
    if(shiftPressed)
        return shiftCharList[a];
    else
        return charList[a];
}

const bool isShift(int a)
{
    if(std::strcmp(charList[a], "<L-SHIFT>") == 0 || std::strcmp(charList[a], "<R-SHIFT>") == 0)
        return true;
    else
        return false;
}

const bool isCaps(int a)
{
    if(std::strcmp(charList[a], "<CAPSLOCK>") == 0)
        return true;
    else
        return false;
}
