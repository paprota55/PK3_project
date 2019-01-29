#pragma once
#include "medicine.h"
#include"searchName.h"
#include"searchCode.h"
#include"searchComplex.h"
#include"search.h"
#include<iostream>
#include<conio.h>
#include<time.h>
#include <fstream>
#include "converter.h"
/**
*Klasa jest naszym ekwipunkiem, w niej znajduja sie metody dodawania, usuwania, wyswietlania czy tez zapisu i odczytu naszej calej bazy lekow.
*/
class inventory : public medicine, public searchName, public searchCode, public searchComplex
{

public:
	medicine* product; /*!< Pole product jest wskaznikiem na pierwszy element z listy lekow.*/
	/**
	*Metoda oczekujaca interakcji uzytkownika.
	*Uzywa metod z klasy medicine w celu ustawienia wszystkich wartosci nowego leku.
	*W przypadku ustawiania pola data z obiektu medicine nastepuje sprawdzenie za pomoca metody verifyName oraz verifyCode czy podany przez uzytkownika kod lub nazwa nie znajduja sie juz w bazie lekow.
	*Petla bedzie dzialala do momentu az uzytkownik nie poda danych, ktore beda zgodne z ich zalozeniami. Nastepnie metda wysyla zapytanie czy zachowac utwrzony lek.
	* W przypadku gdy uzytkownik zaznaczy, ze chce go zachowac wywola metode dodajaca adding, w przeciwnym wypadku usunie element.
	*/
	void addProduct();
	/**
	*Metoda dodajaca.
	*Przyjmuje jako parametr wskaznik na obiekt typu medicine. Przekazywany jest obiekt, ktory ma zostac dodany do listy.
	*Nastepnie porownuje w petli czy nazwa jest mniejsza od napotkanej i wstawia je w miejsce w ktorym wartosc nazwy nastepnego elementu jest wieksza od tej ktora mamy zamiar wstawic.
	*Dzieki temu zalozeniu nasza lista bedzie posortowana bez koniecznosci uzycia oraz dodania metody sortujacej.
	*/
	void adding(medicine*);
	/**
	*Metoda oczekujaca interakcji uzytkownika.
	*W przypadku jesli nie ma zadnej listy lekow to pojawi sie komunikat o tym, ze lista jest pusta.
	*Jesli jest inaczej uzytkownik zostanie poproszony o podanie sposobu w jaki chcialby wskazac lek, ktory jest do usuniecia.
	*Nastepnie zostana wywolane metody przeszukujace z klas searchCode badz searchName oraz zwrocony przez nie element zstanie przekazany do metody removing.
	*/
	void removeProduct();
	/**
	*Metoda usuwajaca.
	*Przyjmuje jako parametr wskaznik na obiekt typu medicine. Przekazywany jest obiekt, ktory ma zostac usuniety z listy bazy danych.
	*Jesli usuwany element jest pierwszy elementem listy, to zostaje wyswitlony komunikat o usuwaniu, a nastepnie zostaje usunieta lista chorob oraz skladnikow. Po czym finalnie zostaje usuniety pierwszy element.
	*W przypadku jesli nie jest to pierwszy element to nastepuje przeszukiwanie listy w celu odnalezienia leku o takiej samej specyfikacji, a nastepnie postepuje jak w przypadku dla pierwszeg elementu.
	*Z tym, ze nie usuwa pierwszego, a znaleziony element listy. W przypadku jesli nasza podana wartosc jest nullptr to zwroci komunikat, ze takiego leku nie ma.
	*/
	void removing(medicine*);
	/**
	*Jest to swojakiego rodzaju menu do wyszukiwania lekow w ekwipunku. Wykorzystuje do tego metody z klas searchName, searchCode, searchComplex.
	*Oczekuje interakcji uzytkownika, ktory wybierze jaka metoda bedzie chcial wyszukac lek oraz po wyborze przekaze sterowanie metodom z klas szukajacych, badz powroci do glownego menu.
	*/
	void searchProduct(medicine*);
	/**
	*Metoda wyswietlajaca.
	*Wyswietla ona na ekran zbior wszystkich lekow jesli istnieje. W przypadku gdy nie istnieje wyrzuca stosowny komunikat oznajmujacy brak jakichkolwiek lekow w bazie danych.
	*/
	void printAll();
	/**
	*Dziala podobnie jak metoda deleteExpired, lecz zamiast usuwania wyswietla wszystkie przeterminowane leki uzytkownikowi.
	*/
	void printExpired(medicine*, const int&);
	/**
	*Metoda przyjmuje jako parametr wskaznik na obiekt typu medicine oraz referencje do stalego obiektu typu int. Naszym wskaznikiem jest w tym przypadku glowa naszej listy(product).
	*Drugim elementem jest liczba odpowiadajaca dzisiejszej dacie. Format - RRRRMMDD. Metoda przy pomocy operatora mniejszosci porownuje w petli, poczawszy od glowy, czy data waznosci elementu jest mniejsza od dzisiejszej.
	*W przypadku jesli jest mniejsza produkt zostanie usuniety z naszej bazy lekow.
	*/
	void deleteExpired(medicine*, const int&);
	/**
	*Metoda przyjmuje jako parametry wskazniki na obiekt klasy medicine, jednym z nich jest glowa naszej listy (product), a drugim element, ktorego poszukujemy.
	*W petli przeszukuje oraz porownuje, czy nazwy lekow sa takie same. Jesli znajdzie taki sam lek, zapyta uzytkownika o czy zechce zwiekszyc ilosc posiadanego leku, jesli zareaguje, ze tak, to poprosi o wprowadzenie liczby lekow o jaka chce zwiekszyc.
	*Jesli uzytkownik zdecyduje sie zeby nie zwiekszac ilosci, metoda zwroci true bez zmiany ilosci. Zwroci rowniez true w przypadku gdy uzytkownik zmieni ilosc.
	*Metoda zwroci wartosc false tylko i wylacznie w przypadku jesli nie znajdzie leku o takim samym kodzie.
	*/
	bool verifyName(medicine *, medicine*);
	/**
	*Metoda przyjmuje jako parametry wskazniki na obiekt klasy medicine, jednym z nich jest glowa naszej listy (product), a drugim element, ktorego poszukujemy.
	*W petli przeszukuje oraz porownuje, czy kody lekow sa takie same. Jesli znajdzie taki sam lek, zapyta uzytkownika o czy zechce zwiekszyc ilosc posiadanego leku, jesli zareaguje, ze tak, to poprosi o wprowadzenie liczby lekow o jaka chce zwiekszyc.
	*Jesli uzytkownik zdecyduje sie zeby nie zwiekszac ilosci, metoda zwroci true bez zmiany ilosci. Zwroci rowniez true w przypadku gdy uzytkownik zmieni ilosc.
	*Metoda zwroci wartosc false tylko i wylacznie w przypadku jesli nie znajdzie leku o takim samym kodzie.
	*/
	bool verifyCode(medicine *, medicine*);
	/**
	*Metoda zapisujaca baze lekow do pliku. Na poczatku usuwa stara baze danych, a nastepnie tworzy nowa na podstawie danych zebranych w aplikacji.
	*Dane zapisuje w petli do momentu napotkania nullptr. Dane wprowadzane sa za pomoca operatora strumieniowego zawartego w klasie medicine.
	*/
	void saveAll();
	/**
	*Metoda odczytujaca baze lekow z pliku. Jako parametr przyjmuje referencje na obiekt typu string, ktorego wartosc jest nazwa pliku z ktorego bedzie odczytywana baza danych.
	* W przypadku gdy plik nie istnieje zostanie wyrzucony wyjatek z powitaniem oraz instrukcja.
	* Jesli plik istnieje, lecz program nie potrafi go odczytac, zostanie wyrzucony odrebny wyjatek z instrukcja oraz informacjadla uzytkownika.
	* Metoda w petli odczytuje z pliku do momentu jego zakonczenia oraz za pomoca operatora strumieniowego wprowadza dane z pliku do naszego nowo utworzonego leku.
	*/
	void loadFromFile(const std::string &fileName);
	/**
	*Konstruktor bezargumentowy
	*
	*Konstruktor w ktorym wartosc pola product ustawiana jest jako nullptr.
	*/
	inventory();
	/**
	*Destruktor
	*
	*Destruktor, ktory kasuje cala nasza powstala baze lekow (liste) oraz ustawia wartosc pola product na nullptr.
	*/
	~inventory();
};