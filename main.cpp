//Headers for using the OS features
#include <unistd.h>
#include <linux/input.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>

//C++ based libraries
#include <iostream>
#include <stdexcept>

//my libraries
#include <keyname.h>
#include <util.h>

//type definations

//function definations
static void checkRoot(void);
static const char *getKeyboardFile(void) noexcept;
static int openKeyboardFile(void);

//main
int main()
{
    int kbd_Fd;
    input_event eve;
    checkRoot();
    kbd_Fd = openKeyboardFile();
    bool shiftPressed = false, capsActive = false; //TODO(lordPoseidon) debug the capsActive error
    while(read(kbd_Fd, &eve, sizeof(input_event)) > 0)
    {
        if(eve.type == EV_KEY)
        {
            if(eve.value == KEY_RELEASE && isCaps(eve.code))
                capsActive = !capsActive;
            if(eve.value == KEY_PRESS && isShift(eve.code))
                shiftPressed = !capsActive;
            if(eve.value == KEY_RELEASE && isShift(eve.code))
                shiftPressed = capsActive;
            if(eve.value == KEY_PRESS)
                std::cout << getKey(eve.code, shiftPressed) << std::endl;
        }
        if(eve.type == EV_KEY && eve.code == 1)
            break;
    }
    close(kbd_Fd);
    return 0;
}
/**
 * Function: checkRoot
 * Arguments: none
 * return: none
 * use: Used to check if the user executed the program by giving superuser 
 *      privillages
 * Exceptions: throw runtime_error if not in root
 **/

static void checkRoot(void)
{
    uid_t id = geteuid(); //if used in sudo then id = 0
    if(id != 0)
        throw std::runtime_error("Must be in root");
}

/**
 * Function: getKeyboardFile
 * Arguments: none
 * return: the path of the file which will be used to get input from keyboard
 * use: used in function openKeyboardFile to get the path of the file for keyboard
 * Exceptions: no exceptions
 **/

static const char *getKeyboardFile(void) noexcept
{
    const char *str = "/dev/input/event4";
    return str;
}

/**
 * Function: openKeyboardFile
 * Arguments: none
 * return: the file descriptor for the opened keyboard file, which will
 *         check the keystrokes
 * use: used to open the file for the keyboard
 * Exceptions: throw runtime_error if file is not opened
 **/

static int openKeyboardFile(void)
{
    int fd = open(getKeyboardFile(), O_RDONLY);
    if(fd < 0)
        throw std::runtime_error("The file descriptor can't be negetive\
                , there was error in opening the keyboard input file");
    return fd;
}
