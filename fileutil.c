#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileutil.h"

#define InitialCapacity 10

// DIRECTIONS
// Choose whether you are doing the 2D array or
// the array of arrays.
// For the 2D array,
//    implement loadFile2D, substringSearch2D, and free2D.
// For the array of arrays, 
//    implement loadFileAA, substringSearchAA, and freeAA.


// Load the text file from the given filename.
// Return a pointer to the array of strings.
// Sets the value of size to be the number of valid
// entries in the array (not the total array length).
/* char ** loadFileAA(char *filename, int *size)
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// TODO
	// Allocate memory for an array of strings (arr).
	// Read the file line by line.
    //   Trim newline.
	//   Expand array if necessary (realloc).
	//   Allocate memory for the string (str).
	//   Copy each line into the string (use strcpy).
	//   Attach the string to the large array (assignment =).
    // Close the file.
	
	// The size should be the number of entries in the array.
	*size = 0;
	
	// Return pointer to the array of strings.
	return NULL;
}
*/
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

	//initial capacity and size
	int capacity = InitialCapacity;
	*size = 0;

	//allocate memory for 2d array
	char(*arr)[COLS] = malloc(capacity * sizeof(char[COLS]));
	if (!arr)
	{
		perror("Memory allocation failed");
		fclose(in);
		exit(1);
	}
	//buffer for reading lines
	char buffer[1000];

	//read each line of the file
	while (fgets(buffer, sizeof(buffer), in))
	{
		buffer[strcspn(buffer, "\n")] = '\0';

		//check if capicity needs expanding
		if(*size >= capacity)
		{
			capacity *= 2; //double it
			arr = realloc(arr, capacity * sizeof(char[COLS]));
			if (!arr)
			{
				perror("Memory reallocation failed");
				fclose(in);
				exit(1);
			}
		}

		//copy buffer into array 
		strcpy(arr[*size], buffer);
		(*size)++; //increment to reflect new line added
	}

	// Return pointer to the array.
	fclose(in);
	return arr;
}

// Search the array for the target string.
// Return the found string or NULL if not found.
/* char * substringSearchAA(char *target, char **lines, int size)
{

	return NULL;
}
*/
char * substringSearch2D(char *target, char (*lines)[COLS], int size)
{
	for(int i = 0; i < size; i++)
	{
		//strstr to check if target is a substring of lines[i]
		if (strstr(lines[i], target) != NULL)
		{
			return lines[i]; // return the first matching line
		}
	}
    return NULL; //return null if not found
}

// Free the memory used by the array
/* void freeAA(char ** arr, int size)
{

}
*/
void free2D(char (*arr)[COLS])
{
	free(arr);
}