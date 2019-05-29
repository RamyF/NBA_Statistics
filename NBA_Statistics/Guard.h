#pragma once
#include "Player.h"
class Guard : public Player
{
private:
	double steals, turnovers;
public:
	// accessors
	double GetSteals() { return steals; }
	double GetTurnovers() { return turnovers; }

	// mutators
	void SetSteals(double newSteals) { steals = newSteals; }
	void setTurnovers(double newTurnovers) { turnovers = newTurnovers; }

	Guard();
	Guard(string firstName, string lastName, int jerseyNum, string height, int draftYear, double weight, string college, double points,
		double assists, double freethrowPercent, double twoPointPercent, double threePointPercent, double per, double offRating,
		double defRating, int age, double steals, double turnovers);
	~Guard();
};

