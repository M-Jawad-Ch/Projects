//Author: Muhammad Jawad Chaudhary

#include<iostream>
#include<math.h>

/*
* This programs checks whether a number is prime or not using the concept that the smallest prime factor of a number
* is less than or equal to the square root of the number.
* Thus we can check whether a number is prime or not in a very efficent way.
*/

int primer(int);                        //This function is the main function
bool divisibility_check(int,int);       //This returns true if the first number is divisible to the second
int index_returner(int*,int,int);       //This will return the index of the number which is larger than the second enterd number

int main()
{
    int number = 179424673;            //10 millionth prime number
    if(number % 2 == 0)
    {
        std :: cout << number << " is not a prime number\n";
        return 0;
    }
    primer(number);
}

int primer(int number)
{
    int square_root = sqrt(number);
    int primes[square_root] = {3};      //array of all the prime numbers less than and equal to the square root of the orignal number
    int nthprime = 0;
    int size = sizeof(primes)/sizeof(primes[0]);
    bool x;
    for(int i = 3; i <= square_root; i += 2)
    {
        x = true;
        if(divisibility_check(number,primes[nthprime]))
        {
            std :: cout << number << " is not a prime number\n";
            return 0;
        }
        for(int j = 0; j < index_returner(primes,sqrt(i),size); j++)
        {
            if(divisibility_check(i,primes[j]))
            {
                x = false;
                break;
            }
        }
        if(x == true)
        {
            nthprime++;
            primes[nthprime] = {i};
        }
    }
    std :: cout << number << " is a prime number\n";
}
bool divisibility_check(int number,int divisor)
{
    if( number % divisor == 0) return true;
    else return false;
}
int index_returner(int primes[],int number,int size)
{
    for(int i = 0; i < size; i++)
    {
        if(number < primes[i]) return i;
    }
    return -1;
}