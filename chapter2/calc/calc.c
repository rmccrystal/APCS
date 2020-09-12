#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

typedef enum
{
    Add,
    Subtract,
    Multiply,
    Divide,
    Mod,
} Operator;

double calculate(float num1, float num2, Operator operator);

int main(int argc, char *argv[])
{
    float num1, num2;
    Operator operator;

    // Check if there is the right amount of args
    if (argc != 4)
    {
        printf("Not enough arguments, only got %d. Usage: ./calc <num1> <operator> <num2>\n", argc);
        return 1;
    }

    // TODO: Make this account for errors
    num1 = atof(argv[1]);
    num2 = atof(argv[3]);

    // Get the first element of the second argument
    switch (argv[2][0])
    {
        case '+':
            operator = Add;
            break;
        case '-':
            operator = Subtract;
            break;
        case 'x':
            operator = Multiply;
            break;
        case '/':
            operator = Divide;
            break;
        case '%':
            operator = Mod;
            break;
        default:
            printf("%c is not a valid operator. Use [+,-,*,/]\n", argv[2][0]);
            return 1;
    }

    double result = calculate(num1, num2, operator);

    printf("%f\n", result);
}

double calculate(float num1, float num2, Operator operator)
{
    int rem;

    switch (operator)
    {
        case Add:
            return num1 + num2;
        case Subtract:
            return num1 - num2;
        case Multiply:
            return num1 * num2;
        case Divide:
            return num1 / num2;
        case Mod:
            // Take mod of floating point numbers
            // Source: https://docs.cs50.net/2019/ap/problems/calc/calc.html#the-mod-squad
            rem = (int) (num1 / num2);
            return num1 - (num2 * (float) rem);
        default:
            // We should never be here as we already sanitized the operator in main
            printf("Encountered an unknown operator\n");
            return 1;
    }
}
