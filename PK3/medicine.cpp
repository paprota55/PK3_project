#include"stdafx.h"
#include"medicine.h"


medicine::medicine()
{
	next = nullptr;
}

medicine::~medicine()
{
	
}

void medicine::addToStringList(medicine*current, const int& x) //Dodaje lek/skladnik do naszego ciagu
{
	std::string temp;
	bool circle = true;
	char arrow;
	while (circle)
	{
		system("CLS");
		if (x == 1) std::cout << "Dodac chorobe? y/n\n y = tak/ n = nie";
		else std::cout << "Dodac skladnik? y/n\n y = tak/ n = nie";
		arrow = tolower(_getch());
		switch (arrow)
		{
		case 'y':
			system("CLS");
			if (x == 1)
			{
				printIt(current->dise, 1);
				std::cout << "Podaj nazwe choroby: ";
				getline(std::cin, temp);
				current->dise.push_front(convertToUpper(temp));
				current->dise.unique();
				current->dise.sort();
			}
			else 
			{
			printIt(current->compo, 0);
			std::cout << "Podaj nazwe skladniku: ";
			getline(std::cin, temp);
			current->compo.push_front(convertToUpper(temp));
			current->compo.unique();
			current->compo.sort();
			}
			break;
		case 'n':
			circle = false;
			return;
			break;
		}

	}
}

void medicine::printIt(std::list<std::string> tempo, const int& x)
{
	std::list<std::string>::iterator i;
	if (x == 1) std::cout << "Choroby: ";
	else std::cout << "Skladniki: ";
	if (tempo.empty())
	{
		std::cout << "Brak danych";
	}
	for (i = tempo.begin(); i != tempo.end(); i++)
	{
		std::cout << *i;
		i++;
		if (i != tempo.end())
		{
			std::cout << ", ";
		}
		i--;
	}
	std::cout << std::endl;
}

void medicine::removeList(std::list<std::string>& temp) //usuwa cala liste lekow lub skladnikow
{
	temp.erase(temp.begin(), temp.end());
}

void medicine::editStringList(medicine*current, const int& type) //posrednik funkcji do edycji listy lekow oraz skladnikow
{
	addToStringList(current,type);
	removeElementFromList(current, type);
}

void medicine::removeElementFromList(medicine* current, const int& x) //usuwa jeden element z listy chorob/skladnikow
{
	std::list<std::string>::iterator i;
	std::string temp;
	bool circle = true;
	char arrow;
	while (circle)
	{
		system("CLS");
		if (x == 1) std::cout << "Usunac chorobe? y/n\n y = tak/ n = nie";
		else std::cout << "Usunac skladnik? y/n\n y = tak/ n = nie";
		arrow = tolower(_getch());
		switch (arrow)
		{
		case 'y':
			system("CLS");
			if (x == 1)
			{
				printIt(current->dise, 1);
				std::cout << "Podaj nazwe choroby: ";
				getline(std::cin, temp);
				current->dise.remove(convertToUpper(temp));
			}
			else
			{
				printIt(current->compo, 0);
				std::cout << "Podaj nazwe skladniku: ";
				getline(std::cin, temp);
				current->compo.remove(convertToUpper(temp));
			}
			break;
		case 'n':
			circle = false;
			return;
			break;
		}

	}
}

bool medicine::operator==(medicine & temp)
{
	if (this->data.getName() == temp.data.getName())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool medicine::operator!=(medicine & temp)
{
	if (this->data.getName() == temp.data.getName())
	{
		return false;
	}
	else
	{
		return true;
	}
}

void medicine::showMedicine(medicine* current) //pokazuje elementy leku podanego do funkcji
{
	using namespace std;

	int ill = 1;
	int comp = 0;

	cout << current->data;
	cout << current->ages;
	std::cout << "Recepta: "; if (current->recept.getPrescription() == 1)std::cout << "Tak\n"; else std::cout << "Nie\n";
	std::cout << "Alergia: "; if (current->alergic.getAllergy() == 1)std::cout << "Tak\n"; else std::cout << "Nie\n";
	cout << current->ref;
	current->printIt(current->dise, ill);
	current->printIt(current->compo, comp);
	cout << current->date;
	std::cout << std::endl;
}

std::ostream & operator<<(std::ostream & out, medicine * current)
{
	char save = 'S';
	std::list<std::string>::iterator i;
	out << converter::convertToSaveLoad(current->data.getName(),save) << std::endl;
	out << current->data.getPrice() << " " << current->data.getCode() << " " << current->data.getQuantity() << "\n" << converter::convertToSaveLoad(current->data.getDescription(), save) << "\n";
	out << current->date.getDay() << " " << current->date.getMonth() << " " << current->date.getYear() << "\n";
	out << current->ages.getBottom() << " " << current->ages.getTop() << "\n";

	if (current->alergic.getAllergy() == true) out << 1 << " ";
	else out << 0 << " ";

	if (current->recept.getPrescription()) out << 1 << "\n";
	else out << 0 << "\n";

	for (i = current->compo.begin(); i != current->compo.end(); i++)
	{
		out << converter::convertToSaveLoad(*i, save) << " ";
	}
	out << ".\n";
	for (i = current->dise.begin(); i != current->dise.end(); i++)
	{
		out << converter::convertToSaveLoad(*i, save) << " ";
	}
	out << ".";
	if (current->next != nullptr)
	{
		out << "\n";
	}
	return out;
}

std::istream & operator>>(std::istream & in, medicine *temp)
{
	double price;
	int code;
	float age;
	unsigned int quantity;
	char load = 'L';

	std::string tmp, tmp2;

	in >> tmp;
	temp->data.setName(converter::convertToSaveLoad(tmp, load)); // nazwa leku
	in >> price;
	temp->data.setPrice(price); // cena leku
	in >> code;
	temp->data.setCode(code); // kod leku
	in >> quantity;
	temp->data.setQuantity(quantity); // ilosc jednego leku
	in >> tmp2;
	temp->data.setDescription(converter::convertToSaveLoad(tmp2, load)); //opis leku
	in >> code;
	temp->date.setDay(code); // ustaw dzien
	in >> code;
	temp->date.setMonth(code); //ustaw miesiac
	in >> code;
	temp->date.setYear(code); // ustaw rok
	in >> age;
	temp->ages.setBottom(age); // ustaw dolna granice wieku
	in >> age;
	temp->ages.setTop(age); // ustaw gorna granice wieku
	in >> code;
	if (code == 0) temp->alergic.setAllergy(false);
	else temp->alergic.setAllergy(true);				// ustawienie czy ma alergeny
	in >> code;
	if (code == 0) temp->recept.setPrescription(false);
	else temp->recept.setPrescription(true);
	temp->next = nullptr;
	in >> tmp;
	while (tmp != ".")
	{
		temp->compo.push_front(converter::convertToSaveLoad(tmp, load));
		in >> tmp;
	}
	in >> tmp2;
	while (tmp2 != ".")
	{
		temp->dise.push_front(converter::convertToSaveLoad(tmp2, load));
		in >> tmp2;
	}
	return in;
}

void medicine::editMenu()//menu koordynujace edycje znalezionego leku
{
	int ill = 1;
	int comp = 0;
	bool circle = true;
	char arrow2 = ' ';
	while (circle)
	{
		system("cls");
		showMedicine(this);
		std::cout << "Edytuj:\n1. Cena, Ilosc, Opis\n2. Przedzial wiekowy\n3. Czy jest alergenny\n4. Czy na recpete\n5. Data waznosci\n6. Refundacja\n7. Lista chorob\n8. Lista skladnikow\n9. Koniec edycji";
		arrow2 = _getch();
		switch (arrow2)
		{
		case '1':
			data.setAddition(1);
			break;
		case '2':
			ages.setAgeRange();
			break;
		case '3':
			alergic.setAllergyMain();
			break;
		case '4':
			recept.setPrescriptionMain();
			break;
		case '5':
			date.setDate();
			break;
		case '6':
			ref.setRefundMain();
			break;
		case '7':
			editStringList(this, ill);
			break;
		case '8':
			editStringList(this, comp);
			break;
		case '9':
			circle = false;
			break;
		}
	}
}

void medicine::edit() //funkcja posredniczaca do editMenu, pokazuje, ze szukanego leku nie ma lub pyta uzytkownika czy chce go edytowac
{
	char arrow2;
	if (this == nullptr)
	{
		std::cout << "Nie ma takiego leku sprobuj ponownie.\n";
		system("pause");
		return;
	}
	else
	{
		this->showMedicine(this);
		std::cout << "Czy chcesz edytowac? (y/n)";
		arrow2 = _getch();

		switch (tolower(arrow2))
		{
		case 'y':
			this->editMenu();
			break;
		case 'n':
			return;
			break;
		}
	}
}
