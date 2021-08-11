#include "library.h"

std::map<std::string, Book> database;

Library::Library() {

}

//public

void Library::add_book(Book book) {
    std::cout << "Adding Book Title: " << book.get_title() << std::endl;

    database.insert(std::make_pair(book.get_title(), book));
    std::cout << "Title: " << database.at(book.get_title()).get_title() << " has been added to the Library." << std::endl;

}

void Library::remove_book(std::string book_title) {
    database.erase(book_title);
    std::cout << "Title: " << book_title << " has been removed from the Library." << std::endl;

}

void Library::checkout_book(std::string book_title) {
    // check if book exists in database
    // switch checkout flag to true
    database.at(book_title).set_checkout_status(true);
}

void Library::return_book(std::string book_title) {
    database.at(book_title).set_checkout_status(false);
}

void Library::preview_book(Book book) {
    std::cout << book.get_title() << std::endl;
    std::cout << book.get_description() << std::endl;
}

void Library::display_available_books(){
    // loop through map displaying title of each book
    std::map<std::string, Book>::iterator it;
    std::cout << "display_available_books" << std::endl;
    std::cout << database.size() << std::endl;
    for (it = database.begin(); it != database.end(); it++)
    {
        std::cout << "display_available_books" << std::endl;
        std::cout << "Title: " << it->first << std::endl;
        std::cout << "Description: " << it->second.get_description() << std::endl;
        std::cout << "" << it->second.get_description() << std::endl;
    }
}

//private 
int get_database_size(){
    return database.size();
}