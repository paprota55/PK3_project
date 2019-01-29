#include"stdafx.h"
#include "allergy.h"


allergy::allergy()
{
	alle = false;
}

allergy::allergy(bool x)
{
	alle = x;
}

allergy::~allergy() {};

void allergy::setAllergy(bool x)
{
	alle = x;
}

bool allergy::getAllergy()
{
	return alle;
}

void allergy::setAllergyMain() //Zapytania do uzytkownika czy lek posiada alergeny
{
	char arrow;
	int x = 0;

	const int character_up = 72;
	const int character_down = 80;

	while (true)
	{
		system("cls");
		std::cout << "Czy posiada alergeny?\n";
		if (x == 0) std::cout << "Tak\n->Nie\n";
		else std::cout << "->Tak\nNie\n";
		std::cout << "Wybierz strzalkami zatwierdz enterem";
		
		arrow = _getch();
		switch (arrow)
		{
		case character_up:
			if (x < 1)x++;
			break;
		case character_down:
			if (x > 0)x--;
			break;
		case '\015':
			setAllergy(x);
			return;
			break;
		}
	}
	
}

