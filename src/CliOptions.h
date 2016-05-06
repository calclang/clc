//
// Created by tobe on 5/5/2016.
//

#ifndef CLC_CLIOPTIONS_H
#define CLC_CLIOPTIONS_H
#define CLC_VERSION "0.0.0-dev"

#include <cstring>
#include <iostream>
using namespace std;

/**
 * Stores the result of parsing the command line.
 * Example:
 * CliOptions* cliOptions = new CliOptions(argc, argv);
 */
class CliOptions {
public:
    // The file path to read from.
    string input_file_name;
    // Determines whether to time running the program.
    bool log_performance = false;
    // Determines whether to print help info.
    bool show_help = false;
    // Determines whether to print the CLC version.
    bool show_version = false;
    // Determines whether to print verbose output.
    bool verbose = false;

    CliOptions(int argc, char** argv);
    int PrintHelp();
    int PrintVersion();
};


#endif //CLC_CLIOPTIONS_H
