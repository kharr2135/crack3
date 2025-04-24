#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileutil.h"

// DIRECTIONS
// Choose whether you are doing the 2D array or
// the array of arrays. array of arrays
// For the array of arrays, 
//    implement loadFileAA, substringSearchAA, and freeAA.


// Load the text file from the given filename.
// Return a pointer to the array of strings.
// Sets the value of size to be the number of valid
// entries in the array (not the total array length).

//array of arrays
char ** loadFileAA(char *filename, int *size)
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// TODO
	// Allocate memory for an array of strings (arr). D
	// Read the file line by line. D
    //   Trim newline. D
	//   Expand array if necessary (realloc). D 
	//   Allocate memory for the string (str). D
	//   Copy each line into the string (use strcpy). D
	//   Attach the string to the large array (assignment =). D
    // Close the file.
	
	char **arr = NULL;
	int capacity = 10;
	*size = 0;

	arr = malloc(capacity * sizeof(char*));
	if (arr == NULL) {
		perror("Memory allocation failed");
		exit(1);
	}

	char buffer[1024];
	while (fgets(buffer, sizeof(buffer), in)) {
		buffer[strcspn(buffer, "\n")] = '\0'; // Trim newline

		if (*size >= capacity) {
			capacity *= 2;
			char **temp = realloc(arr, capacity * sizeof(char*));
			if (temp == NULL) {
				perror("Reallocation failed");
				exit(1);
			}
			arr = temp;
		}
 //malloc dynamic memory
		arr[*size] = malloc(strlen(buffer) + 1);
		if (arr[*size] == NULL) {
			perror("String allocation failed");
			exit(1);
		}
		strcpy(arr[*size], buffer);
		(*size)++;
	}

	fclose(in);
	
	// The size should be the number of entries in the array.
	return arr;
}

char (*loadFile2D(char *filename, int *size))[COLS]
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// TODO
	// Allocate memory for an 2D array, using COLS as the width.
	// Read the file line by line into a buffer.
    //   Trim newline.
	//   Expand array if necessary (realloc).
	//   Copy each line from the buffer into the array (use strcpy).
    // Close the file.
	
	// The size should be the number of entries in the array.
	*size = 0;
	
	// Return pointer to the array.
	return NULL;
}

// Search the array for the target string.
// Return the found string or NULL if not found.
char * substringSearchAA(char *target, char **lines, int size)
{
	for (int i = 0; i < size; i++) {
		if (strstr(lines[i], target)) {
			return lines[i];
		}
	}
	return NULL;
}

char * substringSearch2D(char *target, char (*lines)[COLS], int size)
{
    
    return NULL;
}

// Free the memory used by the array
void freeAA(char ** arr, int size)
{
	for (int i = 0; i < size; i++) {
		free(arr[i]);
	}
	free(arr);
}

void free2D(char (*arr)[COLS])
{

}
