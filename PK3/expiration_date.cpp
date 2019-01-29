#include"stdafx.h"
#include"expiration_date.h"
#include <Windows.h>

expiration_date::expiration_date()
{
	day = 0;
	month = 0;
	year = 0;
}

expiration_date::expiration_date(int x)
{
	day = x;
	month = 0;
	year = 0;
}

expiration_date::expiration_date(int x, int y)
{
	day = x;
	month = y;
	year = 0;
}

expiration_date::expiration_date(int x, int y, int z)
{
	day = x;
	month = y;
	year = z;
}

expiration_date::~expiration_date()
{
	day = 0;
	month = 0;
	year = 0;
};

void expiration_date::setDay(int x)
{
	day = x;
}

void expiration_date::setMonth(int y)
{
	month = y;
}

void expiration_date::setYear(int z)
{
	year = z;
}

int expiration_date::getDay()
{
	return day;
}

int expiration_date::getMonth()
{
	return month;
}

int expiration_date::getYear()
{
	return year;
}


bool expiration_date::year366(int number) //Sprawdza czy rok jest przestepny
{
		if (number % 4 == 0 && number % 100 != 0 || number % 400 == 0)
			return true;
		else
			return false;
}

bool expiration_date::operator==(expiration_date &newDate)
{
	if (this->getDay() == newDate.getDay() && this->getMonth() == newDate.getMonth() && this->getYear() == newDate.getYear()) return true;
	return false;
}

bool expiration_date::operator<(int x) //operator sprawdza czy data nie jest mniejsza od podanej
{
	int first;
	first = this->getYear() * 10000;
	first += (this->getMonth() * 100);
	first += this->getDay();
	if (first < x) return true;
	return false;
}


void expiration_date::setDate() //funkcja komunikujaca sie z uzytkownikiem, ktora wymaga uzupelnienia pol daty waznosci
{
	SYSTEMTIME st;
	GetLocalTime(&st);

	bool cycle = true;
	bool programm = true;
	char arrow;

	const int character_up = 72;
	const int character_down = 80;

	int state = 1;
	int jump = 1;
	int _year = st.wYear;
	int _month = st.wMonth;
	int _day = st.wDay;

	while(programm)
	switch (state) 
	{
		case 1:
			cycle = true;	
			while (cycle)
			{
				system("cls");
				printExpirationDate();
				std::cout << "Ustaw rok: " << _year << std::endl;

				std::cout << "strzalki gora/dol | enter - zatwierdz";

				arrow = _getch();
				switch (arrow)
				{
				case character_up:
					_year += jump;
					break;
				case character_down:
					if (_year > st.wYear) _year -= jump;
					break;
				case '\015':
					state = 2;
					cycle = false;
					year = _year;
					break;
				}
			}
			break;
		case 2:
			cycle = true;
	
			while (cycle)
			{
				system("cls");
				printExpirationDate();
				std::cout << "Ustaw miesiac: " << _month << std::endl;
				std::cout << "strzalki gora/dol | enter - zatwierdz/ backspace - powrot do roku";

				arrow = _getch();
				switch (arrow)
				{
				case character_up:
					if (_month < 12)
					{
						_month += jump;
					}
					break;

				case character_down:
					if (_year == st.wYear)
					{
						if (_month > st.wMonth)
						{
							_month -= jump;
						}
					}
					else if (_month > 1)
					{
						_month -= jump;
					}
					break;
				case '\015':
					month = _month;
					state = 3;
					cycle = false;
					break;

				case '\010':
					state = 1;
					cycle = false;
					break;
				}
			}
			break;
		case 3:
			cycle = true;
			while (cycle)
			{
				system("cls");
				printExpirationDate();
				std::cout << "Ustaw dzien: " << _day << std::endl;
				std::cout << "strzalki gora/dol | enter - zatwierdz/ backspace - powrot do miesiaca";
				arrow = _getch();
				switch (arrow)
				{
				case character_up:
					if (_month == 4 || _month == 6 || _month == 9 || _month == 11)
					{
						if (_day < 30) _day += jump;

					}
					else if (_month == 2)
					{
						if (year366(_year))
						{
							if (_day < 29) _day += jump;
						}
						else
						{
							if (_day < 28) _day += jump;
						}
					}
					else
					{
						if (_day < 31) _day += jump;
					}
					break;

				case character_down:
					if (_year == st.wYear && _month == st.wMonth)
					{
						if (_day > st.wDay) _day -= jump;
					}
					else
					{
						if (_day > 1) _day -= jump;
					}
					break;
				case '\015':
					day = _day;
					state = 4;
					cycle = false;
					break;
				case '\010':
					state = 2;
					cycle = false;
					break;
				}
			}
			break;
		case 4:
			programm = false;
			return;
			break;
			}

}

std::ostream & operator<<(std::ostream &out, expiration_date&x)
{
	if(x.getMonth()<10) return out << "Data waznosci: " << x.getDay() << ".0" << x.getMonth() << "." << x.getYear() << std::endl;
	return out << "Data waznosci: " << x.getDay() << "." << x.getMonth() << "." << x.getYear() << std::endl;
}

void expiration_date::printExpirationDate()
{
	std::cout << "Data waznosci: Dzien: " <<getDay() << " Miesiac: " << getMonth() << " Rok: " << getYear() << std::endl;
}
