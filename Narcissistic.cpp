//Narcissistic Numbers
#include<iostream>

int n_digits (int);    //Number of digits
int divisor_s (int); 
int powers (int,int);  //Same as 'pow(base,exponent)'

int main ()
{
    int number,n_digit,divisor,check;
    std :: cout << "Enter the number\n";
    std :: cin >> number;
    check = number;
    n_digit = n_digits(number);
    divisor = divisor_s(n_digit); 
    int numbers[n_digit] = {0};
    for (int n = 0; n < n_digit; n++)
    {
        numbers[n] = number / divisor;
        number = number % divisor;
        divisor = divisor / 10;
    }
    for (int n = 0; n < n_digit; n++)
    {
        numbers[n] = powers(numbers[n],n_digit);
    }
    int result = 0;
    for (int n = 0; n < n_digit; n++)
    {
        result = result + numbers[n];
    }
    if (result == check) std :: cout << check << " is a Narcissistic Number.\n";
    else std :: cout << check << " is not a Narcissistic Number.\n";
    return 0;
}

int powers(int input,int power)
{
    int result = input;
    for (int i = power; i > 1; i--)
    {
        result = result * input;
    }
    return result;
}

int divisor_s(int n_digits)
{
    int result = 1;
    for (int i = 1; i < n_digits; i++ )
    {
        result = result * 10;
    }
    return result;
}

int n_digits (int number)
{
    int n_digit;
    for (n_digit = 0 ; number > 0 ; n_digit++)
    {
        number = number / 10;
    }
    return n_digit;
}