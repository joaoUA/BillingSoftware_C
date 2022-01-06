#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Menu.h"

struct InvoiceEntries *getNewInvoice();

struct Items{
    char product[50];
    int amount;
    float unitPrice;
};
typedef struct Items Item;

struct InvoiceEntries{
    char customer[50];
    int orderSize;
    struct InvoiceEntries *next;
    Item *items;
};
typedef struct InvoiceEntries InvoiceEntry;

int main()
{

    InvoiceEntry *first = NULL;
    int option;

    ///Program Loop
    showMenu();
    validateUserOptionInput(&option);

    first = getNewInvoice();
    printf("First entry at %p, number of orders %d, next Invoice at %p\n", first, first->orderSize, first->next);

    switch(option)
    {
        case 1:
            ///add invoice
            break;
        case 2:
            ///search invoice
            break;
        case 3:
            ///show all invoices
            break;
        case 4:
            ///exit program
            break;
        default:
            break;
    }

    return 0;
}


InvoiceEntry *getNewInvoice()
{
    ///Create pointer for new invoice, and allocate memory
    InvoiceEntry *newInvoice = NULL;
    newInvoice = malloc(sizeof(InvoiceEntry));
    if(newInvoice == NULL) printf("Error allocating memory!\n");
    else
    {
        bool validNameEntry = false;
        bool validOrderSize = false;
        ///Get Customer Name
        do{

            printf("Enter customer name: ");
            fflush(stdin);
            fgets(newInvoice->customer, sizeof(newInvoice->customer), stdin);
            ///Gets the length of the name without '\0' character. Checks if a string was introduced.
            validNameEntry = strlen(newInvoice->customer) - 1 >= 1;

            if(!validNameEntry) printf("Invalid Name! (Too short)\n");
        }
        while(!validNameEntry);

        ///Get Number of Items in Order
        do{
            printf("Amount of Items purchased: ");
            scanf("%d", &(newInvoice->orderSize));
            validOrderSize = newInvoice->orderSize >= 1 && newInvoice->orderSize <= 50;
            if(!validOrderSize) printf("Not Valid Number of Items!\n");
        }
        while(!validOrderSize);

        ///Create array for items
        newInvoice->items = malloc(newInvoice->orderSize * sizeof(*(newInvoice->items)) );
        if(newInvoice->items == NULL) printf("Error Allocating Memory for Items Array\n");
        else
        {
            ///Progress the array and enter each item
            for(int i = 0; i < newInvoice->orderSize; i++)
            {
                Item *ptr = newInvoice->items+i;
                printf("Introduce product name: ");
                fflush(stdin);
                fgets((newInvoice->items+i)->product, 50, stdin);

                ///Handle line-break that comes with fgets()
                (newInvoice->items+i)->product[strcspn((newInvoice->items+i)->product, "\n")] = 0;

                printf("Number of %s: ", (newInvoice->items+i)->product);
                fflush(stdin);
                scanf("%d", &((newInvoice->items+i)->amount));

                printf("Unit Price: ");
                scanf("%f", &((newInvoice->items+i)->unitPrice));
            }


            for(int i = 0; i < newInvoice->orderSize; i++)
            {
                Item *ptr = newInvoice->items+i;

                printf("| Item %2d | Name: %20s | Amount %3d | Unit Price %5.2f |\n",
                       i+1,
                       ptr->product,
                       ptr->amount,
                       ptr->unitPrice);
            }
        }

        newInvoice->next = NULL;
    }
    return newInvoice;
}
