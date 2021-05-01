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
#ifndef CARD_HPP_INCLUDED
#define CARD_HPP_INCLUDED
#pragma once 
#include<string>
class Card
{
public:
	Card() = default;
	Card(const std::string& name, const std::string& effect);
	std::string get_name()const;
	std::string get_effect()const;
protected:
	std::string name;
	std::string effect;
}; 
#endif // CARD_HPP_INCLUDED