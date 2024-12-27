#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define COMMAND_LENGTH 256
#define ARGUMENTS_LENGTH 256

int main(int argc, char *argv[]) {

    // NO FLAGS: argv[1] = filename
    // YES FLAGS: argv[2] = filename
    // anything after will just be appended to the execution string

    if (argc < 2) {
        fprintf(stderr, "easy_c_run usage: %s <flags> <source_file>\n", argv[0]);
        return 1;
    }

    char source_filename[COMMAND_LENGTH];
    int x = 1; // index of source_filename in the command. default is 1 (no flags)

    if (argc > 2) {
	    if ( (strcmp (argv[1], "--sudo") ) == 0 ) {
	    	x = 2;
       	    }
    }

    strncpy(source_filename, argv[x], COMMAND_LENGTH - 1);
    source_filename[COMMAND_LENGTH - 1] = '\0';

    char optionalArguments[ARGUMENTS_LENGTH] = " ";
    char runAsSudo[5] = "";


   if (argc > 1) {

	if(strcmp(argv[1], "--sudo")==0) {
		for (int i=3;i<argc;i++) { // becomes i=3 since the first 2 elements are filename and --sudo flag
			strcat(optionalArguments, argv[i]);
			strcat(optionalArguments, " ");
		}

		strcat(runAsSudo, "sudo");

	} else {
		for (int i=2;i<argc;i++) {
			strcat(optionalArguments, argv[i]);
			strcat(optionalArguments, " ");
		}
	}

   }


    char compile_command[COMMAND_LENGTH];
    snprintf(compile_command, COMMAND_LENGTH, "%s gcc %s.c -o %s", runAsSudo, source_filename, source_filename);

    int return_code_c = system(compile_command);

    if (return_code_c != 0) {
        fprintf(stderr, "\nCompilation error for %s\n", source_filename);
        return 1;
    }

    char execute_command[COMMAND_LENGTH];

    snprintf(execute_command, COMMAND_LENGTH, "./%s", source_filename); // need to add flags here
    strcat(execute_command, optionalArguments);

    int return_code_e = system(execute_command);

    printf("\n");

    if (return_code_e != 0) {
        fprintf(stderr, "\nExecution error for %s\n", source_filename);
        return 1;
    }

    return 0;
}
