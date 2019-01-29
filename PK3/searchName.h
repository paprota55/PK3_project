#pragma once
#include "search.h"
/**
* Klasa dziedziczy z klasy bazowej search, a nastepnie nadpisuje funkcje na odpowiadajace nazwie klasy.
*/
class searchName :
	public search
{
public:
	/**
	* Metoda przyjmuje jako parametr referencje do zmiennej typu int, referencje do zmiennej typu string oraz wskaznik na obiekt typu medicine*.
	* Parametr typu int jest w tym wypadku nieistotny.
	* Metoda ta ma za zadanie przeszukac podana liste wskaznikow (medicine*) i znalezc w niej w przypadku klasy searchName element, ktorego nazwa jest taka sama jak nazwa podana w paramaterze typu string.
	* \return nullptr, w przypadku jesli nie znajdzie takowego elementu lecz w przypadku kiedy znajdzie zwraca wskaznik na element, ktory posiada taki sam kod.
	*/
	medicine* searchGood(const int&, const std::string&, medicine*);
	/**
	* Metoda, ktora przyjmuje jako parametr wskaznik na obiekt typu medicine. Metoda ta nie robi z parametrem nic. Jedynie prosi uzytkownika o podanie nazwy.
	* Pobiera funkcja getline ciag znakow podany przez uzytkownika, a nastepnie przekazuje do funkcji konwertujacej na duze litery.
	* Przekonwertowany parametr przekazuje do funkcji odpowiedzialnej za przeszukanie listy.
	* Zwraca wskaznik na element, ktory zwrocila funkcja searchGood.
	*/
	medicine* writeAndSearch(medicine*);
	/**
	* Klasa searchName nie wykorzystuje tej metody w zakresie swojej pracy.
	*/
	void complexSearch(medicine* head);
	/**
	* Klasa searchName nie wykorzystuje tej metody w zakresie swojej pracy.
	*/
	bool searchInList(medicine*, const std::string &);
	searchName();
	~searchName();
};

