#pragma once
#include <iostream>
#include <string>

class Address {
private:
	std::string house;
	std::string street;
	std::string city;
	std::string country;

public:
	bool Equals(const Address& address);
	void PrintAddress();

	Address(std::string house, std::string street, std::string city, std::string country);
	Address() {}

	void SetHouse(std::string);
	void SetStreet(std::string);
	void SetCity(std::string);
	void SetCountry(std::string);


	std::string GetHouse();
	std::string GetStreet();
	std::string GetCity();
	std::string GetCountry();
};