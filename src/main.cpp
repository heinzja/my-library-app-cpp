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
   try {
      Book book1 = Book("1","11","111");
      Book book2 = Book("2","22","222");
      Book book3 = Book("3","33","333");

      lib.add_book(book1);
   } catch (invalid_argument &e){
      std::cout << e.what() << std::endl;
   }



   // display start-up message
   cout << "Welcome to the Library\n";

   // display Library Menu
   cout << "1 - view all library books\n";
   cout << "2 - checkout book\n";
   cout << "3 - return book\n";
   cout << "4 - view checkedout books\n";

   // get user input
   char user_input;
   cin >> user_input;
   // check if input is valid
   cout << "user_input = " << user_input << "\n";
   // select option from available list
   switch (user_input)
   {
   case '1':
   {
      cout << "Library Book Database\n";
      // loop through map and display each title
      break;
   };
   case '2':
   {
      cout << "Type the title of the book you wish you checkout.\n";
      break;
   };
   case '3':
   {
      cout << "Type the title of the book you wish to return.\n";
      // get user input
      // check if input is valid
      // check to see if key exists in map of database
      // check to see if
      break;
   };
   case '4':
   {
      cout << "Currently Checkedout Books:\n";
      // prints out list of checked out books
      break;
   };
   default:
   {
      cout << "user_input = " + user_input;
      break;
   };
   }

   return 0;
}