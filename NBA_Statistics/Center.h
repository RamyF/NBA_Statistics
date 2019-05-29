#pragma once
#include "Player.h"
class Center : public Player
{
private:
	double blocks, offRebounds, defRebounds;
public:

	// accessors 
	double GetBlocks() { return blocks; }
	double GetOffRebounds() { return offRebounds; }
	double GetDefRebounds() { return defRebounds; }

	// mutator
	void SetBlocks(double newBlocks) { blocks = newBlocks; }
	void SetOffRebounds(double newOffRebounds) { offRebounds = newOffRebounds; }
	void SetDefRebounds(double newDefRebounds) { defRebounds = newDefRebounds; }

	// print player
	void PrintPlayer();

	Center();
	Center(string firstName, string lastName, int jerseyNum, string height, int draftYear, double weight, string college, double points,
		double assists, double freethrowPercent, double twoPointPercent, double threePointPercent, double per, double offRating,
		double defRating, int age, double blocks, double offRebounds, double defRebounds);
	~Center();
};

