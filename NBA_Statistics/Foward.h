#pragma once
#include "Player.h"
class Foward : public Player
{
private:
	double steals, turnovers, blocks, rebounds;
public:
	// accessors
	double GetSteals() { return steals; }
	double GetTurnovers() { return turnovers; }
	double GetBlocks() { return blocks; }
	double GetRebounds() { return rebounds; }

	// mutators
	void GetSteals(double newSteals) { steals = newSteals; }
	void GetTurnovers(double newTurnovers) { turnovers = newTurnovers; }
	void GetBlocks(double newBlocks) { blocks = newBlocks; }
	void GetRebounds(double newRebounds) { rebounds = newRebounds; }

	Foward();
	Foward(string firstName, string lastName, int jerseyNum, string height, int draftYear, double weight, string college, double points,
		double rebounds, double assists, double freethrowPercent, double twoPointPercent, double threePointPercent, double per, double offRating,
		double defRating, int age, double steals, double turnovers, double blocks);
	~Foward();
};

