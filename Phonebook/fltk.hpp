// Kelby Hubbard
// Chaluunbat Purev
// CS202 Group Project
// The Alaskan Phonebook

#ifndef FLTK_HPP_
#define FLTK_HPP_

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <Fl/Fl_Text_Display.H>

#pragma comment(lib, "fltk.lib")
Fl_Double_Window* runFLTK();
void file_open_cb(Fl_Widget* w, void* data);

void save(Fl_Widget* w, void* data);
void quit(Fl_Widget* w, void* data);
void open(Fl_Widget* w, void* data);
#endif
