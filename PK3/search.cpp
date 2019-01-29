#include"stdafx.h"
#include "search.h"

medicine* search::searchGood(const int&, const std::string &newMed, medicine* head)//Przeszukiwanie listy w celu znalezienia takiego leku o podanej nazwie
{
	std::cout << "Szukam zgodnego leku z podanymi danymi.";
	return nullptr;
}

medicine* search::writeAndSearch(medicine*head)//interakcja z uzytkownikiem o podanie kodu, a nastepnie wywolanie funkcji przeszukujacej liste lekow
{
	std::cout << "Prosze podac dane i je wyszukam.";
	return nullptr;
}

void search::complexSearch(medicine* head) //wyszukiwanie kompleksowe
{
	std::cout << "Wyszukiwanie kompleksowe.";
}

bool search::searchInList(medicine*tempo, const std::string&name) //przeszukuje liste chorob w celu odnalezienia podanego
{
	std::cout << "Przeszukuje liste chorob.";
	return false;
}

search::search()
{
}

search::~search()
{
}
