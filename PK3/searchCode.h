#pragma once
#include "search.h"
/**
* Klasa dziedziczy z klasy bazowej search, a nastepnie nadpisuje funkcje na odpowiadajace nazwie klasy.
*/
class searchCode :
	public search
{
public:
	/**
	* Metoda przyjmuje jako parametr referencje do zmiennej typu int, referencje do zmiennej typu string oraz wskaznik na obiekt typu medicine*.
	* Parametr typu string jest w tym wypadku nieistotny.
	* Metoda ta ma za zadanie przeszukac podana liste wskaznikow (medicine*) i znalezc w niej w przypadku klasy searchCode element o takiej wartosci kodu jaka zostala podana przy zmiennej typu int.
	* \return nullptr, w przypadku jesli nie znajdzie takowego elementu lecz w przypadku kiedy znajdzie zwraca wskaznik na element, ktory posiada taki sam kod.
	*/
	medicine* searchGood(const int&, const std::string&, medicine*);
	/**
	* Metoda, ktora przyjmuje jako parametr wskaznik na obiekt typu medicine. Metoda ta nie robi z parametrem nic. Jedynie prosi uzytkownika o podanie kodu.
	* W przypadku gdy przeciwnik poda zly kod, bedzie caly czas pytala o poprawny. Parametr jaki przyjmuje przekazuje dalej do metody searchGood.
	* Zwraca wskaznik na element, ktory zwrocila funkcja searchGood.
	*/
	medicine* writeAndSearch(medicine*);
	/**
	* Klasa searchCode nie wykorzystuje tej metody w zakresie swojej pracy.
	*/
	void complexSearch(medicine* head);
	/**
	* Klasa searchCode nie wykorzystuje tej metody w zakresie swojej pracy.
	*/
	bool searchInList(medicine*, const std::string &);
	searchCode();
	~searchCode();
};


