#include <unistd.h>
#include <linux/input.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

const int KEY_RELEASE = 0;
const int KEY_PRESS = 1;

void printHelpText(void);
void printVersionInfo(void);
void checkRoot(void);
const char *getKeyboardFile(void) noexcept;
int openKeyboardFile(void);
