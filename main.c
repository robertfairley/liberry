/**
 *      liberry
 *
 *      A library inventory tracking command line application.
 *
 *      TODO: See other inline TODOS
 *      TODO: Add ISBN reference for future interaction
 *      TODO: Add DB store
 *      TODO: Add editing, removal, updates
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/liberry.h"
#include "src/collection.c"
#include "src/book.c"

int main (void)
{
        collection *l = Library();
        int selection;

        clearScreen();

        // TODO: Add a proper menu function to offer task choices.

        L_MENU:
        printf("\r\n\t\tLIBERRY!\n");
        printf("\t======================\r\n");
        printf("\t1. Add a Book\n");
        printf("\t2. List Inventory\n");
        printf("\t3. Exit\n\n");
        selection = getchar();

        switch ( selection ) {
                case 49:
                        clearScreen();
                        addBook(l);
                        goto L_MENU;
                case 50:
                        if (l->size == 0) {
                                clearScreen();
                                printf("Library is empty.\n");
                                goto L_MENU;
                        } else {
                                clearScreen();
                                listLibrary(l);
                                printf("\n[ Press return when finished ]\r\n");
                                getchar();
                                goto L_MENU;
                        }
                        break;
                case 51:
                        printf("Exiting...\r\n");
                        break;
                default:
                        clearScreen();
                        printf("You entered %d\r\n", selection);
                        printf("Your selection was out of bounds.\n");
                        printf("Exiting...\r\n");
                        break;
        }

        return 0;
}
