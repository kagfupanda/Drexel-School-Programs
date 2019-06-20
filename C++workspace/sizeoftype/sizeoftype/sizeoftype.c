//
//  main.c
//  sizeoftype
//
//  Created by Siddharth Srinivasan on 9/19/18.
//  Copyright © 2018 Siddharth Srinivasan. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    printf("size of char on this system is %d bytes \n", sizeof(char));
    printf("size of short on this system is %d bytes \n", sizeof(short));
    printf("size of int on this system is %d bytes \n", sizeof(int));
    printf("size of long on this system is %d bytes \n", sizeof(long));
    printf("size of float on this system is %d bytes \n", sizeof(float));
    printf("size of double on this system is %d bytes \n", sizeof(double));
    
    int i;
    printf("size of i is %d bytes\n", sizeof(i));
    
    char *ptr; /* ptr is a pointer, i.e. ptr is a pointer to a char */
    /* ptr is a pointer to "a char" or "the first char of a string of chars" -can't tell */
    
    printf("size of a pointer in this system is %d \n", sizeof(ptr));
    
    return 0;
}
