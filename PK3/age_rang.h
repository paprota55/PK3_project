#pragma once
#include<iostream>
#include<conio.h>
/**
* Klasa reprezentuje czesc informacji zawartych w leku.
* Obiekt klasy zawiera dwa pola typu float, ktore przechowuja odpowiednio dolna i gorna granice wieku leku.
*/
class age_range
{
	float bottom, top; /*!< Pole bottom oraz top zawieraja gorna oraz dolna granice wieku leku. */
public:
	/**
	* Metoda ustawia gorna granice.
	*
	* Zostala utworzona w celu uzyskania dostepu oraz pozwolenia do edycji pola top.
	*/
	void setTop(float);
	/**
	* Metoda ustawia dolna granice.
	*
	* Zostala utworzona w celu uzyskania dostepu oraz pozwolenia do edycji pola bottom.
	*/
	void setBottom(float);
	/**
	* Metoda zwraca pole top.
	*
	* Zostala utworzona w celu uzyskania dostepu do pola top przez klasy niezaprzyjaznione.
	* \return top.
	*/
	float getTop();
	/**
	* Metoda zwraca pole bottom.
	*
	* Zostala utworzona w celu uzyskania dostepu do pola bottom przez klasy niezaprzyjaznione.
	* \return bottom.
	*/
	float getBottom();
	/**
	* Metoda wyswietlajaca aktualny status naszych pol
	*
	* Metoda wyswietla na ekran aktualny stan pol. Uzywa metod typu "get", aby uzyskac dostep oraz wyswietlic pola zawarte w obiekcie.
	*/
	void printAgeRange();
	/**
	* Metoda wchodzaca w interakcje z uzytkownikiem.
	*
	* Zostala utworzona w celu udzielenia mozliwosci edycji oraz wprowadzenia danych przez uzytkownika, ktora ustawia wartosci pol przy pomocy metod "set".
	* Wysyla ona zapytania do uzytkownika w celu informacji, ktore z pol chcialby on ustawic. Po wprowadzeniu poprawnych danych ustawia wartosc naszego pola na podana przez uzytkownika.
	* Uzywa rowniez metody printAgeRange() do pokazywania uzytkownikowi aktualnego stanu wprowadzonych przez niego danych oraz danych leku.
	*/
	void setAgeRange();
	/**
	*Konstruktor bezargumentowy
	*
	*Konstruktor bezargumentowy ustalajacy pola klasy age_range w przypadku pola bottom ustawia wartosc 0, a w przypadku top wartosc 200.
	*/
	age_range();
	/**
	*Konstruktor jednoargumentowy
	*
	*Konstruktor jednoargumentowy ustalajacy pola klasy age_range w przypadku pola bottom ustawia wartosc podana w konstruktorze, a w przypadku top wartosc 200.
	*/
	age_range(float);
	/**
	*Konstruktor dwuargumentowy
	*
	*Konstruktor dwuargumentowy ustalajacy pola klasy age_range w przypadku obu pol ustawia wartosc podana w konstruktorze.
	*/
	age_range(float, float);
	/**
	*Destruktor
	*
	*Zeruje wszystkie pola, obiektu klasy age_range.
	*/
	~age_range();
};
/**
* Operator strumieniowy
*
* Wyswietla pola klasy podobnie do klasy printAgeRange().
*/
std::ostream & operator<<(std::ostream &out, age_range&x);