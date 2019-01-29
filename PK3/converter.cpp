#include "stdafx.h"
#include "converter.h"

std::string converter::convertToUpper(std::string& x) //konwertuje nazwy lekow/chorob na duze litery zeby latwiejsze bylo przeszukiwanie
{
	int length = x.length();

	for (int i = 0; i < length; i++)
	{
		x[i] = toupper(x[i]);
	}

	return x;
}

std::string converter::convertToSaveLoad(std::string& name, char option) //Funkcja zamieniajaca spacje na "_" co zapewnia ciaglosc znakow w przypadku nazw kilku czlonowych
{
	char correct[2] = " ";
	int length = name.length();
	for (int i = 0; i < length; i++)
	{
		if (option == 'S')
		{
			if (name[i] == ' ')
			{
				name[i] = '_';
			}
		}
		else if (option == 'L')
		{
			if (name[i] == '_')
			{
				name[i] = ' ';
			}
		}
	}
	return name;
}

converter::converter()
{
}

converter::~converter()
{
}

