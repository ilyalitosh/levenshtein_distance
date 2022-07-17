#include<stdio.h>
#include<string.h>
#include "levenshtein.h"

#define LEN(arr) ((int) (sizeof (arr) / sizeof (arr)[0]))


int calculate(char* first, char* second) {
	int firstSize = strlen(first);
	int secondSize = strlen(second);

	if (firstSize == 0 || secondSize == 0) {
        return firstSize == 0 ? secondSize : firstSize;
    }

    // Create two dimensional array
    int charsTable[firstSize + 1][secondSize + 1];
    memset(charsTable, 0, sizeof(charsTable));

    // Fill table by first word
    for (int i = 1, j = 0, counter = 1; i <= firstSize; i++, counter++) {
        charsTable[i][j] = counter;
    }

    // Fill table by second word
    for (int i = 0, j = 1, counter = 1; j <= secondSize; j++, counter++) {
        charsTable[i][j] = counter;
    }

    // Table should look like (if first word is 'first' and second word is 'second'):
    //       s e c o n d
    //    --------------
    //   | 0 1 2 3 4 5 6
    // f | 1 0 0 0 0 0 0
    // i | 2 0 0 0 0 0 0
    // r | 3 0 0 0 0 0 0
    // s | 4 0 0 0 0 0 0
    // t | 5 0 0 0 0 0 0

    int firstWordCharsTableSize = LEN(charsTable);
    int secondWordCharsTableSize = LEN(charsTable[0]);

    for (int i = 1; i < firstWordCharsTableSize; i++) {
        for (int j = 1; j < secondWordCharsTableSize; j++) {
            int d1 = charsTable[i][j - 1] + 1;
            int d2 = charsTable[i - 1][j] + 1;
            int d3 = charsTable[i - 1][j - 1] + equals(first[i - 1], second[j - 1]);
            charsTable[i][j] = min(d1, d2, d3);
        }
    }

    return charsTable[firstSize][secondSize];
}

int min(int i1, int i2, int i3) {
	int intArray[3] = {i1, i2, i3};
	int arraySize = LEN(intArray);

	int minValue = intArray[0];
	for (int i = 1; i < arraySize; i++) {
		if (intArray[i] <= minValue) {
			minValue = intArray[i];
		}
	}
	return minValue;
}

int equals(char c1, char c2) {
	return c1 == c2 ? 0 : 1;
}
