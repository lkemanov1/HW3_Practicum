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
#ifndef PENDULUMCARD_HPP_INCLUDED
#define PENDULUMCARD_HPP_INCLUDED
#pragma once
#include "Card.hpp"
#include "MonsterCard.hpp"
#include "MagicCard.hpp"
#include <iostream>

class PendulumCard : public MonsterCard, public MagicCard
{
public:
	PendulumCard() = default;
	PendulumCard(const MonsterCard& monster, const MagicCard& magic, const short& scale, const std::string& name, const std::string& effect);
	short get_scale()const;
private:
	short scale;

};
#endif // PENDULUMCARD_HPP_INCLUDED