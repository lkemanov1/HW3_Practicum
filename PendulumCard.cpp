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
#include "PendulumCard.hpp"
#include <iostream>
PendulumCard::PendulumCard(const MonsterCard& monster, const MagicCard& magic, const short& scale, const std::string& name, const std::string& effect):MonsterCard(monster),MagicCard(magic)
{
	this->name = name;
	this->effect = effect;
	this->scale = scale;
	if (this->scale < 1)
		this->scale = 1;
	if (this->scale > 13)
		this->scale = 13;
}

short PendulumCard::get_scale() const
{
	return this->scale;
}
