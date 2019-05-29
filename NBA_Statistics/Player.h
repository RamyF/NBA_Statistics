#pragma once
#include <string>
using namespace std;
class Player
{
private:
	string firstName, lastName, height, college;
	int draftYear, jerseyNum, age;
	double weight, points, assists, freethrowPercent, twoPointPercent, threepointPercent, per, offRating, defRating;
public:
	// accessors (implemented)
	string GetFirstName() { return firstName; }
	string GetLastName() { return lastName; }
	string GetHeight() { return height; }
	string GetCollege() { return college; }
	int GetDraftYear() { return draftYear; }
	int GetJerseyNum() { return jerseyNum; }
	int GetAge() { return age; }
	double GetWeight() { return weight; }
	double GetPoints() { return points; }
	double GetAssists() { return assists; }
	double GetFreethrowPercent() { return freethrowPercent; }
	double GetTwoPointPercent() { return twoPointPercent; }
	double GetThreePointPercent() { return threepointPercent; }
	double GetPER() { return per; }
	double GetOffRating() { return offRating; }
	double GetDefRating() { return defRating; }

	// access full name
	string GetFullName() { return (firstName + " " + lastName); }

	// mutators (implemented)
	void SetFirstName(string newName) { firstName = newName; }
	void SetLastName(string newName) { lastName = newName; }
	void SetHeight(string newHeight) { height = newHeight; }
	void SetCollege(string newCollege) { college = newCollege; }
	void SetDraftYear(int newDraftYear) { draftYear = newDraftYear; }
	void SetJerseyNum(int newJerseyNum) { jerseyNum = newJerseyNum; }
	void SetAge(int newAge) { age = newAge; }
	void SetWeight(double newWeight) { weight = newWeight; }
	void SetPoints(double newPoints) { points = newPoints; }
	void SetAssists(double newAssists) { assists = newAssists; }
	void SetFreethrowPercent(double newFreethrowPercent) { freethrowPercent = newFreethrowPercent; }
	void SetTwoPointPercent(double newTwoPointPercent) { twoPointPercent = newTwoPointPercent; }
	void SetThreePointPercent(double newThreePointPercent) { threepointPercent = newThreePointPercent; }
	void SetPER(double newPER) { per = newPER; }
	void SetOffRating(double newOffRating) { offRating = newOffRating; }
	void SetDefRating(double newDefRating) { defRating = newDefRating; }

	Player();
	Player(string firstName, string lastName, int jerseyNum, string height, int draftYear, double weight, string college, double points,
		double assists, double freethrowPercent, double twoPointPercent, double threePointPercent, double per, double offRating,
		double defRating, int age);
	~Player();
};

