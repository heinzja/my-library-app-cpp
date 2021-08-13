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
    void Library::preview_book(std::string book_title);
    void Library::display_available_books();
    void Library::display_checked_out_books();
    void Library::checkout_book(std::string book_title);

private:
    std::map<std::string, Book> database;
    std::map<std::string, Book> checked_out_database;
    int Library::get_database_size();
    bool Library::does_book_exist_in_database(std::string book_title);
};

#endif