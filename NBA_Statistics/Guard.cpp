#include "Guard.h"

Guard::Guard()
{
}

Guard::Guard(string firstName, string lastName, int jerseyNum, string height, int draftYear, double weight, string college, double points,
	double assists, double freethrowPercent, double twoPointPercent, double threePointPercent, double per, double offRating, double defRating, int age, 
	double steals, double turnovers) : Player( firstName,  lastName,  jerseyNum,  height,  draftYear,  weight,  college,  points,
		 assists,  freethrowPercent,  twoPointPercent,  threePointPercent,  per,  offRating, defRating,  age)
{
	this->steals = steals;
	this->turnovers = turnovers;
}


Guard::~Guard()
{
}
