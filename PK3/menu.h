#pragma once
#include "inventory.h"
#include <cstdio>

/**
* Klasa jest naszym kokpitem sterujacym od ktorej rozpoczyna sie praca programu.
* W klasie tej nastepuje utworzenie naszego "ekwipunku", czyli bazy z danymi. W tym miejscu rowniez nastepuje sterowanie, ktore pokazuje uzytkownikowi opcje z ktorych moze korzystac.
* Z tej klasy wybieramy pozycje, ktora nastepnie przekazuje sterowanie reszcie klas. Posiada dwa pola typu int, jedno odpowidzialne za wybor opcji z naszego menu, a drugie przechowuje informacje odnosnie dzisiejszej daty.
* Klasa posiada rowniez pole, przechowujace cala baze danych.
*/
class menu
{
protected:
	int choice, today;/*!< Pole choice zawiera informacje o wybranej opcji przez uzytkownika, a pole today posiada informacje o dzisiejszej dacie */
	inventory list;/*!< Pole list jest polem przechowujacym cala baze danych lekow.*/

public:
	/**
	* Metoda zwraca obiekt typu int z ktorego korzysta metoda startMenu().
	*
	* Metoda zostala stworzona aby uzytkownik mogl obslugiwac menu, za pomoca strzalek oraz klawisza enter.
	* Metoda ta ustala pole choice. Za pomoca strzalek uzytkownik wybiera, ktoras z opcji z menu, a nastepnie zatwierdza enterem.
	* W momencie zatwierdzenia, nasze pole choice zmienia wartosc i jest zwracane przez funkcje. Wartosc jest ograniczona z gory i z dolu, aby nie dalo sie wyjsc poza granice menu.
	*/
	int controlMenu();
	/**
	* Metoda ma za zadanie uruchomic odpowiednie funkcje wybrane przez uzytkownika w menu za pomoca funkcji controlMenu(). Poszczegolnym wartoscia pola choice przyporzadkowuje odpowiednie funkcje do wywolania na polu list.
	* Na poczatku startu menu nastepuje wywolanie funkcji pola list, ktora odczytuje cala baze (jesli takowa istniala).
	* Z funkcji switch zostaje wybrana opcja odpowiednia do zwroconej wartosci przez funkcje controlMenu().
	*/
	void startMenu();
	/**
	* Metoda ma za zadanie wyswietlic na ekran menu, aby uzytkownik wiedzial na jakiej pozycji znajduje sie kursor. Oraz mogl odpowiednio sie ustawic, aby wybrac to co go interesuje.
	* W zaleznosci od tego ktora strzalke nacisnie uzytkownik, kursor przesuwa sie w te strone na ktora ona wskazuje.
	*/
	void printMenu();
	/**
	*Konstruktor jednoargumentowy
	*
	*Konstruktor w ktorym ustawiana jest dzisiejsza data dla pola today.
	*/
	menu();
	/**
	*Destruktor
	*
	*Destruktor, ktory zeruje pola today oraz choice.
	*/
	~menu();
};