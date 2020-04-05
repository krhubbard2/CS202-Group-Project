// Kelby Hubbard
// Chaluunbat Purev
// CS202 Group Project
// The Alaskan Phonebook

#ifndef FLTK_HPP_
#define FLTK_HPP_
//#define WIN32

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <Fl/Fl_Text_Display.H>
#include <FL/Fl_Table_Row.H>
#include <FL/Fl_Scroll.H>

#include <iostream>
using std::cout;
using std::endl;
using std::string;
#include <vector>
using std::vector;
#include <tuple>
using std::tuple;
using std::make_tuple;
using std::get;
#include <string>

// Derive a class from Fl_Table_Row
class MyTable : public Fl_Table_Row {
public:
	// Draw the row/col headings
	//    Make this a dark thin upbox with the text inside.
	//
	void DrawHeader(const char* s, int X, int Y, int W, int H);

	// Handle drawing table's cells
	//     Fl_Table calls this function to draw each visible cell in the table.
	//     It's up to us to use FLTK's drawing functions to draw the cells the way we want.
	//
	void draw_cell(TableContext context, int ROW = 0, int COL = 0, int X = 0, int Y = 0, int W = 0, int H = 0);

	// Constructor
	//     Make our data array, and initialize the table options.
	//
	MyTable(int X, int Y, int W, int H, int s, const char* L = 0) : Fl_Table_Row(X, Y, W, H, L) {
		// Rows
		rows(s);             // how many rows
		row_header(1);              // enable row headers (along left)
		row_height_all(20);         // default height of rows
		row_resize(0);              // disable row resizing
		// Cols
		cols(3);             // how many columns
		col_header(1);              // enable column headers (along top)
		col_width_all(162);          // default width of columns
		col_resize(1);              // enable column resizing
		end();                      // end the Fl_Table group
	}
	~MyTable() { }
};

//Fl_Double_Window* runFLTK();
void file_open_cb(Fl_Widget* w, void* data);

void save(Fl_Widget* w, void* data);
void quitProgram(Fl_Widget* w, void* data);
void quit(Fl_Widget* w, void* data);
void open(Fl_Widget* w, void* data);
void help(Fl_Widget* w, void* data);
void searchCallback(Fl_Widget* w, void* data);
void modifyCallback(Fl_Widget* w, void* data);
void addCallback(Fl_Widget* w, void* data);
void deleteCallback(Fl_Widget* w, void* data);
void getVector(vector<tuple<string, string, double>>& v);



#endif
