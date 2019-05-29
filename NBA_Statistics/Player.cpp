#include "Player.h"

Player::Player()
{
}

Player::Player(string firstName, string lastName, int jerseyNum, string height, int draftYear, double weight, string college, double points,
	double assists, double freethrowPercent, double twoPointPercent, double threePointPercent, double per, double offRating,
	double defRating, int age)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->jerseyNum = jerseyNum;
	this->height = height;
	this->draftYear = draftYear;
	this->weight = weight;
	this->college = college;
	this->points = points;
	this->assists = assists;
	this->freethrowPercent = freethrowPercent;
	this->twoPointPercent = twoPointPercent;
	this->threepointPercent = threePointPercent;
	this->per = per;
	this->offRating = offRating;
	this->defRating = defRating;
	this->age = age;
}


Player::~Player()
{
}
