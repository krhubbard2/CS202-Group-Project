// Kelby Hubbard
// Chaluunbat Purev
// CS202 Group Project
// The Alaskan Phonebook
#include "phonebook.hpp"
#include "fltk.hpp"


int main(int argc, char** argv)
{

  runFLTK();
  return Fl::run();

  vector<tuple<string, string, double>> phonebook;

  //Sample entrys
  phonebook.push_back(make_tuple("BTestF", "BTestL", 3607029067));
  phonebook.push_back(make_tuple("DTestF", "DTestL", 3607029061));
  phonebook.push_back(make_tuple("ATestF", "ATestL", 3607029066));
  phonebook.push_back(make_tuple("CTestF", "CTestL", 3607029068));


  cout << "The Alaskan Phonebook!" << endl;

  bool mainLoop = true;

  //Main program in never ending loop (until exit)
  while (mainLoop)
  {
  cout << "Please choose an option from below." << endl;

  //Display menu
  printMenu();

  bool loop = true;
  int switchx;

  //Ensure proper entry for main menu selection
  while (loop)
  {
      string line;
      getline(cin, line);

      int selection;
      istringstream iss(line);
      iss >> selection;

      //Invalid entry (not an int)
      if (!iss)
      {
        cout << "Invalid entry. Please enter an integer." << endl;
        loop = true;
      }
      else
      {
        //Invalid entry (not 1-5)
        if (selection < 1 || selection > 6)
        {
          cout << "Invalid entry. Please select 1-6." << endl;
          loop = true;
        }
        //Proper entry. Continuing program.
        else
        {
          switchx = selection;
          loop = false;
        }
      }
  }

  //Menu selection

    switch (switchx)
    {
      //Add Record
      case 1:
              addRecord(phonebook);
              break;

      //Print Record
      case 2:
              sort(phonebook.begin(), phonebook.end(), sortVec);
              printRecords(phonebook);
              break;

      //Modify Record
      case 3: modifyRecord(phonebook);
              break;

      //Search Record
      case 4: searchRecord(phonebook);
              break;

      //Delete Record
      case 5: deleteRecord(phonebook);
              break;

      //Exit Program
      case 6: mainLoop = false;
              break;
    }
  }

  cout << "Goodbye." << endl;
  
}
