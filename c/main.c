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

int main(void)
{
  collection *l = Library();
  int selection;

  clear_screen();

  // TODO: Add a proper menu function to offer task choices.

  L_MENU:
  printf("\r\n\t\tLIBERRY!\n");
  printf("\t======================\r\n");
  printf("\t1. Add a Book\n");
  printf("\t2. List Inventory\n");
  printf("\t3. Exit\n\n");
  selection = getchar();

  switch(selection) {
    case 49:
      clear_screen();
      add_book(l);
      goto L_MENU;
    case 50:
      if (l->size == 0) {
        clear_screen();
        printf("Library is empty.\n");
        goto L_MENU;
      }
      else {
        clear_screen();
        list_library(l);
        printf("\n[ Press return when finished ]\r\n");
        getchar();
        goto L_MENU;
      }
      break;
    case 51:
      printf("Exiting...\r\n");
      break;
    default:
      clear_screen();
      printf("You entered %d\r\n", selection);
      printf("Your selection was out of bounds.\n");
      printf("Exiting...\r\n");
      break;
  }

  return 0;
}
