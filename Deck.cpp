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
#include "Deck.hpp"

Deck::Deck(const std::string& name)
{
    this->name = name;
}

Deck Deck::operator=(const Deck& from)
{
    this->name = from.name;
    this->clear_deck();
    for (int idx = 0; idx < from.monsters.size(); idx++) 
    {
        this->monsters.push_back(from.monsters[idx]);
    }
    for (int idx = 0; idx < from.magics.size(); idx++) 
    {
        this->magics.push_back(from.magics[idx]);
    }
    for (int idx = 0; idx < from.pendulums.size(); idx++) 
    { 
        this->pendulums.push_back(from.pendulums[idx]);
    }
    return *this;
}

MonsterCard Deck::get_monster(int idx) const
{
    return this->monsters[idx];
}

MagicCard Deck::get_magic(int idx) const
{
    return this->magics[idx];
}

PendulumCard Deck::get_pendulum(int idx) const
{
    return this->pendulums[idx];
}

int Deck::get_monsters_count() const
{
    return this->monsters.size();
}

int Deck::get_magics_count() const
{
    return this->magics.size();
}

int Deck::get_pendulums_count() const
{
    return this->pendulums.size();
}

std::string Deck::get_name() const
{
    return this->name;
}

void Deck::add_monster(const MonsterCard& monster)
{
    this->monsters.push_back(monster);
}

void Deck::add_magic(const MagicCard& magic)
{
    this->magics.push_back(magic);
}

void Deck::add_pendulum(const PendulumCard& pendulum)
{
    this->pendulums.push_back(pendulum);
}

void Deck::change_monster(const int& idx, const MonsterCard& monster)
{
    this->monsters[idx] = monster;
}

void Deck::change_magic(const int& idx, const MagicCard& magic)
{
    this->magics[idx] = magic;
}

void Deck::change_pendulum(const int& idx, const PendulumCard& pendulum)
{
    this->pendulums[idx] = pendulum;
}

void Deck::clear_deck()
{
    this->monsters.clear();
    this->magics.clear();
    this->pendulums.clear();
}
