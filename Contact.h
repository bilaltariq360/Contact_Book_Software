#pragma once
#include "Address.h"

#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif // !BASIC_LIB


class Contact {
private:
	std::string first_name;
	std::string last_name;
	std::string mobile_number;
	std::string email_address;
	static int contact_id_setter;
	int contact_id;
	Address* address;

public:
	bool Equals(Contact contact) const;

	Contact& operator = (const Contact& contact);

	Contact();
	Contact(std::string first_name, std::string last_name, std::string mobile_number, std::string email_address, Address* address);

	void SetFirstName(std::string);
	void SetLastName(std::string);
	void SetMobileNumber(std::string);
	void SetEmailAddress(std::string);
	void SetContactIdInFile(int contact_id_setter);
	void SetContactId();
	void SetAddress(Address*);

	std::string GetFirstName() const;
	std::string GetLastName() const;
	std::string GetMobileNumber() const;
	std::string GetEmailAddress() const;
	int GetContactId() const;
	Address* GetAddress() const;

	/*Contact& operator = (Contact& contact);*/
};