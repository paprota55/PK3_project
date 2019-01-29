#include "stdafx.h"
#include "searchCode.h"

medicine* searchCode::searchGood(const int& code, const std::string &newMed, medicine* head)//Przeszukiwanie listy w celu znalezienia takiego leku o podanej nazwie
{
	if (head == nullptr) return nullptr;
	medicine* current = head;

	while (current != nullptr)
	{
		if (current->data.getCode() == code)
		{
			return current;
		}
		current = current->next;
	}
	return nullptr;
}

medicine* searchCode::writeAndSearch(medicine*head)//interakcja z uzytkownikiem o podanie kodu, a nastepnie wywolanie funkcji przeszukujacej liste lekow
{
	medicine* current;
	int code;
	system("cls");
	std::cout << "Podaj kod leku: ";
	while (!(std::cin >> code))
	{
		std::cout << "Zly kod!\nPodaj poprawny: " << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n'); //czyszczenie strumienia ze wszystkich znakow
	}

	current = searchCode::searchGood(code, "", head);
	return current;
}

void searchCode::complexSearch(medicine * head)
{
}

bool searchCode::searchInList(medicine *, const std::string &)
{
	return false;
}

searchCode::searchCode()
{
}


searchCode::~searchCode()
{
}

