#include <iostream>
#include "book.h"
#include "library.h"

using namespace std;

// main() is where program execution begins.
int main(int argc, char *argv[])
{
   // load library
   Library lib = Library();
   // load books into database
   try
   {
      Book book1 = Book("title", "11", "111");
      Book book2 = Book("title2", "22", "222");
      Book book3 = Book("title3", "33", "333");

      lib.add_book(book1);
      lib.add_book(book2);
      lib.add_book(book3);
   }
   catch (invalid_argument &e)
   {
      cout << e.what() << endl;
   }

   while (1 == 1)
   {

      // display start-up message
      cout << "Welcome to the Library" << endl;

      // display Library Menu
      cout << "1 - view all library books" << endl;
      cout << "2 - checkout book" << endl;
      cout << "3 - return book" << endl;
      cout << "4 - view checked out books" << endl;
      cout << "5 - preview book" << endl;
      cout << "6 - read checked out book" << endl;
      cout << "7 - exit application" << endl;
      // get user input
      char user_input;
      cin >> user_input;
      // select option from available list
      switch (user_input)
      {
      case '1':
      {
         cout << "Library Book Database" << endl;
         // loop through map and display each title
         lib.display_available_books();
         break;
      };
      case '2':
      {
         cout << "Type the title of the book you wish you checkout." << endl;
         string user_input;
         cin >> user_input;
         lib.checkout_book(user_input);
         break;
      };
      case '3':
      {
         cout << "Type the title of the book you wish to return." << endl;
         string user_input;
         // get user input
         cin >> user_input;
         lib.return_book(user_input);
         break;
      };
      case '4':
      {
         cout << "Currently Checkedout Books:" << endl;
         // prints out list of checked out books
         lib.display_checked_out_books();
         break;
      };
      case '5':
      {
         cout << "Type the Title of the Book You Wish to Preview" << endl;
         string user_input;
         cin >> user_input;
         lib.preview_book(user_input);
         break;
      };
      case '6':
      {
         cout << "Type the Title of the Book You Wish to Read" << endl;
         string user_input;
         cin >> user_input;
         lib.preview_book(user_input);
         break;
      };
      case '7':
      {
         cout << "Closing Application" << endl;
         exit(0);
         break;
      };
      default:
      {
         cout << "Invalid User Input, Please Select Another Option." << endl;
         break;
      };
      }
   }
   return 0;
}