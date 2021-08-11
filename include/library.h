#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

#include <iostream>
#include <map>
#include <iterator>
#include <string>
#include "book.h"

class Library
{
public:
    Library();
    void Library::add_book(Book book);
    void Library::remove_book(std::string book_title);
    void Library::checkout_book(std::string book_title);
    void Library::return_book(std::string book_title);
    void Library::preview_book(Book book);
    void Library::display_available_books();

private:
    std::map<std::string, Book> database;
    int get_database_size();
};

#endif