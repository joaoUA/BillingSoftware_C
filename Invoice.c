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
        printf("%-35s","Enter customer name: ");
        fgets(newInvoice->customer, sizeof(newInvoice->customer), stdin);
        newInvoice->customer[strcspn(newInvoice->customer, "\n")] = 0;
        fflush(stdin);

        ///Gets the length of the name without '\0' character. Checks if a string was introduced.
        validNameEntry = strlen(newInvoice->customer) - 1 >= 1;

        if(!validNameEntry) printf("Invalid Name! (Too short)\n");
    }
    while(!validNameEntry);


    ///Get Number of Items in Order
    do{
        printf("\n");
        printf("%-35s", "Amount of Items purchased: ");
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
            printf("\n");
            printf("%-35s","Introduce product name: ");
            fgets(item->product, 50, stdin);
            fflush(stdin);
            validItemName = strlen(item->product) - 1 >= 3;
            if(!validItemName) printf("Invalid Product Name!\n");
        }
        while(!validItemName);

        ///Handle 'linebreak' that come with fgets()
        item->product[strcspn(item->product,"\n")] = 0;

        ///Item Unit Price
        do{
            printf("%-35s","Introduce the unit Price: ");
            scanf("%f", &(item->unitPrice));
            fflush(stdin);
            validItemPrice = item->unitPrice > 0;
            if(!validItemPrice) printf("Invalid Unit Price\n");
        }
        while(!validItemPrice);

        ///Item Amount
        do{
            printf("%-35s","Introduce the amount: ");
            scanf("%d", &(item->amount));
            fflush(stdin);

            validItemAmount = item->amount >= 1 && item->amount <=99;
            if(!validItemAmount) printf("Invalid Item Amount!\n");
        }
        while(!validItemAmount);

    }

    printInvoice(newInvoice);

    newInvoice->next = NULL;
    return newInvoice;
}

void printInvoice(InvoiceEntry *invoice)
{
    float total = 0;
    printf("%50s","\nRESTAURANT\n");

    printf("Invoice to: %s\n", invoice->customer);
    printf("%50s", "--------------------------------------------------");
    printf("\n%-20s%-15s%-15s", "Items", "Qty", "Total");
    printf("\n\n");


    for(int i = 0; i < invoice->orderSize; i++)
    {
        printf("%-20s%-15d%-15.2f\n",
               invoice->items[i].product,
               invoice->items[i].amount,
               invoice->items[i].amount * invoice->items[i].unitPrice);
        total += invoice->items[i].amount * invoice->items[i].unitPrice;
    }

    printf("\n");
    printf("%50s", "--------------------------------------------------");
    printf("\n");
    printf("%-44s%6.2f\n", "SubTotal", total);
    printf("%-44s%6.2f\n", "Discount @10%", total * 0.10);
    total -= total * 0.10;
    printf("%50s", "------");
    printf("\n");
    printf("%-44s%6.2f\n", "Net Total", total);
    printf("%-44s%6.2f\n", "CGST @9%",total * 0.09);
    printf("%-44s%6.2f\n","SGST @9%", total * 0.09);
    total -= total * 0.09 * 0.09;
    printf("%50s", "--------------------------------------------------");
    printf("\n");
    printf("%-44s%6.2f\n", "Grand Total", total);

    printf("\n");
    return;
}
