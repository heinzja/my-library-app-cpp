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
    static const unsigned int MAX_TITLE_LENGTH = 100;
    static const unsigned int MAX_DESCRIPTION_LENGTH = 10000;
    static const unsigned int MAX_CONTENTS_LENGTH = 1500000;
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