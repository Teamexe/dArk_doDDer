#ifndef __KEYNAME__
#define __KEYNAME__

#define UNKNOWN_KEY "-1"

const char *getKey(int a, bool shiftPressed);
const bool isShift(int);
const bool isCaps(int);

#endif