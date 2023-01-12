/*  DSE 20.2F
    Index Number : CODSE202F-008
    Name         : K. A. N. D. Kumarasinghe
*/

#include<iostream>
#include<fstream>
#include<iomanip>>
#include<string>
#include<stdlib.h>
using namespace std;
class Book //
{ protected:
    string book_code,book_name,author_name;
    float book_price;
    int choice;
    public:
        void displayData();
};
void Book::displayData() //Function to display details of all books
    {
     while(1)
     {
      cout<<"......................................."<<endl;
      cout<<"              Book Display             "<<endl;
      cout<<".......................................\n\n";
      cout<<"         01) Sinhala Novels"<<endl;
      cout<<"         02) Comic Books"<<endl;
      cout<<"         03) Science Books"<<endl;
      cout<<"         04) Go to Main Menu\n\n"<<endl;
      cout<<".......................................\n";
      cout<<"        Enter Your Choice:" ;cin>>choice;
      system("cls");


      if(choice==1)
      {     cout<<endl;
            cout<<"......................................."<<endl;
            cout<<"           Sinhala Novels List           "<<endl;
            cout<<".......................................\n\n";
            ifstream sinhalabook;
            sinhalabook.open("SinhalaBook.txt");
            if (!sinhalabook)
            {
                cout<<"       Files Does Not Found !!\n\n\n\n";
            }
            else
            {
                while(sinhalabook)
                {sinhalabook>>book_code>>book_name>>author_name>>book_price;
                if(sinhalabook.eof())
                {break;
                }
                cout<<"Book Code     : "<<book_code<<"\n"<<"Book Name     : "<<book_name<<"\n"<<"Author's Name : "<<author_name<<"\n"<<"Selling Price : Rs. "<<book_price<<"\n"<<endl;
                }
            }

      }

      if(choice==2)
      {     cout<<endl;
            cout<<"......................................."<<endl;
            cout<<"           Comic Book List           "<<endl;
            cout<<".......................................\n\n";
            ifstream comicbook;
            comicbook.open("ComicBook.txt");
            if (!comicbook)
            {
                cout<<"       Files Does Not Found !!\n\n\n\n";
            }
            else
            {
                while(comicbook)
                {comicbook>>book_code>>book_name>>author_name>>book_price;
                if(comicbook.eof())
                {break;
                }
                cout<<"Book Code     : "<<book_code<<"\n"<<"Book Name     : "<<book_name<<"\n"<<"Author's Name : "<<author_name<<"\n"<<"Selling Price : Rs. "<<book_price<<"\n"<<endl;
                }
            }
      }

      if(choice==3)
      {     cout<<endl;
            cout<<"......................................."<<endl;
            cout<<"           Science Book List           "<<endl;
            cout<<".......................................\n\n";
            ifstream sciencebook;
            sciencebook.open("ScienceBook.txt");
            if (!sciencebook)
            {
                cout<<"       Files Does Not Found !!\n\n\n\n";
            }
            else
            {
                while(sciencebook)
                {sciencebook>>book_code>>book_name>>author_name>>book_price;
                if(sciencebook.eof())
                {break;
                }
                cout<<"Book Code     : "<<book_code<<"\n"<<"Book Name     : "<<book_name<<"\n"<<"Author's Name : "<<author_name<<"\n"<<"Selling Price : Rs. "<<book_price<<"\n"<<endl;
                }
            }
        }

      if(choice==4)
      break;

     }
     system("cls");
   }


class ScienceBook:public Book
{ public:
    void write_ScienceData();
    void deletedata();
    void editdata();
};
     void ScienceBook::write_ScienceData() //Function to add science books to file
    {   ofstream sciencebook;
        sciencebook.open("ScienceBook.txt",ios::app);
        cout<<"   Follow below instructions\n "<<endl;
        cout<<"   (Please use underscore instead of spaces between words)"<<endl;
        cout<<"   (First letter must be capital in every word)\n\n";
        cout<<"......................................."<<endl;
        cout<<"          Adding Science Books         "<<endl;
        cout<<".......................................\n\n";
        cout<<"\n   Insert Book Code     : ";cin>>book_code;
        cout<<"\n   Insert Book Name     : ";cin>>book_name;
        cout<<"\n   Insert Author's Name : ";cin>>author_name;
        cout<<"\n   Insert Selling Price : Rs. ";cin>>book_price;
        sciencebook<<setw(5)<<book_code<<setw(35)<<book_name<<setw(35)<<author_name<<setw(5)<<book_price<<endl;
        sciencebook.close();
        cout<<endl;
        cout<<"......................................."<<endl;
        cout<<"       Book Added Successfully !"<<endl;
        cout<<"......................................."<<endl;
    }
    void ScienceBook::deletedata() //Function to delete science books
    {         string bc;
              cout<<"\n......................................."<<endl;
              cout<<"Enter Name of the Book want to delete :";cin>>bc;
              cout<<".......................................\n"<<endl;

              ifstream sciencebook;
              sciencebook.open("ScienceBook.txt");
              ofstream e;
              e.open("new.txt");
              sciencebook>>book_code;
              sciencebook>>book_name;
              sciencebook>>author_name;
              sciencebook>>book_price;

              while(!sciencebook.eof())
              {
                  if(book_name!=bc)
                  {
                      e<<setw(6)<<book_code<<setw(35)<<book_name<<setw(35)<<author_name<<setw(5)<<book_price<<endl;
                  }
                  else
                    {cout<<"\t    Book Deleted !!\n\n";
                    break;

                    }
                    sciencebook>>book_code;
                    sciencebook>>book_name;
                    sciencebook>>author_name;
                    sciencebook>>book_price;
                    break;
                  }
                e.close();
                sciencebook.close();

                if (remove("ScienceBook.txt")!=0)
                {
                    cout<<"\n\t Inavlid Book code \n";
                }

                if (rename("new.txt","ScienceBook.txt")!=0)
                {
                    cout<<"\n\t File does not remove";
                }

                }

    void ScienceBook::editdata() //Function to edit science books
        {   string bc,newid,newp;
            cout<<"\n..........................................."<<endl;
            cout<<"Enter Name of the Science Book want to Edit : ";cin>>bc;
            cout<<".............................................\n\n"<<endl;

              ifstream sciencecbook;
              sciencecbook.open("ScienceBook.txt");
              ofstream e;
              e.open("edit.txt");
              sciencecbook>>book_code;
              sciencecbook>>book_name;
              sciencecbook>>author_name;
              sciencecbook>>book_price;

              while(!sciencecbook.eof())
              {
                  if(book_name!=bc)
                  {
                      e<<setw(6)<<book_code<<setw(35)<<book_name<<setw(35)<<author_name<<setw(5)<<book_price<<endl;
                  }
                  else
                    {cout<<"     Enter new Book Code  :";cin>>newid;
                     cout<<"\n     Enter new Book Price : Rs. ";cin>>newp;
                     cout<<"\n\n      Book Edited Successfully !!\n\n\n";


                     e<<setw(6)<<newid<<setw(35)<<book_name<<setw(35)<<author_name<<setw(5)<<newp<<endl;
                    }
                    sciencecbook>>book_code;
                    sciencecbook>>book_name;
                    sciencecbook>>author_name;
                    sciencecbook>>book_price;

                  }
                e.close();
                sciencecbook.close();

               remove("ScienceBook.txt");
               rename("edit.txt","ScienceBook.txt");
           }


class ComicBook:public Book
{public:
    void write_ComicData();
    void deletedata();
    void editdata();
};
     void ComicBook::write_ComicData() //Function to add comic books to file
    {   ofstream comicbook;
        comicbook.open("ComicBook.txt",ios::app);
        cout<<"   Follow below instructions\n "<<endl;
        cout<<"   (Please use underscore instead of spaces between words)"<<endl;
        cout<<"   (First letter must be capital in every word)\n\n";
        cout<<"......................................."<<endl;
        cout<<"           Adding Comic Books          "<<endl;
        cout<<".......................................\n\n";
        cout<<"\n   Insert Book Code     : ";cin>>book_code;
        cout<<"\n   Insert Book Name     : ";cin>>book_name;
        cout<<"\n   Insert Author's Name : ";cin>>author_name;
        cout<<"\n   Insert Selling Price : Rs. ";cin>>book_price;
        comicbook<<setw(5)<<book_code<<setw(35)<<book_name<<setw(35)<<author_name<<setw(5)<<book_price<<endl;
        comicbook.close();
        cout<<endl;
        cout<<"......................................."<<endl;
        cout<<"       Book Added Successfully !"<<endl;
        cout<<"......................................."<<endl;
    }
    void ComicBook::deletedata() //Function to delete comic books
    {         string bc;
              cout<<"\n......................................."<<endl;
              cout<<"Enter Name of the Book want to delete :";cin>>bc;
              cout<<".......................................\n"<<endl;

              ifstream comicbook;
              comicbook.open("ComicBook.txt");
              ofstream e;
              e.open("new.txt");
              comicbook>>book_code;
              comicbook>>book_name;
              comicbook>>author_name;
              comicbook>>book_price;

              while(!comicbook.eof())
              {
                  if(book_name!=bc)
                  {
                      e<<setw(6)<<book_code<<setw(35)<<book_name<<setw(35)<<author_name<<setw(5)<<book_price<<endl;
                  }
                  else
                    {cout<<"\t    Book Deleted !!\n\n";
                    break;

                    }
                    comicbook>>book_code;
                    comicbook>>book_name;
                    comicbook>>author_name;
                    comicbook>>book_price;
                    break;
                  }
                e.close();
                comicbook.close();

                if (remove("ComicBook.txt")!=0)
                {
                    cout<<"\n\t Invalid Book code \n";
                }

                if (rename("new.txt","ComicBook.txt")!=0)
                {
                    cout<<"\n\t File does not remove";
                }

                }


    void ComicBook::editdata() //Function to edit comic books
        {   string bc,newid,newp;
            cout<<"\n........................................."<<endl;
            cout<<"Enter Name of the Comic Book want to Edit : ";cin>>bc;
            cout<<"...........................................\n\n"<<endl;

              ifstream comicbook;
              comicbook.open("ComicBook.txt");
              ofstream e;
              e.open("edit.txt");
              comicbook>>book_code;
              comicbook>>book_name;
              comicbook>>author_name;
              comicbook>>book_price;

              while(!comicbook.eof())
              {
                  if(book_name!=bc)
                  {
                      e<<setw(6)<<book_code<<setw(35)<<book_name<<setw(35)<<author_name<<setw(5)<<book_price<<endl;
                  }
                  else
                    {cout<<"     Enter new Book Code  :";cin>>newid;
                     cout<<"\n     Enter new Book Price : Rs. ";cin>>newp;
                     cout<<"\n\n     Book Edited Successfully !!\n\n\n";


                     e<<setw(6)<<newid<<setw(35)<<book_name<<setw(35)<<author_name<<setw(5)<<newp<<endl;
                    }
                    comicbook>>book_code;
                    comicbook>>book_name;
                    comicbook>>author_name;
                    comicbook>>book_price;

                  }
                e.close();
                comicbook.close();

               remove("ComicBook.txt");
               rename("edit.txt","ComicBook.txt");
           }

class SinhalaBook:public Book
{public:
    void write_SinhalaData();
    void deletedata();
    void editdata();
};
    void SinhalaBook::write_SinhalaData() //Function to add sinhala books to file
    {   ofstream sinhalabook;
        sinhalabook.open("SinhalaBook.txt",ios::app);
        cout<<"   Follow below instructions\n "<<endl;
        cout<<"   (Please use underscore instead of spaces between words)"<<endl;
        cout<<"   (First letter must be capital in every word)\n\n";
        cout<<"......................................."<<endl;
        cout<<"         Adding Sinhala Novels          "<<endl;
        cout<<".......................................\n\n";
        cout<<"\n   Insert Book Code     : ";cin>>book_code;
        cout<<"\n   Insert Book Name     : ";cin>>book_name;
        cout<<"\n   Insert Author's Name : ";cin>>author_name;
        cout<<"\n   Insert Selling Price : Rs. ";cin>>book_price;
        sinhalabook<<setw(6)<<book_code<<setw(35)<<book_name<<setw(35)<<author_name<<setw(5)<<book_price<<endl;
        sinhalabook.close();
        cout<<endl;
        cout<<"......................................."<<endl;
        cout<<"       Book Added Successfully !"<<endl;
        cout<<"......................................."<<endl;
    }

    void SinhalaBook::deletedata() //Function to delete sinhala books
    {         string bc;
              cout<<"\n.............................................."<<endl;
              cout<<"Enter Name of the Sinhala Novel want to delete :";cin>>bc;
              cout<<"................................................\n"<<endl;

              ifstream sinhalabook;
              sinhalabook.open("SinhalaBook.txt");
              ofstream e;
              e.open("new.txt");
              sinhalabook>>book_code;
              sinhalabook>>book_name;
              sinhalabook>>author_name;
              sinhalabook>>book_price;

              while(!sinhalabook.eof())
              {
                  if(book_name!=bc)
                  {
                      e<<setw(6)<<book_code<<setw(35)<<book_name<<setw(35)<<author_name<<setw(5)<<book_price<<endl;
                  }
                  else
                    {cout<<"\t    Book Deleted !!\n\n";
                    break;

                    }
                    sinhalabook>>book_code;
                    sinhalabook>>book_name;
                    sinhalabook>>author_name;
                    sinhalabook>>book_price;
                    break;
                  }
                e.close();
                sinhalabook.close();

                if (remove("SinhalaBook.txt")!=0)
                {
                    cout<<"\n\t Invalid Book code \n";
                }

                if (rename("new.txt","SinhalaBook.txt")!=0)
                {
                    cout<<"\n\t File does not remove";
                }

                }


    void SinhalaBook::editdata() //Function to edit sinhala books
            {   string bc,newid,newp;
                cout<<"\n............................................"<<endl;
                cout<<"Enter Name of the Sinhala Novel want to Edit : ";cin>>bc;
                cout<<"..............................................\n\n"<<endl;

              ifstream sinhalabook;
              sinhalabook.open("SinhalaBook.txt");
              ofstream e;
              e.open("edit.txt");
              sinhalabook>>book_code;
              sinhalabook>>book_name;
              sinhalabook>>author_name;
              sinhalabook>>book_price;

              while(!sinhalabook.eof())
              {
                  if(book_name!=bc)
                  {
                      e<<setw(6)<<book_code<<setw(35)<<book_name<<setw(35)<<author_name<<setw(5)<<book_price<<endl;
                  }
                  else
                    {cout<<"     Enter new Book Code  :";cin>>newid;
                     cout<<"\n     Enter new Book Price : Rs. ";cin>>newp;
                     cout<<"\n\n     Book Edited Successfully !!\n\n\n";


                     e<<setw(6)<<newid<<setw(35)<<book_name<<setw(35)<<author_name<<setw(5)<<newp<<endl;
                    }
                    sinhalabook>>book_code;
                    sinhalabook>>book_name;
                    sinhalabook>>author_name;
                    sinhalabook>>book_price;

                  }
                e.close();
                sinhalabook.close();

               remove("SinhalaBook.txt");
               rename("edit.txt","SinhalaBook.txt");
           }



int main()
{   Book B;
    SinhalaBook SIB;
    ComicBook CB;
    ScienceBook SB;
    string book_code,book_name,author_name,ubook_name;
    float book_price;
    int menu_no,choice,c,booktype;
    while(1)
    {cout<<endl; //Main menu of the application
     cout<<"***************************************"<<endl;
     cout<<"             ND Book Store             "<<endl;
     cout<<"***************************************\n\n";
     cout<<"         01) Add a book\n";
     cout<<"         02) Display Books\n";
     cout<<"         03) Search Books\n";
     cout<<"         04) Edit Books\n";
     cout<<"         05) Delete Books\n";
     cout<<"         06) Exit\n\n";
     cout<<".......................................\n";
     cout<<"     What do you want to do?\n";
     cout<<"     (Please enter 1 to 5) ";cin>>menu_no;
     system("cls");

    if(menu_no==1) // Book adding menu
    {while(1)
        {   cout<<endl;
            cout<<"......................................."<<endl;
            cout<<"               Book Adding             "<<endl;
            cout<<".......................................\n";
            cout<<"    Types of Books:\n\n";
            cout<<"         01) Sinhala Novels"<<endl;
            cout<<"         02) Comic Books"<<endl;
            cout<<"         03) Science Books"<<endl;
            cout<<"         04) Go to Main Menu"<<endl;
            cout<<".......................................\n";
            cout<<"        Insert your Choice: ";cin>>choice;
            system("cls");

            if(choice==1)
            {SIB.write_SinhalaData();
            }
            if(choice==2)
            {CB.write_ComicData();
            }
            if(choice==3)
            {SB.write_ScienceData();
            }
            if(choice==4)
            break;
        }
        }

    if(menu_no==2)
        {B.displayData();
        }
    if(menu_no==3) //Book searching main menu
        {   cout<<endl;
            cout<<"......................................."<<endl;
            cout<<"            Searching Books            "<<endl;
            cout<<".......................................\n\n";
            cout<<"         01) Search"<<endl;
            cout<<"         02) Go to Main Menu"<<endl;
            cout<<"\n.......................................\n";
            cout<<"\n        Insert your Choice: ";cin>>choice;
            system("cls");

             if(choice==1) // Book searching book category menu
            {cout<<"......................................."<<endl;
             cout<<"            Searching Books            "<<endl;
             cout<<".......................................\n\n";

             string book_types[3] = {"Sinhala Novels","Comic Books","Science Books"};
             for(c=0;c<3;c++)
             {
                 cout<<"          0"<<c+1<<") "<<book_types[c]<<endl;
             }
             cout<<"          04) Go to Main Menu"<<endl;
             cout<<endl<<"        Insert your choice: ";cin>>booktype;
             cout<<".......................................\n\n";
             fstream bfind;
            if(booktype == 1) // Sinhala book searching
             {   cout<<"   Follow below instructions\n "<<endl;
                 cout<<"   (Please use underscore instead of spaces between words)"<<endl;
                 cout<<"   (First letter must be capital in every word)\n";
                 cout<<".......................................\n";
                 cout<<"   Please enter Book Name: ";cin>>ubook_name;
                 system("cls");
                 bfind.open("SinhalaBook.txt",ios::in);
                 if(bfind.is_open())
                 {
                     while(bfind.good())
                     {
                         bfind>>book_code;
                         bfind>>book_name;
                         bfind>>author_name;
                         bfind>>book_price;

                         if(book_name == ubook_name)
                         {
                             cout<<endl<<"Book Code   : "<< book_code<<endl;
                             cout<<"Book Name   : "<< book_name<<endl;
                             cout<<"Author Name : "<< author_name<<endl;
                             cout<<"Book Price  : Rs. "<< book_price<<endl<<endl;
                             break;
                         }
                     }
                 }
                 else
                 {   cout<<".......................................\n";
                     cout<<"     There is no Sinhala Book file\n"<<endl;
                     cout<<"        Please add Sinhala books"<<endl;
                     cout<<".......................................\n\n\n";
                 }
                 bfind.close();
             }
             else if(booktype == 2) // Comic book searching
             {   cout<<"   Follow below instructions\n "<<endl;
                 cout<<"   (Please use underscore instead of spaces between words)"<<endl;
                 cout<<"   (First letter must be capital in every word)\n";
                 cout<<".......................................\n";
                 cout<<"   Please enter Book Name: ";cin>>ubook_name;
                 system("cls");
                 bfind.open("ComicBook.txt",ios::in);
                 if(bfind.is_open())
                 {
                     while(bfind.good())
                     {
                         bfind>>book_code;
                         bfind>>book_name;
                         bfind>>author_name;
                         bfind>>book_price;

                         if(book_name == ubook_name)
                         {
                             cout<<endl<<"Book Code   : "<< book_code<<endl;
                             cout<<"Book Name   : "<< book_name<<endl;
                             cout<<"Author Name : "<< author_name<<endl;
                             cout<<"Book Price  : Rs. "<< book_price<<endl<<endl;
                             break;
                         }
                     }
                 }
                 else
                 {   cout<<".......................................\n";
                     cout<<"     There is no Comic Book file\n"<<endl;
                     cout<<"        Please add Comic books"<<endl;
                     cout<<".......................................\n\n\n";
                 }
                 bfind.close();
             }
             else if(booktype == 3) //Science book searching
             {   cout<<"   Follow below instructions\n "<<endl;
                 cout<<"   (Please use underscore instead of spaces between words)"<<endl;
                 cout<<"   (First letter must be capital in every word)\n";
                 cout<<".......................................\n";
                 cout<<"   Please enter Book Name: ";cin>>ubook_name;
                 system("cls");
                 bfind.open("ScienceBook.txt",ios::in);
                 if(bfind.is_open())
                 {
                     while(bfind.good())
                     {
                         bfind>>book_code;
                         bfind>>book_name;
                         bfind>>author_name;
                         bfind>>book_price;
                         if(book_name == ubook_name)
                         {
                             cout<<endl<<"Book Code   : "<< book_code<<endl;
                             cout<<"Book Name   : "<< book_name<<endl;
                             cout<<"Author Name : "<< author_name<<endl;
                             cout<<"Book Price  : Rs. "<< book_price<<endl<<endl;
                             break;
                         }
                     }
                 }
                 else
                 {   cout<<".......................................\n";
                     cout<<"     There is no Science Book file\n"<<endl;
                     cout<<"        Please add Science books"<<endl;
                     cout<<".......................................\n\n\n";
                 }
                 bfind.close();
             }
            }
        }
        if (menu_no==4) // Book editing menu
        {   cout<<endl;
            cout<<"......................................."<<endl;
            cout<<"              Editing Books            "<<endl;
            cout<<".......................................\n\n";
            cout<<"         01) Edit Sinhala Books"<<endl;
            cout<<"         02) Edit Comic Books"<<endl;
            cout<<"         03) Edit Science Books"<<endl;
            cout<<"         04) Go to Main Menu"<<endl;
            cout<<"\n.......................................\n";
            cout<<"\n        Insert your Choice: ";cin>>choice;
            system("cls");

            if(choice==1)
            {SIB.editdata();
            }
            if (choice==2)
            {CB.editdata();
            }
            if(choice==3)
            {SB.editdata();
            }
        }

        if(menu_no==5) // book deleting menu
    {       cout<<endl;
            cout<<"......................................."<<endl;
            cout<<"            Deleting Books            "<<endl;
            cout<<".......................................\n\n";
            cout<<"         01) Delete Sinhala Books"<<endl;
            cout<<"         02) Delete Comic Books"<<endl;
            cout<<"         03) Delete Science Books"<<endl;
            cout<<"         04) Go to Main Menu"<<endl;
            cout<<"\n.......................................\n";
            cout<<"\n        Insert your Choice: ";cin>>choice;
            system("cls");

            if(choice==1)
            {SIB.deletedata();
            }
            else if(choice==2)
            {CB.deletedata();
            }
            else if(choice==3)
            {SB.deletedata();
            }
   }
    if(menu_no==6) //Exit
    break;
 }
    return 0;
}


/*  DSE 20.2F
    Index Number : CODSE202F-008
    Name         : K. A. N. D. Kumarasinghe
*/




