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
// В теле ф-ии записываем  адрес card в позицию _cardsCount : _cards[_cardsCount] = card;  и 
// увеличиваем счетчик  _cardsCount на единицу : _cardsCount++;
//чтобы быть готовыми к приему следующей карты, если понадобится. 
//Таким образом в первых  _cardsCount позициях array мы храним полученные игроком карты.
void Player::addCard(Card * card){
	
	_cards[_cardsCount] = card; // это и есть запись адреса карты в наш array в следующую свободную позицию.
	_cardsCount++;
}

// КАК ЭТО ФУНКЦИЯ PRINT ВНУТРИ ЭТОЙ ЖЕ ФУНКЦИИ PRINT? + СТРЕЛОЧКУ -> НЕ ПРОХОДИЛИ..нужно поменять
void Player::print(){
	
	cout << _name << ':'<< endl;
	cout << "---------"<< endl;
	for (int i = 0;i < _cardsCount;i++)	{
		
		// если у тебя A - объект класса, то к любому члену класса обращаешься A.b; а если A - указатель на объект, то A->b;
		//если объект (instance), то точка, если указатель (pointer), то стрелочка;
		// это вызов метода класса, только ты не сам объект используешь, а более естественно вызываешь  - по адресу объекта. 
		//короче, это равносильно (*_cards[i]).Print();
		// вот этот вызов понятен ведь: 
		// Card c;
		// c.Print(); 
		// A если взять адрес с, вот так -  &с, то можно обратиться 
		// (&с)->Print();
		// - напечатать объект по адресу..
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

// ЭТО ДЛЯ ЧЕГО??
/*
void Player::reset(){
	
	for (int i = 0;i < _cardsCount;i++)	{
		
		_cards[i] = 0;
	}
	_cardsCount = 0;
}
*/

	// BlackJack::BlackJack () {
		// card_deck = new string [52];
	// }
	
