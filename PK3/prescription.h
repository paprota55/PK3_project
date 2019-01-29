#pragma once
#include <conio.h>
#include<iostream>
/**
* Klasa reprezentuje czesc informacji zawartych w leku.
* Obiekt klasy zawiera pole typu bool przechowujace wartosc prawda badz falsz w zaleznosci czy dany lek jest na recepte czy nie.
*/
class prescription
{
	bool prescript;/*!< Pole prescript zawiera informacje o tym czy lek jest na recepte*/
public:
	/**
	* Metoda przypisuje recepte do leku.
	*
	* Zostala utworzona w celu uzyskania dostepu oraz pozwolenia do edycji pola prescript.
	*/
	void setPrescription(bool);
	/**
	* Metoda wchodzaca w interakcje z uzytkownikiem.
	*
	* Zostala utworzona w celu udzielenia mozliwosci edycji oraz wprowadzenia danych przez uzytkownika, ktora ustawia wartosc pola przy pomocy metody "set".
	* Wysyla ona zapytania do uzytkownika w celu informacji, ktora z opcji chce wybrac dla pola. Po wprowadzeniu poprawnych danych ustawia wartosc naszego pola na podana przez uzytkownika.
	*/
	void setPrescriptionMain();
	/**
	* Metoda zwraca pole prescript.
	*
	* Zostala utworzona w celu uzyskania dostepu do pola prescript przez klasy niezaprzyjaznione.
	* \return prescript.
	*/
	bool getPrescription();

	/**
	*Konstruktor bezargumentowy
	*
	*Konstruktor bezargumentowy ustalajacy pole klasy prescription na wartosc false.
	*/
	prescription();
	/**
	*Konstruktor jednoargumentowy
	*
	*Konstruktor jednoargumentowy ustalajacy pole klasy alle na podane w konstruktorze.
	*/
	prescription(bool);
	~prescription();
};