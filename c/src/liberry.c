/**
 *  liberry.c
 *    Program-wide helper/utility functions
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liberry.h"

/**
 * clearScreen:
 *  Clear the terminal window for redraw
 */
void clear_screen(void)
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J\r\n";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

/**
 * getInput:
 *  Get input from STDIN to a buffer.
 *  Prevent potential buffer overflow via input.
 * 
 *  char   *buf  : Buffer to write to
 *  char   *msg  : Prompt message displayed before input
 *  size_t  size : Size of input
 */
int get_input(char *buf, char *msg, size_t size)
{
  int character, expect;

  if (msg != NULL) {
    printf("%s ", msg);
    fflush (stdout);
  }

  if (fgets (buf, size, stdin) == NULL)
    return 2;

  if (buf[strlen(buf)-1] != '\n') {
    expect = 0;
    while (((character = getchar()) != '\n') && (character != EOF))
            expect = 1;
    return (expect == 1) ? 2 : 0;
  }

  buf[strlen(buf) - 1] = '\0';

  return 0;
}

/**
 * clearInputBuffer:
 *  Empty the buffer to be used again.
 */
void clear_input_buffer(char *buf)
{
  free(buf);
}

/** Generate an internal book entry ID */
int generate_id (void)
{
  int newId;

  srand((unsigned int)__TIME__);
  newId = (rand() % 100);

  return newId;
}

/** Add a book to the collection. Prompt for each implemented field */
void add_book(collection *library)
{
  char  c[280];
  book *b           = Book();
  int   buffer_size = sizeof(c);

  b->id = generate_id();

  /** Get the title */
  get_input(c, "Title:", buffer_size);
  b->title = c;
  clear_input_buffer(c);

  /** Get the author */
  get_input(c, "Author:", buffer_size);
  b->author = c;
  clear_input_buffer(c);

  /** Get the type of book */
  get_input(c, "Type of Book:", buffer_size);
  b->type = c;
  clear_input_buffer(c);

  /** Get the subject of the book */
  get_input(c, "Subject of the Book:", buffer_size);
  b->subject = c;
  clear_input_buffer(c);

  /** Get the synopsis of the book */
  get_input(c, "Synopsis of the Book (optional):", buffer_size);
  b->synopsis = c;
  clear_input_buffer(c);

  /** ...notes  */

  /** Add to library */
  push_collection(library, *b);

  clear_screen();

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

/** Check if the collection is full */
int full_collection (collection *this)
{
  return this->capacity == this->size;
}

/** Check if the collection is empty */
int empty_collection (collection *this)
{
  return this->size == 0;
}

/** If the collection is too small to allow the current action,
 * reallocate enough memory to permit it */
void realloc_collection (collection *this)
{
  this->capacity += RECORDS_BUFFER; 
  this->data     = realloc(this->data, (this->capacity * sizeof(this->data)) );
}

/** Add a book to the collection */
void push_collection (collection *this, book bk)
{
  if ( full_collection(this) )
    realloc_collection(this);
  this->data[this->size++] = bk;
}

/** List the contents of the entire collection */
void list_library(collection *this)
{
  int a_len = (int) LEN_A(this->data);
  int i;

  printf("YOUR LIBRARY COLLECTION\n");
  printf("=======================\n");
  if (a_len < 1) {
    fprintf(stderr, "ERROR: No library.\n");
    exit(1);
  }
  else {
    for (i = 0; i < a_len; i++) {
      printf("ID:\t%d", this->data[i].id);
      printf("TITLLE:\t%s", this->data[i].title);
      printf("AUTHOR:\t%s", this->data[i].author);
      printf("TYPE:\t%s", this->data[i].type);
      if (( (int) LEN_A( this->data[i].notes ) != 0 ))
        printf("NOTES: Y");
      else
        printf("NOTES: N");
      printf("- - - - - - - - - - - - -");
    }
  }
}