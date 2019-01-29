#include"stdafx.h"
#include "prescription.h"


prescription::prescription()
{
	prescript = false;
}

prescription::prescription(bool x)
{
	prescript = x;
}

prescription::~prescription() {};

void prescription::setPrescription(bool x)
{
	prescript = x;
}

bool prescription::getPrescription()
{
	return prescript;
}

void prescription::setPrescriptionMain()//interakcja z uzytkownikiem, wymusza ustawienie wartosci czy lek jest na recepte
{
	char arrow;
	int x = 0;

	const int character_up = 72;
	const int character_down = 80;

	while (true)
	{
		system("cls");
		std::cout << "Czy jest na recepte?\n";
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
			setPrescription(x);
			return;
			break;
		}
	}

}

