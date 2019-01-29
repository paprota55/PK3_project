#pragma once
#include"converter.h"
#include<string> 
/**
* Klasa zawierajaca funkcje odpowiedzialne za konwertowanie zmiennych z innych klas.
*/
class converter
{
public:
	/**
	* Metoda przyjmuje jako parametr obiekt typu string, a nastepnie konwertuje wszystkie skladowe (char) na duze litery alfabetu w przypadku jesli byly one literami.
	* W petli uzywa funkcji toupper() dla kazdego elementu ciagu znakow co w rezultacie daje konwersje malych liter na duze.
	* Zwraca przekonwertowana zmienna string \return x.
	*/
	std::string convertToUpper(std::string& x);
	/**
	* Metoda przyjmuje jako parametr obiekt typu string, oraz typu char.
	* Obiekt typu char moze posiadac 2 wartosci 'S' lub 'L' co oznacza Save - Load. Dla odpowiedniej opcji ustalane jest czy funkcja ma zamieniac wystepujace w obiekcie string spacje na znaki '_' czy tez znaki '_' na spacje.
	* W przypadku zapisu ('S') spacje zamieniane sa na '_', a dla dczytu odwrotnie.
	* Funkcja jest statyczna gdyz nie odwoluje sie do zadnego obiektu klasy converter, a do obiektow innych klas.
	* Zwraca obiekt typu string.
	*/
	static std::string convertToSaveLoad(std::string&, char);

	converter();
	~converter();
};
