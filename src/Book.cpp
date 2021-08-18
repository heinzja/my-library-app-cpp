#include "book.h"

//public

// private
string title = "default";
string description = "default";
string contents = "default";
bool checked_out = false;

// public

// Book init
Book::Book(string new_title, string new_description, string new_contents)
{
    set_title(new_title);
    set_description(new_description);
    set_contents(new_contents);
    set_checkout_status(false);
}

// basic getter to return book title
string Book::get_title()
{
    return this->title;
}

// basic getter to return book description
string Book::get_description()
{
    return this->description;
}

// basic getter to return book contents
string Book::get_contents()
{
    return this->contents;
}

// basic getter to return book checkout status
bool Book::get_checkout_status()
{
    return this->checked_out;
}

// basic setter to update book title
// throws invalid_argument if the title length is 0 or greater than MAX_TITLE_LENGTH
void Book::set_title(string new_title)
{
    if (new_title.length() > 0 && new_title.length() <= MAX_TITLE_LENGTH)
    {
        this->title = new_title;
    }
    else
    {
        throw invalid_argument("Error: Title Length");
    }
}

// basic setter to update book description
// @throws invalid_argument if the books description is 0 or greater than MAX_DESCRIPTION_LENGTH
void Book::set_description(string new_description)
{
    if (new_description.length() > 0 && new_description.length() <= MAX_DESCRIPTION_LENGTH)
    {
        this->description = new_description;
    }
    else
    {
        throw invalid_argument("Error: Description Length");
    }
}

// basic setter to update book contents
// @throws invalid_argument if book contents length is 0 or is greater than MAX_TITLE_LENGTH
void Book::set_contents(string new_contents)
{
    if (new_contents.length() > 0 && new_contents.length() <= MAX_CONTENTS_LENGTH)
    {
        this->contents = new_contents;
    }
    else
    {
        throw invalid_argument("Error: set_contents() -> contents.length()");
    }
}

// basic setter to update book checkout status
void Book::set_checkout_status(bool new_checkout_status)
{
    this->checked_out = new_checkout_status;
}

// private