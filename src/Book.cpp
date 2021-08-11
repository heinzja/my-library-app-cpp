#include "book.h"

//public

// private
std::string title = "default";
std::string description = "default";
std::string contents = "default";
bool checked_out = false;

// public
Book::Book(std::string new_title, std::string description, std::string contents)
{
    std::cout << "new_title: " << new_title << std::endl;
    std::cout << "new_title.length: " << new_title.length() << std::endl;
    std::cout << "new_title.size: " << new_title.size() << std::endl;

    std::cout << "title: " << this->title << std::endl;

    std::string str = new_title;
    std::cout << str << std::endl;
    if (new_title.length() > 0 && new_title.length() <= max_title_length)
    {
        this->title = str;
        std::cout << "string > 0 && string <= " << max_title_length << " -> " << str << this->title << std::endl;
    } else {
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

        // throw error
        throw std::invalid_argument("Error: set_title() -> title.length()");
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

        // throw error
        throw std::invalid_argument("Error: set_description() -> description.length()");
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
        // throw error
        throw std::invalid_argument("Error: set_contents() -> contents.length()");
    }
}

void Book::set_checkout_status(bool new_checkout_status)
{
    this->checked_out = new_checkout_status;
}

// private