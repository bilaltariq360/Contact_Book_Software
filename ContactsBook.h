#pragma once
#include "Address.h"
#include "Contact.h"
#include <string>
#include "ContactsGroup.h"
#include "HistoryList.h"

#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif // !BASIC_LIB


class ContactsBook {
private:
	Contact* contacts_list;
	int size_of_contacts;
	int size_of_groups;
	static int group_count;
	static int contacts_count;
	ContactsGroup* groups_list;
	HistoryList history_list;

public:
	void AddContact(Contact& contact);
	int TotalContacts() const;

	bool AdvanceSearch(std::string);

	ContactsBook(int size_of_list);
	ContactsBook();

	void PrintContactsSorted(std::string choice);
	void PrintContactsUnsorted();
	void PrintContactByIndex(int contact_index);
	void PrintOnlyNameAndContacts();
	void MergeDuplicates();

	void LoadFromFile(std::string file_name);
	void SaveToFile(std::string file_name);
	void DeleteContact(int index_number);
	void EditContact(int index_number, Contact& contact);

	void AddContactInGroup(Contact& contact, int group_number);
	void DeleteContactInGroup(int group_number, int index_number);

	void SetContactsList(int size_of_list);
	void SetGroupContacts(int members);
	void SetSizeOfGroups(int SetSizeOfGroups);

	Contact GetContact(int index_number);
	HistoryList GetHistoryList() const;

	ContactsBook& operator = (ContactsBook& contact);

	void SetGroupDetails(std::string group_name, int total_group_members);

	ContactsGroup* GetGroupAddress() const;

	void DisplayGroupMembers(int group_number);
	void DisplayGroupDetails();

	void SetHistoryList();

	void SaveGroupToFile();

	void DeleteGroup(int group_index);

private:
	bool Full() const;
	void ResizeList();
	void SortContactsList(Contact* contacts_list, std::string choice);
};