#pragma once
#include <string>
using namespace std;
class Account
{
public:

	struct PersonalInfo
	{
		string firstName;
		string lastName;
		string userID;
		string password;
	};

	Account(string firstName, string lastName, string userID, string password);
	~Account();
};

