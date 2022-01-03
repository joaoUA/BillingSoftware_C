#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct InvoiceEntries{
    char product[50];
    int amount;
    double unitPrince;
} InvoiceEntry;

int main()
{
    InvoiceEntry invoice;

    strcpy(invoice.product, "apple");
    invoice.amount = 2;
    invoice.unitPrince = 1.4;

    printf("Invoice Entry:\n%d %s - %.2lf\n",invoice.amount, invoice.product, invoice.unitPrince);

    return 0;
}


void showMenu()
{

}
