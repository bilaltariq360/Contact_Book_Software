#pragma once
#include"Contact.h"

#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif // !BASIC_LIB

class ContactsGroup {
	std::string group_name;
	int total_group_members;
	int contacts_count;
	Contact* contacts_group_list;

public:

	ContactsGroup();
	ContactsGroup& operator = (const ContactsGroup& contact_group);

	void SetGroupName(std::string group_name);
	void SetGroupMembers(int total_group_members);
	void SetContactsGroupList(int total_group_members);
	void SetContactsCount(int total_members);

	std::string GetGroupName();
	int GetGroupMembers();
	int GetContactsCount();
	Contact* GetGroupContacts();

	void DisplayGroupMembers();

	void AddMember(Contact& new_member);
	void DeleteMember(int index_number);
	void EditMember(Contact& contact, int index_number);

	void SaveToFile();

private:
	bool Full();
	void ResizeContactsGroupMembers();
};