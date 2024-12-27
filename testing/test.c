#include <stdio.h>

int main(int argc, char *argv[]) {

	for(int i=0; i<argc; i++) {
		printf("\n%lu\n", sizeof(*argv[i])); // yes, this is supposed to include argv[0]
	}
	
	return 0;

}

