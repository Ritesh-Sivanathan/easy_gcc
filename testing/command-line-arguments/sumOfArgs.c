#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	int num1, num2, sum;

	if (argc!=3) {
		printf("Please include 2 numbers as arguments to add");
	} else {
		num1 = atoi(argv[1]);
		num2 = atoi(argv[2]);
		sum = num1+num2;
		printf("%d + %d = %d", num1, num2, sum);
	}


	return 0;
}
