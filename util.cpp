#include <util.h>
#include <iostream>

/**
 * Function: printHelpText
 * Argument: none
 * return: none
 * use: used to print the help message
 **/

void printHelpText(void)
{
    std::cout << "Usage: Logger [OPTION]..." << std::endl
        << "Starts the logging of the keystrokes,"
        << " provided process ran in sudo." << std::endl
        << " If no arguments given then the program will store the log files at"
        << " /var/log/Dodder.log" << std::endl
        << "-h, --help\tdisplay this help and exit" << std::endl
        << "-v, --version\tdisplay the version of the program then exit" << std::endl
        << "-s, --stdout\tdisplay the keystrokes in the stdout" << std::endl
        << "-f, --file\tstore the keystrokes in the file provided" << std::endl;
}

void printVersionInfo(void)
{
    std::cout << "At the alpha stage" << std::endl;
}
