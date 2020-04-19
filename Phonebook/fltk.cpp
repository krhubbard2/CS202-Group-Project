// Kelby Hubbard
// Chaluunbat Purev
// CS202 Group Project
// The Alaskan Phonebook

#include "fltk.hpp"
#include "phonebook.hpp"

// DOESNT REDRAW/REFRESH  YET
void redraw(Fl_Widget* w, void* data)
{
	MyTable &table = *(MyTable*)data;
	table.draw();
}

void MyTable::saveFile(const string& fileName)
{

	ofstream ifile(fileName);
	if (ifile.is_open())
	{
		for (auto i = 0; i < _pb.size(); i++)
		{
			string fname, lname;
			double phone;
			fname = get<0>(_pb.getTuple(i));
			lname = get<1>(_pb.getTuple(i));
			phone = get<2>(_pb.getTuple(i));
			ifile << fname << " " << lname << " " << setprecision(9) << phone << endl;
		}
	}
}

//Save function for menu dropdown bar
void save(Fl_Widget* w, void* data)
{
	auto t = (MyTable*)data;
	t->saveFile("save.txt");
}

//Open function for menu dropdown bar
void open(Fl_Widget* w, void* data)
{
	cout << "Open" << endl;
	auto p =(Phonebook*)data;
	p->openFile("save.txt");
}

//Help function for menu dropdown bar
void help(Fl_Widget* w, void* data)
{
	cout << "Help" << endl;
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

	//Get the table
	auto t = (MyTable*)data;

	t->modifyState();

	
}

//Add Record Button Callback
void addCallback(Fl_Widget* w, void* data)
{
	//Get the table
	//auto t = (MyTable*)data;
	//t->rows((t->rows() +1));


	cout << "Add Record\n";

	//
	// cout << "Add Record\n";
	// vector<tuple<string, string, double>>& vec
	// 	=	*(vector<tuple<string, string, double>>*) data;
	// vec.push_back(make_tuple
	// 	("addRecordFirst", "addRecordLast", 123456789));
	//
	// 	for (auto p : vec)
	// 	{
	// 		cout << get<1>(p) << ", " << get<0>(p) << setw(40)
	// 				 << fixed << std::setprecision(0) << get<2>(p) << endl;
	// 	}
}

//Delete Record Button Callback
void deleteCallback(Fl_Widget* w, void* data)
{
	//Get the table
	auto t = (MyTable*)data;

	//Delete a record/row
	t->deletePb(t->callback_row());

	//Decrease the tables row by one	
	t->rows((t->rows() - 1));

	//Testing prints to console
	t->printAll();
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

void MyTable::DrawHeader(const char* s, int X, int Y, int W, int H, const Fl_Color c) {
	fl_font(FL_HELVETICA, 16);
	fl_push_clip(X, Y, W, H);
	fl_draw_box(FL_THIN_UP_BOX, X, Y, W, H, c);
	fl_color(FL_BLACK);
	fl_draw(s, X, Y, W, H, FL_ALIGN_CENTER);
	fl_pop_clip();
}

void MyTable::draw_cell(TableContext context, int ROW, int COL, int X , int Y , int W , int H) {
	
	string str;
	switch (context) {
	case CONTEXT_STARTPAGE:                   // before page is drawn..
		fl_font(FL_HELVETICA, 16);              // set the font for our drawing operations
		return;
	case CONTEXT_COL_HEADER:                  // Draw column headers
		switch (COL) {
		case 0: str = "First name"; break;
		case 1: str = "Last name"; break;
		case 2: str = "Phone Number"; break;
		default: str = "Unknown column";
		}
		DrawHeader(str.c_str(), X, Y, W, H, FL_GRAY);
		return;
	case CONTEXT_ROW_HEADER:                  // Draw row headers
		str = std::to_string(ROW + 1);
		DrawHeader(str.c_str(), X, Y, W, H, FL_GRAY);
		return;
	case CONTEXT_CELL: {                      // Draw data in cells
		// don't draw this cell if it's being edited
		if (context_edit == context && ROW == row_edit && COL == col_edit && input->visible())
			return;

		auto tp = _pb.getTuple(ROW);
		switch (COL) {
		case 0: str = get<0>(tp); break;
		case 1: str = get<1>(tp); break;
		case 2: str = std::to_string(get<2>(tp)); str.resize(10); break;
		default: str = "Unknown cell";
		}
		if (!modify) {
			//If row is selected indicate that it is selected by changing color
			if (row_selected(ROW)) {
				fl_font(FL_HELVETICA, 16);
				fl_draw_box(FL_THIN_UP_BOX, X, Y, W, H, FL_BLUE);
				fl_color(FL_WHITE);
				fl_draw(str.c_str(), X, Y, W, H, FL_ALIGN_CENTER);

			}
			else
				// Handle coloring of cells
				DrawHeader(str.c_str(), X, Y, W, H, FL_WHITE);
		}
		else {

			callback(&event_callback, (void*)this);
			// Background
			int highlight = is_selected(ROW, COL) && context == context_edit;
			fl_draw_box(FL_THIN_UP_BOX, X, Y, W, H, highlight ? FL_BLUE : FL_WHITE);
			// Text
			fl_font(FL_HELVETICA, 16);
			
			fl_push_clip(X + 3, Y + 3, W - 6, H - 6);
			{
				fl_color(FL_BLACK);
				fl_draw(str.c_str(), X + 3, Y + 3, W - 6, H - 6, FL_ALIGN_CENTER);
			}
			fl_pop_clip();
		}
		return;
	}
	default:
		return;
	}
}

void MyTable::cell_event() {
	int R = callback_row();
	int C = callback_col();
	TableContext context = callback_context();

	switch (context) {
	case CONTEXT_CELL: {                                // A table event occurred on a cell
		switch (Fl::event()) {                            // see what FLTK event caused it
		case FL_PUSH:                                   // mouse click?
			done_editing();                               // finish editing previous
			start_editing(context, R, C);
			return;

		case FL_KEYBOARD:                               // key press in table?
			if (Fl::event_key() == FL_Escape) exit(0);  // ESC closes app
			done_editing();                               // finish any previous editing
			if (C == cols() - 1 || R == rows() - 1) return;       // no editing of totals column
			switch (Fl::e_text[0]) {
			case '0': case '1': case '2': case '3':     // any of these should start editing new cell
			case '4': case '5': case '6': case '7':
			case '8': case '9': case '+': case '-':
				start_editing(context, R, C);
				input->handle(Fl::event());               // pass typed char to input
				break;
			case '\r': case '\n':                       // let enter key edit the cell
				start_editing(context, R, C);
				break;
			}
			return;
		}
		return;
	}

	case CONTEXT_TABLE:                                 // A table event occurred on dead zone in table
		done_editing();                                   // done editing, hide
		return;

	default:
		return;
	}
}

void MyTable::start_editing(TableContext context, int R, int C) {
	// Keep track of cell being edited
	context_edit = context;
	row_edit = R;
	col_edit = C;

	string cell_value;
	switch (C) {
	case 0: cell_value = get<0>(_pb.getTuple(R)); break;
	case 1: cell_value = get<1>(_pb.getTuple(R)); break;
	case 2: cell_value = std::to_string(get<2>(_pb.getTuple(R))); break;
	default: return;
	}

	// Find X/Y/W/H of cell
	int X, Y, W, H;
	find_cell(context, R, C, X, Y, W, H);
	input->resize(X, Y, W, H);                             // Move Fl_Input widget there
	switch (context) {
	case CONTEXT_CELL:
		input->value(cell_value.c_str()); break;
	default: // shouldn't happen
		input->value("?");
		break;
	}
	input->position(0, strlen(input->value()));          // Select entire input field
	input->show();                                      // Show the input widget, now that we've positioned it
	input->take_focus();
}

void MyTable::done_editing() {
	if (input->visible()) {                             // input widget visible, ie. edit in progress?
		set_value_hide();                                 // Transfer its current contents to cell and hide
	}
}

void MyTable::set_value_hide() {

	_pb.setTuple(row_edit, col_edit, input->value());

	cout << input->value() << "\t" << col_edit << endl;

	input->hide();
	window()->cursor(FL_CURSOR_DEFAULT);                // if we don't do this, cursor can disappear!
}