#include <iostream>
#include <unistd.h>
#include <getopt.h>
#include "block.h"

void process_options(int argc, char *argv[], Config &config)
{
    while(true) {
        static option long_options[] = {
            {"help",   no_argument,       nullptr, 'h'},
            {"rows",   required_argument, nullptr, 'r'},
            {"char",   required_argument, nullptr, 'c'},
            {"colour", required_argument, nullptr, 'C'},
            {nullptr, 0,                 nullptr, 0}
        };
        int option_index = 0;
        int opt = getopt_long(argc, argv, "hr:c:C:", long_options, &option_index);
        if(opt == -1) {
            break;
        }
        switch(opt) {
            case 'r':
                try {
                    config.rows = std::stoul(optarg);
                } catch(const std::exception &e) {
                    std::cerr << "Cannot convert '" << optarg << "' to integer" << std::endl;
                    exit(1);
                }
            break;

            case 'c':
                config.character = optarg[0];
            break;

            case 'C':
            {
                config.colour = 033;
                config.colour += '[';
                std::string colour(optarg);
                if(colour=="black") {
                    config.colour += "0;30m";
                } else if(colour=="red") {
                    config.colour += "0;31m";
                } else if(colour=="green") {
                    config.colour += "0;32m";
                } else if(colour=="brown") {
                    config.colour += "0;33m";
                } else if(colour=="blue") {
                    config.colour += "0;34m";
                } else if(colour=="purple") {
                    config.colour += "0;35m";
                } else if(colour=="cyan") {
                    config.colour += "0;36m";
                }
            }
            break;

            case 'h':
            case '?':
            default:
                std::cout << (char)opt << " " << optind << std::endl;
                std::cout << "Usage: " << argv[0] << "\n";
                std::cout << " -h, --help               This help\n";
                std::cout << " -c, --count              Number of ip addresses to output (default 10)\n";
                std::cout << " -h, --json               Output in a json request format\n";
                exit(0);
                break;
        }
    }
}

