// Kelby Hubbard
// Chaluunbat Purev
// CS202 Group Project
// The Alaskan Phonebook

#include "fltk.hpp"
#include <iostream>
using std::cout;
using std::endl;
void test(Fl_Widget* w, void* data)
{
  cout << "hello" << endl;
}


Fl_Double_Window* runFLTK() {


//Main Window
  Fl_Double_Window* w;
  { Fl_Double_Window* window = new Fl_Double_Window
                                              (605, 405, "Alaskan Phonebook");
    w = window;

    // { Fl_Menu_Button* menuButton = new Fl_Menu_Button(0, 0, 70, 25, "Menu");
    // }

    // { Fl_Menu_Bar* menuBar = new Fl_Menu_Bar(0, 0, 75, 25);
    //   menuBar->add("File/Open", 0, test);}
    //

  //  { new Fl_Button(0, 25, 145, 25, "Save"); }

    window->end();
    window->resizable(window);

    window->show();
  } // Fl_Double_Window* o












  return w;
}
