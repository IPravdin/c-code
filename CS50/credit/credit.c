#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long cc = get_long("Credit card: ");

    //Visa 13 digit card
    int n1 = cc / (pow(10, 11));

    //Amex 15 digit card
    int n2 = cc / (pow(10, 13));

    //Mastercard and Visa digit card
    int n3 = cc / (pow(10, 14));

    //narrow n1, n2, n3 into one variable
    int first_ns;
    if (n1 > 10 && n1 < 100)
    {
        first_ns = (int) n1;
    }
    else if (n2 > 10 && n2 < 100)
    {
        first_ns = (int) n2;
    }
    else //(n3 > 10 && n3 < 100)
    {
        first_ns = (int) n3;
    }

    //defines if cc is Visa, Amex or Mastercard
    if ((first_ns == 34 || first_ns == 37) || (first_ns >= 40 && first_ns <= 49) || (first_ns >= 51 && first_ns <= 55))
    {
        int number;
        int odd_sum = 0;
        int even_sum = 0;
        for (int i = 1; i <= 16; i++)
        {
            //every other digit, starting with the number’s second-to-last digit
            if (i % 2 == 0)
            {
                number = cc % 10;
                cc = cc / 10;

                number *= 2;
                if (number > 9)
                {
                    int a = number % 10;
                    number = number / 10;
                    number = number + a;
                }
                even_sum += number;
            }

            //the rest digits
            else
            {
                number = cc % 10;
                cc = cc / 10;

                odd_sum += number;
            }
        }

        //final sum
        int sum = even_sum + odd_sum;

        //Does the sum end with 0?
        if (sum % 10 == 0)
        {
            first_ns /= 10;
            switch (first_ns)
            {
                case 3:
                    printf("AMEX\n");
                    break;
                case 4:
                    printf("VISA\n");
                    break;
                case 5:
                    printf("MASTERCARD\n");
                    break;
            }
        }
        //if not
        else
        {
            printf("INVALID\n");
        }
    }

    //not Visa, Amex nor Mastercard
    else
    {
        printf("INVALID\n");
    }
}