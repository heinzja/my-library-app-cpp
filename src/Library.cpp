#include "library.h"

using namespace std;
map<string, Book> database;

Library::Library()
{
}

//public

void Library::add_book(Book book)
{
    try
    {
        cout << "Adding Book Title: " << book.get_title() << endl;
        database.insert(make_pair(book.get_title(), book));
        cout << "Title: " << database.at(book.get_title()).get_title() << " has been added to the Library." << endl;
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
}

void Library::remove_book(string book_title)
{
    try
    {
        database.erase(book_title);
        cout << "Title: " << book_title << " has been removed from the Library." << endl;
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
}

void Library::checkout_book(string book_title)
{
    // check if book exists in database
    try
    {
        // check user input
        if (book_title.length() > 0 && book_title.length() <= Book::max_title_length)
        {
            // if title exists in map switch checkout flag to true
            if (database.at(book_title).get_checkout_status() != true)
            {
                database.at(book_title).set_checkout_status(true);
            }
            else
            {
                throw exception("Error: Book Already Checked Out");
            }
        }
        else
        {
            throw invalid_argument("Error: Book Length Error");
        }
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
}

void Library::return_book(string book_title)
{
    // check if book exists in database
    try
    {
        // check user input
        if (book_title.length() > 0 && book_title.length() <= Book::max_title_length)
        {
            // if title exists in map switch checkout flag to true
            if (database.at(book_title).get_checkout_status() != false)
            {
                database.at(book_title).set_checkout_status(false);
            }
            else
            {
                throw exception("Error: Book Already Returned");
            }
        }
        else
        {
            throw invalid_argument("Error: Book Length Error");
        }
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
}

void Library::preview_book(Book book)
{
    try
    {
        cout << book.get_title() << endl;
        cout << book.get_description() << endl;
        cout << endl;
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
}

void Library::display_available_books()
{

    map<string, Book>::iterator it;
    cout << "display_available_books" << endl;
    cout << database.size() << endl;
    // loop through map displaying title of each book
    for (it = database.begin(); it != database.end(); it++)
    {
        cout << "display_available_books" << endl;
        cout << "Title: " << it->first << endl;
        if (it->second.get_checkout_status() == 0)
        {
            cout << "\tChecked Out: false" << endl;
        }
        else
        {
            cout << "\tChecked Out: true" << endl;
        }
    }
}

//private
int get_database_size()
{
    return database.size();
}