//
// Created by tobe on 5/5/2016.
//

#include "CliOptions.h"

CliOptions::CliOptions(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        if (!strcmp("-v", argv[i]) || !strcmp("--version", argv[i])) {
            show_version = true;
        } else if (!strcmp("-h", argv[i]) || !strcmp("--help", argv[i])) {
            show_help = true;
        } else if (!strcmp("--verbose", argv[i])) {
            verbose = true;
        } else if (!strcmp("-p", argv[i]) || !strcmp("--log-performance", argv[i])) {
            verbose = true;
        } else {
            input_file_name = argv[i];
        }
    }
}

int CliOptions::PrintHelp() {
    PrintVersion();
    cout << "usage: clc [options...] <file>" << endl;
    return 0;
}

int CliOptions::PrintVersion() {
    cout << "CLC v" << CLC_VERSION << endl;
    return 0;
}

