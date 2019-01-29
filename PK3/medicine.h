#pragma once
#include <string>
#include"expiration_date.h"
#include "allergy.h"
#include "prescription.h"
#include"refund.h"
#include"age_rang.h"
#include "addition.h"
#include <string>
#include<list>
#include<iostream>

/**
*Klasa jest elementem listy. Jest definiowana jako lek, oraz przechowuje wszystkie skladowe dane opisujace lek.
*/
class medicine : public converter
{

public:
	addition data; /*!< Pole data jest obiektem klasy addition oraz przechowuje dane zwiazane z ogolnym opisem leku.*/
	expiration_date date;/*!< Pole date jest obiektem klasy expiration_date oraz przechowuje dane mowiace o dacie waznosci.*/
	allergy alergic;/*!< Pole alergic jest obiektem klasy allergy oraz przechowuje informacje zwiazana z alergennoscia leku.*/
	refund ref;/*!< Pole ref jest obiektem klasy refund oraz przechowuje wartosc stopnia refundacji leku[%].*/
	age_range ages; /*!< Pole ages jest obiektem klasy age_range oraz przechowuje dane przedzialEUR wiekowego.*/
	prescription recept;/*!< Pole recept jest obiektem klasy prescription i przechowuje informacje zwiazana z zapotrzebowaniem na recepte.*/
	std::list<std::string> dise;/*!< Pole dise jest lista stringow, ktora przechowuje wszystkie choroby jakie zostaly podane.*/
	std::list<std::string> compo;/*!< Pole compo jest lista stringow, ktora przechowuje wszystkie skladniki jakie zostaly podane.*/
	medicine* next;/*!< Pole next jest wskaznikiem na nastepny element listy typu medicine.*/
	/**
	*Konstruktor bezargumentowy ustawia wartosc nastepnego elementu na nullptr.
	*/
	medicine();
	~medicine();
	/**
	*Operator porownujacy czy nazwy lekow z obiektu data sa takie same.
	*Jesli tak zwraca true, jesli nie to false.
	*/
	bool operator==(medicine &);
	/**
	*Operator przeciwny do operatora ==.
	*/
	bool operator!=(medicine &);
	//DISE, COMPO Lists:
	/**
	*Metoda przyjmuje jako parametr wskaznik na obiekt klasy medicine oraz zmienna typu int.
	*Zmienna typu int ma na celu przekazac metodzie, ktora z list bedziemy chcieli edytowac (dise/compo).
	*Wskaznik na obiekt jest przekazywany gdyz metoda wlasnie do jego list bedzie dodawala elementy.
	*/
	void addToStringList(medicine*, const int&);
	/**
	*Przyjmuje jako parametr obiekt typu list, ktory jest lista elementow typu string w ktorej przechwywane sa nazwy lekow oraz skladnikow.
	*Sluzy do wyswietlenie wszystkich elementw z przekazanej listy.
	*/
	void printIt(std::list<std::string>, const int&);
	/**
	*Przyjmuje jako parametr obiekt typu list, ktory jest lista elementow typu string w ktorej przechwywane sa nazwy lekow oraz skladnikow.
	*Sluzy do usuniecia calej listy podanej jako parametr.
	*/
	void removeList(std::list<std::string>&);
	/**
	*Metoda dziala podobnie do metody addString tylko zamiast dodawania elementu, to go usuwa.
	*/
	void removeElementFromList(medicine*, const int&);
	/**
	*Metoda posredniczaca, przyjmujaca jako parametry wskaznik na obiekt typu medicine oraz zmienna typu int.
	*Ma na celu zwiekszenie czytelnosci kodu. Przekazuje swoje parametry do nastepnych metod wywlywanych wewnatrz niej.
	*/
	void editStringList(medicine*, const int&);
	//screen
	/**
	*Metoda przyjmuje jako argument wskaznik na obiekt typu medicine.
	*Wypisuje wszystkie pola obiektu medicine oraz pola obiektow znajdujacych sie w medicine.
	*/
	void showMedicine(medicine*);
	/**
	*Metoda oczekujaca interakcji uzytkownika, w ktorej poda on, ktory element leku chcialby edytowac.
	*W zaleznosci od wyboru uzytkownika uruchomia sie metody interaktywne 'set'-owe z klas obiektow, ktore zostana poddane edycji. Jesli edycja zostanie zakonczona, uzytkownik musi wybrac odpowiednia opcje z menu.
	*/
	void editMenu();
	/**
	*Metoda posredniczaca oraz oczekujaca interakcji uzytkownika.
	*Jesli zostanie wywolana dla obiektu, ktory jest nullptr zwroci komunikat, ze podany lek nie istnieje.
	*W przypadku jesli istnieje, zapyta uzytkownika czy chce edytowac lek, a w zaleznosci od wyboru uzytkownika wywola metode editMenu badz nie.
	*/
	void edit();
};
/**
*Operator strumieniowy sluzacy do zapisywania/wypisywania danych.
*Uzywany w programie do zapisu w pliku bazy danych.
*/
std::ostream & operator<<(std::ostream&out, medicine *);
/**
*Operator strumieniowy sluzacy do wczytywania danych.
*Uzywany w programie do odczytywania z pliku przechowujacego baze danych.
*/
std::istream & operator>>(std::istream&in, medicine *);