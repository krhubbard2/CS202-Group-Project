// Kelby Hubbard
// Chaluunbat Purev
// CS202 Group Project
// The Alaskan Phonebook
#include "phonebook.hpp"

tuple<string, string, double> Phonebook::getTuple(const int& n) const { return _phonebook[n]; }
void Phonebook::setTuple(int R, int C, std::string str) {
	auto t = &_phonebook[R];

	switch (C) {
	case 0: get<0>(*t) = str; break;
	case 1: get<1>(*t) = str; break;
	case 2: try { get<2>(*t) = std::stoi(str); }
		  catch (std::invalid_argument e) { break; }
		  break;
	}
}
size_t Phonebook::size() const { return _phonebook.size(); }

void Phonebook::deleteRecord(const int& n) {
	_phonebook.erase(_phonebook.begin() + n);
}

void Phonebook::saveFile(const string& fileName)
{
	ofstream ifile(fileName);
	if (ifile.is_open())
	{
		for (auto i = 0; i < _phonebook.size(); i++)
		{
			string fname, lname;
			double phone;
			fname = get<0>(_phonebook[i]);
			lname = get<1>(_phonebook[i]);
			phone = get<2>(_phonebook[i]);
			ifile << fname << " " << lname << " " << setprecision(9) << phone << endl;
		}
	}
}

void Phonebook::openFile(const string& fileName)
{
	_phonebook.clear();
  string line;
  string firstName;
  string lastName;
  double phoneNumber;
  ifstream ifile(fileName);
  //If file doesn't open
  if (!ifile)
  {
    cout << "Couldn't open file." << endl;
  }
  //If file opens correctly
  else
  {
    bool loop = true;
    while (loop)
    {
      //If file runs to error
      if(!ifile)
      {
        //If EOF end loop
        if (ifile.eof())
        {
          loop = false;
        }
        else
        {
          loop = true;
        }
      }
      //If file not EOF
      else
      {
        getline(ifile, line);
        istringstream iss(line);
        if(!ifile.eof())
        {
          istringstream iss1(line);
          for (int i = 0; i < 3; i++)
          {
            if (i == 0)
            {
              iss1 >> firstName;
            }
            else if (i == 1)
            {
              iss1 >> lastName;
            }
            else if (i == 2)
            {
              iss1 >> phoneNumber;
            }
          }
          if (iss)
          {
            _phonebook.push_back(make_tuple(firstName, lastName, phoneNumber));
          }

        }
      }
    }
  }
}

//Adds record to existing Vector
void Phonebook::addRecord(const string& first, const string& last, const double& phone)
{
  //Adds input to Vector
  _phonebook.push_back(make_tuple(first,last, phone));
}

//Sort vector (tuple) by second item (last name)
bool sortVec(const tuple<string, string, double>&a,
         const tuple<string, string, double>&b)
{
 return(get<1>(a) < get<1>(b));
}

//Prints record out to user "Last, First Number"
void Phonebook::printRecords() const
{
  //If vector is empty, show user
  if (_phonebook.size() == 0)
  {
    cout << "Database is empty." << endl;
  }
  //Print database in form of Last, First & Phonenumber
  else
  {
    cout << "Names" << setw(40) << "Phone" << " numbers" << endl;
    for (auto p : _phonebook)
    {
      cout << get<1>(p) << ", " << get<0>(p) << setw(40)
           << fixed << std::setprecision(0) << get<2>(p) << endl;
    }
  }
}
