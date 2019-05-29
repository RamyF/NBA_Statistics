#include "GeneralUser.h"



GeneralUser::GeneralUser(string firstName, string lastName, string userID, string password, string joinDate) : Account(firstName, lastName, userID, password)
{
	this->joinDate = joinDate;
}


GeneralUser::~GeneralUser()
{
}
