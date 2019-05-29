#pragma once
#include "Center.h"
class RetiredCenter : public Center
{
private:
	int yearRetired;
public:
	// accessors
	int GetYearRetired() { return yearRetired; }

	// mutator
	void setYearRetired(int newYearRetired) { yearRetired = newYearRetired; }

	RetiredCenter();
	RetiredCenter(string firstName, string lastName, int jerseyNum, string height, int draftYear, double weight, string college, double points,
		double assists, double freethrowPercent, double twoPointPercent, double threePointPercent, double per, double offRating,
		double defRating, int age, double blocks, double offRebounds, double defRebounds, int yearRetired);
	~RetiredCenter();
};

