#include "Account.h"



Account::Account(string firstName, string lastName, string userID, string password)
{
	PersonalInfo personalInfo;
	personalInfo.firstName = firstName;
	personalInfo.lastName = lastName;
	personalInfo.userID = userID;
	personalInfo.password = password;
}


Account::~Account()
{
}
