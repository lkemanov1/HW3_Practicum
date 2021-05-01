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
#include "Duelist.hpp"
#include <fstream>
using namespace std;
Duelist::Duelist(const Deck& from, const std::string& name)
{
    this->deck = from;
    this->name = name;
}
Deck Duelist::get_deck() const
{
    return this->deck;
}

bool Duelist::save_to_file(const std::string& file_name) const
{
    ofstream file(file_name);
    if (!file.is_open())
        return false;
    file << this->deck.get_name() << "|" << this->deck.get_monsters_count() << "|" 
            << this->deck.get_magics_count() << "|" << this->deck.get_pendulums_count() << "\n"; 
    for (int idx = 0; idx < this->deck.get_monsters_count(); idx++)
    {
        file << this->deck.get_monster(idx).get_name() << "|";
        file << this->deck.get_monster(idx).get_effect() << "|";
        file << this->deck.get_monster(idx).get_attack() << "|";
        file << this->deck.get_monster(idx).get_defence() << "\n";
    }
    for (int idx = 0; idx < this->deck.get_magics_count(); idx++)
    {
        file << this->deck.get_magic(idx).get_name() << "|";
        file << this->deck.get_magic(idx).get_effect() << "|";
        file << this->deck.get_magic(idx).get_type_name() << "\n";
    }
    for (int idx = 0; idx < this->deck.get_pendulums_count(); idx++)
    {
        file << this->deck.get_pendulum(idx).get_name() << "|";
        file << this->deck.get_pendulum(idx).get_effect() << "|";
        file << this->deck.get_pendulum(idx).get_attack() << "|";
        file << this->deck.get_pendulum(idx).get_defence() << "|";
        file << this->deck.get_pendulum(idx).get_scale() << "|";
        file << this->deck.get_pendulum(idx).get_type_name() << "\n";
    }
    file.close();

    return true;
}

bool Duelist::read_from_file(const std::string& file_name)
{
    cout << "in\n";
    ifstream file(file_name);
    if (!file.is_open())
    {
        cout << "not open\n";
        return false;
    }
    cout << "file open\n";
    this->deck.clear_deck();
    string deck_name,info;
    int monster_count, magic_count, pendulum_count;
    getline(file, info);
    deck_name = readfile(info);
    cout << deck_name << endl;
    monster_count = to_int(readfile(info));
    magic_count = to_int(readfile(info));
    pendulum_count = to_int(readfile(info));
    for (int idx = 0; idx < monster_count; idx++)
    {
        getline(file, info);
        read_monster(info);
    }
    for (int idx = 0; idx < magic_count; idx++)
    {
        getline(file, info);
        read_magic(info);
    }
    for (int idx = 0; idx < pendulum_count; idx++)
    {
        getline(file, info);
        read_pendulum(info);
    }
    return true; 
}

std::string Duelist::readfile(std::string& info) const
{
    string word = "";
    for (int idx = 0; idx < info.size() && info[idx] != '|'; idx++)
    {
        ///cout << info[idx] << endl;
        word += info[idx];
    }
    
    info.erase(0, min(word.size() + 1,info.size()));
    return word;
}

int Duelist::to_int(const std::string& number) const
{
    int num = 0;
    for (int idx = 0; idx < number.size(); idx++)
    {
        num *= 10;
        num += number[idx] - '0';
    }
    return num;
}

void Duelist::read_monster(std::string& monster)
{
    string name, effect;
    int attack, defence;
    name = readfile(monster);
    effect = readfile(monster);
    attack = to_int(readfile(monster));
    defence = to_int(readfile(monster));
    this->deck.add_monster(MonsterCard(Card(name, effect), attack, defence));
}
void Duelist::read_magic(std::string& magic)
{
    string name, effect, type;
    MagicType mtype;
    name = readfile(magic);
    effect = readfile(magic);
    type = readfile(magic);
    if (type == "SPELL") mtype = MagicType::spell;
    if (type == "TRAP") mtype = MagicType::trap;
    if (type == "BUFF") mtype = MagicType::buff;
    this->deck.add_magic(MagicCard(Card(name, effect), mtype));
}
void Duelist::read_pendulum(std::string& pendulum)
{
    MagicType mtype;
    string name,effect,type;
    int attack, defence;
    short scale;
    name = readfile(pendulum);
    effect = readfile(pendulum);
    attack = to_int(readfile(pendulum));
    defence = to_int(readfile(pendulum));
    scale = to_int(readfile(pendulum));
    type = readfile(pendulum);
    if (type == "SPELL") mtype = MagicType::spell;
    if (type == "TRAP") mtype = MagicType::trap;
    if (type == "BUFF") mtype = MagicType::buff;
    Card card(name, effect);
    this->deck.add_pendulum(PendulumCard(MonsterCard(card, attack, defence), MagicCard(card, mtype), scale, name, effect));
}
