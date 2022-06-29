#include "Contact.h"
#include "Address.h"

int Contact::contact_id_setter = 0;

Contact::Contact() {
	this->address = nullptr;
	this->contact_id = 0;
}

Contact::Contact(std::string first_name, std::string last_name, std::string mobile_number, std::string email_address, Address* address) {
	SetFirstName(first_name);
	SetLastName(last_name);
	SetContactId();
	SetMobileNumber(mobile_number);
	SetEmailAddress(email_address);
	SetAddress(address);
}

Contact& Contact::operator = (const Contact& contact) {
	this->SetFirstName(contact.GetFirstName());
	this->SetLastName(contact.GetLastName());
	this->contact_id = contact.GetContactId();
	this->SetMobileNumber(contact.GetMobileNumber());
	this->SetEmailAddress(contact.GetEmailAddress());
	this->SetAddress(contact.GetAddress());

	return *this;
}


void Contact::SetFirstName(std::string first_name) {
	this->first_name = first_name;
}

void Contact::SetLastName(std::string last_name) {
	this->last_name = last_name;
}

void Contact::SetMobileNumber(std::string mobile_number) {
	this->mobile_number = mobile_number;
}

void Contact::SetEmailAddress(std::string email_address) {
	this->email_address = email_address;
}

void Contact::SetContactIdInFile(int contact_id) {
	this->contact_id = contact_id;
	contact_id_setter = contact_id;
}

void Contact::SetContactId() {
	this->contact_id = ++contact_id_setter;
}

void Contact::SetAddress(Address* address) {
	this->address = new Address;
	this->address->SetHouse(address->GetHouse());
	this->address->SetStreet(address->GetStreet());
	this->address->SetCity(address->GetCity());
	this->address->SetCountry(address->GetCountry());
}

std::string Contact::GetFirstName() const {
	return this->first_name;
}

std::string Contact::GetLastName() const {
	return this->last_name;
}

std::string Contact::GetMobileNumber() const {
	return this->mobile_number;
}

std::string Contact::GetEmailAddress() const {
	return this->email_address;
}

int Contact::GetContactId() const {
	return this->contact_id;
}

Address* Contact::GetAddress() const {
	return this->address;
}

bool Contact::Equals(Contact contact) const {
	if (this->first_name == contact.first_name && this->last_name == contact.last_name && this->mobile_number == contact.mobile_number && this->email_address == contact.email_address && this->address->GetHouse() == contact.address->GetHouse() && this->address->GetStreet() == contact.address->GetStreet() && this->address->GetCity() == contact.address->GetCity() && this->address->GetCountry() == contact.address->GetCountry())
		return true;
	return false;
}