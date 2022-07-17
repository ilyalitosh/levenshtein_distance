#include <stdio.h>
#include "levenshtein/levenshtein.h"

int main(int argc, char *argv[]) {
	printf("Distance %i \n", calculate(argv[1], argv[2]));
	return 0;
}