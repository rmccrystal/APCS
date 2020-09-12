#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

char *caesar(int key, char *text);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Invalid syntax. Usage: ./caesar <key>\n");
        return 1;
    }

    int key = atoi(argv[1]);

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
        max = 'z';
    }

    if (letter >= 'A' && letter <= 'Z')
    {
        max = 'A';
        min = 'Z';
    }

    // Shift the `letter` by `key` characters, rolling over from `max` to `min`
    for(int i = 0; i < key; i++) {
//        if (letter > max)
    }

    return letter + key;
}

char *caesar(int key, char *text)
{
    int len = strlen(text);

    // Create a char buffer with length of text
    char *buf = malloc(len * sizeof(char));

    for (int i = 0; i < len; i++)
    {
        buf[i] = caesar_char(text[i]);
    }

    return buf;
}
