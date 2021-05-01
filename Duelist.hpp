/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Lachezar Kemanov
* @idnumber 62615
* @task 1
* @compiler VC
*/
#ifndef DUELIST_INCLUDED
#define DUELIST_HPP_INCLUDED
#pragma once
#include "Deck.hpp"
#include <fstream>
class Duelist
{
public:
	Duelist() = default;
	Duelist(const Deck& from, const std::string& name);

	Deck get_deck()const;
	bool save_to_file(const std::string& file_name)const;
	bool read_from_file(const std::string& file_name);
private:
	std::string name;
	std::string readfile(std::string& info)const;
	int to_int(const std::string& number)const;
	void read_monster(std::string& monster);
	void read_magic(std::string& magic);
	void read_pendulum(std::string& magic);
	Deck deck;
};
#endif // DUELIST_HPP_INCLUDED