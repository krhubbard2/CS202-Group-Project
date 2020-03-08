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

//Modify existing record in vector
void modifyRecord(vector<tuple<string, string, double>>& vec)
{
	cout << "Modify a record. "
		<< "First let's find the record you're looking for." << endl;
	cout << "1) Search by last name" << endl;
	cout << "2) Search by first name" << endl;
	cout << "3) Search by phone number" << endl;
	cout << "4) Main menu" << endl;

	//Ensure entry is an int
	string ss1;
	getline(cin, ss1);
	istringstream iss3(ss1);
	int switchval1;
	iss3 >> switchval1;
	//If entry isn't an int go back to main menu
	if (!iss3)
	{
		cout << "Invalid entry. Going back to main menu." << endl;
	}
	else
	{
		switch (switchval1)
		{
			//Search by last name
		case 1:
		{
			cout << "Please enter last name: ";
			string ll1;
			getline(cin, ll1);

			//Finds record based off last name
			auto it = find_if(vec.begin(), vec.end(), [&](const tuple<string, string, double>& e)
				{return get<1>(e) == ll1; });

			//Record found
			if (it != vec.end())
			{
				//Print record
				cout << "Found." << endl;
				cout << get<1>(*it) << ", " << get<0>(*it) << " (" << fixed
					<< setprecision(0) << get<2>(*it) << ")" << endl;

				//Verify record is the correct one to modify
				cout << "Is this the record you'd like to modify? (Y/N)" << endl;
				string yes;
				getline(cin, yes);

				//If correct
				if (yes == "yes" || yes == "Y" || yes == "YES" || yes == "y" || yes == "Yes")
				{
					cout << "What would you like to modify?" << endl;
					cout << "1) Last name" << endl;
					cout << "2) First name" << endl;
					cout << "3) Phone number" << endl;
					cout << "4) Main menu" << endl;

					string modify;
					getline(cin, modify);

					//Ensure selection is an int
					istringstream iss4(modify);
					int switchval2;
					iss4 >> switchval2;

					//If improper selection return to main menu
					if (!iss4)
					{
						cout << "Invalid entry. Going back to main menu." << endl;
					}

					//If proper selection
					else
					{
						switch (switchval2)
						{
							//Modify last name
						case 1:
						{
							cout << "Modify last name." << endl;
							cout << "Please enter a new last name: ";

							//Grab updated last name
							string newlast;
							getline(cin, newlast);

							//Update last name
							get<1>(*it) = newlast;

							//Show user updated information
							cout << "Entry updated." << endl;
							cout << get<1>(*it) << ", " << get<0>(*it) << " (" << fixed
								<< setprecision(0) << get<2>(*it) << ")" << endl;
							cout << "Exiting to main menu." << endl;

							//Return to main menu
							break;
						}
						break;

						//Modify first name
						case 2:
						{
							cout << "Modify first name." << endl;
							cout << "Please enter a new first name: ";

							//grab updated first name
							string newfirst;
							getline(cin, newfirst);

							//update first name
							get<0>(*it) = newfirst;

							//Show user updated information
							cout << "Entry updated." << endl;
							cout << get<1>(*it) << ", " << get<0>(*it) << " (" << fixed
								<< setprecision(0) << get<2>(*it) << ")" << endl;
							cout << "Exiting to main menu." << endl;

							//Return to main menu
							break;
						}
						break;

						//Modify phone number
						case 3:
						{
							cout << "Modify phone number." << endl;
							cout << "Please enter a new phone number: ";

							//Grab updated phone number
							string newphone;
							getline(cin, newphone);
							istringstream iss5(newphone);
							double newp;
							iss5 >> newp;

							//If phone number wasn't a double
							if (!iss5)
							{
								cout << "Invalid entry. Exiting to main menu." << endl;
								break;
							}

							//If phone number was a valid entry
							else
							{
								//Update phone number
								get<2>(*it) = newp;

								//Display updated information
								cout << "Entry updated." << endl;
								cout << get<1>(*it) << ", " << get<0>(*it) << " (" << fixed
									<< setprecision(0) << get<2>(*it) << ")" << endl;
								cout << "Exiting to main menu." << endl;

								//Return to main menu
								break;
							}
						}
						break;

						//Return to main menu
						case 4: break;

							//Return to main menu
						default: break;
						}
					}
				}
				else
				{
					cout << "Returning to main menu." << endl;
					break;
				}
			}
			else
			{
				cout << "No record found." << endl;
			}
		}
		break;

		//Search by first name
		case 2:
		{
			cout << "Please enter first name: ";
			string ff1;
			getline(cin, ff1);

			//Find entry based off first name
			auto it = find_if(vec.begin(), vec.end(), [&](const tuple<string, string, double>& e)
				{return get<0>(e) == ff1; });

			//If entry was found
			if (it != vec.end())
			{
				//Display entry
				cout << "Found." << endl;
				cout << get<1>(*it) << ", " << get<0>(*it) << " (" << fixed
					<< setprecision(0) << get<2>(*it) << ")" << endl;

				//Ensure entry is the one they'd like to modify
				cout << "Is this the record you'd like to modify? (Y/N)" << endl;
				string yes;
				getline(cin, yes);

				//If it is--continue
				if (yes == "yes" || yes == "Y" || yes == "YES" || yes == "y" || yes == "Yes")
				{
					cout << "What would you like to modify?" << endl;
					cout << "1) Last name" << endl;
					cout << "2) First name" << endl;
					cout << "3) Phone number" << endl;
					cout << "4) Main menu" << endl;

					//Ensure selection was an int
					string modify;
					getline(cin, modify);
					istringstream iss4(modify);
					int switchval2;
					iss4 >> switchval2;
					//If invalid selection, break to main menu
					if (!iss4)
					{
						cout << "Invalid entry. Going back to main menu." << endl;
					}
					//If valid selection--continue
					else
					{
						switch (switchval2)
						{
							//Modify last name
						case 1:
						{
							cout << "Modify last name." << endl;
							cout << "Please enter a new last name: ";

							//Grab updated last name
							string newlast;
							getline(cin, newlast);

							//Update last name
							get<1>(*it) = newlast;

							//Display updated information
							cout << "Entry updated." << endl;
							cout << get<1>(*it) << ", " << get<0>(*it) << " (" << fixed
								<< setprecision(0) << get<2>(*it) << ")" << endl;

							//Return to main menu
							cout << "Exiting to main menu." << endl;
							break;
						}
						break;

						//Modify first name
						case 2:
						{
							cout << "Modify first name." << endl;
							cout << "Please enter a new first name: ";

							//Grab updated first name
							string newfirst;
							getline(cin, newfirst);

							//Update first name
							get<0>(*it) = newfirst;

							//Display updated information
							cout << "Entry updated." << endl;
							cout << get<1>(*it) << ", "
								<< get<0>(*it) << " (" << fixed
								<< setprecision(0) << get<2>(*it) << ")"
								<< endl;

							//Return to main menu
							cout << "Exiting to main menu." << endl;
							break;
						}
						break;

						//Modify Phone Number
						case 3:
						{
							cout << "Modify phone number." << endl;
							cout << "Please enter a new phone number: ";

							//Grab new phone number
							string newphone;
							getline(cin, newphone);
							istringstream iss5(newphone);
							double newp;
							iss5 >> newp;

							//If invalid entry return to main menu
							if (!iss5)
							{
								cout << "Invalid entry. Exiting to main menu." << endl;
								break;
							}

							//If valid entry--continue
							else
							{
								//Update phone number
								get<2>(*it) = newp;

								//Display updated information
								cout << "Entry updated." << endl;
								cout << get<1>(*it) << ", " << get<0>(*it)
									<< " (" << fixed << setprecision(0)
									<< get<2>(*it) << ")" << endl;

								//Return to main menu
								cout << "Exiting to main menu." << endl;
							}
						}
						break;

						//Return to main menu
						case 4: break;

							//Return to main menu
						default: break;
						}
					}
				}
				//Return to main menu
				else
				{
					cout << "Returning to main menu." << endl;
					break;
				}
			}

			//If no record found
			else
			{
				cout << "No record found." << endl;
			}
		}
		//Return to main menu
		break;

		//Search by phone number
		case 3:
		{
			cout << "Please enter phone number (no \".\" or \"-\"): ";
			string pp1;
			getline(cin, pp1);
			istringstream iss4(pp1);
			double pp2;
			iss4 >> pp2;
			//If invalid entry
			if (!iss4)
			{
				cout << "Invalid entry." << endl;
			}

			//If proper entry--continue
			else
			{
				//Find entry via phone number
				auto it = find_if(vec.begin(), vec.end(),
					[&](const tuple<string, string, double>& e)
					{return get<2>(e) == pp2; });

				//If matching entry found
				if (it != vec.end())
				{
					//Display entry and verify if it's the correct one to modify
					cout << "Found." << endl;
					cout << get<1>(*it) << ", " << get<0>(*it) << " (" << fixed
						<< setprecision(0) << get<2>(*it) << ")" << endl;
					cout << "Is this the record you'd like to modify? (Y/N)" << endl;
					string yes;
					getline(cin, yes);

					//If correct entry
					if (yes == "yes" || yes == "Y" || yes == "YES"
						|| yes == "y" || yes == "Yes")
					{
						cout << "What would you like to modify?" << endl;
						cout << "1) Last name" << endl;
						cout << "2) First name" << endl;
						cout << "3) Phone number" << endl;
						cout << "4) Main menu" << endl;

						//Grab selection
						string modify;
						getline(cin, modify);
						istringstream iss4(modify);
						int switchval2;
						iss4 >> switchval2;

						//If selection wasn't an int--break
						if (!iss4)
						{
							cout << "Invalid entry. Going back to main menu." << endl;
						}

						//Correct selection
						else
						{
							switch (switchval2)
							{
								//Modify last name
							case 1:
							{
								cout << "Modify last name." << endl;
								cout << "Please enter a new last name: ";

								//Grab new last name
								string newlast;
								getline(cin, newlast);

								//Update last name
								get<1>(*it) = newlast;

								//Display updated information
								cout << "Entry updated." << endl;
								cout << get<1>(*it) << ", " << get<0>(*it)
									<< " (" << fixed << setprecision(0)
									<< get<2>(*it) << ")" << endl;

								//Return to main menu
								cout << "Exiting to main menu." << endl;
								break;
							}
							break;

							//Modify first name
							case 2:
							{
								cout << "Modify first name." << endl;
								cout << "Please enter a new first name: ";

								//Grab new first name
								string newfirst;
								getline(cin, newfirst);

								//Update first name
								get<0>(*it) = newfirst;

								//Display updated information
								cout << "Entry updated." << endl;
								cout << get<1>(*it) << ", " << get<0>(*it)
									<< " (" << fixed << setprecision(0)
									<< get<2>(*it) << ")" << endl;

								//Return to main menu
								cout << "Exiting to main menu." << endl;
								break;
							}
							break;

							//Modify phone number
							case 3:
							{
								cout << "Modify phone number." << endl;
								cout << "Please enter a new phone number: ";

								//Grab new phone number
								string newphone;
								getline(cin, newphone);
								istringstream iss5(newphone);
								double newp;
								iss5 >> newp;

								//Invalid entry
								if (!iss5)
								{
									cout << "Invalid entry. Exiting to main menu." << endl;
									break;
								}

								//Correct entry--continue
								else
								{
									//Update phone number
									get<2>(*it) = newp;

									//Display updated information
									cout << "Entry updated." << endl;
									cout << get<1>(*it) << ", " << get<0>(*it)
										<< " (" << fixed << setprecision(0)
										<< get<2>(*it) << ")" << endl;

									//Return to main menu
									cout << "Exiting to main menu." << endl;
								}
							}
							break;

							//Return to main menu
							case 4: break;

								//Return to main menu
							default: break;
							}
						}
					}
					//Return to main menu
					else
					{
						cout << "Returning to main menu." << endl;
						break;
					}
				}
				//No matching record found
				else
				{
					cout << "No record found." << endl;
				}
			}
		}
		break;

		//Return to main menu
		case 4: break;

			//Return to main menu
		default: break;
		}
	}
}

//Base Search Record Function
void searchRecord(vector<tuple<string, string, double>>& vec)
{
	cout << "Search record." << endl;
	cout << "1) Search by last name" << endl;
	cout << "2) Search by first name" << endl;
	cout << "3) Search by phone number" << endl;
	cout << "4) Main menu" << endl;

	//Grab selection
	string s1;
	getline(cin, s1);
	istringstream iss2(s1);
	int switchval;
	iss2 >> switchval;

	//Invalid selection
	if (!iss2)
	{
		cout << "Invalid entry. Going back to main menu." << endl;
	}

	//Valid selection--continue
	switch (switchval)
	{

		//Search record by last name
	case 1:
	{
		cout << "Please enter last name: ";

		//Grab name to search
		string l1;
		getline(cin, l1);

		//Search
		searchRecordLast(vec, l1);
	}
	break;

	//Search record by first name
	case 2:
	{
		cout << "Please enter first name: ";

		//Grab name to search
		string f1;
		getline(cin, f1);

		//Search
		searchRecordFirst(vec, f1);
	}
	break;

	//Search record by phone number
	case 3:
	{
		cout << "Please enter phone number (no \".\" or \"-\"): ";

		//Grab number to search
		string p1;
		getline(cin, p1);
		istringstream iss3(p1);
		double p2;
		iss3 >> p2;

		//If not a number
		if (!iss3)
		{
			cout << "Invalid entry." << endl;
		}

		//If a number
		else
		{
			//Search
			searchRecordPhone(vec, p2);
		}
	}

	//Return to main menu
	case 4: break;

		//Return to main menu
	default: break;
	}
}