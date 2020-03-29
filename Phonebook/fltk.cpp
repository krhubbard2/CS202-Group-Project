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

//Quit function for menu dropdown bar
void quit(Fl_Widget* w, void* data)
{
  cout << "quit" << endl;
}

Fl_Double_Window* runFLTK() {


//Main Window
  Fl_Double_Window* w;
  { Fl_Double_Window* window = new Fl_Double_Window
                                              (605, 405, "Alaskan Phonebook");
    w = window;

    // { Fl_Menu_Button* menuButton = new Fl_Menu_Button(0, 0, 70, 25, "Menu");
    // }

    //Drop down menu bar
    { Fl_Menu_Bar* menuBar = new Fl_Menu_Bar(0, 0, 75, 25);

      //When selected runs "open()"" in fltk.cpp
      menuBar->add("File/Open", 0, open);
      //When selected runs "save()"" in fltk.cpp
      menuBar->add("File/Save", 0, save);
      //When selected runs "quit()"" in fltk.cpp
      menuBar->add("File/Quit", 0, quit);
    }


  //  { new Fl_Button(0, 25, 145, 25, "Save"); }

    window->end();
    window->resizable(window);

    window->show();
  } // Fl_Double_Window* o












  return w;
}
