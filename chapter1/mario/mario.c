#include <cs50.h>
#include <stdio.h>

void generateMarioTower(int height);

int main(void)
{
    int height;
    while (true)
    {
        height = get_int("Height: ");
        if (height > 0 && height <= 8)
            break;
    }
    generateMarioTower(height);
}

// Prints some text x times without adding a newline
void repeatPrint(const char *text, int times)
{
    for (int i = 0; i < times; i++)
    {
        printf("%s", text);
    }
}

void generateMarioTower(int height)
{
    for (int i = 1; i <= height; i++)
    {
        repeatPrint(" ", height - i);
        repeatPrint("#", i);
        printf("  ");
        repeatPrint("#", i);
        printf("\n");
    }
}
