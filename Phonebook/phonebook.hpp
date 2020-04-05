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




//////////////////////////////////////////////////////
// P R O T O T Y P E S ///////////////////////////////
//////////////////////////////////////////////////////

//Displays main menu
void printMenu();

//Adds a new record to vector
void addRecord(vector<tuple<string, string, double>> &vec);

//Sorts all current records by last name
bool sortVec(const tuple<string, string, double>&a,
          const tuple<string, string, double>&b);

//Prints all current records
void printRecords(vector<tuple<string, string, double>> &vec);

//Allows user to modify existing records.
void modifyRecord(vector<tuple<string, string, double>> &vec);

////Search records by last name
//void searchRecordLast(vector<tuple<string, string, double>> vec, string name);
//
////Search records by first name
//void searchRecordFirst(vector<tuple<string, string, double>> vec, string name);
//
////Search records by phone number
//void searchRecordPhone(vector<tuple<string, string, double>> vec, double phone);
//
////Delete record by last name
//void deleteRecordLast(vector<tuple<string, string, double>> &vec, string name);
//
////Delete record by first name
//void deleteRecordFirst(vector<tuple<string, string, double>> &vec, string name);
//
////Delete record by phone number
//void deleteRecordPhone(vector<tuple<string, string, double>> &vec, double phone);
//
////Searches existing records
//void searchRecord(vector<tuple<string, string, double>> &vec);
//
////Deletes record (implements deleteRecord(F,L,P))
//void deleteRecord(vector<tuple<string, string, double>> &vec);


#endif
