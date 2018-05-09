#include <iostream>
#include <string>
#include <time.h>
#include "Card.h"
#include "Player.h"

using namespace std;

Card* get_card(Card** deck, int& last){
	int n = rand() % 52;
	Card* c = deck[n];
	deck[n] = deck[last];
	deck[last--] = c; //сохраняем адрес карты, чтобы  потом было что чистить
	return c;
}

int main(){
	char over = 0;
	string name;
	
	cout << endl;
	cout << "Hello!!! " << endl;
	cout << "Welcome to Black Jack!"<< endl;
	cout << endl;
	cout << "What is your name? "<< endl;
	cin >> name;
	cout << "Let's play, " << name << endl;
	
	while (over != 'x')	{
		
		int last = 51;
		Player dealer("Dealer");
		Player player(name);
		
		Card* deck[52];
		for (int i = 2; i <= 14; i++){
			
			for (int j = 0; j < 4; j++){
				
				Card* c = new Card();
				c->AssignValues(j, i);
				deck[(i - 2) * 4 + j] = c;
			}
		}
	
	
	/*
	BlackJack blackjack [52];// 2D array for the deck
	// вместо создания 2D array - создать класс Card.  
	// в классе создать конструкторы - присваивают value и suit.. 
	
	// потом вызвать в main - Card card [52] - и каждая карта в array будет иметь конструкторы и функции..
	// через  for loop заполнить array картами (конкретно)..
// создать для этого array из 4 char suit [] {'S', 'H', 'C', 'D'}
// и аrray из 13 char value [] {'2', '3', '4'...'Q', 'K'...}
// for loop тройная - все arrays перебирает и наполняет
	
	*/
	
	
	return 0;
}