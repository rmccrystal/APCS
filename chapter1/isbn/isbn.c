#include <cs50.h>
#include <stdio.h>

bool is_valid_isbn(long isbn);

int main(void)
{
    long isbn = get_long("ISBN: ");
    bool valid = is_valid_isbn(isbn);
    printf("%s\n", valid ? "YES" : "NO");
}

/// Returns true if `isbn` is valid, false otherwise
/// Note: isbn must be 10 digits long
bool is_valid_isbn(long isbn)
{
    // get the last digit from the isbn and remove it
    int check_digit = isbn % 10;
    isbn /= 10;

    int sum = 0;

    // iterate from i = 9 to 0
    for (int i = 9; i > 0; --i)
    {
        // Get last digit of isbn
        int digit = isbn % 10;

        // add to the sum
        sum += digit * i;

        // remove the digit
        isbn /= 10;
    }

    int remainder = sum % 11;

    return remainder == check_digit;
}
