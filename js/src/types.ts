export type JSON = object[];

export namespace TBookTypes
{
  export type id       = number;
  export type isbn     = number;
  export type title    = string;
  export type author   = string;
  export type genre    = string;
  export type synopsis = string;
  export type notes    = JSON;
  export type lent     = boolean;
}

export type TBook = {
  id       : TBookTypes.id,
  isbn     : TBookTypes.isbn,
  title    : TBookTypes.title,
  author   : TBookTypes.author,
  genre    : TBookTypes.genre,
  synopsis : TBookTypes.synopsis,
  notes    : TBookTypes.notes,
  lent     : TBookTypes.lent,
}

export type TMetadata = {
  name        : string;
  owner       : string;
  lastUpdated : string;
};

export type TLibraryStore      = object[];
export type TLibraryMetadata   = TMetadata;
export type TLibraryCollection = TBook[];
