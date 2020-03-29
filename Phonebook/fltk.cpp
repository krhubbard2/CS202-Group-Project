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
  cout << "save" << endl;
}

//Open function for menu dropdown bar
void open(Fl_Widget* w, void* data)
{
  cout << "open" << endl;
}

void yesQuit(Fl_Widget* w, void* data)
{
  exit(0);
}

//Quit function for menu dropdown bar
void quit(Fl_Widget* w, void* data)
{
   Fl_Window* window = new Fl_Window(340, 150, "Quit");
   Fl_Box* box = new Fl_Box(20, 40, 300, 35, "Are you sure you want to quit?");
   Fl_Button* yesButton = new Fl_Button(120, 100, 100, 25, "Yes I\'m sure.");
   yesButton->callback(yesQuit);

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
    { Fl_Menu_Bar* menuBar = new Fl_Menu_Bar(0, 0, 75, 25);
      //When selected runs "open()"" in fltk.cpp
      menuBar->add("File/Open", 0, open);
      //When selected runs "save()"" in fltk.cpp
      menuBar->add("File/Save", 0, save);
      //When selected runs "quit()"" in fltk.cpp
      menuBar->add("File/Quit", 0, quit);
    }


    window->end();
    window->resizable(window);

    window->show();
  }












  return w;
}
