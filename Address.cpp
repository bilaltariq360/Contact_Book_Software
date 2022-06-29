#include "Address.h"

Address::Address(std::string house, std::string street, std::string city, std::string country) {
	SetHouse(house);
	SetStreet(street);
	SetCity(city);
	SetCountry(country);
}

void Address::SetHouse(std::string house) {
	this->house = house;
}

void Address::SetStreet(std::string street) {
	this->street = street;
}

void Address::SetCity(std::string city) {
	this->city = city;
}

void Address::SetCountry(std::string country) {
	this->country = country;
}

std::string Address::GetHouse() {
	return this->house;
}

std::string Address::GetStreet() {
	return this->street;
}

std::string Address::GetCity() {
	return this->city;
}

std::string Address::GetCountry() {
	return this->country;
}

bool Address::Equals(const Address& address) {
	if ((this->house == address.house) && (this->street == address.street) && (this->city == address.city) && (this->country == address.country))
		return true;
	return false;
}

void Address::PrintAddress() {
	std::cout << "House = " << this->house << ' ';
	std::cout << "Street = " << this->street << ' ';
	std::cout << "City = " << this->city << ' ';
	std::cout << "Country = " << this->country << std::endl;
}
