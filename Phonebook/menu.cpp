// Kelby Hubbard
// Chaluunbat Purev
// CS202 Group Project
// The Alaskan Phonebook
#include "phonebook.hpp"
//Prints Main Menu
void printMenu()
{
  cout << "1) Add telephone record" << endl;
  cout << "2) Show records" << endl;
  cout << "3) Modify record" << endl;
  cout << "4) Search telephone record" << endl;
  cout << "5) Delete record" << endl;
  cout << "6) Exit" << endl;
}


//Adds record to existing Vector
void addRecord(vector<tuple<string, string, double>> &vec)
{
  cout << "Adding new record." << endl;
  cout << "First name: ";

  //Grabs First Name
  string firstname;
  getline(cin, firstname);

  cout << "Last name: ";

  //Grabs Last Name
  string lastname;
  getline(cin, lastname);

  double phone;

  //Grabs Phone Number (Ensures proper input)
  bool loop1 = true;
  while (loop1)
  {
    cout << "Phone number including area code (no \"-\" or \".\"): ";
    string number;
    getline (cin, number);
    istringstream iss1(number);
    double num;
    iss1 >> num;

    //Ensures phone number is a double
    if (!iss1)
    {
      cout << "Error. Improper entry. Please enter a 9 digit phone number." << endl;
      loop1 = true;
    }
    else
    {
      //Ensure number is proper area code and length
      if (num <= 2000000000 || num >= 9999999999)
      {
        cout << "Error. Invalid phone number." << endl;
        loop1 = true;
      }
      else
      {
        phone = num;
        loop1 = false;
      }
    }
  }
  //Adds input to Vector
  vec.push_back(make_tuple(firstname, lastname, phone));
  cout << "Entry added succesfully." << endl;
}


//Sort vector (tuple) by second item (last name)
bool sortVec(const tuple<string, string, double>&a,
          const tuple<string, string, double>&b)
{
  return(get<1>(a) < get<1>(b));
}


//Prints record out to user "Last, First Number"
void printRecords(vector<tuple<string, string, double>> &vec)
{
  //If vector is empty, show user
  if (vec.size() == 0)
  {
    cout << "Database is empty." << endl;
  }
  //Print database in form of Last, First & Phonenumber
  else
  {
    cout << "Names" << setw(40) << "Phone" << " numbers" << endl;
    for (auto p : vec)
    {
      cout << get<1>(p) << ", " << get<0>(p) << setw(40)
           << fixed << std::setprecision(0) << get<2>(p) << endl;
    }
  }
}
