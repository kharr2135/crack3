//i was having a ton of trouble comppiling the code, i got it to work once and then failed to do it again so maybe im missing something in the terminal
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"

#if __has_include("fileutil.h")
#include "fileutil.h"
#endif

#define PASS_LEN 50     // Maximum length any password will be.
#define HASH_LEN 33     // Length of hash plus one for null.

char *linearSearchAA(char *target, char **array, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(target, array[i]) == 0)
            return array[i];
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        printf("Usage: %s hash_file dictionary_file\n", argv[0]);
        exit(1);
    }

    // TODO: Read the hashes file into an array.
    //   Use either a 2D array or an array of arrays.
    //   Use the loadFile function from fileutil.c
    //   Uncomment the appropriate statement.
    int size;
    //char (*hashes)[HASH_LEN] = loadFile(argv[1], &size);
    char **hashes = loadFileAA(argv[1], &size);
    
    // CHALLENGE1: Sort the hashes using qsort.
    
    // TODO
    // Open the password file for reading.
    FILE *fp = fopen(argv[2], "r");
    if (!fp)
    {
        perror("Error opening dictionary file");
        exit(1);
    }

    // TODO
    // For each password, hash it, then use the array search
    // function from fileutil.h to find the hash.
    // If you find it, display the password and the hash.
    // Keep track of how many hashes were found.
    // CHALLENGE1: Use binary search instead of linear search.
    char password[PASS_LEN];
    char hash[HASH_LEN];
    int found = 0;

    while (fgets(password, PASS_LEN, fp))
    {
        char *newline = strchr(password, '\n');
        if (newline) *newline = '\0';

        md5String(password, hash);

        if (linearSearchAA(hash, hashes, size))
        {
            printf("%s -> %s\n", password, hash);
            found++;
        }
    }

    // TODO
    // When done with the file:
    //   Close the file
    //   Display the number of hashes found.
    //   Free up memory.
    fclose(fp);
    freeAA(hashes, size);

    printf("Found %d passwords\n", found);

}