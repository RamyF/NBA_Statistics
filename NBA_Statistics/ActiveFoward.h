#pragma once
#include "Foward.h"
class ActiveFoward : public Foward
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
	friend ostream& operator<<(ostream& cout, ActiveFoward& foward);

	ActiveFoward();
	ActiveFoward(string firstName, string lastName, int jerseyNum, string height, int draftYear, double weight, string college, double points,
		double rebounds, double assists, double freethrowPercent, double twoPointPercent, double threePointPercent, double per, double offRating,
		double defRating, int age, double steals, double turnovers, double blocks, string team, int yearsExp);
	~ActiveFoward();
};

