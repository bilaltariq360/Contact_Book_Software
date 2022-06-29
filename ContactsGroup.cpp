#include"ContactsGroup.h"
#include"ContactsBook.h"
#include"Contact.h"
#include<fstream>

ContactsGroup::ContactsGroup() {
	this->group_name = "";
	this->total_group_members = 0;
	this->contacts_count = 0;
	this->contacts_group_list = nullptr;
}

ContactsGroup& ContactsGroup::operator = (const ContactsGroup& contact_group) {
	this->contacts_count = contact_group.contacts_count;
	this->group_name = contact_group.group_name;
	this->total_group_members = contact_group.total_group_members;

	for (int i = 0; i < this->contacts_count; i++) {
		*(this->contacts_group_list + i) = *(contact_group.contacts_group_list + i);
	}

	return *this;
}

void ContactsGroup::SetGroupName(std::string group_name) {
	this->group_name = group_name;
}

void ContactsGroup::SetGroupMembers(int total_group_members) {
	this->total_group_members = total_group_members;
}

void ContactsGroup::SetContactsGroupList(int total_group_members) {
	this->contacts_group_list = new Contact[total_group_members];
	SetGroupMembers(total_group_members);
}

void ContactsGroup::SetContactsCount(int total_members) {
	this->contacts_count = total_members;
}

std::string ContactsGroup::GetGroupName() {
	return this->group_name;
}

int ContactsGroup::GetGroupMembers() {
	return this->total_group_members;
}

int ContactsGroup::GetContactsCount() {
	return this->contacts_count;
}

Contact* ContactsGroup::GetGroupContacts() {
	return this->contacts_group_list;
}

bool ContactsGroup::Full() {
	if (this->contacts_count == this->total_group_members)
		return true;
	return false;
}

void ContactsGroup::ResizeContactsGroupMembers() {
	total_group_members *= 2;
	Contact* resize_group_members = new Contact[total_group_members];
	for (int i = 0; i < contacts_count; i++) {
		*(resize_group_members + i) = *(contacts_group_list + i);
	}
	delete[] contacts_group_list;
	contacts_group_list = nullptr;
	contacts_group_list = new Contact[total_group_members];
	for (int i = 0; i < contacts_count; i++) {
		*(contacts_group_list + i) = *(resize_group_members + i);
	}
	delete[] resize_group_members;
	resize_group_members = nullptr;
}

void ContactsGroup::AddMember(Contact& new_member) {
	if (Full())
		ResizeContactsGroupMembers();
	this->contacts_group_list[this->contacts_count] = new_member;
	this->contacts_count++;
}

void ContactsGroup::DeleteMember(int index_number) {
	std::swap(contacts_group_list[index_number], contacts_group_list[contacts_count - 1]);
	Contact* delete_contacts_group_list = new Contact[total_group_members];
	contacts_count--;
	for (int i = 0; i < contacts_count; i++) {
		*(delete_contacts_group_list + i) = *(contacts_group_list + i);
	}
	delete[] contacts_group_list;
	contacts_group_list = nullptr;
	contacts_group_list = new Contact[total_group_members];
	for (int i = 0; i < contacts_count; i++) {
		*(contacts_group_list + i) = *(delete_contacts_group_list + i);
	}
	delete[] delete_contacts_group_list;
	delete_contacts_group_list = nullptr;
}

void ContactsGroup::EditMember(Contact& contact, int index_number) {
	contacts_group_list[index_number] = contact;
}

void ContactsGroup::DisplayGroupMembers() {
	for (int i = 0; i < contacts_count; i++) {
		std::cout << std::endl;
		std::cout << contacts_group_list[i].GetFirstName() << " , ";
		std::cout << contacts_group_list[i].GetLastName() << " , ";
		std::cout << contacts_group_list[i].GetContactId() << " , ";
		std::cout << contacts_group_list[i].GetMobileNumber() << " , ";
		std::cout << contacts_group_list[i].GetEmailAddress() << std::endl;
		std::cout << contacts_group_list[i].GetAddress()->GetHouse() << " , ";
		std::cout << contacts_group_list[i].GetAddress()->GetStreet() << " , ";
		std::cout << contacts_group_list[i].GetAddress()->GetCity() << " , ";
		std::cout << contacts_group_list[i].GetAddress()->GetCountry() << std::endl << std::endl;
		std::cout << "-----------------------------------------------------" << std::endl;
	}
}

void ContactsGroup::SaveToFile() {
	std::ofstream file;
	file.open("Groups.txt");
	if (!file.is_open()) {
		std::cout << "Group File Can't Be Open!";
	}
	else {
		file << this->total_group_members << std::endl;
		file << this->contacts_count << std::endl;
		file << this->group_name << std::endl;
		for (int i = 0; i < contacts_count; i++) {
			file << contacts_group_list[i].GetFirstName() << " , ";
			file << contacts_group_list[i].GetLastName() << " , ";
			file << contacts_group_list[i].GetContactId() << " , ";
			file << contacts_group_list[i].GetMobileNumber() << " , ";
			file << contacts_group_list[i].GetEmailAddress() << std::endl;
			file << contacts_group_list[i].GetAddress()->GetHouse() << " , ";
			file << contacts_group_list[i].GetAddress()->GetStreet() << " , ";
			file << contacts_group_list[i].GetAddress()->GetCity() << " , ";
			file << contacts_group_list[i].GetAddress()->GetCountry() << std::endl;
		}
	}
}