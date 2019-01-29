#pragma once
#include<iostream>
#include<conio.h>
/**
* Klasa reprezentuje czesc informacji zawartych w leku.
* Obiekt klasy zawiera jedno pole, ktore odpowiada stopniowi refundacji.
*/
class refund
{
	int ref; /*!< Pole ref zawiera wartosc stopnia refundacji z przedzialu (0-100) podanego w %.*/
public:
	/**
	* Metoda wchodzaca w interakcje z uzytkownikiem.
	*
	* Zostala utworzona w celu udzielenia mozliwosci edycji oraz wprowadzenia danych przez uzytkownika, ktora ustawia wartosc pola przy pomocy metody "set".
	* Wysyla ona zapytania do uzytkownika w celu informacji, ktora z opcji chce wybrac dla pola. Po wprowadzeniu poprawnych danych ustawia wartosc naszego pola na podana przez uzytkownika.
	* Poruszanie w funkcji polega na naciskaniu strzalek oraz klawisza enter. Strzalki maja przeskok co 1, a wiec kazdorazowe nacisniecie ktorejs ze strzalek zmienia wartosc pola ref o 1, lecz aktualizacja nastepuje dopiero po zatwierdzeniu enterem.
	* Pole ref mozna modyfikowac jedynie w zakresie (0-100) co ma odzwierciedlac liczbe %.
	*/
	void setRefundMain();
	/**
	* Metoda ustawia stopien refundacji.
	*
	* Zostala utworzona w celu uzyskania dostepu oraz pozwolenia do edycji pola ref.
	*/
	void setRefund(int);
	/**
	* Metoda zwraca pole ref.
	*
	* Zostala utworzona w celu uzyskania dostepu do pola ref przez klasy niezaprzyjaznione.
	* \return quantity.
	*/
	int getRefund();
	/**
	*Konstruktor bezargumentowy
	*
	*Konstruktor bezargumentowy ustalajacy pola klasy refund ustawia pole ref na wartosc 0.
	*/
	refund();
	/**
	*Konstruktor jednoargumentowy
	*
	*Konstruktor jednoargumentowy ustalajacy wartosc pola ref w zaleznosci od podanej wartosci parametru w konstruktorze.
	*/
	refund(int);
	/**
	* Destruktor
	*
	* Destruktor zeruje wartosc pola ref.
	*/
	~refund();
};
/**
* Operator strumieniowy
*
* Wyswietla pole klasy ref, po podaniu z prawej strony << obiektu klasy refund.
*/
std::ostream & operator<<(std::ostream &out, refund&x);
