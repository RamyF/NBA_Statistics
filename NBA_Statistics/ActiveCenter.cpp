#include "ActiveCenter.h"
#include <iostream>

ostream& operator<<(ostream& cout, ActiveCenter& center)
{
	string name = center.GetFullName();
	return cout << name;
}

ActiveCenter::ActiveCenter()
{
}

ActiveCenter::ActiveCenter(string firstName, string lastName, int jerseyNum, string height, int draftYear, double weight, string college, double points,
	double assists, double freethrowPercent, double twoPointPercent, double threePointPercent, double per, double offRating,
	double defRating, int age, double blocks, double offRebounds, double defRebounds, int yearsExp, string team) : Center( firstName,  lastName,  jerseyNum,  height,  draftYear,  weight,  college,  points,
		 assists,  freethrowPercent,  twoPointPercent,  threePointPercent,  per,  offRating, defRating,  age,  blocks,  offRebounds,  defRebounds)
{
	this->yearsExp = yearsExp;
	this->team = team;
}


ActiveCenter::~ActiveCenter()
{
}

void ActiveCenter::PrintPlayer()
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
	cout << "PPG: " << this->GetPoints() << "\t  Assists: " << this->GetAssists() << "\tOffensive Rebounds: " << this->GetOffRebounds() << endl << endl;
	cout << "Defensive Rebounds: " << this->GetDefRebounds() << "\tBlocks: " << this->GetBlocks() << endl << endl;
	cout << "Freethrow %: " << this->GetFreethrowPercent() << "%" << "\t2-Point %: " << this->GetTwoPointPercent() << "%" << "\t3-Point %: " << this->GetThreePointPercent() << "%" << endl << endl;
	cout << "\t\t\tAdvanced" << endl;
	cout << "\t\t\t-----" << endl;
	cout << "PER: " << this->GetPER() << "  Offensive Rating: " << this->GetOffRating() << "  Defensive Rating: " << this->GetDefRating() << endl << endl << endl;
}
