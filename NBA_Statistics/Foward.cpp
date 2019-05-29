#include "Foward.h"


Foward::Foward()
{
}

Foward::Foward(string firstName, string lastName, int jerseyNum, string height, int draftYear, double weight, string college, double points,
	double rebounds, double assists, double freethrowPercent, double twoPointPercent, double threePointPercent, double per, double offRating,
	double defRating, int age, double steals, double turnovers, double blocks) : Player( firstName,  lastName,  jerseyNum,  height,  draftYear,  weight,  college,  points,
		 assists,  freethrowPercent,  twoPointPercent,  threePointPercent,  per,  offRating, defRating,  age)
{
	this->steals = steals;
	this->turnovers = turnovers;
	this->blocks = blocks;
	this->rebounds = rebounds;
}


Foward::~Foward()
{
}
