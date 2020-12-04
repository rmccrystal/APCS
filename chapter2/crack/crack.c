#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// if we're compiling on apple, use the unistd library and use crypt.h
// if we're not on apple
#ifdef __APPLE__

#include <unistd.h>

#else
#include <crypt.h>
#endif

bool check(char *hashed, char *password)
{
    return strcmp(crypt(password, "50"), hashed) == 0;
}

// Cracks a password of length 4 using the `check` function
char *crack(char *hashed, char alphabet[])
{
    long alphabet_len = (long) strlen(alphabet);

    // preserve value out of scope so we can return it
    static char password[6];

    memset(password, 0, 6);

    // -1 represents null terminator
    for (int i = -1; i < alphabet_len; ++i)
    {
        for (int j = -1; j < alphabet_len; ++j)
        {
            for (int k = -1; k < alphabet_len; ++k)
            {
                for (int l = -1; l < alphabet_len; ++l)
                {
                    for (int m = 0; m < alphabet_len; ++m)
                    {
                        // set password
                        password[0] = alphabet[m];
                        password[1] = l == -1 ? '\0' : alphabet[l];
                        password[2] = k == -1 ? '\0' : alphabet[k];
                        password[3] = j == -1 ? '\0' : alphabet[j];
                        password[4] = i == -1 ? '\0' : alphabet[i];

                        if (check(hashed, password))
                        {
                            return password;
                        }
                    }
                }
            }
        }
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack <hash>\n");
        return 1;
    }

    char *hashed = argv[1];

    char *password = crack(hashed, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLNOPQRSTUVWXYZ");

    if (password == NULL)
    {
        printf("could not decrypt\n");
        return 1;
    }

    printf("%s\n", password);
}