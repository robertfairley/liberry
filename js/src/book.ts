import { IBook } from './model/book'
import { Book } from './types'

class Book implements IBook
{
  id       = 0;
  isbn     = 0;
  title    = '';
  author   = '';
  genre    = '';
  synopsis = '';
  notes    = [];
  lent     = false;

  setISBN ( isbn : Book.isbn, cb? : any ) : boolean
  {
    if ( !isbn ) {
      if ( cb )
        cb( false );
      return false;
    }

    if ( isbn.toString.length > 9 || isbn.toString.length < 9 ) {
      throw new Error("ISBN must be 9 digits long.");
    }

    this.isbn = isbn;

    if ( cb ) 
      cb( true );

    return true;
  }

  setLentStatus ( val : boolean, cb? : any ) : boolean
  {
    if ( !val ) {
      if ( cb )
        cb( false );
      return false;
    }

    this.lent = val;

    if ( cb )
      cb( true );

    return true;
  }

  setTitle ( title : Book.title, cb? : any ) : boolean
  {
    if ( !title ) {
      if ( cb )
        cb( false );
      return false;
    }

    this.title = title;

    if ( cb )
      cb( true );

    return true;
  }

  setAuthor ( author : Book.author, cb? : any ) : boolean
  {
    if ( !author ) {
      if ( cb )
        cb( false );
      return false;
    }

    this.author = author;

    if ( cb )
      cb( true );

    return true;
  }

  addNote ( subject : string, content : string, cb? : any ) : boolean
  {
    const newNote = {
      "subject": null,
      "content": null
    };

    if ( !subject )
      newNote.subject = "";

    if ( !content ) {
      throw new Error("Note requires content.\n");
    }

    newNote.subject = subject;
    newNote.content = content;

    this.notes.push(newNote);
    if ( cb )
      cb( true );

    return true;
  }


}