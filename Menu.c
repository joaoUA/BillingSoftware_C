#include <stdio.h>
#include "Menu.h"

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
    ///Validate User's Menu Input
    do{
        scanf("%d", pOption);
        fflush(stdin);
        if(*pOption <1 || *pOption > 4) printf("Invalid Menu Option! Pick your Option...\n");
    }
    while(*pOption <1 || *pOption > 4);
}
