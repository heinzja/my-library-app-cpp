#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdexcept>

using namespace std;

class Book
{
public:
    static const unsigned int max_title_length = 10;
    static const unsigned int max_description_length = 10000;
    static const unsigned int max_contents_length = 1500000;
    Book(std::string title, std::string description, std::string contents);
    std::string Book::get_title();
    std::string Book::get_description();
    std::string Book::get_contents();
    bool Book::get_checkout_status();
    void Book::set_title(std::string new_title);
    void Book::set_description(std::string new_description);
    void Book::set_contents(std::string new_contents);
    void Book::set_checkout_status(bool new_checkout_status);
private:
    std::string title;
    std::string description;
    std::string contents;
    bool checked_out;

};

#endif