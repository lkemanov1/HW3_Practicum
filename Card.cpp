#include "Card.hpp"
Card::Card(const std::string& name, const std::string& effect)
{
	this->effect = effect;
	this->name = name;
}

std::string Card::get_name()const
{
	return this->name;
}

std::string Card::get_effect()const
{
	return this->effect;
}
