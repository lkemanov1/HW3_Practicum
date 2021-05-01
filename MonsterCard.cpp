#include "MonsterCard.hpp"
#include<iostream>
MonsterCard::MonsterCard()
{
	this->attack = 0;
	this->defence = 0;
}

MonsterCard::MonsterCard(const Card& card, const int& attack, const int& defence):Card(card)
{
	this->attack = attack;
	this->defence = defence;
}
int MonsterCard::get_attack() const
{
	return this->attack;
}
int MonsterCard::get_defence() const
{
	return this->defence;
}
