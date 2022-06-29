#include<iostream>
#include<string>
#include"Address.h"
#include"Contact.h"
#include"ContactsBook.h"

void menu();
Contact inputCont();
Address inputAddr();
void ManageContact(ContactsBook& conBook);

int main() {
	system("color 0E");
	char option;
	int select = 0;
	int select_contact = 0;
	int groups = 0;
	int group_number = 0;
	int group_members = 0;
	int del_number = 0;
	std::string search = "";
	std::string group_name = "";
	std::string sort = "";
	ContactsBook conBook;
	Contact contact;
	Address address;
	do {
		system("cls");
		menu();
		std::cout << "Enter options from above menu: ";
		std::cin >> select;

		if (select == 1) {
			system("cls");
			int size_of_contacts;
			std::cout << "Enter size of contacts: ";
			std::cin >> size_of_contacts;
			conBook.SetContactsList(size_of_contacts);
		}

		else if (select == 2) {
			system("cls");
			contact = inputCont();
			conBook.AddContact(contact);
			conBook.SaveToFile("Contacts.txt");
		}

		else if (select == 3) {
			system("cls");
			conBook.MergeDuplicates();
			conBook.SaveToFile("Contacts.txt");
		}

		else if (select == 4) {
			system("cls");
			std::cout << "Enter to search: ";
			std::cin >> search;

			if (conBook.AdvanceSearch(search)) {
				ManageContact(conBook);
			}
		}

		else if (select == 5) {
			system("cls");
			conBook.PrintOnlyNameAndContacts();
			ManageContact(conBook);
		}

		else if (select == 6) {
			system("cls");
			std::cout << "Sort By:\n\n1. First Name\n2. Last Name\n\nEnter your option: ";
			std::cin >> select;
			if (select == 1)
				conBook.PrintContactsSorted("First Name");
			else
				conBook.PrintContactsSorted("Last Name");
		}

		else if (select == 7) {
			system("cls");
			conBook.PrintContactsUnsorted();
		}

		else if (select == 8) {
			system("cls");
			std::cout << "Total contacts stored = " << conBook.TotalContacts() << std::endl;
		}

		else if (select == 9) {
			system("cls");
			conBook.SaveToFile("Contacts.txt");
		}

		else if (select == 10) {
			system("cls");
			conBook.LoadFromFile("Contacts.txt");
			conBook.PrintContactsUnsorted();
		}

		else if (select == 11) {
			system("cls");
			std::cout << "How many groups you want to make: ";
			std::cin >> groups;
			conBook.SetSizeOfGroups(groups);
			conBook.SetGroupContacts(groups);
			for (int i = 0; i < groups; i++)
			{
				std::cout << std::endl;
				std::cout << "Enter Group " << i + 1 << " Name: ";
				std::cin >> group_name;
				std::cout << "Enter Group Membes that You Want To Enter In Group " << i + 1 << " : ";
				std::cin >> group_members;
				conBook.SetGroupDetails(group_name, group_members);
				std::cout << std::endl;
			}
		}

		else if (select == 12) {
			system("cls");
			bool match = false;
			conBook.DisplayGroupDetails();
			std::cout << "Enter Group Name: ";
			std::cin >> group_name;
			for (int i = 0; i < groups; i++)
			{
				if ((conBook.GetGroupAddress() + i)->GetGroupName() == group_name)
				{
					std::cout << std::endl;
					conBook.PrintContactsUnsorted();
					std::cout << std::endl;
					std::cout << "Enter contact number from above that you want to enter: ";
					std::cin >> select;
					contact = conBook.GetContact(select - 1);
					conBook.AddContactInGroup(contact, i);
					conBook.SaveGroupToFile();
					std::cout << "Contact Added To Group!" << std::endl;
					match = true;
					break;
				}
			}
			if (match == false) {
				std::cout << "There is no such group exists!" << std::endl;
			}
			match = false;
		}

		else if (select == 13) {
			system("cls");
			conBook.DisplayGroupDetails();
			std::cout << "Enter group number: ";
			std::cin >> group_number;
			conBook.DisplayGroupMembers(group_number - 1);
		}

		else if (select == 14) {
			system("cls");
			conBook.DisplayGroupDetails();
			std::cout << std::endl;
			std::cout << "Enter Group number from above: ";
			std::cin >> group_number;
			conBook.DisplayGroupMembers(group_number - 1);
			std::cout << "Enter Contact number to delete: ";
			std::cin >> select;
			conBook.DeleteContactInGroup(group_number - 1, select - 1);
		}

		else if (select == 15) {
		system("cls");
		conBook.DisplayGroupDetails();
		std::cout << "Enter Group Number You Want To Delete: ";
		std::cin >> select;
		conBook.DeleteGroup(select - 1);
		std::cout << std::endl << std::endl << "Your Selected Group Has Been Deleted!";
		}

		else if (select == 16) {
			system("cls");
			conBook.GetHistoryList().PrintHistoryList();
		}

		else if (select == 0)
			return 0;
		std::cout << "\n\nEnter any key to continoue ........ ";
		system("pause > null");
	} while (select != 0);

	return 0;
}

void menu() {
	std::cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-Contacts Book Software-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";
	std::cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-Developed By Bilal-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n";
	const int items_size = 17;
	std::string menu_items[items_size] = { "[1].  Creat New Contact list",
									  "[2].  Add New Contact",
									  "[3].  Merge Duplicate Contacts",
									  "[4].  Advance Search Contacts",
									  "[5].  Manage Contacts",
		                                                          "[6].  Print Sorted Contacts",
									  "[7].  Print Unsorted Contacts",
									  "[8].  Display Contacts Count",
									  "[9].  Save Contacts",
									  "[10]. Load Contacts",
									  "[11]. Creat New Group",
									  "[12]. Add Member To Existing Group",
									  "[13]. Display Group members",
									  "[14]. Delete Contact From Group",
									  "[15]. Delete Group",
									  "[16]. Print Search List",
									  "[0].  Exit" };

	for (int i = 0; i < items_size; i++) {
		std::cout << menu_items[i] << std::endl;
		if (i % 2 == 0)
			system("color 0B");
		else if (i % 3 == 0)
			system("color 0C");
		else
			system("color 0E");
	}
	std::cout << std::endl;
}

Address inputAddr() {
	std::string house;
	std::string street;
	std::string city;
	std::string country;
	std::cout << "Enter House: ";
	std::cin >> house;
	std::cout << "Enter Street: ";
	std::cin >> street;
	std::cout << "Enter City: ";
	std::cin >> city;
	std::cout << "Enter Country: ";
	std::cin >> country;

	Address temp(house, street, city, country);

	return temp;
}

Contact inputCont() {
	std::string first_name;
	std::string last_name;
	std::string mobile_number;
	std::string email_address;
	bool check = false;
	do {
		std::cout << "Enter First Name: ";
		std::cin >> first_name;
		if (first_name.length() == 0) {
			std::cout << "First Name Can't be empty!" << std::endl;
		}
	} while (first_name.length() == 0);
	do {
		std::cout << "Enter Last Name: ";
		std::cin >> last_name;
		if (last_name.length() == 0) {
			std::cout << "Last Name Can't be empty!" << std::endl;
		}
	} while (last_name.length() == 0);
	do {
		std::cout << "Enter Mobile Number: ";
		std::cin >> mobile_number;
		if (mobile_number.length() == 0 || mobile_number.length() < 11 || mobile_number.length() > 11) {
			std::cout << "Mobile Number Can't be empty, less or greater than 11 digits!" << std::endl;
		}
	} while (mobile_number.length() == 0 || mobile_number.length() < 11 || mobile_number.length() > 11);
	do {
		std::cout << "Enter Email Address: ";
		std::cin >> email_address;
		if (email_address.length() == 0) {
			std::cout << "Email Address Can't be empty!" << std::endl;
		}
		for (int i = 0; i < email_address.length(); i++) {
			if (email_address[i] == '@') {
				check = true;
				i = email_address.length();
			}
			if (i == email_address.length() - 1) {
				std::cout << "Email Address Can't be without @!" << std::endl;
			}
		}
	} while (email_address.length() == 0 || check == false);

	Address adr = inputAddr();
	Contact temp(first_name, last_name, mobile_number, email_address, &adr);

	return temp;
}

void ManageContact(ContactsBook& conBook) {
	char option;
	int select_contact;
	int select;
	Contact contact;
	std::cout << "\n\nWould You Like To Edit Or Delete Contact [ Y / N ]: ";
	std::cin >> option;
	if (option == 'y' || option == 'Y') {
		std::cout << "Enter Contact Number To Manage Contact And View Detail: ";
		std::cin >> select_contact;
		system("cls");
		std::cout << "Your Selected Contact:\n\n";
		conBook.PrintContactByIndex(select_contact - 1);
		std::cout << "[1]. Edit\n";
		std::cout << "[2]. Delete\n\n";
		std::cout << "Select Option: ";
		std::cin >> select;
		if (select == 1) {
			contact = inputCont();
			conBook.EditContact(select_contact - 1, contact);
			std::cout << "Contact Has Updated Successfully!";
		}
		if (select == 2) {
			conBook.DeleteContact(select_contact - 1);
			std::cout << "Contact Has Been Deleted!";
		}
		conBook.SaveToFile("Contacts.txt");
	}
}
