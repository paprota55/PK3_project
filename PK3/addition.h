#pragma once
#include<string>
#include <conio.h>
#include"converter.h"
#include<iostream>
#include <string>
#include <cctype>
/**
* Klasa reprezentuje czesc informacji zawartych w leku.
* Obiekt klasy zawiera dwa pola typu int zawierajace dane o kodzie oraz ilosci danego leku, pole typu double przechowujace cene oraz dwa pola typu string, ktore sa odpowiedzialne za przechowywanie odpowiednio nazwy oraz opisu leku.
*/
class addition : public converter
{
	std::string name;/*!< Pole name zawiera nazwe leku. */
	int code;/*< Pole code zawiera kod leku. */
	double price;/*< Pole price zawiera cene leku. */
	int quantity;/*< Pole quantity zawiera ilosc sztuk leku. */
	std::string description;/*< Pole description zawiera ogolny opis leku. */
public:
	/**
	* Metoda ustawia nazwe leku.
	*
	* Zostala utworzona w celu uzyskania dostepu oraz pozwolenia do edycji pola name.
	*/
	void setName(std::string);
	/**
	* Metoda ustawia cene leku.
	*
	* Zostala utworzona w celu uzyskania dostepu oraz pozwolenia do edycji pola price.
	*/
	void setPrice(double);
	/**
	* Metoda ustawia kod leku.
	*
	* Zostala utworzona w celu uzyskania dostepu oraz pozwolenia do edycji pola code.
	*/
	void setCode(int);
	/**
	* Metoda ustawia ilosc sztuk leku.
	*
	* Zostala utworzona w celu uzyskania dostepu oraz pozwolenia do edycji pola quantity.
	*/
	void setQuantity(int);
	/**
	* Metoda ustawia opis leku.
	*
	* Zostala utworzona w celu uzyskania dostepu oraz pozwolenia do edycji pola description.
	*/
	void setDescription(std::string);

	/**
	* Metoda zwraca pole name.
	*
	* Zostala utworzona w celu uzyskania dostepu do pola name przez klasy niezaprzyjaznione.
	* \return name.
	*/
	std::string getName();
	/**
	* Metoda zwraca pole description.
	*
	* Zostala utworzona w celu uzyskania dostepu do pola description przez klasy niezaprzyjaznione.
	* \return description.
	*/
	std::string getDescription();
	/**
	* Metoda zwraca pole price.
	*
	* Zostala utworzona w celu uzyskania dostepu do pola price przez klasy niezaprzyjaznione.
	* \return price.
	*/
	double getPrice();
	/**
	* Metoda zwraca pole quantity.
	*
	* Zostala utworzona w celu uzyskania dostepu do pola quantity przez klasy niezaprzyjaznione.
	* \return quantity.
	*/
	int getQuantity();
	/**
	* Metoda zwraca pole code.
	*
	* Zostala utworzona w celu uzyskania dostepu do pola code przez klasy niezaprzyjaznione.
	* \return code.
	*/
	int getCode();

	/**
	* Metoda wchodzaca w interakcje z uzytkownikiem.
	*
	* Zostala utworzona w celu udzielenia mozliwosci edycji oraz wprowadzenia danych przez uzytkownika, ktora ustawia wartosci pol przy pomocy metod "set".
	* Wysyla ona zapytania do uzytkownika w celu informacji, ktore z pol chcialby on ustawic. Po wprowadzeniu poprawnych danych ustawia wartosc naszego pola na podana przez uzytkownika.
	* Uzywa rowniez metody printAddition() do pokazywania uzytkownikowi aktualnego stanu wprowadzonych przez niego danych oraz danych leku.
	*/
	void setAddition(int);
	/**
	* Metoda wyswietlajaca aktualny status naszych pol
	*
	* Metoda wyswietla na ekran aktualny stan pol. Uzywa metod typu "get", aby uzyskac dostep oraz wyswietlic pola zawarte w obiekcie.
	*/
	void printAddition();
	/**
	* Operator umozliwiajacy bezposrednie dodanie ilosci posiadanego leku do pola quantity bez koniecznosci wywolywania osobnych funkcji.
	*/
	addition & operator+=(const int&);
	/**
	* Operator porownujacy pola name obiektor klasy addition.
	* Przyjmuje jako parametr obiekt klasy addition.
	* \return true, jesli nazwy obiektow sa takie same oraz false w przeciwnym razie.
	*/
	bool operator==(addition &);
	/**
	*Konstruktor bezargumentowy
	*
	*Konstruktor bezargumentowy ustalajacy pola klasy addition w przypadku typow liczbowych na '0' w przypadku typow ciagu znakow ustawia 'empty'.
	*/
	addition();
	/**
	*Destruktor
	*
	*Zeruje wszystkie pola, obiektu klasy addition.
	*/
	~addition();
};
/**
* Operator strumieniowy
*
* Wyswietla pola klasy podobnie do klasy printAddition().
*/
std::ostream & operator<<(std::ostream &out, addition&x);

