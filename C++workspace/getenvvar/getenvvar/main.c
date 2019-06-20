//
//  main.c
//  getenvvar
//
//  Created by Siddharth Srinivasan on 9/19/18.
//  Copyright © 2018 Siddharth Srinivasan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h> /* for getenv() function */
/* This program prints the value of the environment variable passed on the command line
 */
int main(int argc,  char * argv[]) {
    /* check that env var name is specified on command line */
    /* if only command name, and nothing else, then argc value will be 1
     /* if additional args are specified on command line,
     * then argc value will be greater than 1*/
    // check by ching the value of argc
    if (argc < 2) { // true means => is ONE
        printf("Usage: %s <env_var_name>\n", argv[0]);
        return 0;
    }
    char *ret_value;
    ret_value = getenv(argv[1]);
    /* check ret_value for NULL pointer before printing */
    if(ret_value == NULL) {
        printf("env var %s does not exist \n", argv[1]);
    } else {
        printf("env var %s has value %s\n", argv[1], ret_value);
    }
    
    return 0;
}
