//
//  main.c
//  printcmdlineargs
//
//  Created by Siddharth Srinivasan on 9/19/18.
//  Copyright © 2018 Siddharth Srinivasan. All rights reserved.
//

#include <stdio.h>
/* This program prints the arguments specified on the command line, the program invocation is teh command line
 */

int main(int argc, const char * argv[]) {
    // argc = arg 'c' count, i.e count of cmd line arguments specified
    // argv = arg 'v'ector, ie vector of the strings containing the arguments
    // NOTE: char * character pointer represents "string"
    //BE CAREFUL
    // A "string" must always end with a nul character, value '\0'
    // argv is an array of "char *" (strings) i.e it has brackets
    // char *argv[] is command line split into words
    // since argv is an array, access it by index
    //index 0 alwasy has the command name
    printf("program's name is: %s \n", argv[0]);
    /* 1st,*/
    for (int i = 0; i < argc; ++i) {
        printf("argv at %d is %s\n", i, argv[i]);
    }
    return 0;
}
