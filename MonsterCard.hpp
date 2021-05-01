#ifndef MONSTERCARD_HPP_INCLUDED
#define MONSTERCARD_HPP_INCLUDED
#pragma once 
#include "Card.hpp"
class MonsterCard :virtual public Card
{
public:
	MonsterCard();
	MonsterCard(const Card& card,const int& attack, const int& defence);
	int get_attack()const;
	int get_defence()const;
protected:
	int attack;
	int defence;
};
#endif // MONSTERCARD_HPP_INCLUDED
