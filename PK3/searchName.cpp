#include "stdafx.h"
#include "searchName.h"

medicine* searchName::searchGood(const int&, const std::string &newMed, medicine* head)//Przeszukiwanie listy w celu znalezienia takiego leku o podanej nazwie
{
	if (head == nullptr) return nullptr;
	medicine* current = head;
	while (current != nullptr)
	{
		if (current->data.getName() == newMed)
		{
			return current;
		}
		current = current->next;
	}
	return nullptr;
}

medicine* searchName::writeAndSearch(medicine*head)//interakcja z uzytkownikiem o podanie kodu, a nastepnie wywolanie funkcji przeszukujacej liste lekow
{
	medicine* current;
	std::string name;
	system("cls");
	std::cout << "Podaj nazwe leku: ";
	getline(std::cin, name);
	name = convertToUpper(name);
	current = searchName::searchGood(0, name, head);
	return current;
}

void searchName::complexSearch(medicine * head)
{
}

bool searchName::searchInList(medicine *, const std::string &)
{
	return false;
}

searchName::searchName()
{
}


searchName::~searchName()
{
}