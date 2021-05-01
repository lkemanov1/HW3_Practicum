#include "MagicCard.hpp"

MagicCard::MagicCard(const Card& card, const MagicType type):Card(card),type(type){}

MagicType MagicCard::get_type()const
{
	return this->type;
}

std::string MagicCard::get_type_name() const
{
	if (this->type == MagicType::buff) return "BUFF";
	if (this->type == MagicType::spell) return "SPELL";
	return "TRAP";
}

