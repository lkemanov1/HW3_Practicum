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
#ifndef DECK_INCLUDED
#define DECK_HPP_INCLUDED
#pragma once
#include "MonsterCard.hpp"
#include "MagicCard.hpp"
#include "PendulumCard.hpp"
#include <vector>
class Deck
{
public:
	Deck() = default;
	Deck(const std::string& name);
	Deck operator=(const Deck& from);
	MonsterCard get_monster(int idx)const;
	MagicCard get_magic(int idx)const;
	PendulumCard get_pendulum(int idx)const;
	int get_monsters_count()const;
	int get_magics_count()const;
	int get_pendulums_count()const;
	std::string get_name()const;
	void add_monster(const MonsterCard& monster);
	void add_magic(const MagicCard& magic);
	void add_pendulum(const PendulumCard& pendulum);
	void change_monster(const int& idx, const MonsterCard& monster);
	void change_magic(const int& idx, const MagicCard& magic);
	void change_pendulum(const int& idx, const PendulumCard& pendulum);
	void clear_deck();
private:
	std::vector<MonsterCard> monsters;
	std::vector<MagicCard> magics;
	std::vector<PendulumCard> pendulums;
	std::string name;
};
#endif // CARD_HPP_INCLUDED