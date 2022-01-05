#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void showMenu();
void validateUserOptionInput(int* pOption);

typedef struct InvoiceEntries{
    char product[50];
    int amount;
    double unitPrince;
} InvoiceEntry;

int main()
{
    InvoiceEntry invoice;
    InvoiceEntry invoices[];
    int option;

    showMenu();
    validateUserOptionInput(&option);

    switch(option)
    {
        case 1:
            ///add invoice
            break;
        case 2:
            ///search invoice
            break;
        case 3
            ///show all invoices
            break;
        case 4
            ///exit program
            break;
        default:
            break;
    }

    printf("Invoice Entry:\n%d %s - %.2lf\n",invoice.amount, invoice.product, invoice.unitPrince);

    return 0;
}


void showMenu()
{
    printf("*************************\n");
    printf("    Menu\n");
    printf("-------------------------\n");
    printf(" 1. Add Invoice\n");
    printf(" 2. Search Invoice\n");
    printf(" 3. Show All Invoices\n");
    printf(" 4. Exit\n");
    printf("-------------------------\n");
    printf(" Pick your option...\n");
    printf(".........................\n");
}

void validateUserOptionInput(int* pOption)
{
    bool invalidOption = true;
    do{
        scanf("%d", pOption);
        invalidOption = (*pOption <1 || *pOption > 4);

        if(invalidOption) printf("Invalid Menu Option! Pick your Option...\n");
    }
    while(invalidOption);
}
