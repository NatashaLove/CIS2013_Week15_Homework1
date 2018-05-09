#include <iostream>
#include <string>
#include "Player.h"
#include "Card.h"

using namespace std;
// Class :: Constructor
Player::Player(string name){
	
	_name = name;
}

Player::~Player(){
	
}

void Player::addCard(Card * card){
	
	_cards[_cardsCount] = card;
	_cardsCount++;
}

// ЭТО ДЛЯ ЧЕГО??
void Player::reset(){
	
	for (int i = 0;i < _cardsCount;i++)	{
		
		_cards[i] = 0;
	}
	_cardsCount = 0;
}

// КАК ЭТО ФУНКЦИЯ PRINT ВНУТРИ ЭТОЙ ЖЕ ФУНКЦИИ PRINT? + СТРЕЛОЧКУ -> НЕ ПРОХОДИЛИ..нужно поменять
void Player::print(){
	
	cout << _name << ':'<< endl;
	cout << "---------"<< endl;
	for (int i = 0;i < _cardsCount;i++)	{
		
		_cards[i]->print();
		cout << endl;
	}
	cout << "Total points: " << points() << endl;
	cout << "-------------------"<< endl;
}

// СТРЕЛОЧКУ -> НЕ ПРОХОДИЛИ..нужно поменять функцию (или изучить стрелочку)
int Player::points(){
	
	int weight = 0;
	for (int i = 0;i < _cardsCount;i++)	{
		
		weight += _cards[i]->weight();
	}
	return weight;
}

string Player::name(){
	
	return _name;
}

	// BlackJack::BlackJack () {
		// card_deck = new string [52];
	// }
	
