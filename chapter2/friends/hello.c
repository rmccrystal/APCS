#include <cs50.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./hello <name>\n");
        return 1;
    }

    printf("Hello, %s!\n", argv[1]);
}