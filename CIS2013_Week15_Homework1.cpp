#include <iostream>
#include <string>
#include <time.h>
#include "Card.h"
#include "Player.h"

using namespace std;

// в - Card* get_card(Card** deck, int& last) - deck - указатель на массив карт, указатель на колоду
// last - номер последней карты в колоде, которая еще не играла 
//(амперсанд здесь говорит, что это не копия параметра, который мы передаем в ф-ию, а сам параметр, 
//если мы его изменим внутри, то он изменится и снаружи и мы будем знать его новое значение)

Card* get_card(Card** deck, int& last){
//этим самым заявили, что везде где мы напишем a = get_card(b, c): a - это переменная Сard* a ! 
//и мы здесь присваиваем ей значение, которое  возвращаем из функции оператором  return
	
	//int n = rand() % 52; // так берет карту из полной 52-хкартной, не укороченной колоды
	
	//получаем случайный индекс карты из активной части колоды, n ,eltn от 0 до last включительно (первый раз last у нас - 51, второй 50 и т.д.)
	int n = rand() % (last + 1); // выпавшие карты мы убираем за пределы действия last
	Card* c = deck[n]; //получили карту
	
	//индекс-номер места в array последней не игравшей карты - last, мы её deck[last] берём и записываем на место выпавшей в ячейку массива с номером n  - deck[n]
	deck[n] = deck[last]; //последней неигранной карты в колоде (первый раз 51-ю, когда тянем 2-й раз 50-ю и т.д. ) 
	//записываем на место выпавшей (реально оперируем не с картами, а с их адресами, поэтому так все просто)
	// первый раз мы сдаем одну карту откуда-то из колоды, на её место записываем 51-ю, а сданную записываем в  deck[51];
	//когда сдаем вторую, то на её место записываем 50-ю, а сданную на место 50-й

	deck[last--] = c; // //выпавшую записываем на место последней и затем уменьшаем счетчик на 1, 
	//чтобы активных карт стало меньше на 1. 
	//можно было бы просто выкинуть выпавшую карту из колоды, но мы выделили для нее память, когда вызывали new, 
	//и нам надо потом ее освободить будет, поэтому мы и сохраняем адрес карты, чтобы  потом было что чистить
	// в deck[last] у нас хранится последняя не игравшаяся карта, все карты после last - уже играли
	// last - последняя в  array только в самый первый раз

	//сохраняем адрес карты, чтобы  потом было что чистить
	return c; //возвращаем адрес выпавшей карты
	// возвращает значение "с" из функции, при объявлении ф-ии первое что мы пишем - тип возвращаемого значения  - здесь это пойнтер (на адрес)!
}
// а также после вызова ф-ии у нас будет новое значение параметра last, 
//уменьшенное на единицу, которое, когда нам понадобится сдать карту, мы передадим в следующий вызов get_card.


// question to continue the game
void question (char& answer) {
	
	cout << "Do you want to hit more? y/n" << endl;
	cin >> answer;
}

int main(){
	char over = 0;
	char answ='y';
	char answer;
	string name;
	
	cout << endl;
	cout << "Hello!!! " << endl;
	cout << "Welcome to Black Jack!"<< endl;
	cout << endl;
	cout << "What is your name? "<< endl;
	cin >> name;
	
	
	while (answ== 'y')	{
				
		int last = 51;
		Player dealer("Dealer");
		Player player(name);
		
		Card* deck[52];
		
		// у первых 10-ти номинал совпадает с названием, поэтому проще начать с 2-ки и закончить 14-м королем, 
		//( проще потом в вызове AssignValues - короче switch):
		// в этом массиве у нас карты располагаются так - 4 двойки SCDH, 4 тройки, 4 четверки...
		//в конце 4 короля: KS, KC, KD, KH; 
		// начинаем заполнять i=0 j=0   2S; i=0 j=1 2C..
		for (int i = 2; i <= 14; i++){
			
			for (int j = 0; j < 4; j++){
				
				Card* c = new Card(); // это оператор new. он выделяет память нужного размера и помещает туда объект, 
				//который создает при помощи конструктора Card(), нам он возвращает адрес этого участка памяти (указатель на вновь созданный объект) -"c". 
				//Карта использует метод для присвоения значений и масти
				c->assignValues(j, i); // это вызов метода класса, только ты не сам объект используешь, а более естественно вызываешь  - по адресу объекта. 
				// объект по адресу "с" имеет такие значения теперь.
				
				// цикл начинается с i=2; для i=2 выражение в скобках получается просто j, 
				// т.е. при i=2 мы обращаемся последовательно к 0, 1, 2 и 3-му элементам массива. 
				//Дальше: i=3 : выражение в скобках получается 4+ j, это 4,5,6,7-й и т.д
				//когда i наконец 14, 12*4 = 48, получаем последние 4 позиции в колоде 48.49.50.51
				deck[(i - 2) * 4 + j] = c;
				// при этом масть у нас задает j, а карту от двойки до короля (14) i;
				// Assign задает как раз эти величины, а также назначает вес. исходя из i;
			}
		}
	
	cout << "						Let's play, " << name << endl;
	cout << "			********************************************************" << endl;
		//rand() - ф-я псевдослучайная, т.е. при последовательных запусках приложения, вывалит одно и то же, если не задать разный seed.
		//вот  srand(time(0));  и задает seed в виде количества секунд с начала 1970 г.
		srand(time(0));
		
		//пойнтер "c" приравнивается к значению, которое возвращает ф-я, а именно к адресу случайной карты
		Card* c = get_card(&deck[0], last);
		player.addCard(c);
		c = get_card(&deck[0], last);
		player.addCard(c);
		player.print();
		cout << endl;

		c = get_card(&deck[0], last);
		dealer.addCard(c);
		c = get_card(&deck[0], last);
		dealer.addCard(c);
		dealer.print();
		cout << endl;
		
		// ВОЗМОЖНО НЕ нужно сплит..
		if (player.points() == 21){
			
			if (dealer.points() == 21){
				
				cout << endl << "Dealer wins!" << endl;
			} else {
				
				cout << endl << player.name() << " wins!";
			}
			
		} else if (player.points() > 21){
			
			cout << endl << dealer.name() << " wins!";
			
		} else {
			
			bool b = true;
			// char x;
			
			cout << endl;
			question (answer);
			//cin >> x;
			
			while (answer == 'y') {
				
					
				c = get_card(&deck[0], last);
				player.addCard(c);
				player.print();
				
				if (player.points() == 21){
					
					cout << endl << player.name() << " wins!";
					b = false;
					break;
				}
				else if (player.points() > 21){
					
					cout << endl << dealer.name() << " wins!";
					b = false;
					break;
				}
				//cin >> x;
				question (answer);
			}	
			
			while ((dealer.points() <= 17) && (player.points() < 21)) {
				
				c = get_card(&deck[0], last);
				dealer.addCard(c);
				dealer.print();
				
			}
			if ((dealer.points() <= 21) && (dealer.points() >= player.points())){
			
				cout << endl << dealer.name() << " wins!";
				break;
			}
			if (dealer.points() > 21){
					
				cout << endl << player.name() << " wins!";
				break;
					//exit(0);
			} else if (dealer.points() < player.points()){
					
					cout << endl << player.name() << " wins!";
				break;
					// //exit(0);
				}
			
				
// ЗАЧЕМ ЭТА while loop? 
// ПОЧЕМУ ==18? И ПРИ ЭТОМ ИГРОК ВЫИГРЫВАЕТ?
/*
			while (b){
				
				c = get_card(&deck[0], last);
				dealer.addCard(c);
				dealer.print();
				if (dealer.points() > 21){
					
					cout << endl << player.name() << " wins!";
					b = false;
				} else if ((dealer.points() == 21) || (dealer.points() >= player.points())){
					
					cout << endl << dealer.name() << " wins!";
					b = false;
				} else if (dealer.points() >= 18){
					
					cout << endl << dealer.name() << " stays!" << endl;
					cout << player.name() << " wins!";
					b = false;
				}
			}
			*/
		}

		for (int i = 0; i < 52; i++)
		{
			delete deck[i];
		}
		
		cout << endl;
		cout << "Do you wanna play another game? (y/n): " << endl;
		cin >> answ;
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