import * as fs from 'fs'

import { Book } from './book'
import { ILibrary, ILibraryProps } from './model/library'
import { IBook } from './model/book'
import {
  TBook,
  TBookTypes,
  TLibraryStore,
  TLibraryMetadata,
  TLibraryCollection
} from './types'

export default class Library implements ILibrary
{
  database = null;

  metadata   : TLibraryMetadata     =
  {
    "name"        : "",                 // Library Name
    "owner"       : "",                 // Library Owner
    "lastUpdated" : `${new Date}`,      // Date last updated (cast to type string)
  };
  collection : TLibraryCollection   = [];
  store      : TLibraryStore        =
  [
    this.metadata,
    {
      "collection": this.collection,
    },
  ];

  constructor ( props : ILibraryProps )
  {
    this.database = __dirname + props.storeFile;

    fs.readFile(this.database, 'utf8', (err, data) => {
      // Read database and load collection, meta, etc

      let loadStore = JSON.parse(data);

      this.metadata.name  = loadStore[0].name;
      this.metadata.owner = loadStore[0].owner;
      this.collection     = loadStore[1].collection;

      this.store[0]               = this.metadata;
      this.store[1]["collection"] = this.collection;
    });
  }

  addBook ( book : IBook ) : boolean
  {
    let libraryStore : TLibraryStore = this.store[1]["collection"];
    let canAddBook   : boolean = false;

    libraryStore.forEach( ( item : TBook ) => {
      if ( item.id == book.id)
        canAddBook = false;

      // TODO: add ability/option to modify book.

      canAddBook = true;
    });

    if ( canAddBook === false ) {
      console.error("Cannot add book. Book already exists.");
      return false;
    }
    
    this.collection.push( book );

    return true;
  }

  removeBook ( id : TBookTypes.id ) : boolean
  {
    console.log('Not yet implemented.');

    return false;
  }

  lendBook ( id : TBookTypes.id ) : boolean
  {
    console.log('Not yet implemented');

    return false;
  }

  returnBook ( id : TBookTypes.id ) : boolean
  {
    console.log('Not yet implemented');

    return false;
  }

  listBooks () : void
  {
    let libraryStore : TLibraryStore = this.store;

    libraryStore[1]["collection"].forEach( item => console.log(item));
  }

  listAllData () : void
  {
    let libraryStore : TLibraryStore = this.store;

    console.log(JSON.stringify(libraryStore, null, 2));
  }

  saveLibraryState () : boolean
  {
    let status    : boolean = false;
    let writeData : string  = JSON.stringify(this.store, null, 2);

    this.metadata["lastUpdated"] = `${new Date()}`;
    
    this.store[0] = this.metadata;

    fs.writeFile(
      this.database, 
      writeData, //data
      null,       //options
      ( err : NodeJS.ErrnoException ) =>
    {
      if (err) {
        throw new Error(err.message);
      }
    });

    status = true;
    return status;
  }
}