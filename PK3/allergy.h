#pragma once
#include<conio.h>
#include<iostream>
/**
* Klasa reprezentuje czesc informacji zawartych w leku.
* Obiekt klasy zawiera pole typu bool przechowujace wartosc prawda badz falsz w zaleznosci czy dany lek jest alergenny czy nie.
*/
class allergy
{
	bool alle; /*!< Pole alle zawiera informacje o alergennosci*/
public:
	/**
	* Metoda ustawia alergennosc leku.
	*
	* Zostala utworzona w celu uzyskania dostepu oraz pozwolenia do edycji pola alle.
	*/
	void setAllergy(bool);
	/**
	* Metoda zwraca pole alle.
	*
	* Zostala utworzona w celu uzyskania dostepu do pola alle przez klasy niezaprzyjaznione.
	* \return alle.
	*/
	bool getAllergy();
	/**
	* Metoda wchodzaca w interakcje z uzytkownikiem.
	*
	* Zostala utworzona w celu udzielenia mozliwosci edycji oraz wprowadzenia danych przez uzytkownika, ktora ustawia wartosc pola przy pomocy metody "set".
	* Wysyla ona zapytania do uzytkownika w celu informacji, ktora z opcji chce wybrac dla pola. Po wprowadzeniu poprawnych danych ustawia wartosc naszego pola na podana przez uzytkownika.
	*/
	void setAllergyMain();
	/**
	*Konstruktor bezargumentowy
	*
	*Konstruktor bezargumentowy ustalajacy pole klasy allergy na wartosc false.
	*/
	allergy();
	/**
	*Konstruktor jednoargumentowy
	*
	*Konstruktor jednoargumentowy ustalajacy pole klasy alle na podane w konstruktorze.
	*/
	allergy(bool);
	~allergy();
};

