
// Kelby Hubbard
// Chaluunbat Purev
// CS202 Group Project
// The Alaskan Phonebook
#include "fltk.hpp"



int main(int argc, char** argv){

	vector<tuple<string, string, double>> _phonebook;



	//Sample entrys
  _phonebook.push_back(make_tuple("BTestF", "BTestL", 3607029067));
	_phonebook.push_back(make_tuple("DTestF", "DTestL", 3607029061));
	_phonebook.push_back(make_tuple("ATestF", "ATestL", 3607029066));
	_phonebook.push_back(make_tuple("CTestF", "CTestL", 3607029068));

	getVector(_phonebook);

	//Main Window
	Fl_Double_Window* window = new Fl_Double_Window(605, 405, "Alaskan Phonebook");

	//Table to display data
	MyTable table(25, 45, 530, 275, _phonebook.size());

	//Drop down menu bar
	{ Fl_Menu_Bar* menuBar
		= new Fl_Menu_Bar(0, 0, 85, 25);
	//When selected runs "open()" in fltk.cpp
	menuBar->add("File/Open", FL_CTRL + 'o', open);
	//When selected runs "save()" in fltk.cpp
	menuBar->add("File/Save", FL_CTRL + 's', save);
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
	addButton->callback(addCallback, (void*) &_phonebook);
	addButton->callback(redraw, (void*) &table);
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


	window->end();
	window->resizable(table);
	window->show(argc, argv);

	return (Fl::run());

}
