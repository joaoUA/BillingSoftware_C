#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Menu.h"
#include "Invoice.h"

InvoiceEntry *getLastInvoice(InvoiceEntry *head);
void searchMatchingInvoice(char *customerName, InvoiceEntry *head);
void showAllInvoices(InvoiceEntry *head);

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

    ///MENU
    int option;
    char searchName[50];

    ///Program Loop
    do{
        system("cls");
        showMenu();
        validateUserOptionInput(&option);

        switch(option)
        {

            case 1:
                system("cls");
                if(head == NULL) head = createNewInvoice();
                else getLastInvoice(head)->next = createNewInvoice();

                break;
            case 2:
                ///search invoice
                do{
                    printf("Enter Customer Name: ");
                    fgets(searchName, 50, stdin);
                    searchName[strcspn(searchName, "\n")] = 0;
                }
                while(strlen(searchName) - 1 < 3);
                searchMatchingInvoice(searchName, head);
                break;
            case 3:
                ///show all invoices
                showAllInvoices(head);
                break;
            case 4:
                exit(0);
                break;
            default:
                break;
        }
        system("pause");
    }
    while(option != 4);

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

void searchMatchingInvoice(char *customerName, InvoiceEntry *head)
{
    InvoiceEntry *current = head;

    while(current != NULL)
    {
        if(strcmp(customerName, current->customer) == 0)
        {
            printInvoice(current);
        }

        current = current->next;
    }
}

void showAllInvoices(InvoiceEntry *head)
{
    InvoiceEntry *current = head;

    while(current != NULL)
    {
        printInvoice(current);

        current = current->next;
    }
}
