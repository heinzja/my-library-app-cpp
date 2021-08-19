#include <iostream>
#include <fstream>
#include <direct.h>
#include <filesystem>
#include "book.h"
#include "library.h"
namespace fs = std::filesystem;

using namespace std;

Library lib = Library();

// private
void import_book_file(string file_path)
{
   try
   {
      fstream newfile;
      newfile.open(file_path, ios::in); //open a file to perform read operation using file object
      if (newfile.is_open())
      { //checking whether the file is open
         string tp;
         string contents;
         //read data from file object and put it into string.
         while (getline(newfile, tp))
         {
            //append the data of the string to contents
            contents.append(tp + "\n");
         }
         newfile.close(); //close the file object.
         Book tmp_book = Book(file_path.substr(9), "description", contents);
         lib.add_book(tmp_book);
      }
      else
      {
         cout << "file not open" << endl;
      }
   }
   catch (exception &e)
   {
      cout << e.what() << endl;
   }
}

// main() is where program execution begins.
int main(int argc, char *argv[])
{
   // load books into database
   try
   {
      std::string path = "../books/";
      for (const auto &entry : fs::directory_iterator(path))
      {
         import_book_file(entry.path().generic_string());
      }
   }
   catch (invalid_argument &e)
   {
      cout << e.what() << endl;
   }

   // display start-up message
   cout << "Welcome to the Library" << endl;

   while (1 == 1)
   {

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
         lib.read_book(user_input);
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