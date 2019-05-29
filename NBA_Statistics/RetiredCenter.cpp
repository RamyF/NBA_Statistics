#include "RetiredCenter.h"


RetiredCenter::RetiredCenter()
{
}

RetiredCenter::RetiredCenter(string firstName, string lastName, int jerseyNum, string height, int draftYear, double weight, string college, double points,
	double assists, double freethrowPercent, double twoPointPercent, double threePointPercent, double per, double offRating,
	double defRating, int age, double blocks, double offRebounds, double defRebounds, int yearRetired) : Center(firstName, lastName, jerseyNum, height, draftYear, weight, college, points,
		assists, freethrowPercent, twoPointPercent, threePointPercent, per, offRating, defRating, age, blocks, offRebounds, defRebounds)
{
	this->yearRetired = yearRetired;
}


RetiredCenter::~RetiredCenter()
{
}
