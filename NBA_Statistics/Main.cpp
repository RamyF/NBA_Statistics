#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <time.h>
#include "ActiveGuard.h"
#include "ActiveFoward.h"
#include "ActiveCenter.h"
#include "Admin.h"
#include "GeneralUser.h"
#include "Structs.cpp"

using namespace std;

// function prototypes
void LoginScreen(bool &loginSuccessful, char &isAdmin);
void LoadPlayers(ActiveGuard *&activeGuardsPtr, ActiveFoward *&activeFowardsPtr, ActiveCenter *&activeCentersPtr);
string CapitalizeFirstLetters(string);
void FindPlayer(ActiveGuard(&activeGuards)[27], ActiveFoward(&activeFowards)[18], ActiveCenter(&activeCenters)[12], bool &isGuard, bool &isFoward, bool &isCenter, int &playerIndex, string const nameToSearch);

int main()
{
	int choice = 0;
	while (choice != 4)
	{
		// Login Info
		bool loginSuccessful = false;
		char isAdmin;
		LoginScreen(loginSuccessful, isAdmin); // handle login
		// main func variables
		int amountOfPlayers;
		string nameToSearch;
		bool returnToMainMenu = false;

		while (loginSuccessful)
		{

			ActiveGuard activeGuards[27];
			ActiveFoward activeFowards[18];
			ActiveCenter activeCenters[12];
			ActiveGuard *activeGuardsPtr = activeGuards;
			ActiveFoward *activeFowardsPtr = activeFowards;
			ActiveCenter *activeCentersPtr = activeCenters;
			int amountOfPlayers = size(activeGuards) + size(activeFowards) + size(activeCenters);
			int subChoice = 0;
			ActiveGuard *tempGuard = new ActiveGuard(); // stores temporary points while being swapped
			ActiveFoward *tempFoward = new ActiveFoward();
			ActiveCenter *tempCenter = new ActiveCenter();
			// menu
			cout << endl << endl << "MAIN MENU" << endl;
			cout << "--------" << endl;
			cout << "1. Player Search" << endl;
			cout << "2. Leaderboards" << endl;

			if (isAdmin == 'Y')
				cout << "3. Players To Be Added" << endl;
			else
				cout << "3. Request Player" << endl;

			cout << "4. Exit Program" << endl;
			cout << "Enter Selection: "; 
			cin >> choice;
			while (choice < 0 || choice > 4)
			{
				cout << "That is an invalid selection" << endl;
				cout << "Enter a correct selection: ";
				cin >> choice;
			}

			switch (choice)
			{
			case 1:
				LoadPlayers(activeGuardsPtr, activeFowardsPtr, activeCentersPtr);
				while (!returnToMainMenu)
				{
					cin.ignore();
					cout << "Please enter the players first and last name: ";
					getline(cin, nameToSearch);
					nameToSearch = CapitalizeFirstLetters(nameToSearch);

					// find player in arrays
					bool isGuard = false, isFoward = false, isCenter = false;
					int playerIndex = -1;
					FindPlayer(activeGuards, activeFowards, activeCenters, isGuard, isFoward, isCenter, playerIndex, nameToSearch);

					if (isGuard == true)
					{
						cout << "\n\n\nName: " << activeGuards[playerIndex] << endl;
						activeGuards[playerIndex].PrintPlayer();
					}

					else if (isFoward == true)
					{
						cout << "\n\n\nName: " << activeFowards[playerIndex] << endl;
						activeFowards[playerIndex].PrintPlayer();
					}

					else if (isCenter == true)
					{
						cout << "\n\n\nName: " << activeCenters[playerIndex] << endl;
						activeCenters[playerIndex].PrintPlayer();
					}

					cout << "Search for another player? (Y or N): ";
					char response;
					cin >> response;
					response = toupper(response);
					if (response != 'Y')
						returnToMainMenu = true;
				}
				//case 2:
				break;
			case 2:
				LoadPlayers(activeGuardsPtr, activeFowardsPtr, activeCentersPtr);
				cout << "\n\n\n1. Points" << endl;
				cout << "2. Assists" << endl;
				cout << "3. Rebounds" << endl;
				cout << "4. PER" << endl;
				cout << "5. Offensive Rating" << endl;
				cout << "6. Defensive Rating" << endl;
				cout << "Enter Selection: ";
				cin >> subChoice;
				while (subChoice < 0 || choice > 1)
				{
					cout << "That is an invalid selectio or that section has not been implemneted yet" << endl;
					cout << "Enter a correct selection: ";
					cin >> choice;
				}
				switch (subChoice)
				{
				case 1:
					int end = size(activeGuards);
					// sort guards array by points
					for (int i = 0; i < (size(activeGuards) - 1); i++)
					{
						for (int i = 0; i < end; i++)
						{
							if (activeGuards[i].GetPoints() < activeGuards[i + 1].GetPoints()) // check if next index has a higher points per game
							{
								*tempGuard = activeGuards[i + 1]; // temporary guard holder to switch players
								activeGuards[i + 1] = activeGuards[i]; // switch player
								activeGuards[i] = *tempGuard; // switch player
							}

						}
						end--; // shorten length to compare adjecent players
					}
					delete tempGuard;


					// sort fowards array by points
					end = size(activeFowards);
					for (int i = 0; i < (size(activeFowards) - 1); i++)
					{
						for (int i = 0; i < end; i++)
						{
							if (activeFowards[i].GetPoints() < activeFowards[i + 1].GetPoints())
							{
								*tempFoward = activeFowards[i + 1];
								activeFowards[i + 1] = activeFowards[i];
								activeFowards[i] = *tempFoward;
							}

						}
						end--;
					}
					delete tempFoward;

					// sort centers array by points
					end = size(activeCenters);
					for (int i = 0; i < (size(activeCenters) - 1); i++)
					{
						for (int i = 0; i < end; i++)
						{
							if (activeCenters[i].GetPoints() < activeCenters[i + 1].GetPoints())
							{
								*tempCenter = activeCenters[i + 1];
								activeCenters[i + 1] = activeCenters[i];
								activeCenters[i] = *tempCenter;
							}

						}
						end--;
					}
					delete tempCenter;

					// print sorted player name and ppg values
					int indexGuards = size(activeGuards);
					int indexFowards = size(activeFowards);
					int indexCenters = size(activeCenters);
					int counter = 0;
					if (indexGuards < indexFowards && indexGuards < indexCenters) // check if guards array is the shortest (cant correctly print sorted arrays that are different lengths. So find smallest array)
					{
						for (int i = 0; i < indexGuards; i++)
						{
							if (activeGuards[i].GetPoints() > activeFowards[i].GetPoints() && // check if guard's points at given index is larger than foward and center
								activeGuards[i].GetPoints() > activeCenters[i].GetPoints())
							{
								counter++;
								cout << counter << ". " << activeGuards[i].GetFullName() << "\t" << activeGuards[i].GetPoints() << endl;
								if (activeFowards[i].GetPoints() > activeCenters[i].GetPoints()) // check which position after guard to print next (next highest points either foward or center)
								{
									counter++;
									cout << counter << ". " << activeFowards[i].GetFullName() << "\t" << activeFowards[i].GetPoints() << endl;
									counter++;
									cout << counter << ". " << activeCenters[i].GetFullName() << " " << activeCenters[i].GetPoints() << endl;
								}
								else
								{
									counter++;
									cout << counter << ". " << activeCenters[i].GetFullName() << "\t" << activeCenters[i].GetPoints() << endl;
									counter++;
									cout << counter << ". " << activeFowards[i].GetFullName() << " " << activeFowards[i].GetPoints() << endl;
								}
							}

							else if (activeFowards[i].GetPoints() > activeGuards[i].GetPoints() && activeFowards[i].GetPoints() > activeCenters[i].GetPoints()) // check if fowards's points at given index is larger than guard and center
							{
								counter++;
								cout << counter << ". " << activeFowards[i].GetFullName() << "\t" << activeFowards[i].GetPoints() << endl;
								if (activeGuards[i].GetPoints() > activeCenters[i].GetPoints())
								{
									counter++;
									cout << counter << ". " << activeGuards[i].GetFullName() << "\t" << activeGuards[i].GetPoints() << endl;
									counter++;
									cout << counter << ". " << activeCenters[i].GetFullName() << " " << activeGuards[i].GetPoints() << endl;
								}

								else
								{
									counter++;
									cout << counter << ". " << activeCenters[i].GetFullName() << " " << activeGuards[i].GetPoints() << endl;
									counter++;
									cout << counter << ". " << activeGuards[i].GetFullName() << "\t" << activeGuards[i].GetPoints() << endl;
								}
							}

							else
							{
								counter++;
								cout << counter << ". " << activeCenters[i].GetFullName() << "\t" << activeCenters[i].GetPoints() << endl;
								if (activeGuards[i].GetPoints() > activeFowards[i].GetPoints())
								{
									counter++;
									cout << counter << ". " << activeGuards[i].GetFullName() << "\t" << activeGuards[i].GetPoints() << endl;
									counter++;
									cout << counter << ". " << activeFowards[i].GetFullName() << " " << activeGuards[i].GetPoints() << endl;
								}

								else
								{
									counter++;
									cout << counter << ". " << activeFowards[i].GetFullName() << " " << activeGuards[i].GetPoints() << endl;
									counter++;
									cout << counter << ". " << activeGuards[i].GetFullName() << "\t" << activeGuards[i].GetPoints() << endl;
								}
							}
						}

					}

					else if (indexFowards < indexGuards && indexFowards < indexGuards)  // same algorithm as above (see comments inside of above if statement)
					{
						for (int i = 0; i < indexFowards; i++)
						{
							if (activeGuards[i].GetPoints() > activeFowards[i].GetPoints() &&
								activeGuards[i].GetPoints() > activeCenters[i].GetPoints())
							{
								counter++;
								cout << counter << ". " << activeGuards[i].GetFullName() << "\t" << activeGuards[i].GetPoints() << endl;
								if (activeFowards[i].GetPoints() > activeCenters[i].GetPoints())
								{
									counter++;
									cout << counter << ". " << activeFowards[i].GetFullName() << "\t" << activeFowards[i].GetPoints() << endl;
									counter++;
									cout << counter << ". " << activeCenters[i].GetFullName() << " " << activeCenters[i].GetPoints() << endl;
								}
								else
								{
									counter++;
									cout << counter << ". " << activeCenters[i].GetFullName() << "\t" << activeCenters[i].GetPoints() << endl;
									counter++;
									cout << counter << ". " << activeFowards[i].GetFullName() << " " << activeFowards[i].GetPoints() << endl;
								}
							}

							else if (activeFowards[i].GetPoints() > activeGuards[i].GetPoints() && activeFowards[i].GetPoints() > activeCenters[i].GetPoints())
							{
								counter++;
								cout << counter << ". " << activeFowards[i].GetFullName() << "\t" << activeFowards[i].GetPoints() << endl;
								if (activeGuards[i].GetPoints() > activeCenters[i].GetPoints())
								{
									counter++;
									cout << counter << ". " << activeGuards[i].GetFullName() << "\t" << activeGuards[i].GetPoints() << endl;
									counter++;
									cout << counter << ". " << activeCenters[i].GetFullName() << " " << activeGuards[i].GetPoints() << endl;
								}

								else
								{
									counter++;
									cout << counter << ". " << activeCenters[i].GetFullName() << " " << activeGuards[i].GetPoints() << endl;
									counter++;
									cout << counter << ". " << activeGuards[i].GetFullName() << "\t" << activeGuards[i].GetPoints() << endl;
								}
							}

							else
							{
								counter++;
								cout << counter << ". " << activeCenters[i].GetFullName() << "\t" << activeCenters[i].GetPoints() << endl;
								if (activeGuards[i].GetPoints() > activeFowards[i].GetPoints())
								{
									counter++;
									cout << counter << ". " << activeGuards[i].GetFullName() << "\t" << activeGuards[i].GetPoints() << endl;
									counter++;
									cout << counter << ". " << activeFowards[i].GetFullName() << " " << activeGuards[i].GetPoints() << endl;
								}

								else
								{
									counter++;
									cout << counter << ". " << activeFowards[i].GetFullName() << " " << activeGuards[i].GetPoints() << endl;
									counter++;
									cout << counter << ". " << activeGuards[i].GetFullName() << "\t" << activeGuards[i].GetPoints() << endl;
								}
							}
						}

					}

					else
					{
						for (int i = 0; i < indexCenters; i++)
						{
							if (activeGuards[i].GetPoints() > activeFowards[i].GetPoints() &&
								activeGuards[i].GetPoints() > activeCenters[i].GetPoints())
							{
								counter++;
								cout << counter << ". " << activeGuards[i].GetFullName() << "\t" << activeGuards[i].GetPoints() << endl;
								if (activeFowards[i].GetPoints() > activeCenters[i].GetPoints())
								{
									counter++;
									cout << counter << ". " << activeFowards[i].GetFullName() << "\t" << activeFowards[i].GetPoints() << endl;
									counter++;
									cout << counter << ". " << activeCenters[i].GetFullName() << " " << activeCenters[i].GetPoints() << endl;
								}
								else
								{
									counter++;
									cout << counter << ". " << activeCenters[i].GetFullName() << "\t" << activeCenters[i].GetPoints() << endl;
									counter++;
									cout << counter << ". " << activeFowards[i].GetFullName() << " " << activeFowards[i].GetPoints() << endl;
								}
							}

							else if (activeFowards[i].GetPoints() > activeGuards[i].GetPoints() && activeFowards[i].GetPoints() > activeCenters[i].GetPoints())
							{
								counter++;
								cout << counter << ". " << activeFowards[i].GetFullName() << "\t" << activeFowards[i].GetPoints() << endl;
								if (activeGuards[i].GetPoints() > activeCenters[i].GetPoints())
								{
									counter++;
									cout << counter << ". " << activeGuards[i].GetFullName() << "\t" << activeGuards[i].GetPoints() << endl;
									counter++;
									cout << counter << ". " << activeCenters[i].GetFullName() << " " << activeGuards[i].GetPoints() << endl;
								}

								else
								{
									counter++;
									cout << counter << ". " << activeCenters[i].GetFullName() << " " << activeGuards[i].GetPoints() << endl;
									counter++;
									cout << counter << ". " << activeGuards[i].GetFullName() << "\t" << activeGuards[i].GetPoints() << endl;
								}
							}

							else
							{
								counter++;
								cout << counter << ". " << activeCenters[i].GetFullName() << "\t" << activeCenters[i].GetPoints() << endl;
								if (activeGuards[i].GetPoints() > activeFowards[i].GetPoints())
								{
									counter++;
									cout << counter << ". " << activeGuards[i].GetFullName() << "\t" << activeGuards[i].GetPoints() << endl;
									counter++;
									cout << counter << ". " << activeFowards[i].GetFullName() << " " << activeGuards[i].GetPoints() << endl;
								}

								else
								{
									counter++;
									cout << counter << ". " << activeFowards[i].GetFullName() << " " << activeGuards[i].GetPoints() << endl;
									counter++;
									cout << counter << ". " << activeGuards[i].GetFullName() << "\t" << activeGuards[i].GetPoints() << endl;
								}
							}
						}
					} // same algorithm as above (see comments inside of above if statement)


					break;
				/*default:
					cout << "Not implemented";
					break;*/
					//case 2:
					//	break;
					//case 3:
					//	break;
					//case 4:
					//	break;
					//case 5:
					//	break;
					//case 6:
					//	break;


				}
				/*case 3:
					cout << "Not Implemented" << endl;*/
					
				case 4:
					system("Pause");
					return 0;
				break;
			}



		}

		while (loginSuccessful == false)
		{
			cout << "\nUser not found!\n";
			LoginScreen(loginSuccessful, isAdmin);
		}
	}
	system("Pause");
	return 0;
}

// handles login functionality
void LoginScreen(bool &loginSuccessful, char &isAdmin)
{
	int choice;
	cout << "LOGIN SCREEN" << endl;
	cout << "------------\n\n";
	cout << "1. Returning User" << endl;
	cout << "2. Create an Account" << endl;
	cout << "Enter Selection: ";
	cin >> choice;
	while (choice != 1 && choice != 2)
	{
		cout << "That is an invalid selection" << endl;
		cout << "Enter a correct selection: ";
		cin >> choice;
	}
	string fUsername, fPassword, fFirstName, fLastName, joinDate;
	if (choice == 1)
	{
		// recieve username and password from user
		string username;
		string password;
		cout << "\nEnter Username: "; // add validation
		cin >> username;
		cout << "Enter Password: "; // add validation
		cin >> password;
		ifstream infile;
		bool *LoginSuccessfulPtr = &loginSuccessful; // used just for requiremnet fyi used on line 464
		
		
		infile.open("AdminInfo.txt");
		while (!infile.eof())
		{
			infile >> fFirstName >> fLastName >> fUsername >> fPassword;
			if (fUsername == username && fPassword == password)
			{
				Admin adminUser = Admin(fFirstName, fLastName,  fUsername,  fPassword);
				if (adminUser.GetStatus() == 0)
				{
					isAdmin = 'Y';
					*LoginSuccessfulPtr = true;
					cout << ".....Login Authenticated\n\n";
				}
			}

		}
		infile.close();

		infile.open("UserInfo.txt");
		while (!infile.eof())
		{
			infile >> fFirstName >> fLastName >> fUsername >> fPassword >> joinDate;
			if (fUsername == username && fPassword == password)
			{
				GeneralUser gUser = GeneralUser(fFirstName, fLastName, fUsername, fPassword, joinDate);
				loginSuccessful = true;
				cout << ".....Login Authenticated\n\n";
			}
		}
	}

	else if (choice == 2)
	{
		cout << "Enter First Name: ";
		cin >> fFirstName;
		cout << "Enter Last Name: ";
		cin >> fLastName;
		cout << "Enter Username: ";
		cin >> fUsername;
		cout << "Enter Password: ";
		cin >> fPassword;
		char date[9];
		_strdate_s(date);
		joinDate = date;

		ofstream outfile;
		outfile.open("UserInfo.txt", ios::app);
		outfile << "\n" << fFirstName << " " << fLastName << " " << fUsername << " " << fPassword << " "<< joinDate;
		outfile.close();

		cout << "User has been added" << endl;
		loginSuccessful = true;
	}

}

// load players from txt files
void LoadPlayers(ActiveGuard *&activeGuardsPtr, ActiveFoward *&activeFowardsPtr, ActiveCenter *&activeCentersPtr)
{
	ifstream infile;

	// read from file to instantiate Active Guards
	infile.open("ActiveGuard.txt");
	int i = 0;
	while (!infile.eof())
	{
		string firstName, lastName, height, college, team;
		int jerseyNum, draftYear, age, yearsExp;
		double weight, points, assists, freethrowPercent, twoPointPercent, threePointPercent, per, offRating, defRating, steals, turnovers;
		infile >> firstName >> lastName >> jerseyNum >> height >> draftYear >> weight >> college >> points >> assists >> freethrowPercent >> twoPointPercent >>
			threePointPercent >> per >> offRating >> defRating >> age >> steals >> turnovers >> yearsExp >> team;
		if (firstName == "")
			break;
		activeGuardsPtr[i] = ActiveGuard(firstName, lastName, jerseyNum, height, draftYear, weight, college, points,
			assists, freethrowPercent, twoPointPercent, threePointPercent, per, offRating,
			defRating, age, steals, turnovers, yearsExp, team);
		i++;
	}
	infile.close();

	// read from file to instatiate active fowards
	infile.open("ActiveFoward.txt");
	i = 0;
	while (!infile.eof())
	{
		string firstName, lastName, height, college, team;
		int jerseyNum, draftYear, age, yearsExp;
		double weight, points, rebounds, assists, freethrowPercent, twoPointPercent, threePointPercent, per, offRating, defRating, steals, turnovers, blocks;
		infile >> firstName >> lastName >> jerseyNum >> height >> draftYear >> weight >> college >> points >> rebounds >> assists >> freethrowPercent >> twoPointPercent >>
			threePointPercent >> per >> offRating >> defRating >> age >> steals >> turnovers >> blocks >> team >> yearsExp;
		if (firstName == "")
			break;
		activeFowardsPtr[i] = ActiveFoward(firstName, lastName, jerseyNum, height, draftYear, weight, college, points, rebounds, assists, freethrowPercent, twoPointPercent,
			threePointPercent, per, offRating, defRating, age, steals, turnovers, blocks, team, yearsExp);
		i++;
	}
	infile.close();

	// read from file to instatiate active centers
	infile.open("ActiveCenter.txt");
	i = 0;
	while (!infile.eof())
	{
		string firstName, lastName, height, college, team;
		int jerseyNum, draftYear, age, yearsExp;
		double weight, points, assists, freethrowPercent, twoPointPercent, threePointPercent, per, offRating, defRating, blocks, offRebounds, defRebounds;

		infile >> firstName >> lastName >> jerseyNum >> height >> draftYear >> weight >> college >> points >> assists >> freethrowPercent >> twoPointPercent >>
			threePointPercent >> per >> offRating >> defRating >> age >> blocks >> offRebounds >> defRebounds >> yearsExp >> team;
		if (firstName == "")
			break;
		activeCentersPtr[i] = ActiveCenter(firstName, lastName, jerseyNum, height, draftYear, weight, college, points, assists, freethrowPercent, twoPointPercent,
			threePointPercent, per, offRating, defRating, age, blocks, offRebounds, defRebounds, yearsExp, team);
		i++;
	}
	infile.close();
}

// Capitalizes first letter in every word
string CapitalizeFirstLetters(string inputString)
{
	int sizeofString = inputString.length();
	char *stringCpy = new char[sizeofString + 1];
	strcpy_s(stringCpy, (sizeofString + 1), inputString.c_str());
	stringCpy[0] = toupper(inputString[0]);

	for (int i = 1; i < sizeofString; i++)
	{
		if (stringCpy[i - 1] == ' ')
			stringCpy[i] = toupper(stringCpy[i]);
		else
			stringCpy[i] = tolower(stringCpy[i]);
	}
	inputString = stringCpy;
	delete[] stringCpy;
	return inputString;
}

void FindPlayer(ActiveGuard (&activeGuards)[27], ActiveFoward (&activeFowards)[18], ActiveCenter (&activeCenters)[12], bool &isGuard, bool &isFoward, bool &isCenter, int &playerIndex, string const nameToSearch)
{
	try
	{
		// check/find if guard
		for (int i = 0; i < size(activeGuards); i++)
		{
			if (activeGuards[i].GetFullName() == nameToSearch)
			{
				playerIndex = i;
				isGuard = true;
			}
		}
		// check/find if foward
		for (int i = 0; i < size(activeFowards); i++)
		{
			if (activeFowards[i].GetFullName() == nameToSearch)
			{
				playerIndex = i;
				isFoward = true;
			}
		}
		// check/find if center
		for (int i = 0; i < size(activeCenters); i++)
		{
			if (activeCenters[i].GetFullName() == nameToSearch)
			{
				playerIndex = i;
				isCenter = true;
			}
		}

		if (isGuard == false && isFoward == false && isCenter == false)
			throw 21;
	}
	catch (int x)
	{
		cout << "That player is not in the program. The program will now close.\n";
		system("Pause");
		exit(0);
	}
	

}


