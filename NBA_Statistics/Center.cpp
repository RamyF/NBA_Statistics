#include "Center.h"


Center::Center()
{
}
Center::Center(string firstName, string lastName, int jerseyNum, string height, int draftYear, double weight, string college, double points,
	double assists, double freethrowPercent, double twoPointPercent, double threePointPercent, double per, double offRating,
	double defRating, int age, double blocks, double offRebounds, double defRebounds) : Player( firstName,  lastName,  jerseyNum,  height,  draftYear,  weight,  college,  points,
		 assists,  freethrowPercent,  twoPointPercent,  threePointPercent,  per,  offRating, defRating,  age)
{
	this->blocks = blocks;
	this->offRebounds = offRebounds;
	this->defRebounds = defRebounds;
}


Center::~Center()
{
}
