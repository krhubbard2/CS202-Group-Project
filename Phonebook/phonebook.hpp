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
	void setPhone(int R, int C, std::string str);

	//this called when clear button pressed
	void clearSearch();

	//Search the string in all columns and populate searched with them
	void setSearch(const string& str);

	//Return size of phonebook
	size_t size() const;

	//Opens and imports saved entries
	void openFile(const string& fileName);

	//Saves entries for importing later
	void saveFile(const string& fileName);

	//Adds a new record to vector
	void addRecord(const string& first, const string& last,const double& phone);

	//Prints all current records
	void printRecords() const;

	//Deletes record (implements deleteRecord(F,L,P))
	void deleteRecord(const int& n);

	void setPhonebook(vector<tuple<string, string, double>> v_) {_phonebook = v_; }

	vector<tuple<string, string, double>>::iterator begin() { return _phonebook.begin(); }
	vector<tuple<string, string, double>>::iterator end() { return _phonebook.end(); }

private:
	vector<tuple<string, string, double>> _phonebook;
	vector<tuple<string, string, double>> _searched;
};

bool sortVec(const tuple<string, string, double>& a,
						 const tuple<string, string, double>& b);

#endif
