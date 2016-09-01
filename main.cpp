#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include "block.h"


int main(int argc, char *argv[])
{
    Config config={4,'=',""};
    process_options(argc, argv, config);
    winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    std::cout << config.colour;
    for(size_t y=0; y<config.rows; ++y) {
        for(size_t x=0; x<w.ws_col; ++x)
        {
            std::cout << config.character;
        }
    }
    std::cout << "\033[0;0m";
    return 0;
}


