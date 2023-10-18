/*
Author: Kusuma Murthy
KUID: 3095756
Date Created: 10/14/2023
Lab: Lab 5, Program 1
Last modified: 10/18/2023
Purpose: To write a program that reads into a file and provides the user a sales report
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Key_Value // initializing a dictionary
{
    char key[100];
    double value;
};

struct Key_Value month_sales[12]; // creates an empty dictionary called month_sales

// This method creates a dictionary where the months are the key names, and the sales number is the value
// This method also reads into the file containing the sales numbers
void create_dictionary()
{
    FILE *sales = fopen("problem_1_input.txt", "r");

    char mySales[100];
    const char *months[] = {"January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    int i = 0;
    while (fgets(mySales, sizeof(mySales), sales) && (i < 12))
    {
        float sale_num = atof(mySales);
        strcpy(month_sales[i].key, months[i]);
        month_sales[i].value = sale_num;
        i++;
    }
    fclose(sales);
}

// This method prints the monthly sales report
void print_monthly_sales_report()
{
    printf("Monthly Sales Report for 2022: \n");
    printf("\n");
    printf("%-10s %s\n", "Month", "Sales");
    printf("\n");

    for (int i = 0; i < 12; i++)
    {
        printf("%-10s $%.2f\n", month_sales[i].key, month_sales[i].value);
    }
}

// This method prints the sales summary
void print_sales_summary()
{
    float max_sales = month_sales[0].value, min_sales = max_sales, avg_sales = 0, total_sales = 0;
    char max_month[100], min_month[100];

    printf("Sales Summary \n");
    printf("\n");

    for (int i = 0; i < 12; i++)
    {
        if (month_sales[i].value > max_sales)
        {
            max_sales = month_sales[i].value;
            strcpy(max_month, month_sales[i].key);
        }

        if (month_sales[i].value <= min_sales)
        {
            min_sales = month_sales[i].value;
            strcpy(min_month, month_sales[i].key);
        }

        total_sales += month_sales[i].value;
    }

    avg_sales = total_sales / 12;

    printf("Minimum sales: $%.2f (%s)\n", min_sales, min_month);
    printf("Maximum sales: $%.2f (%s)\n", max_sales, max_month);
    printf("Average sales: $%.2f\n", avg_sales);
}

// This function calculates and prints the six month moving average report
void print_six_month_report()
{
    char max_month[100], min_month[100];
    float avg_sales = 0;

    printf("Six-Month Moving Average Report:\n");
    printf("\n");
    for (int i = 0; i <= 6; i++)
    {
        float total_sales = 0;
        for (int j = i; j <= (5 + i); j++)
        {
            total_sales += month_sales[j].value;
        }
        avg_sales = total_sales / 6;
        printf("%-10s - %-10s $%.2f\n", month_sales[i].key, month_sales[i + 5].key, avg_sales);
    }
}

// This method prints the sales report in order of highest slaes to the lowest sales
void print_high_to_low()
{
    float temp_value;

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (month_sales[i].value > month_sales[j].value)
            {
                // perfroms the actions on the value pairs
                temp_value = month_sales[i].value;
                month_sales[i].value = month_sales[j].value;
                month_sales[j].value = temp_value;

                // performs the actions on the key pairs
                struct Key_Value temp_month;
                strcpy(temp_month.key, month_sales[i].key);
                strcpy(month_sales[i].key, month_sales[j].key);
                strcpy(month_sales[j].key, temp_month.key);
            }
        }
    }

    printf("Sales Report (Highest to Lowest):\n");
    printf("\n");
    printf("%-10s %-10s\n", "Month", "Sales");
    printf("\n");

    for (int i = 0; i < 12; ++i)
    {
        printf("%-10s: $%-10.2f\n", month_sales[i].key, month_sales[i].value);
    }
}

// this is the main methos with call of the the methods created above and clculates and prints the results
int main()
{
    create_dictionary();
    print_monthly_sales_report();
    printf("\n");
    printf("\n");
    print_sales_summary();
    printf("\n");
    printf("\n");
    print_six_month_report();
    printf("\n");
    printf("\n");
    print_high_to_low();
    return 0;
}