#ifndef MAGICCARD_HPP_INCLUDED
#define MAGICCARD_HPP_INCLUDED
#pragma once
#include "Card.hpp"
enum class MagicType
{
	trap,
	buff,
	spell
};

class MagicCard :virtual public Card
{
public:
	MagicCard() = default;
	MagicCard(const Card& card, const MagicType type);
	MagicType get_type()const;
	std::string get_type_name()const;
protected:
	MagicType type;
}; 
#endif // MAGICCARD_HPP_INCLUDED