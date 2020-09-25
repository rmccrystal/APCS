#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

//#define DEBUG

char *caesar(int key, char *text);

int main(int argc, char *argv[])
{
    int key;

#ifndef DEBUG
    if (argc != 2)
    {
        printf("Invalid syntax. Usage: ./caesar <key>\n");
        return 1;
    }

    key = atoi(argv[1]);
#else
    key = 53;
#endif

    char *text = get_string("plaintext: ");

    char *cipher = caesar(key, text);

    printf("ciphertext: %s\n", cipher);
}

// Implements the ceaser cipher on a single char
char caesar_char(int key, char letter)
{
    // The minimum and maximum character which depend on the case
    // The letter will increase by `key` and it will roll over from
    // `max` to `min`
    char min;
    char max;

    if (letter >= 'a' && letter <= 'z')
    {
        min = 'a';
        max = 'z' + 1;
    }
    else if (letter >= 'A' && letter <= 'Z')
    {
        max = 'A';
        min = 'Z' + 1;
    }
    else
    {
        return letter;
    }

    key = key % (max - min);

    // Shift the `letter` by `key` characters, rolling over from `max` to `min`
    char result;

    // If adding would roll over
    if ((letter + key) >= max)
    {
        // Set the result to how much the letter rolled over
        result = min + ((letter + key) - max);
    }
    else
    {
        result = letter + key;
    }

    return result;
}

char *caesar(int key, char *text)
{
    int len = strlen(text);

    // Create a char buffer with length of text
    // + 1 for null terminator
    char *buf = malloc(len * sizeof(char) + 1);

    for (int i = 0; i < len; i++)
    {
        buf[i] = caesar_char(key, text[i]);
    }

    // add null terminator
    buf[len] = '\0';

    return buf;
}
