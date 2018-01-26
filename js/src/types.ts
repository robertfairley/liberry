export type JSON = object[];

export namespace Book
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