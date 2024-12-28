#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define COMMAND_LENGTH 256
#define ARGUMENTS_LENGTH 256

void compileProgram(int argc, char *argv[], char optionalArguments[], char runAsSudo[], char source_filename[]) {

    char compile_command[COMMAND_LENGTH];

    if (argc > 1) {

	if (strcmp(argv[1], "--sudo") == 0) {

		strcat(runAsSudo, "sudo");

		for (int i=3;i<argc;i++) {
		    strcat(optionalArguments, argv[i]);
		    strcat(optionalArguments, " ");
		}

	} else {

		for (int i=2;i<argc;i++) {
		    strcat(optionalArguments, argv[i]);
		    strcat(optionalArguments, " ");

		}
	}

   }


    snprintf(compile_command, COMMAND_LENGTH, "%s gcc %s.c -o %s", runAsSudo, source_filename, source_filename);

    int return_code_c = system(compile_command);

    if (return_code_c != 0) {
        fprintf(stderr, "\nCompilation error for %s. Returned %d\n", source_filename, return_code_c);
    }

}

void executeProgram(char source_filename[], char optionalArguments[]) {

    char execute_command[COMMAND_LENGTH];

    snprintf(execute_command, COMMAND_LENGTH, "./%s", source_filename); // need to add flags here
    strcat(execute_command, optionalArguments);

    int return_code_e = system(execute_command);

    printf("\n");

    if (return_code_e != 0) {
        fprintf(stderr, "\nExecution error for %s\n", source_filename);
    }

}

int main(int argc, char *argv[]) {

    // NO FLAGS: argv[1] = filename
    // YES FLAGS: argv[2] = filename
    // anything after will just be appended to the execution string

    if (argc < 2) {
        fprintf(stderr, "easy_c_run usage: %s <flags> <source_file>\n", argv[0]);
        return 1;
    }

    char source_filename[COMMAND_LENGTH];
    int filenameIndex = 1;


   // should probably make this more dynamic for future flags

    if (argc > 2) {
	    if ( (strcmp (argv[1], "--sudo") ) == 0 ) {
	    	filenameIndex = 2;
       	    }
    } 

    strncpy(source_filename, argv[filenameIndex], COMMAND_LENGTH - 1);
    source_filename[COMMAND_LENGTH - 1] = '\0';

    char optionalArguments[ARGUMENTS_LENGTH] = " ";
    char runAsSudo[5] = "";

    compileProgram(argc, argv, optionalArguments, runAsSudo, source_filename);
    executeProgram(source_filename, optionalArguments);

    return 0;
}
