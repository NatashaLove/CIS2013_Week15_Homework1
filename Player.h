#include <iostream>
#include <string>
//g++ CIS2013_Week15_Homework1.cpp

using namespace std;

// class Card; - в начале - forward declaration, в этом месте компилятор ничего не знает о классе Card, а мы его хотим здесь в файле использовать, 
//вот мы ему и говорим, что Сard - это класс, а не что-то другое, а что и как этот класс делает компилятору здесь неважно,
// потому что мы внутрь класса Card здесь (на этапе объявления в файле .h) не лезем;
// ты его в этом файле использовать будешь - поэтому "вызвал"; При этом объект не нужно создавать-  просто класс объявили и все.
class Card;

class Player {
	private:
	
	Card* _cards[12]; // array of twelve (maximum hand) pointers to addresses of objects of type Card*
	// т.е. в каждой из 12-ти ячеек массива содержится адрес объекта Card
	string _name;
	int _cardsCount = 0; // сколько карт получил игрок
	
	public:
	
	Player(string name);
	~Player();

	void addCard(Card* card);
	//void reset();
	void print();
	int points();
	string name();
};


/*
class BlackJack {
	private: 
	//string file_name = "todo.dat";
	string *card_deck; // will be array - deck of cards - make it 2D - call in main : BlackJack blackjack [52];
	// in .cpp : card_deck = new string [52];
	//int length =0;
	int next=0;
	string card;
	string suit, value;
	
	//void file_read();
	//void file_save();
	
	
	public:
		
	// default constructor
	BlackJack ();
	
};
*/