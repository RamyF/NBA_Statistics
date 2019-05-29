#include "Admin.h"



Admin::Admin(string firstName, string lastName, string userID, string password) : Account( firstName,  lastName,  userID,  password)
{
	this->status = isAdmin;
}


Admin::~Admin()
{
}

