# Problem: Primes
## tl;dl
Implement a program that calculates all primes below a number.
```
./primes
n: 10
2,3,5,7
```
## Background
For a number to be prime, it must not be divisible by all numbers below it. In programming terms, for any prime number n, 
n%a must not be zero for a in all numbers below n.

## Specification
In `primes.c` in `~chapter1/primes`, write a program that prompts a user for a number n and then
reports (via `printf`) a comma separated list of all primes below that number.