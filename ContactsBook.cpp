#include "ContactsBook.h"
#include "ContactsGroup.h"
#include <fstream>

ContactsBook::ContactsBook() {
	this->groups_list = nullptr;
	this->contacts_list = nullptr;
	this->size_of_contacts = 0;
	this->size_of_groups = 0;
	LoadFromFile("Contacts.txt");
}

ContactsBook& ContactsBook::operator = (ContactsBook& contact_book) {
	this->contacts_count = contact_book.contacts_count;
	this->group_count = contact_book.group_count;
	this->history_list = contact_book.history_list;
	this->size_of_contacts = contact_book.size_of_contacts;
	this->size_of_groups = contact_book.size_of_groups;
	for (int i = 0; i < this->group_count; i++) {
		*(this->groups_list + i) = *(contact_book.groups_list + i);
	}

	for (int i = 0; i < this->contacts_count; i++) {
		*(this->contacts_list + i) = *(contact_book.contacts_list + i);
	}

	return *this;
}

int ContactsBook::contacts_count = 0;
int ContactsBook::group_count = 0;

void ContactsBook::SetSizeOfGroups(int size_of_groups) {
	this->size_of_groups = size_of_groups;
}

void ContactsBook::SetGroupContacts(int members) {
	this->groups_list = new ContactsGroup[members];
}

Contact ContactsBook::GetContact(int index_number) {
	return this->contacts_list[index_number];
}

void ContactsBook::AddContact(Contact& contact) {
	if (Full())
		ResizeList();

	this->contacts_list[this->contacts_count] = contact;
	this->contacts_count++;
}

int ContactsBook::TotalContacts() const {
	return this->contacts_count;
}

bool ContactsBook::Full() const {
	if (this->contacts_count == this->size_of_contacts)
		return true;
	return false;
}

void ContactsBook::ResizeList() {
	size_of_contacts *= 2;
	Contact* resize_c = new Contact[size_of_contacts];
	for (int i = 0; i < contacts_count; i++) {
		*(resize_c + i) = *(contacts_list + i);
	}
	delete[] contacts_list;
	contacts_list = nullptr;
	this->contacts_list = new Contact[size_of_contacts];
	for (int i = 0; i < contacts_count; i++) {
		*(contacts_list + i) = *(resize_c + i);
	}
	delete[] resize_c;
	resize_c = nullptr;
}

bool ContactsBook::AdvanceSearch(std::string search_id) {
	int search_count = 0;
	int total_searches = 0;
	std::string data_stored;
	bool founded = false;

	for (int i = 0; i < search_id.length(); i++) {
		if (search_id[i] >= 65 && search_id[i] <= 90)
			search_id[i] += 32;
	}

	for (int i = 0; i < contacts_count; i++) {
		data_stored = contacts_list[i].GetFirstName() + contacts_list[i].GetLastName() + contacts_list[i].GetMobileNumber() + contacts_list[i].GetEmailAddress() + contacts_list[i].GetAddress()->GetHouse() + contacts_list[i].GetAddress()->GetStreet() + contacts_list[i].GetAddress()->GetCity() + contacts_list[i].GetAddress()->GetCountry();
		
		for (int l = 0; l < data_stored.length(); l++) {
			if (data_stored[l] >= 65 && data_stored[l] <= 90)
				data_stored[l] += 32;
		}
		
		for (int j = 0, k = 0; j < data_stored.length(); j++) {
			if (search_id[k] == data_stored[j]) {
				search_count++;
				k++;
			}
			if (search_id.length() == search_count) {
				PrintContactByIndex(i);
				j = data_stored.length();
				search_count = 0;
				total_searches++;
				founded = true;
			}
		}
	}

	std::cout << "Total " << total_searches << " Contacts Matched!";

	history_list.InsertSearch(search_id);

	if (founded) {
		return true;
	}
	return false;
}

ContactsBook::ContactsBook(int size_of_list) {
	SetContactsList(size_of_list);
}

void ContactsBook::SetContactsList(int size_of_list) {
	this->contacts_list = new Contact[size_of_list];
	this->size_of_contacts = size_of_list;
}

void ContactsBook::PrintContactsSorted(std::string choice) {
	Contact* cont_list;
	cont_list = new Contact[size_of_contacts];
	for (int i = 0; i < contacts_count; i++) {
		*(cont_list + i) = *(contacts_list + i);
	}
	SortContactsList(cont_list, choice);
	for (int i = 0; i < contacts_count; i++) {
		std::cout << (cont_list + i)->GetFirstName() << " , ";
		std::cout << (cont_list + i)->GetLastName() << " , ";
		std::cout << (cont_list + i)->GetMobileNumber() << " , ";
		std::cout << (cont_list + i)->GetEmailAddress() << std::endl;
		std::cout << (cont_list + i)->GetAddress()->GetHouse() << " , ";
		std::cout << (cont_list + i)->GetAddress()->GetStreet() << " , ";
		std::cout << (cont_list + i)->GetAddress()->GetCity() << " , ";
		std::cout << (cont_list + i)->GetAddress()->GetCountry() << std::endl << std::endl;
	}
}

void ContactsBook::PrintContactsUnsorted() {
	for (int i = 0; i < contacts_count; i++) {
		PrintContactByIndex(i);
	}
}

void ContactsBook::PrintContactByIndex(int contact_index) {
	std::cout << contacts_list[contact_index].GetFirstName() << " , ";
	std::cout << contacts_list[contact_index].GetLastName() << " , ";
	std::cout << contacts_list[contact_index].GetContactId() << " , ";
	std::cout << contacts_list[contact_index].GetMobileNumber() << " , ";
	std::cout << contacts_list[contact_index].GetEmailAddress() << std::endl;
	std::cout << contacts_list[contact_index].GetAddress()->GetHouse() << " , ";
	std::cout << contacts_list[contact_index].GetAddress()->GetStreet() << " , ";
	std::cout << contacts_list[contact_index].GetAddress()->GetCity() << " , ";
	std::cout << contacts_list[contact_index].GetAddress()->GetCountry() << std::endl << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl << std::endl;
}

void ContactsBook::PrintOnlyNameAndContacts() {
	for (int i = 0; i < contacts_count; i++) {
		std::cout << i + 1 << ". " << contacts_list[i].GetFirstName();
		std::cout << " " << contacts_list[i].GetLastName() << " ";
		std::cout << contacts_list[i].GetMobileNumber() << std::endl;
	}
}

void ContactsBook::SortContactsList(Contact* cont_list, std::string choice) {
	for (int i = 0; i < contacts_count; i++) {
		for (int j = i + 1; j < contacts_count; j++) {
			if (choice == "First Name" && cont_list[i].GetFirstName() > cont_list[j].GetFirstName()) {
				std::swap(cont_list[i], cont_list[j]);
			}
			else if (choice == "Last Name" && cont_list[i].GetLastName() > cont_list[j].GetLastName()) {
				std::swap(cont_list[i], cont_list[j]);
			}
		}
	}
}

void ContactsBook::MergeDuplicates() {
	int count = contacts_count;
	for (int z = 0; z < count; z++) {
		for (int i = 0; i < contacts_count; i++) {
			for (int j = i + 1; j < contacts_count; j++) {
				if (contacts_list[i].Equals(contacts_list[j])) {
					for (int k = j; k < contacts_count - 1; k++) {
						contacts_list[k] = contacts_list[k + 1];
					}
					contacts_count--;
				}
			}
		}
	}
}

void ContactsBook::DeleteContact(int index_number) {
	for (int i = 0; i < group_count; i++)
	{
		for (int j = 0; j < groups_list[i].GetContactsCount(); j++)
		{
			if (contacts_list[index_number].Equals(groups_list[i].GetGroupContacts()[j])) {
				groups_list[i].DeleteMember(j);
			}
		}
	}
	std::swap(contacts_list[index_number], contacts_list[contacts_count - 1]);
	contacts_count--;
	Contact* del_contact = new Contact[size_of_contacts];
	for (int i = 0; i < contacts_count; i++) {
		*(del_contact + i) = *(contacts_list + i);
	}
	delete[] contacts_list;
	contacts_list = nullptr;
	this->contacts_list = new Contact[size_of_contacts];
	for (int i = 0; i < contacts_count; i++) {
		*(contacts_list + i) = *(del_contact + i);
	}
	delete[] del_contact;
	del_contact = nullptr;
}

void ContactsBook::EditContact(int index_number, Contact& contact) {
	for (int i = 0; i < group_count; i++)
	{
		for (int j = 0; j < groups_list[i].GetContactsCount(); j++)
		{
			if (contacts_list[index_number].Equals(groups_list[i].GetGroupContacts()[j])) {
				groups_list[i].EditMember(contact, j);
			}
		}
	}
	contacts_list[index_number] = contact;
}

void ContactsBook::LoadFromFile(std::string file_name) {
	std::fstream file;
	file.open(file_name, std::ios::in);
	if (!file.is_open()) {
		std::cout << "Contact can't be load at this moment. Try later!" << std::endl;
	}
	else {
		Address adr;
		std::string read;
		int read_id;
		file >> this->size_of_contacts;
		file >> this->contacts_count;
		SetContactsList(size_of_contacts);
		for (int i = 0; i < contacts_count; i++) {
			file >> read;
			this->contacts_list[i].SetFirstName(read);
			file >> read >> read;
			this->contacts_list[i].SetLastName(read);
			file >> read >> read_id;
			this->contacts_list[i].SetContactIdInFile(read_id);
			file >> read >> read;
			this->contacts_list[i].SetMobileNumber(read);
			file >> read >> read;
			this->contacts_list[i].SetEmailAddress(read);
			file >> read;
			adr.SetHouse(read);
			file >> read >> read;
			adr.SetStreet(read);
			file >> read >> read;
			adr.SetCity(read);
			file >> read >> read;
			adr.SetCountry(read);
			this->contacts_list[i].SetAddress(&adr);
		}
	}
}

void ContactsBook::SaveToFile(std::string file_name) {
	std::fstream file;
	file.open(file_name, std::ios::out);
	if (!file.is_open()) {
		std::cout << "Contact can't be save at this moment. Try later!" << std::endl;
	}
	else {
		file << size_of_contacts << std::endl;
		file << contacts_count << std::endl;
		for (int i = 0; i < contacts_count; i++) {
			file << contacts_list[i].GetFirstName() << " , ";
			file << contacts_list[i].GetLastName() << " , ";
			file << contacts_list[i].GetContactId() << " , ";
			file << contacts_list[i].GetMobileNumber() << " , ";
			file << contacts_list[i].GetEmailAddress() << std::endl;
			file << contacts_list[i].GetAddress()->GetHouse() << " , ";
			file << contacts_list[i].GetAddress()->GetStreet() << " , ";
			file << contacts_list[i].GetAddress()->GetCity() << " , ";
			file << contacts_list[i].GetAddress()->GetCountry() << std::endl;
		}
		file.close();
	}
}

void ContactsBook::SetGroupDetails(std::string group_name, int total_group_members) {
	this->groups_list[group_count].SetGroupName(group_name);
	this->groups_list[group_count].SetContactsGroupList(total_group_members);
	group_count++;
}

void ContactsBook::AddContactInGroup(Contact& contact, int group_number) {
	this->groups_list[group_number].AddMember(contact);
}

void ContactsBook::DeleteContactInGroup(int group_number, int index_number) {
	this->groups_list[group_number].DeleteMember(index_number);
}

void ContactsBook::DisplayGroupMembers(int group_number) {
	this->groups_list[group_number].DisplayGroupMembers();
}

void ContactsBook::DisplayGroupDetails() {
	for (int i = 0; i < this->group_count; i++)
	{
		std::cout << "Group " << i + 1 << " Details:" << std::endl;
		std::cout << "Group Name = " << this->groups_list[i].GetGroupName() << std::endl;
		std::cout << "Group Members = " << this->groups_list[i].GetContactsCount() << std::endl << std::endl;
	}
}

ContactsGroup* ContactsBook::GetGroupAddress() const {
	return this->groups_list;
}

void ContactsBook::SetHistoryList() {
	this->history_list.SetObjects(2);
}

HistoryList ContactsBook::GetHistoryList() const {
	return this->history_list;
}

void ContactsBook::SaveGroupToFile() {
	this->groups_list->SaveToFile();
}

void ContactsBook::DeleteGroup(int group_index) {
	std::swap(groups_list[group_index], groups_list[group_count - 1]);
	group_count--;
	ContactsGroup* del_groups_list = new ContactsGroup[group_count];
	for (int i = 0; i < group_count; i++) {
		*(del_groups_list + i) = *(groups_list + i);
	}

	delete[] groups_list;
	groups_list = nullptr;
	groups_list = new ContactsGroup[group_count];

	for (int i = 0; i < group_count; i++) {
		*(groups_list + i) = *(del_groups_list + i);
	}

	delete[] del_groups_list;
	del_groups_list = nullptr;
}