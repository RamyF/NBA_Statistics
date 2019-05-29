#include "RetiredGuard.h"


RetiredGuard::RetiredGuard()
{
}

RetiredGuard::RetiredGuard(string firstName, string lastName, int jerseyNum, string height, int draftYear, double weight, string college, double points,
	double assists, double freethrowPercent, double twoPointPercent, double threePointPercent, double per, double offRating, double defRating, int age,
	double steals, double turnovers, int yearRetired) : Guard( firstName,  lastName,  jerseyNum,  height,  draftYear,  weight,  college,  points,
		 assists,  freethrowPercent,  twoPointPercent,  threePointPercent,  per,  offRating,  defRating,  age, steals,  turnovers)
{
	this->yearRetired = yearRetired;
}


RetiredGuard::~RetiredGuard()
{
}
