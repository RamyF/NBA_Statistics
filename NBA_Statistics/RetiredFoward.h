#pragma once
#include "Foward.h"
class RetiredFoward : public Foward
{
private:
	int yearRetired;
public:
	// accessors
	int GetYearRetired() { return yearRetired; }

	// mutator
	void setYearRetired(int newYearRetired) { yearRetired = newYearRetired; }

	RetiredFoward();

	RetiredFoward(string firstName, string lastName, int jerseyNum, string height, int draftYear, double weight, string college, double points,
		double rebounds, double assists, double freethrowPercent, double twoPointPercent, double threePointPercent, double per, double offRating,
		double defRating, int age, double steals, double turnovers, double blocks, int yearRetired);
	~RetiredFoward();
};

