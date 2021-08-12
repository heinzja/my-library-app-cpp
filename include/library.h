#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

#include <iostream>
#include <map>
#include <iterator>
#include <string>
#include <stdexcept>
#include "book.h"

class Library
{
public:
    Library();
    void Library::add_book(Book book);
    void Library::remove_book(std::string book_title);
    void Library::return_book(std::string book_title);
    void Library::preview_book(string book_title);
    void Library::display_available_books();
    Book Library::checkout_book(std::string book_title);

private:
    std::map<std::string, Book> database;
    int get_database_size();
    bool does_book_exist_in_database(string book_title);
};

#endif