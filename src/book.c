/**
 *  book.c
 *
 *  Functions that help with adding and manipulating
 *  individual book records.
 *
 */
#include <stdio.h>

/** Generate an internal book entry ID */
int generateId (void)
{
        int newId;

        srand((unsigned int)__TIME__);
        newId = (rand() % 100);

        return newId;
}

/** Add a book to the collection. Prompt for each implemented field */
void addBook(collection *library)
{
        book *b = Book();
        char  c[280];           // char buffer
        int   bufSize = sizeof(c);

        b->id = generateId();

        /** Get the title */
        getInput(c, "Title:", bufSize);
        b->title = c;
        clearInputBuffer(c);

        /** Get the author */
        getInput(c, "Author:", bufSize);
        b->author = c;
        clearInputBuffer(c);

        /** Get the type of book */
        getInput(c, "Type of Book:", bufSize);
        b->type = c;
        clearInputBuffer(c);

        /** Get the subject of the book */
        getInput(c, "Subject of the Book:", bufSize);
        b->subject = c;
        clearInputBuffer(c);

        /** Get the synopsis of the book */
        getInput(c, "Synopsis of the Book (optional):", bufSize);
        b->synopsis = c;
        clearInputBuffer(c);

        /** ...notes  */

        /** Add to library */
        push_collection(library, *b);

        clearScreen();

        printf(" ~ ~ ~ ~ ~ ~ ~ ~ ~ \n");
        printf("ID:\t%d\n", b->id);
        printf("TITLE:\t%s\n", b->title);
        printf("AUTHOR:\t%s\n", b->author);
        printf("TYPE:\t%s\n", b->type);
        printf("SUBJECT:\t%s\n", b->subject);
        printf("SYNOPSIS:\t%s\n", b->synopsis);
        printf(" ~ ~ ~ ~ ~ ~ ~ ~ ~ \n");

        printf("\nBook was added to your library.\r\n");
}

