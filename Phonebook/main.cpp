
// Kelby Hubbard
// Chaluunbat Purev
// CS202 Group Project
// The Alaskan Phonebook

#include "fltk.hpp"
#include "phonebook.hpp"


int main(int argc, char** argv){


	Phonebook pb;

	pb.openFile("save.txt");

	//Main Window
	Fl_Double_Window* window = new Fl_Double_Window(605, 405, "Alaskan Phonebook");

	//Table to display data
	MyTable table(25, 45, 530, 275, pb.size());
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
	{ Fl_Button* searchButton
		= new Fl_Button(30, 350, 110, 25, "Search Record");
	searchButton->callback(searchCallback);
	}

	//Add Record Button
	{ Fl_Button* addButton
		= new Fl_Button(310, 350, 110, 25, "Add Record");
	addButton->callback(addCallback, (void*) &table);

	}

	//Modify Record Button
	{ Fl_Check_Button* modifyButton
		= new Fl_Check_Button(170, 350, 110, 25, "Modify Record");
	modifyButton->callback(modifyCallback, (void*)&table);
	}

	//Delete Record Button
	{ Fl_Button* deleteButton
		= new Fl_Button(445, 350, 110, 25, "Delete Record");
	deleteButton->callback(deleteCallback, (void*) &table);
	}


	window->end();
	window->resizable(table);
	window->show(argc, argv);

	return (Fl::run());

}
