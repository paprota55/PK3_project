#include "stdafx.h"
#include "searchComplex.h"

medicine * searchComplex::searchGood(const int &, const std::string &, medicine *)
{
	return nullptr;
}

medicine * searchComplex::writeAndSearch(medicine *)
{
	return nullptr;
}

bool searchComplex::searchInList(medicine*tempo, const std::string&name) //przeszukuje liste chorob w celu odnalezienia podanego
{
	std::list<std::string> diseList(tempo->dise);
	while (!diseList.empty())
	{
		if (diseList.front() == name)
		{
			return true;
		}
		diseList.pop_front();
	}
	return false;
}

void searchComplex::complexSearch(medicine* head) //wyszukiwanie kompleksowe
{
	medicine* current = head;
	bool allergy, prescript;
	bool circle = true;
	int refund = 0, x = 0;
	char arrow, arrow2, arrow3, arrow4;

	std::string dise;
	while (circle)
	{
		system("cls");
		std::cout << "Czy lek moze posiadac alergeny? (y/n)";
		arrow = _getch();
		switch (tolower(arrow))
		{
		case 'y':
			allergy = true;
			circle = false;
			break;
		case 'n':
			allergy = false;
			circle = false;
			break;
		}

	}
	circle = true;
	while (circle)
	{
		system("cls");
		std::cout << "Czy lek moze byc bez recepty? (y/n)";
		arrow2 = _getch();
		switch (tolower(arrow2))
		{
		case 'y':
			prescript = true;
			circle = false;
			break;
		case 'n':
			prescript = false;
			circle = false;
			break;
		}

	}

	const int character_up = 72;
	const int character_down = 80;
	circle = true;
	while (circle)
	{
		system("cls");
		std::cout << "Powyzej jakiego stopnia refundacji szukac?(0-100): " << x << std::endl;

		std::cout << "strzalki gora/dol | enter - zatwierdz";

		arrow3 = _getch();
		switch (arrow3)
		{
		case character_up:
			if (x < 100)x++;
			break;
		case character_down:
			if (x > 0)x--;
			break;
		case '\015':
			circle = false;
			break;
		}
	}

	system("cls");
	int age = 0;
	int age2 = 200;
	std::cout << "Podaj dolna granice wieku: ";
	while (!(std::cin >> age))
	{
		std::cout << "Zly wiek!\nPodaj poprawny: " << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n'); //czyszczenie strumienia ze wszystkich znakow
	}
	if (age < 0)age = 0;
	else if (age > age2) age = age2;

	system("cls");

	std::cout << "Podaj gorna granice wieku: ";
	while (!(std::cin >> age))
	{
		std::cout << "Zly wiek!\nPodaj poprawny: " << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n'); //czyszczenie strumienia ze wszystkich znakow
	}
	if (age2 < age)age2 = age;
	else if (age2 > 200) age2 = 200;


	system("cls");
	std::cout << "Podaj chorobe, ktora ma zwalczac: ";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');
	std::getline(std::cin, dise);
	int count = 0;
	while (current != nullptr)
	{
		count++;
		if (searchInList(current, convertToUpper(dise)))
		{
			if (allergy == true || (current->alergic.getAllergy() == false))
			{
				if (prescript == false || (current->recept.getPrescription() == true))
				{
					if (current->ref.getRefund() >= x)
					{
						if ((current->ages.getBottom() <= age && current->ages.getTop() >= age2))
						{
							std::cout << count << ". ";
							current->showMedicine(current);
						}
					}
				}
			}
		}
		current = current->next;
	}
	std::cout << "Zapamietaj nazwe lub kod leku, a nastepnie podaj jedno z nich.\n";
	system("pause");

	circle = true;
	while (circle)
	{
		system("cls");
		searchCode x;
		searchName y;
		std::cout << "Z pomoca czego chcesz wyszukac lek?\n1. Nazwa\n2. Kod\n3. Wyjscie";
		arrow4 = _getch();
		switch (arrow4)
		{
		case '1':
			current = y.writeAndSearch(head);
			current->edit();
			circle = false;
			break;
		case '2':
			current = x.writeAndSearch(head);
			current->edit();
			circle = false;
			break;
		case '3':
			circle = false;
			break;
		}
	}
	current = nullptr;
}

searchComplex::searchComplex()
{
}


searchComplex::~searchComplex()
{
}

