#include "library.h"

using namespace std;
map<string, Book> database;
map<string, Book> checked_out_database;

Library::Library()
{
}

//public

void Library::add_book(Book book)
{
    try
    {
        database.insert(make_pair(book.get_title(), book));
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
        if (book_title.length() > 0 && book_title.length() <= Book::max_title_length)
        {
            if (does_book_exist_in_database(&database, book_title))
            {
                database.erase(book_title);
            }
            else
            {
                throw exception("Error: Book Does Not Exist in Database");
            }
        }
        else
        {
            throw exception("Error: Book Title Length");
        }
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
            if (does_book_exist_in_database(&database, book_title))
            {
                if (database.at(book_title).get_checkout_status() != true)
                {
                    database.at(book_title).set_checkout_status(true);
                    checked_out_database.insert(make_pair(book_title, database.at(book_title)));
                    cout << "You Have Checked Out: " << checked_out_database.at(book_title).get_title() << endl;
                }
                else
                {
                    throw exception("Error: Book Already Checked Out");
                }
            }
            else
            {
                throw exception("Error: Book Does Not Exist in Database");
            }
        }
        else
        {
            throw invalid_argument("Error: Book Title Length");
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
                checked_out_database.erase(book_title);
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

void Library::preview_book(string book_title)
{
    // check if book exists in database
    try
    {
        // check user input
        if (book_title.length() > 0 && book_title.length() <= Book::max_title_length)
        {
            // if title exists in map switch checkout flag to true
            if (does_book_exist_in_database(&database, book_title))
            {
                cout << "Title:\n\t" << database.at(book_title).get_title() << endl;
                cout << "Description:\n\t" << database.at(book_title).get_description() << endl;
            }
            else
            {
                throw exception("Error: Book Does Not Exist In Database");
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

void Library::read_book(string book_title)
{
    // check if book exists in database
    try
    {
        // check user input
        if (book_title.length() > 0 && book_title.length() <= Book::max_title_length)
        {
            // if title exists in map switch checkout flag to true
            if (does_book_exist_in_database(&database, book_title))
            {
                cout << "Title:\n\t" << database.at(book_title).get_title() << endl;
                cout << "Contents:\n\t" << database.at(book_title).get_contents() << endl;
            }
            else
            {
                throw exception("Error: Book Does Not Exist In Database");
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

void Library::display_available_books()
{

    map<string, Book>::iterator it;
    // loop through map displaying title of each book
    for (it = database.begin(); it != database.end(); it++)
    {
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

void Library::display_checked_out_books()
{
    map<string, Book>::iterator it;
    // loop through map displaying title of each book
    for (it = checked_out_database.begin(); it != checked_out_database.end(); it++)
    {
        cout << "Title: " << it->first << endl;
    }
}

//private
int Library::get_database_size()
{
    return database.size();
}

// checks to see if a specific book exists in the database
// by checked if the book title matches possible keys available
bool Library::does_book_exist_in_database(map<string, Book> *database_to_search, string book_title)
{
    try
    {
        map<string, Book>::iterator it;
        if (database_to_search->find(book_title) != database_to_search->end())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
        return false;
    }
}