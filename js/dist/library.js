"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const fs = require("fs");
class Library {
    constructor(props) {
        this.database = null;
        this.metadata = {
            "name": "",
            "owner": "",
            "lastUpdated": `${new Date}`,
        };
        this.collection = [];
        this.store = [
            this.metadata,
            {
                "collection": this.collection,
            },
        ];
        this.database = __dirname + props.storeFile;
        fs.readFile(this.database, 'utf8', (err, data) => {
            // Read database and load collection, meta, etc
            let loadStore = JSON.parse(data);
            this.metadata.name = loadStore[0].name;
            this.metadata.owner = loadStore[0].owner;
            this.collection = loadStore[1].collection;
            this.store[0] = this.metadata;
            this.store[1]["collection"] = this.collection;
        });
    }
    addBook(book) {
        let libraryStore = this.store[1]["collection"];
        let canAddBook = false;
        libraryStore.forEach((item) => {
            if (item.id == book.id)
                canAddBook = false;
            // TODO: add ability/option to modify book.
            canAddBook = true;
        });
        if (canAddBook === false) {
            console.error("Cannot add book. Book already exists.");
            return false;
        }
        this.collection.push(book);
        return true;
    }
    removeBook(id) {
        console.log('Not yet implemented.');
        return false;
    }
    lendBook(id) {
        console.log('Not yet implemented');
        return false;
    }
    returnBook(id) {
        console.log('Not yet implemented');
        return false;
    }
    listBooks() {
        let libraryStore = this.store;
        libraryStore[1]["collection"].forEach(item => console.log(item));
    }
    listAllData() {
        let libraryStore = this.store;
        console.log(JSON.stringify(libraryStore, null, 2));
    }
    saveLibraryState() {
        let status = false;
        let writeData = JSON.stringify(this.store, null, 2);
        fs.writeFile(this.database, writeData, //data
        null, //options
        (err) => {
            if (err) {
                throw new Error(err.message);
            }
        });
        status = true;
        return status;
    }
}
exports.default = Library;
