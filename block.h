#pragma once

#include <string>

struct Config {
    size_t rows;
    char character;
    std::string colour;
};

void process_options(int argc, char *argv[], Config &config);
