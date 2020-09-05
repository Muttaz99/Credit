//credit

#include <stdio.h>
#include <cs50.h>

//the main function
int main(void)
{
    long num;

    //input credit card number
    do
    {
        num = get_long("Number: ");
    }
    while (num < 1);

    int digit = 0;
    long j = num;

    //count how many digits
    do
    {
        j = j / 10;
        digit++;
    }
    while (j / 100 != 0);
    
    //adding 2 extra digits
    digit += 2;
    
    //variables needed in the algorithm
    int sum1 = 0;
    int sum2 = 0;
    int sum;
    int x;
    long num1 = num;
    long num2 = num;
    
    //Luhn’s Algorithm
    for (int i = 2; i <= digit; i += 2)
    {
        num1 = num1 / 10;
        x = (num1 % 10) * 2;
        
        if (num1 % 10 >= 5)
        {
            sum1 = sum1 + 1 + (x % 10);
        }
        
        else
        {
            sum1 = sum1 + x;
        }
        
        num1 = num1 / 10;
    }
    
    for (int i = 1; i <= 15 ; i += 2)
    {
        sum2 = sum2 + (num2 % 10);
        num2 = num2 / 100;
    }
    
    sum = sum1 + sum2;

    //checking the validity
    if (sum % 10 == 0 && digit == 15 && (j == 34 || j == 37))
    {
        printf("AMEX\n");
    }
        
    else if (sum % 10 == 0 && digit == 16 && (j == 51 || j == 52 || j == 53 || j == 54 || j == 55))
    {
        printf("MASTERCARD\n");
    }
        
    else if (sum % 10 == 0 && (digit == 16 || digit == 13) && j / 10 == 4)
    {
        printf("VISA\n");
    }
        
    else 
    {
        printf("INVALID\n");
    }
}