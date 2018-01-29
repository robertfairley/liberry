import { JSON } from '../types'
//import { IBook } from './book'

export interface ILibraryProps
{
  storeFile : string | null;
}

export interface ILibrary
{
  metadata   : object;
  collection : JSON;
  database   : string;
}
