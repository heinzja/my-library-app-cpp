#include "book.h"

//public

// private
std::string title = "default";
std::string description = "default";
std::string contents = "default";
bool checked_out = false;
int max_title_length = 10;
int max_description_length = 100;
int max_contents_length = 100;

// public
Book::Book(std::string title, std::string description, std::string contents)
{
    if (title.length() > 0 && title.length() <= max_title_length)
    {
        this->title = title;
    }
    else
    {
        // throw error
        throw std::invalid_argument("title length error");
    }

    if (description.length() > 0 && description.length() <= max_description_length)
    {
        this->description = description;
    }
    else
    {
        // throw error
        throw std::invalid_argument("description length error");
    }

    if (contents.length() > 0 && contents.length() <= max_contents_length)
    {
        this->contents = contents;
    }
    else
    {
        // throw error
        throw std::invalid_argument("contents length error");
    }
}

std::string Book::get_title()
{
    return this->title;
}

std::string Book::get_description()
{
    return this->description;
}

std::string Book::get_contents()
{
    return this->contents;
}

bool Book::get_checkout_status()
{
    return this->checked_out;
}

void Book::set_title(std::string new_title)
{
    // check new_title length > 0 and <= max_title_length
    if (title.length() > 0 && title.length() <= max_title_length)
    {
        this->title = new_title;
    }
    else
    {
        std::cout << "Error: set_title() -> title.length()" << std::endl;
    }
}

void Book::set_description(std::string new_description)
{
    // check new_description length > 0 and <= max_description_length
    if (description.length() > 0 && description.length() <= max_description_length)
    {
        this->description = new_description;
    }
    else
    {
        std::cout << "Error: set_description() -> description.length()" << std::endl;
    }
}

void Book::set_contents(std::string new_contents)
{
    // check new_contents length > 0 and <= max_contents_length
    if (contents.length() > 0 && contents.length() <= max_contents_length)
    {
        this->contents = new_contents;
    }
    else
    {
        std::cout << "Error: set_contents() -> contents.length()" << std::endl;
    }
}

void Book::set_checkout_status(bool new_checkout_status)
{
    this->checked_out = new_checkout_status;
}

// private