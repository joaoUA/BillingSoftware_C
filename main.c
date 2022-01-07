#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Menu.h"
#include "Invoice.h"

InvoiceEntry *getLastInvoice(InvoiceEntry *head);

int main()
{

    /**
    TODO
    MOVE INVOICE STRUCTS AND FUNCTIONS TO THEIR OWN HEADER AND C FILES

    FINISH ABILITY TO ADD INVOICES
    ADD SEARCH METHOD
    ADD METHOD TO SHOW ALL INVOICES
    ADD METHOD TO EXIT APP
    */

    ///LINKED LIST
    InvoiceEntry *head = NULL;
    InvoiceEntry *tail = NULL;

    ///MENU
    int option;

    ///Program Loop
    showMenu();
    validateUserOptionInput(&option);

    switch(option)
    {
        case 1:
            if(head == NULL) head = createNewInvoice();
            else getLastInvoice(head)->next = createNewInvoice();

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

InvoiceEntry *getLastInvoice(InvoiceEntry *head)
{
    InvoiceEntry *current = head;

    while(current!=NULL)
    {
        if(current->next != NULL) current=current->next;
        else return current;
    }
    return current;
}

