import { Book } from '../types'

export interface IBook
{
  id       : Book.id       | null;
  isbn     : Book.isbn     | null;
  title    : Book.title    | null;
  author   : Book.author   | null;
  genre    : Book.genre    | null;
  synopsis : Book.synopsis | null;
  notes    : Book.notes    | null;
  lent     : Book.lent     | null;
}

