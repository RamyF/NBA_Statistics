#include "RetiredFoward.h"

RetiredFoward::RetiredFoward()
{
}

RetiredFoward::RetiredFoward(string firstName, string lastName, int jerseyNum, string height, int draftYear, double weight, string college, double points,
	double rebounds, double assists, double freethrowPercent, double twoPointPercent, double threePointPercent, double per, double offRating,
	double defRating, int age, double steals, double turnovers, double blocks, int yearRetired) : Foward( firstName,  lastName,  jerseyNum,  height,  draftYear,  weight,  college,  points, rebounds,
		assists,  freethrowPercent,  twoPointPercent,  threePointPercent,  per,  offRating, defRating,  age,  steals,  turnovers,  blocks)
{
	this->yearRetired = yearRetired;
}


RetiredFoward::~RetiredFoward()
{
}
