#pragma once
#include "Center.h"
#include <iostream>
using namespace std;
class ActiveCenter : public Center
{
private:
	int yearsExp;
	string team;
public:
	// accessors 
	int GetYearsExp() { return yearsExp; }
	string GetTeam() { return team; }

	// mutators
	void SetYearsExp(int newYearsExp) { yearsExp = newYearsExp; }
	void SetTeam(string newTeam) { team = newTeam; }

	// print player
	void PrintPlayer();
	
	// insertion operator overload
	friend ostream& operator<<(ostream& cout, ActiveCenter& center);

	ActiveCenter();
	ActiveCenter(string firstName, string lastName, int jerseyNum, string height, int draftYear, double weight, string college, double points,
		double assists, double freethrowPercent, double twoPointPercent, double threePointPercent, double per, double offRating,
		double defRating, int age, double blocks, double offRebounds, double defRebounds, int yearsExp, string team);
	~ActiveCenter();
};

