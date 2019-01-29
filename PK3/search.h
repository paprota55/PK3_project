#pragma once
#include "medicine.h"
#include <iostream>
/**
* Klasa jest klasa bazowa dla klas searchName,searchCode oraz searchComplex.
*/
class search : public converter
{
public:
	/**
	* Metoda wirtualna searchGood jest tylko i wylacznie podstawa do kolejnych klas.
	*/
	virtual medicine* searchGood(const int&, const std::string&, medicine*);
	/**
	* Metoda wirtualna writeAndSearch jest tylko i wylacznie podstawa do kolejnych klas.
	*/
	virtual medicine* writeAndSearch(medicine*);
	/**
	* Metoda wirtualna complexSearch jest tylko i wylacznie podstawa do kolejnych klas.
	*/
	virtual void complexSearch(medicine* head);
	/**
	* Metoda wirtualna searchInList jest tylko i wylacznie podstawa do kolejnych klas.
	*/
	virtual bool searchInList(medicine*, const std::string &);

	search();
	~search();
};