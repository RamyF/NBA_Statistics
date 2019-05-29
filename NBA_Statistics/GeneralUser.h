#pragma once
#include "Account.h"
class GeneralUser : public Account
{
private:
	string joinDate;
public:
	GeneralUser(string firstName, string lastName, string userID, string password, string joinDate);
	~GeneralUser();
};

