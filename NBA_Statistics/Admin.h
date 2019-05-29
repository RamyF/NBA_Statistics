#pragma once
#include "Account.h"
#include "AdministratorEnum.cpp"
class Admin : public Account
{
private:
	AdminStatus status;
public:
	AdminStatus GetStatus() { return status; }
	Admin(string firstName, string lastName, string userID, string password);
	~Admin();
};


