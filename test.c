// Example program for Command Line Arguments in C from GeeksForGeeks
// Original Source: https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/

// C program named mainreturn.c to demonstrate the working
// of command line arguement

#include <stdio.h>

// defining main with arguments
int main(int argc, char* argv[])
{
    printf("You have entered %d arguments:\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    return 0;
}
