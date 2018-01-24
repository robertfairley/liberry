/**
 * util.c
 *
 * Utility functions for the library collection itself
 *
 */

#include <assert.h>
#include <stdio.h>

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
void listLibrary(collection *this)
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
                        if (( (int)LEN_A( this->data[i].notes ) != 0 ))
                                        printf("NOTES: Y");
                        else
                                        printf("NOTES: N");
                        printf("- - - - - - - - - - - - -");
                }
        }

}