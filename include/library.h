#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

using namespace std;

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
    void Library::remove_book(string book_title);
    void Library::return_book(string book_title);
    void Library::preview_book(string book_title);
    void Library::display_available_books();
    void Library::display_checked_out_books();
    void Library::read_book(string book_title);
    void Library::checkout_book(string book_title);

private:
    map<string, Book> database;
    map<string, Book> checked_out_database;
    int Library::get_database_size();
    bool Library::does_book_exist_in_database(map<string, Book>* database_to_search, string book_title);
};

#endif