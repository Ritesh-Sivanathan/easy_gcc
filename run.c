#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMMAND_LENGTH 256

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "easy_c_run usage: %s <source_file>\n (DON'T INCLUDE .out OR .c)", argv[0]);
        return 1;
    }

    char source_filename[COMMAND_LENGTH];
    strncpy(source_filename, argv[1], COMMAND_LENGTH - 1);
    source_filename[COMMAND_LENGTH - 1] = '\0';

    char compile_command[COMMAND_LENGTH];
    snprintf(compile_command, COMMAND_LENGTH, "gcc %s.c -o %s", source_filename, source_filename);

    int return_code_c = system(compile_command);

    if (return_code_c != 0) {
        fprintf(stderr, "\nCompilation error for %s\n", source_filename);
        return 1;
    }

    char execute_command[COMMAND_LENGTH];
    snprintf(execute_command, COMMAND_LENGTH, "./%s", source_filename);

    int return_code_e = system(execute_command);

    printf("\n");

    if (return_code_e != 0) {
        fprintf(stderr, "\nExecution error for %s\n", source_filename);
        return 1;
    }

    return 0;
}
