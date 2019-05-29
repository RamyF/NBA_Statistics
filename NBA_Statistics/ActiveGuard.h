#pragma once
#include "Guard.h"
class ActiveGuard :
	public Guard
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

	// print method
	void PrintPlayer();

	// insertion operator overload
	friend ostream& operator<<(ostream& cout, ActiveGuard& guard);

	ActiveGuard();
	ActiveGuard(string firstName, string lastName, int jerseyNum, string height, int draftYear, double weight, string college, double points,
		double assists, double freethrowPercent, double twoPointPercent, double threePointPercent, double per, double offRating,
		double defRating, int age, double steals, double turnovers, int yearsExp, string team);
	~ActiveGuard();
};

