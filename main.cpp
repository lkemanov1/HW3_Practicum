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
using namespace std;
int main()
{
    string myfile = "test.txt";
    Deck mydeck("The best deck");
    Card card1("name", "effect");
    Card card2("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.");
    Card card3("Dark Magician", "THe ultimate wizard");
    Card card4("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.");
    Card card5("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.");
    MagicCard magic(Card("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards"), MagicType::spell);
    MonsterCard monster(Card("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards"), 1200, 600);
    mydeck.add_magic(MagicCard(card1, MagicType::buff));
    mydeck.add_monster(MonsterCard(card2, 3000, 2500));
    mydeck.add_monster(MonsterCard(card3, 2500, 2100));
    mydeck.add_magic(MagicCard(card4, MagicType::spell));
    mydeck.add_magic(MagicCard(card5, MagicType::trap));
    mydeck.add_pendulum(PendulumCard(monster,magic,8,"Timegazer Magician","Your opponent cannot activate Trap Magic Cards"));
    mydeck.change_magic(0, MagicCard(card4, MagicType::spell));
    Duelist duelist(mydeck, "Ivan Petrov");
    duelist.save_to_file(myfile);
    duelist.read_from_file(myfile);
    cout << duelist.get_deck().get_monsters_count() << endl;
    cout << duelist.get_deck().get_magics_count() << endl;
    cout << duelist.get_deck().get_pendulums_count() << endl;
    return 0;
}/*
Blue-Eyes White Dragon|This legendary dragon is a powerful engine of destruction.|3000|2500
Dark Magician|The ultimate wizard.|2500|2100
Swords of Revealing Light|Your opponent's monsters cannot declare an attack.|SPELL
Magic Cylinder|Inflict damage to your opponent equal to its ATK.|TRAP
Timegazer Magician|Your opponent cannot activate Trap Magic Cards|1200|600|8|SPELL
*/