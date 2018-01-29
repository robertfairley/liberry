"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
class Book {
    constructor() {
        this.id = 0;
        this.isbn = 0;
        this.title = '';
        this.author = '';
        this.genre = '';
        this.synopsis = '';
        this.notes = [];
        this.lent = false;
    }
    setISBN(isbn, cb) {
        if (!isbn) {
            if (cb)
                cb(false);
            return false;
        }
        if (isbn.toString.length > 9 || isbn.toString.length < 9) {
            throw new Error("ISBN must be 9 digits long.");
        }
        this.isbn = isbn;
        if (cb)
            cb(true);
        return true;
    }
    setLentStatus(val, cb) {
        if (!val) {
            if (cb)
                cb(false);
            return false;
        }
        this.lent = val;
        if (cb)
            cb(true);
        return true;
    }
    setTitle(title, cb) {
        if (!title) {
            if (cb)
                cb(false);
            return false;
        }
        this.title = title;
        if (cb)
            cb(true);
        return true;
    }
    setAuthor(author, cb) {
        if (!author) {
            if (cb)
                cb(false);
            return false;
        }
        this.author = author;
        if (cb)
            cb(true);
        return true;
    }
    addNote(subject, content, cb) {
        const newNote = {
            "subject": null,
            "content": null
        };
        if (!subject)
            newNote.subject = "";
        if (!content) {
            throw new Error("Note requires content.\n");
        }
        newNote.subject = subject;
        newNote.content = content;
        this.notes.push(newNote);
        if (cb)
            cb(true);
        return true;
    }
}
exports.Book = Book;
