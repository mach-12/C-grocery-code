#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int NAME_LENGTH = 10;

// Defining a Data Structure Item
typedef struct
{
    int index;
    int quantity;
    int price;
}
item;

int main()
{
    // Number of store items
    int n;
    printf("Enter number of items in stock: ");
    scanf("%d", &n);


    // Stock is an array n items
    item stock[n];
    char* item_names[n];

    printf("name price quantity\n");

    // Filling the array
    for (int i = 0; i < n; i++)
    {
        // Allocating memory for the name
        item_names[i] = malloc(NAME_LENGTH * sizeof(char));

        // Storing attributes in Struct and Array
        scanf("%s %i %i", item_names[i], &stock[i].price, &stock[i].quantity);
        stock[i].index = i;
    }

    // Printing stock items
    for (int i = 0; i < n; i++)
    {
        printf("('%s', %i, %i)", item_names[stock[i].index], stock[i].price ,stock[i].quantity);
        if (i != n - 1 && n > 0)
            printf(", ");
    }
    printf("\n");

    // Number of store items
    int m;
    printf("\nEnter number of items in bag: ");
    scanf("%d", &m);

    // bag is an array m items
    item bag[m];

    printf("\nname quantity\n");

    // Filling the array
    for (int i = 0; i < m; i++)
    {
        // Allocating memory for the name
        char* bag_item_name = malloc(NAME_LENGTH * sizeof(char));

        // Storing attributes in Struct and Array
        scanf("%s %i", bag_item_name, &bag[i].quantity);

        // pointing bag item to stock item
        for (int j = 0; j < n; j++)
        {
            if (strcmp(bag_item_name, item_names[stock[j].index]) == 0)
            {
                bag[i].index = j;
            }
        }
    }
    printf("\n");

    // Initialising variable to hold data
    int total = 0;
    int missing[m];
    int missing_count = 0;

    // Printing Bill
    printf("Bill: ");
    for (int i = 0; i < m; i++)
    {
        // Loop variables
        int price = stock[bag[i].index].price;
        int quantity_bag = bag[i].quantity;

        // Evaluating total of valid items
        if (stock[bag[i].index].quantity >= bag[i].quantity)
        {
            printf("('%s', %i, %i)", item_names[bag[i].index], price * quantity_bag, quantity_bag);
            if (i != m - 1 && m > 0)
                printf(", ");
            total += price * quantity_bag;
        }
        else
        {
            missing[i] = bag[i].index;
            missing_count++;
        }
    }

    printf("\n\nTotal = %i\n", total);

    // Printing out missing values
    for (int i = 0; i < missing_count; i++)
    {
        if (i == 0)
        {
            printf("\nMissing: ");
            printf("[");
        }

        printf("'%s'", item_names[missing[i]]);
        if (i != missing_count - 1 && missing_count != 1)
            printf(", ");
    }
    printf("]\n");
}
