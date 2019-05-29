#include "ActiveGuard.h"
#include <iostream>
ActiveGuard::ActiveGuard()
{
}

ActiveGuard::ActiveGuard(string firstName, string lastName, int jerseyNum, string height, int draftYear, double weight, string college, double points,
	double assists, double freethrowPercent, double twoPointPercent, double threePointPercent, double per, double offRating,
	double defRating, int age, double steals, double turnovers, int yearsExp, string team) : Guard( firstName,  lastName,  jerseyNum,  height,  draftYear,  weight,  college,  points,
		 assists,  freethrowPercent,  twoPointPercent,  threePointPercent,  per,  offRating,  defRating,  age, steals,  turnovers)
{
	this->yearsExp = yearsExp;
	this->team = team;
}


ActiveGuard::~ActiveGuard()
{
}


void ActiveGuard::PrintPlayer()
{

	cout << "Position: Guard" << endl;
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
	cout << "PPG: " << this->GetPoints() << "\t  Assists: " << this->GetAssists() << "\tSteals Per Game: " << this->GetSteals() << "\tTurnovers: " << this->GetTurnovers() << endl << endl;
	cout << "Freethrow %: " << this->GetFreethrowPercent() << "%" << "\t2-Point %: " << this->GetTwoPointPercent() << "%" << "\t3-Point %: " << this->GetThreePointPercent() << "%" << endl << endl;
	cout << "\t\t\tAdvanced" << endl;
	cout << "\t\t\t-----" << endl;
	cout << "PER: " << this->GetPER() << "  Offensive Rating: " << this->GetOffRating() << "  Defensive Rating: " << this->GetDefRating() << endl << endl << endl;



}

ostream & operator<<(ostream & cout, ActiveGuard & guard)
{
	string name = guard.GetFullName();
	return cout << name;
}
