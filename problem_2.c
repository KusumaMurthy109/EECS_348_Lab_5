/*
Author: Kusuma Murthy
KUID: 3095756
Date Created: 10/14/2023
Lab: Lab 5, Program 2
Last modified: 10/18/2023
Purpose: To write a program that reads into a file and provides the user a sales report
*/
#include <stdio.h>

// This method prints out the differnet combinatiosn for the score
void points(int input_value)
{
    const int td_conversion = 8;
    const int td_field = 7;
    const int td = 6;
    const int fg = 3;
    const int s = 2;
    for (int i = 0; i < (input_value / td_conversion); i++)
    {
        for (int j = 0; j < (input_value / td_field); j++)
        {
            for (int k = 0; k < (input_value / td); k++)
            {
                for (int l = 0; l < (input_value / fg); l++)
                {
                    for (int m = 0; m < (input_value / s); m++)
                    {
                        if (((8 * i) + (7 * j) + (6 * k) + (3 * l) + (2 * m)) == input_value)
                        {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety \n", i, j, k, l, m);
                        }
                    }
                }
            }
        }
    }
}

// this method mainly interacts with the user as it asks for an input, gives an output, and it runs the while loop until the user inputs a 0 or 1
int main()
{
    int input_value;
    while (1)
    {
        printf("Enter 0 or 1 to STOP");
        printf("\nEnter the NFL Score: ");
        scanf("%d", &input_value);
        if (input_value == 0 || input_value == 1)
        {
            printf("Program stopped\n");
            break;
        }
        else if (input_value < 0)
        {
            printf("Invalid input try again\n");
        }
        else
        {
            points(input_value);
        }
    }
    return 0;
}