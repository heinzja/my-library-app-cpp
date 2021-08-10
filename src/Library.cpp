#include "library.h"

std::map<std::string, Book> database[10];

Library::Library() {

}

//public

void Library::add_book(Book book) {
    this->database->insert({book.get_title(), book});

    std::cout << "Title: " << this->database->at("1").get_title() << " has been added to the Library." << std::endl;
}

void Library::remove_book(std::string book_title) {
    this->database->erase(book_title);
    std::cout << "Title: " << book_title << " has been removed from the Library." << std::endl;

}

void Library::checkout_book(std::string book_title) {
    Book book_to_checkout = this->database->at(book_title);
    
}

void Library::return_book(std::string book_title) {

}

void Library::preview_book(Book book) {

}

void Library::display_available_books(){

}

//private 
int get_database_size(){
    return database->size();
}