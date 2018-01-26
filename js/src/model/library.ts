import { JSON } from '../types'
import { IBook } from './book'

export interface ILibrary
{
  metadata   : object;
  collection : JSON;
}
