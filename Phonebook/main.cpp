
// Kelby Hubbard
// Chaluunbat Purev
// CS202 Group Project
// The Alaskan Phonebook

#include "fltk.hpp"
#include "phonebook.hpp"
#include <algorithm>
using std::sort;

int main(int argc, char** argv){


	Phonebook pb;

	pb.openFile("save.txt");
	sort(pb.begin(), pb.end(), sortVec);

	//Main Window
	Fl_Double_Window* window = new Fl_Double_Window(605, 375, "Alaskan Phonebook");

	//Table to display data
	MyTable table(25, 45, 550, 275, pb.sizeP());
	table.setPb(pb);

	//Drop down menu bar
	{ Fl_Menu_Bar* menuBar
		= new Fl_Menu_Bar(0, 0, 85, 25);
	//When selected runs "open()" in fltk.cpp
	menuBar->add("File/Open", FL_CTRL + 'o', open, (void*) &table);
	//When selected runs "save()" in fltk.cpp
	menuBar->add("File/Save", FL_CTRL + 's', save, (void*) &table);
	//When selected runs "quit()" in fltk.cpp
	menuBar->add("File/Quit", FL_CTRL + 'q', quit);
	//When selected runs "help()" in fltk.cpp
	menuBar->add("Help/Help", FL_CTRL + 'h', help);
	}

	//Search Record Button
	{ Fl_Input* srchInp
		= new Fl_Input(340, 5, 120, 25);
	Fl_Button* searchButton
		= new Fl_Button(465, 5, 60, 25, "Search");
	searchButton->callback(searchCallback, (void*) &table);
	 Fl_Button* clearButton
		= new Fl_Button(530, 5, 50, 25, "Clear");
	 clearButton->callback(clearCallback, (void*) &table);
	}

	//Add Record Button
	{ Fl_Button* addButton
		= new Fl_Button(310, 330, 110, 25, "Add Record");
	addButton->callback(addCallback, (void*) &table);

	}

	//Modify Record Button
	{ Fl_Check_Button* modifyButton
		= new Fl_Check_Button(170, 5, 110, 25, "Modify Record");
	modifyButton->callback(modifyCallback, (void*)&table);
	}

	//Delete Record Button
	{ Fl_Button* deleteButton
		= new Fl_Button(445, 330, 110, 25, "Delete Record");
	deleteButton->callback(deleteCallback, (void*) &table);
	}


	window->end();
	window->resizable(table);
	window->show(argc, argv);

	return (Fl::run());

}
