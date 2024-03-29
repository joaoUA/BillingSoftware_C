#ifndef INVOICE_H_INCLUDED
#define INVOICE_H_INCLUDED

typedef struct Items{
    char product[50];
    int amount;
    float unitPrice;
} Item;

typedef struct InvoiceEntries{
    char customer[50];
    int orderSize;
    struct InvoiceEntries *next;
    struct Items *items;
} InvoiceEntry;


InvoiceEntry *createNewInvoice();

void printInvoice(InvoiceEntry *invoice);

#endif // INVOICE_H_INCLUDED
