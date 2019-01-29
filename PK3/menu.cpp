#include"stdafx.h"
#include"menu.h"
#include<Windows.h>


int menu::controlMenu() //kontrola menu za pomoca strzalek
{
	int down = 1;
	choice = down;
	int up = 6;
	int jump = 1;
	const int character_up = 72;
	const int character_down = 80;
	char arrow;
	while (true)
	{
		system("cls");
		printMenu();
		arrow = _getch();
		switch (arrow)
		{
		case character_up:
			if (choice > down) choice -= jump;
			break;
		case character_down:
			if (choice < up) choice += jump;
			break;
		case '\015':
			return choice;
			break;
		}
	}
	
}

void menu::startMenu() //tutaj nastepuje wybor opcji z wyswietlanego menu
{
	list.loadFromFile("baza.txt");

	while (true)
	{
		switch (controlMenu())
		{
			system("cls");
		case 1:
			list.printAll();
			break;
		case 2:
			list.searchProduct(list.product);
			break;
		case 3:
			list.addProduct();
			break;
		case 4:
			list.removeProduct();
			break;
		case 5:
			list.printExpired(list.product,today);
			list.deleteExpired(list.product, today);
			break;
		case 6:
			std::cout << "Do zobaczenia";
			list.saveAll();
			Sleep(1000);
			exit(0);
			break;
		}
			
	}
}

void menu::printMenu()
{
	if (choice == 1) std::cout << "->";
	std::cout << " Wyswietl wszystkie leki" << "            Dzisiejsza data: " << today << "\n";
	if (choice == 2) std::cout << "->";
	std::cout << " Wyszukaj lek\n";
	if (choice == 3) std::cout << "->";
	std::cout << " Dodaj lek\n";
	if (choice == 4) std::cout << "->";
	std::cout << " Usun lek\n";
	if (choice == 5) std::cout << "->";
	std::cout << " Pokaz przeterminowane leki\n";
	if (choice == 6) std::cout << "->";
	std::cout << " Wylacz program\n";
}

menu::menu()//konstruktor ustawiajacy dzisiejsza date w celu pozniejszego wykorzystania jej do sprawdzenia czy istnieja leki przeterminowane
{
	SYSTEMTIME st;
	GetLocalTime(&st);

	int _year = st.wYear;
	int _month = st.wMonth;
	int _day = st.wDay;
	today = (_year * 10000) + (_month * 100) + _day;
}

menu::~menu()
{
	today = 0;
	choice = 0;
}
