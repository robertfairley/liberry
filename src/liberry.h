#ifndef H_LIBERRY

#include <unistd.h>

/** Default Values */
#define ID_PREFIX               "book_"

#define RECORDS_BUFFER          30
#define NOTE_BUFFER             20
#define MAXIMUM_RECORDS         300
#define MAXIMUM_GENRES          20

#define MAXIMUM_TITLE_LENGTH    50
#define MAXIMUM_AUTHOR_LENGTH   50
#define MAXIMUM_TYPE_LENGTH     20
#define MAXIMUM_SUBJECT_LENGTH  100
#define MAXIMUM_SYNOPSIS_LENGTH 280
#define MAXIMUM_NOTE_LENGTH     1000

/** Macros */
#define LEN_A(x)  (sizeof(x) / sizeof(x[0]))

/** Book definitions and declarations */
typedef struct Notes
{
        char *note;
} Notes;

typedef struct book
{
        int   id;
        int   n_capacity;

        char  *title;
        char  *author;
        char  *type;
        char  *subject;
        char  *synopsis;

        Notes *notes;
} book;

typedef struct book book;

book *Book (void)
{
        book *bk       = malloc(sizeof(book));
        bk->title      = "";
        bk->author     = "";
        bk->type       = "";
        bk->subject    = "";
        bk->synopsis   = "";
        bk->n_capacity = NOTE_BUFFER;
        bk->notes      = malloc(bk->n_capacity * sizeof(Notes));
        bk->id         = 0;

        return bk;
}

/** Library Collection definitions and declarations */
typedef struct collection
{
        //TODO: Add libary midterm storage?
        size_t capacity;
        size_t size;
        book   *data;
} collection;

typedef struct collection collection;

collection *Library (void)
{
        collection *c = malloc(sizeof(collection));
        c->capacity   = RECORDS_BUFFER;
        c->size       = 0;
        c->data       = malloc(c->capacity * sizeof(book));
        return c;
}

/** General Utility Functions */
void clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J\r\n";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

int getInput(char *buf, char *msg, size_t size)
{
        int c, x;

        if (msg != NULL) {
                printf("%s ", msg);
                fflush (stdout);
        }
        
        if (fgets (buf, size, stdin) == NULL)
                return 2;

        if (buf[strlen(buf)-1] != '\n') {
                x = 0;
                while (((c = getchar()) != '\n') && (c != EOF))
                        x = 1;
                return (x == 1) ? 2 : 0;
        }

        buf[strlen(buf) - 1] = '\0';

        return 0;
}

char *clearInputBuffer(char *buf)
{
        buf = NULL;
        return buf;
}

#endif
