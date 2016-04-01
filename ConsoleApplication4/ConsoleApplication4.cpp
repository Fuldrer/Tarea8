// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

struct Deck{
public:
	int tipo;
	Deck *nextdeck;
	Deck(int tipo){
		this->tipo = tipo;
	}

	void next(Deck * deck){
		nextdeck = deck;
	}
	Deck *getnextdeck(){

		return nextdeck;
	}
};

struct Stack{
public:
	int size;
	int getsize(){
		return size;
	}

	Deck *top = nullptr;

	Deck *gettop(){
		return this->top;
	}

	void push_back(Deck* deck){
		if (top != nullptr){
			deck->next(top);
		}
		top = deck;
		size++;
	}

	void pop_back(){
		top = top->getnextdeck();
		size--;
	}

};

int main()
{
	Stack decks;
	for (int a = 1; a <= 9; a++){
		decks.push_back(new Deck(a));
	}

	while (decks.getsize() > 0){
		std::cout << decks.top << std::endl;
		decks.pop_back();
	}
	return 0;
}

