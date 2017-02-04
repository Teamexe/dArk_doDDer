#include <unistd.h>
#include <linux/input.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <cstring>
#include <stdexcept>

const int KEY_RELEASE = 0;
const int KEY_PRESS = 1;

void printHelpText(void);
void printVersionInfo(void);
void checkRoot(void);
const char *getKeyboardFile(void) noexcept;
int openKeyboardFile(void);
const bool isNetPresent(void);
