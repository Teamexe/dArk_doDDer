#include <keyname.h>

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


const char *getKey(int a)
{
    return charList[a];
}
