#include"stdafx.h"
#include "addition.h"



addition::addition()
{
	code = 0;
	price = 0;
	quantity = 0;
	name = "empty";
	description = "empty";
}

addition::~addition()
{
	code = 0;
	price = 0;
	quantity = 0;
	name = "";
	description = "";
}

void addition::setName(std::string _name)
{
	name = _name;
}

void addition::setDescription(std::string _description)
{
	description = _description;
}

void addition::setPrice(double x)
{
	price = x;
}

void addition::setQuantity(int y)
{
	if (y < 0) quantity = 0;
	else quantity = y;
}

void addition::setCode(int _code)
{
	code = _code;
}

std::string addition::getName()
{
	return name;
}

std::string addition::getDescription()
{
	return description;
}

double addition::getPrice()
{
	return price;
}

int addition::getCode()
{
	return code;
}

int addition::getQuantity()
{
	return quantity;
}

void addition::setAddition(int edit) //Funkcja ustawiajaca wszystkie elementy klasy
{
	using namespace std;
	char arrow;
	double _price;
	int _code = 0;
	std::string tmp, tmp2;
	while (true)
	{
		system("cls");
		std::cout << "Aktualne dane:\n";
		printAddition();
		std::cout << "\n";
		if(edit == 1)std::cout << "Ktore pole chcesz ustawic?\n1. Nazwa - Tylko przy dodawaniu leku\n2. Cena\n3. Kod - Tylko przy dodawaniu leku\n4. Liczbe lekow\n5. Opis\nNacisnij ESC jesli chcesz zakonczyc wprowadzanie.\n";
		else std::cout << "Ktore pole chcesz ustawic?\n1. Nazwa\n2. Cena\n3. Kod\n4. Liczbe lekow\n5. Opis\nNacisnij ESC jesli chcesz zakonczyc wprowadzanie.\n";
		arrow = _getch();
		switch (arrow)
		{
		case '1':
			if (edit == 1) {}
			else
			{
				system("cls");
				std::cout << "Podaj nazwe leku: ";
				getline(std::cin, tmp);
				setName(convertToUpper(tmp));
			}
				break;
		case '2':
			system("cls");
			std::cout << "Podaj cene: ";
			while (!(std::cin >> _price))
			{
				std::cout << "ZLA CENA!\nPodaj poprawna: " << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n'); //czyszczenie strumienia ze wszystkich znakow
			}
			if (_price < 0) _price = 0;
			setPrice(_price);
			break;
		case '3':
			if (edit == 1) {}
			else
			{
				system("cls");
				std::cout << "Podaj kod: ";
				while (!(std::cin >> _code))
				{
					std::cout << "ZLY KOD!\nPodaj poprawny: " << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n'); //czyszczenie strumienia ze wszystkich znakow
				}
				if (_code < 0) _code = 0;
				setCode(_code);
			}
			break;
		case '4':
			system("cls");
			std::cout << "Podaj liczbe lekow: ";
			while (!(std::cin >> _code))
			{
				std::cout << "ZLA LICZBA LEKOW!\nPodaj poprawna: " << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n'); //czyszczenie strumienia ze wszystkich znakow
			}
			if (_code < 0) _code = 0;
			setQuantity(_code);
			break;
		case '5':
			system("cls");
			std::cin.clear();
			std::cout << "Podaj opis: ";
			getline(std::cin, tmp2);
			setDescription(tmp2);
			break;
		case '\033':
			if(getName() != "" && getCode() !=0) return;
			else system("cls");  std::cout << "Musisz podac nazwe leku oraz kod!\n"; system("PAUSE");
			break;
			}
		}
	}

void addition::printAddition()
{
	std::cout << "Nazwa leku: " << getName() << " Cena: " << getPrice() << " zl Kod: " << getCode() << " Ilosc: " << getQuantity() << " Opis: " << getDescription()<<std::endl;

}

addition & addition::operator+=(const int &arg) //operator zwiekszajacy ilosc lekow
{
	int _quant = this->getQuantity();
	_quant += arg;
	if (_quant < 0) _quant = 0;
	this->setQuantity(_quant);
	return *this;
}

std::ostream & operator<<(std::ostream &out, addition&x)
{
	return out << "Nazwa: " << x.getName() << "\nCena: " << x.getPrice() << " zl\nKod: " << x.getCode() << "\nIlosc: " << x.getQuantity() << "\nOpis: " << x.getDescription() << std::endl;
}

bool addition::operator==(addition & newAdd) //Operator porownujacy nazwy lekow
{
	if (this->getName() == newAdd.getName())
	{
		return true;
	}
	return false;
}

