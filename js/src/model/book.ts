import { TBookTypes } from '../types'

export interface IBook
{
  id       : TBookTypes.id       | null;
  isbn     : TBookTypes.isbn     | null;
  title    : TBookTypes.title    | null;
  author   : TBookTypes.author   | null;
  genre    : TBookTypes.genre    | null;
  synopsis : TBookTypes.synopsis | null;
  notes    : TBookTypes.notes    | null;
  lent     : TBookTypes.lent     | null;
}
