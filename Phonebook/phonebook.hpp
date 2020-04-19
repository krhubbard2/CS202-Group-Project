// Kelby Hubbard
// Chaluunbat Purev
// CS202 Group Project
// The Alaskan Phonebook
#ifndef PHONEBOOK_HPP_
#define PHONEBOOK_HPP_

//////////////////////////////////////////////////////
// L I B R A R I E S /////////////////////////////////
//////////////////////////////////////////////////////

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
using std::getline;
#include <fstream>
using std::ofstream;
using std::ifstream;
#include <sstream>
using std::istringstream;
#include <vector>
using std::vector;
#include <tuple>
using std::tuple;
using std::make_tuple;
using std::get;
#include <iomanip>
using std::setw;
using std::fixed;
using std::setprecision;
#include <algorithm>
using std::sort;
using std::find;
using std::find_if;


class Phonebook {
public:
	Phonebook(const vector<tuple<string, string, double>>& phonebook) : _phonebook(phonebook) {}
	Phonebook() {}

	//Return ROW/Tuple
	tuple<string, string, double> getTuple(const int& n) const;
	
	//Edit ROW/Tuple
	void setTuple(int R, int C, std::string str);

	size_t size() const;

	//Opens and imports saved entries
	void openFile(const string& fileName);

	//Saves entries for importing later
	void saveFile(const string& fileName);

	//Displays main menu
	void printMenu();

	//Adds a new record to vector
	void addRecord();

	//Prints all current records
	void printRecords() const;

	//Allows user to modify existing records.
	void modifyRecord();

	//Deletes record (implements deleteRecord(F,L,P))
	void deleteRecord(const int& n);

	void setPhonebook(vector<tuple<string, string, double>> v_) {_phonebook = v_; }


	////Sorts all current records by last name
	//bool sortVec(const tuple<string, string, double>& a,
	//	const tuple<string, string, double>& b);
	////Search records by last name
	//void searchRecordLast(vector<tuple<string, string, double>> vec, string name);
	//
	////Search records by first name
	//void searchRecordFirst(vector<tuple<string, string, double>> vec, string name);
	//
	////Search records by phone number
	//void searchRecordPhone(vector<tuple<string, string, double>> vec, double phone);
	//
	////Searches existing records
	//void searchRecord(vector<tuple<string, string, double>> &vec);
	//
private:
	vector<tuple<string, string, double>> _phonebook;
};



#endif
