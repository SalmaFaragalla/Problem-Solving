/* https://www.hackerrank.com/challenges/game-of-thrones/problem */
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

/*
 * Complete the 'gameOfThrones' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */

char* gameOfThrones(char* s)
{
    int stringLength = strlen(s);
    
    // Create Frequency Array
    #define ALPHABET_COUNT ((int)26)
    int frequencyArray[ALPHABET_COUNT] = {0};
    int index=0;
    
    for (index=0 ; index<stringLength ; ++index)
    {
        ++frequencyArray[s[index]- 'a'];
    }
    
    //If the string length is even, all characters must occur an even number of times.
    //If the string length is odd, all characters must occur an even number of times , except one (the character in the center) 
    int targetOddCounter = (stringLength % 2 == 0) ? 0 : 1;
  
    int oddCounter=0;
    for (index=0 ; index<ALPHABET_COUNT ; ++index)
    {
        // if odd frequency
        if (frequencyArray[index]%2 != 0)
        {
            ++oddCounter;
            if (oddCounter > targetOddCounter)
            {
                return "NO";
            }
        }
    }
    return "YES";
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = gameOfThrones(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}
