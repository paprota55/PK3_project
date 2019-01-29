#pragma once
#include <iostream>
#include <conio.h>
/**
* Klasa reprezentuje czesc informacji zawartych w leku.
* Obiekt klasy zawiera trzy pola typu int przechowujace odpowiednio dzien, miesiac oraz rok, informuje o dacie waznosci leku.
*/
class expiration_date
{
	int day, month, year;/*!< Pole day, month, year zawieraja odpowiednio wartosci odpowiedzialne za dzien, miesiac oraz rok. */
public:
	/**
	* Metoda zwraca pole day.
	*
	* Zostala utworzona w celu uzyskania dostepu do pola day przez klasy niezaprzyjaznione.
	* \return day.
	*/
	int getDay();
	/**
	* Metoda zwraca pole month.
	*
	* Zostala utworzona w celu uzyskania dostepu do pola month przez klasy niezaprzyjaznione.
	* \return month.
	*/
	int getMonth();
	/**
	* Metoda zwraca pole month.
	*
	* Zostala utworzona w celu uzyskania dostepu do pola month przez klasy niezaprzyjaznione.
	* \return month.
	*/
	int getYear();
	/**
	* Metoda wyswietlajaca aktualny status naszych pol
	*
	* Metoda wyswietla na ekran aktualny stan pol. Uzywa metod typu "get", aby uzyskac dostep oraz wyswietlic pola zawarte w obiekcie.
	*/
	void printExpirationDate();
	/**
	* Metoda wchodzaca w interakcje z uzytkownikiem.
	*
	* Zostala utworzona w celu udzielenia mozliwosci edycji oraz wprowadzenia danych przez uzytkownika, ktora ustawia wartosci pol przy pomocy metod "set".
	* Wysyla ona zapytania do uzytkownika w celu informacji, ktore z pol chcialby on ustawic. Po wprowadzeniu poprawnych danych ustawia wartosc naszego pola na podana przez uzytkownika.
	* Uzywa rowniez metody printExpirationDate() do pokazywania uzytkownikowi aktualnego stanu wprowadzonych przez niego danych oraz danych leku.
	* Wprowadzanie przez uzytkownika w glownej mierze polega na naciskaniu przyciskow strzalek, entera oraz esc. Istnieje rowniez odwolanie do klawisza backspace.
	* Funkcja ma na celu przyspieszenie wprowadzania, gdyz uzytkownik niekoniecznie musi byc mistrzem klawiatury, wiec wygodniejsze jest naciskanie na konkretne klawisze i oczekiwanie zmian na ekranie.
	*/
	void setDate();
	/**
	* Metoda ustawia dzien.
	*
	* Zostala utworzona w celu uzyskania dostepu oraz pozwolenia do edycji pola day.
	*/
	void setDay(int);
	/**
	* Metoda ustawia miesiac.
	*
	* Zostala utworzona w celu uzyskania dostepu oraz pozwolenia do edycji pola month.
	*/
	void setMonth(int);
	/**
	* Metoda ustawia rok.
	*
	* Zostala utworzona w celu uzyskania dostepu oraz pozwolenia do edycji pola year.
	*/
	void setYear(int);
	/**
	* Metoda sprawdza czy wystepuje rok przestepny.
	*
	* Zostala utworzona w celu sprawdzania czy podczas wprowadzania danych wystepuje rok przestepny czy tez nie. Jesli wystepuje wtedy jeden z miesiecy posiada o jeden dzien wiecej niz w przypadku zwyklego roku.
	* Przyjmuje jako parametr wartosc, ktora odpowiada aktualnemu rokowi.
	* \return true, w przypadku jesli wystepuje rok przestepny oraz \return false jesli nie.
	*/
	bool year366(int number);
	/**
	* Operator porownujacy obiekty klasy expiration_date.
	*
	* Porownuje on wystepujace daty obiektow.
	* \return true, jesli daty obiektow sa takie same oraz false w przeciwnym razie.
	*/
	bool operator==(expiration_date&);
	/**
	* Operator mniejszosci.
	*
	* Przyjmuje jako argument zmienna typu int.
	* Sprawdza czy data w obiekcie klasy expiration_date jest mniejsza od podanej jako liczba typu int.
	* \return true, jesli data jest mniejsza od podanej liczby, w przeciwnym razie \return false.
	*/
	bool operator<(int);
	/**
	*Konstruktor bezargumentowy
	*
	*Konstruktor bezargumentowy ustalajacy pola klasy expiration_date wszystkim polom przypisuje wartosc 0.
	*/
	expiration_date();
	/**
	*Konstruktor jednoargumentowy
	*
	*Konstruktor jednoargumentowy ustalajacy pola klasy expiration_date polu day przypisuje wartosc podana w konstruktorze, a reszte ustawia na 0.
	*/
	expiration_date(int);
	/**
	*Konstruktor dwuargumentowy
	*
	*Konstruktor dwuargumentowy ustalajacy pola klasy expiration_date polu day oraz month przypisuje wartosc podana w konstruktorze, a pole year ustawia na 0.
	*/
	expiration_date(int, int);
	/**
	*Konstruktor wieloargumentowy
	*
	*Konstruktor wieloargumentowy ustalajacy pola klasy expiration_date przypisuje polom wartosci podane w konstruktorze.
	*/
	expiration_date(int, int, int);
	/**
	*Destruktor
	*
	*Destruktor ustawia wartosci wszystkich pol na 0.
	*/
	~expiration_date();
};
/**
* Operator strumieniowy
*
* Wyswietla pola obiektu klasy expiration_date podanego za operatorem.
*/
std::ostream & operator<<(std::ostream &out, expiration_date&x);

