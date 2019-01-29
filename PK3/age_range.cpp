#include"stdafx.h"
#include "age_rang.h"


age_range::age_range()
{
	bottom = 0;
	top = 200;
}

age_range::age_range(float x)
{
	bottom = x;
	top = 200;
}

age_range::age_range(float x, float y)
{
	bottom = x;
	top = y;
}

age_range::~age_range()
{
	bottom = 0;
	top = 0;
};

void age_range::setTop(float x)
{
	top = x;
}

void age_range::setBottom(float y)
{
	bottom = y;
}

float age_range::getTop()
{
	return top;
}

float age_range::getBottom()
{
	return bottom;
}

std::ostream & operator<<(std::ostream &out, age_range&x)
{
	if (x.getTop() >= 190 && x.getBottom() == 0) return out << "Brak ograniczen wiekowych.\n";
	else return out << "Lek od " << x.getBottom() << " roku zycia do " << x.getTop() << " roku zycia.\n";
}

void age_range::printAgeRange()
{
	if (getTop() >= 190 && getBottom() == 0) std::cout << "Brak ograniczen wiekowych.\n";
	else std::cout << "Lek od " << getBottom() << " roku zycia do " << getTop() << " roku zycia.\n";
}

void age_range::setAgeRange()
{
	char arrow,choice;
	float _lower = 0;
	bool circle;
	const int character_up = 72;
	const int character_down = 80;
	int jump = 1;
	
	while (true)
	{
		system("cls");
		std::cout << "Aktualne dane -> ";
		printAgeRange();
		std::cout << "Ktora granice wieku chcesz ustawic?\n1. Dolna\n2. Gorna\nNacisnij ESC jesli chcesz zatwierdzic i przejsc dalej.\n";
		arrow = _getch();
		choice = arrow;
		if (arrow == '2') arrow = '1';
		switch (arrow)
		{
		case '1':
			circle = true;
			while (circle)
			{
				system("cls");
				printAgeRange();
				if (choice == '1') std::cout << "Dolna granica\n";
				else if (choice == '2') std::cout << "Gorna granica\n";
				std::cout << "Ustaw granice: " << _lower << std::endl;
				std::cout << "strzalki gora/dol | enter - zatwierdz";
				arrow = _getch();
				switch (arrow)
				{
				case character_up:
					if (choice == '1')
					{
						if (_lower < getTop()) _lower += jump;
					}
					else _lower += jump;
					break;

				case character_down:
					if (choice == '2')
					{
						if (_lower > getBottom()) _lower -= jump;
					}

					else if (_lower > 0) _lower -= jump;
					break;

				case '\015':
					if (choice == '1')
					{
						setBottom(_lower);
					}
					else if (choice == '2')
					{
						setTop(_lower);
					}
					circle = false;
					break;
				}
			}
			break;
		case '\033':
			return;
			break;
		}
	}
}

