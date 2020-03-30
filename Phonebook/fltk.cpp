// Kelby Hubbard
// Chaluunbat Purev
// CS202 Group Project
// The Alaskan Phonebook

#include "fltk.hpp"
#include <iostream>
using std::cout;
using std::endl;

//Save function for menu dropdown bar
void save(Fl_Widget* w, void* data)
{
  cout << "Save" << endl;
}

//Open function for menu dropdown bar
void open(Fl_Widget* w, void* data)
{
  cout << "Open" << endl;
}

//Exits program
void quitProgram(Fl_Widget* w, void* data)
{
  exit(0);
}

//Search Record Button Callback
void searchCallback(Fl_Widget* w, void* data)
{
  cout << "Search Record\n";
}

//Modify Record Button Callback
void modifyCallback(Fl_Widget* w, void* data)
{
  cout << "Modify Record\n";
}

//Add Record Button Callback
void addCallback(Fl_Widget* w, void* data)
{
  cout << "Add Record\n";
}

//Delete Record Button Callback
void deleteCallback(Fl_Widget* w, void* data)
{
  cout << "Delete Record\n";
}

//Quit function for menu dropdown bar
void quit(Fl_Widget* w, void* data)
{
   Fl_Window* window = new Fl_Window(340, 150, "Quit");
   Fl_Box* box = new Fl_Box(20, 40, 300, 35, "Are you sure you want to quit?");
   Fl_Button* yesButton = new Fl_Button(120, 100, 100, 25, "Yes I\'m sure.");
   yesButton->callback(quitProgram);

   box->show();
   window->show();
  // exit(0);
}

//Main run function for FLTK/GUI
Fl_Double_Window* runFLTK() {
//Main Window
  Fl_Double_Window* w;
  { Fl_Double_Window* window = new Fl_Double_Window
                                              (605, 405, "Alaskan Phonebook");
    w = window;

    //Drop down menu bar
    { Fl_Menu_Bar* menuBar
        = new Fl_Menu_Bar(0, 0, 75, 25);
      //When selected runs "open()"" in fltk.cpp
      menuBar->add("File/Open", 0, open);
      //When selected runs "save()"" in fltk.cpp
      menuBar->add("File/Save", 0, save);
      //When selected runs "quit()"" in fltk.cpp
      menuBar->add("File/Quit", 0, quit);
    }

    //Search Record Button
    { Fl_Button* searchButton
        = new Fl_Button(30, 350, 110, 25, "Search Record");
      searchButton->callback(searchCallback);
    }

    //Add Record Button
    { Fl_Button* addButton
        = new Fl_Button(310, 350, 110, 25, "Add Record");
      addButton->callback(addCallback);
    }

    //Modify Record Button
    { Fl_Button* modifyButton
        = new Fl_Button(170, 350, 110, 25, "Modify Record");
      modifyButton->callback(modifyCallback);
    }

    //Delete Record Button
    { Fl_Button* deleteButton
        = new Fl_Button(445, 350, 110, 25, "Delete Record");
      deleteButton->callback(deleteCallback);
    }

    //Text Display for Printing Records to Screen
    { Fl_Text_Buffer* buff = new Fl_Text_Buffer();
      Fl_Text_Display* textDisplay
        = new Fl_Text_Display(25, 45, 530, 275);
        textDisplay->buffer(buff);
      buff->text("Welcome to the Alaskan Phonebook.\nTo get started press any"
                " of the following buttons.\nYour records will show here.\n"
                "Enjoy.\n");
    }

    window->end();
    window->resizable(window);

    window->show();
  }






  return w;
}
