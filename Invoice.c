#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "Invoice.h"

InvoiceEntry *createNewInvoice()
{
    ///Create pointer for new invoice, and allocate memory
    InvoiceEntry *newInvoice = NULL;
    newInvoice = malloc(sizeof(InvoiceEntry));

    ///Check if the memory was allocated
    if(newInvoice == NULL)
    {
        printf("Error allocating memory\n");
        return NULL;
    }

    ///Get Invoice Data From User
    bool validNameEntry = false;
    bool validOrderSize = false;
    bool validItemName = false;
    bool validItemAmount = false;
    bool validItemPrice = false;

    ///Get Customer Name
    do{
        printf("Enter customer name: ");
        fgets(newInvoice->customer, sizeof(newInvoice->customer), stdin);
        fflush(stdin);

        ///Gets the length of the name without '\0' character. Checks if a string was introduced.
        validNameEntry = strlen(newInvoice->customer) - 1 >= 1;

        if(!validNameEntry) printf("Invalid Name! (Too short)\n");
    }
    while(!validNameEntry);


    ///Get Number of Items in Order
    do{
        printf("Amount of Items purchased: ");
        scanf("%d", &(newInvoice->orderSize));
        fflush(stdin);
        validOrderSize = newInvoice->orderSize >= 1 && newInvoice->orderSize <= 50;
        if(!validOrderSize) printf("Not Valid Number of Items!\n");
    }
    while(!validOrderSize);

    ///Create array for items
    ///Allocate memory needed based on amount of items
    newInvoice->items = malloc(newInvoice->orderSize * sizeof(*(newInvoice->items)) );

    if(newInvoice->items == NULL)
    {
        printf("Error Allocating Memory for Items Array\n");
        return NULL;
    }

    ///Loop the item array and add items
    for(int i = 0; i < newInvoice->orderSize; i++)
    {
        Item *item = newInvoice->items+i;

        ///Product Name
        do{
            printf("Introduce product name: ");
            fgets(item->product, 50, stdin);
            fflush(stdin);
            validItemName = strlen(item->product) - 1 >= 3;
            if(!validItemName) printf("Invalid Product Name!\n");
        }
        while(!validItemName);

        ///Handle 'linebreak' that come with fgets()
        item->product[strcspn(item->product,"\n")] = 0;

        ///Item Amount
        do{
            printf("Number of %s: ", item->product);
            scanf("%d", &(item->amount));
            fflush(stdin);

            validItemAmount = item->amount >= 1 && item->amount <=99;
            if(!validItemAmount) printf("Invalid Item Amount!\n");
        }
        while(!validItemAmount);

        ///Item Unit Price
        do{
            printf("Unit Price: ");
            scanf("%f", &(item->unitPrice));
            fflush(stdin);
            validItemPrice = item->unitPrice > 0;
            if(!validItemPrice) printf("Invalid Unit Price\n");
        }
        while(!validItemPrice);
    }


    for(int i = 0; i < newInvoice->orderSize; i++)
    {
        Item *item = newInvoice->items+i;

        printf("| Item %2d | Name: %20s | Amount %3d | Unit Price %5.2f |\n",
               i+1,
               item->product,
               item->amount,
               item->unitPrice);
    }

    newInvoice->next = NULL;
    return newInvoice;
}

void printInvoice(InvoiceEntry *invoice)
{
    printf("FOUND\n");
    return;
}
