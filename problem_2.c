#include <stdio.h>

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