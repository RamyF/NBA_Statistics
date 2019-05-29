#include "ActiveFoward.h"
#include <iostream>


ActiveFoward::ActiveFoward()
{
}

ActiveFoward::ActiveFoward(string firstName, string lastName, int jerseyNum, string height, int draftYear, double weight, string college, double points,
	double rebounds, double assists, double freethrowPercent, double twoPointPercent, double threePointPercent, double per, double offRating,
	double defRating, int age, double steals, double turnovers, double blocks, string team, int yearsExp) : Foward( firstName,  lastName,  jerseyNum,  height,  draftYear,  weight,  college,  points,
		 rebounds,  assists,  freethrowPercent,  twoPointPercent,  threePointPercent,  per,  offRating, defRating,  age,  steals,  turnovers,  blocks)
{
	this->team = team;
	this->yearsExp = yearsExp;
}


ActiveFoward::~ActiveFoward()
{
}

void ActiveFoward::PrintPlayer()
{

	cout << "Position: Foward" << endl;
	cout << "Age: " << this->GetAge() << endl;
	cout << "Jersey Number: " << this->GetJerseyNum() << endl;
	cout << "Height: " << this->GetHeight() << endl;
	cout << "Year Drafted: " << this->GetDraftYear() << endl;
	cout << "Weight: " << this->GetWeight() << " lbs" << endl;
	cout << "School: " << this->GetCollege() << endl;
	cout << "Team: " << this->GetTeam() << endl;
	cout << "Years Experience: " << this->GetYearsExp() << " Years" << endl;
	cout << "\t\t\tSTATS" << endl;
	cout << "\t\t\t-----" << endl;
	cout << "PPG: " << this->GetPoints() << "\t  Assists: " << this->GetAssists() << "\tRebounds: " << this->GetRebounds() << endl << endl;
	cout << "\tSteals Per Game: " << this->GetSteals() << "\tTurnovers: " << this->GetTurnovers() << "\tBlocks: " << this->GetBlocks() << endl << endl;
	cout << "Freethrow %: " << this->GetFreethrowPercent() << "%" << "\t2-Point %: " << this->GetTwoPointPercent() << "%" << "\t3-Point %: " << this->GetThreePointPercent() << "%" << endl << endl;
	cout << "\t\t\tAdvanced" << endl;
	cout << "\t\t\t-----" << endl;
	cout << "PER: " << this->GetPER() << "  Offensive Rating: " << this->GetOffRating() << "  Defensive Rating: " << this->GetDefRating() << endl << endl << endl;
}

ostream & operator<<(ostream & cout, ActiveFoward & foward)
{
	string name = foward.GetFullName();
	return cout << name;
}
