#pragma once
#include "searchName.h"
#include "searchCode.h"
/**
* Klasa dziedziczy z klasy bazowej search. Metody klasy maja za zadanie przeszukiwac liste lekow w celu odnalezienia takiego, ktory zwalcza konkretna chorobe.
* Wykorzystuje ona klasy dziedziczace z search (searchCode, searchName) w celu wykorzystania ich w ponownym wyszukiwaniu leku, ktory chcemy edytowac.
* Wykorzystuje je ze wzgledu na to, gdyz metody z klasy searchComplex wypisuja wszystkie leki, ktore posiadaja podana chorobe.
*/
class searchComplex :
	public search
{
public:
	/**
	* Klasa searchComplex nie wykorzystuje tej metody w zakresie swojej pracy.
	*/
	medicine* searchGood(const int&, const std::string&, medicine*);
	/**
	* Klasa searchComplex nie wykorzystuje tej metody w zakresie swojej pracy.
	*/
	medicine* writeAndSearch(medicine*);
	/**
	*Metoda przyjmuje jako wartosc wskaznik na element klasy medicine. Nastepnie wysuwa do uzytkownika zapytania odnosnie leku, jakie parametry musza byc spelnione.
	* Po nacisnieciu odpowiedniej opcji przez uzytkownika oraz uzupelnieniu wszystkich, nastepuje przeszukiwanie w celu znalezienia leku o podanych parametrach.
	* Zostana wypisane wszystkie leki, ktore spelniaja odpowiednie warunki.
	* Po wyszukaniu lekow uzytkownik bedzie mial czas na wybranie leku, ktory go interesuje.
	* W dalszej czesci nastepuje wywolanie funkcji z klasy searchName, lub searchCode w zaleznosci od tego co wybierze uzytkownik w celu odnalezienia leku, ktory go interesuje i wczesniej mial mozliwosc wybrania go sposrod listy.
	* Metoda zakancza sie po zakonczeniu metody z klasy searchName badz searchCode.
	*/
	void complexSearch(medicine* head);
	/**
	* Metoda przyjmuje jako parametry wskaznik na obiekt typu medicine oraz referencje obiektu typu string.
	* Jej zadaniem jest przeszukiwanie listy chorob dla danego leku.
	* W przypadku jesli ktoras z nazw chorob jest taka sama jak parametr typu string zwraca true, w przeciwnym wypadku wyrzuca false.
	*/
	bool searchInList(medicine*, const std::string &);
	searchComplex();
	~searchComplex();
};

