#pragma once
#include "Guard.h"
class RetiredGuard : public Guard
{
private:
	int yearRetired;
public:
	// accessor 
	int GetYearRetired() { return yearRetired; }
	//mutator
	void SetYearRetired(int newYearRetired) { yearRetired = newYearRetired; }

	RetiredGuard();
	RetiredGuard(string firstName, string lastName, int jerseyNum, string height, int draftYear, double weight, string college, double points,
		double assists, double freethrowPercent, double twoPointPercent, double threePointPercent, double per, double offRating, double defRating, int age,
		double steals, double turnovers, int yearRetired);
	~RetiredGuard();
};

