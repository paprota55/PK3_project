#include"stdafx.h"
#include"inventory.h"

inventory::inventory()
{
	product = nullptr;
}

inventory::~inventory()
{
	if (!product)
	{
		delete product;
	}
	else
	{
		medicine* current = product;
		while (current)
		{
			product = product->next;
			delete current;
			current = product;
		}
	}
	product = nullptr;
}

void inventory::printAll()
{
	using namespace std;
	int i = 1;

	system("cls");
	if (product != nullptr)
	{
		medicine* current = product;
		while (current != nullptr)
		{
			std::cout << i++ << ". ";
			current->showMedicine(current);
			current = current->next;
		}
		//std::cout << "\nNasicnij przycisk jesli chcesz kontynuowac...";
		system("PAUSE");

	}
	else
	{
		std::cout << "Nie ma zadnej listy lekow."<<std::endl;
		//std::cout << "\nNasicnij przycisk jesli chcesz kontynuowac...";
		system("PAUSE");
		
	}
}

void inventory::addProduct() //dodawanie leku do bazy
{
	bool circle = true;
	char arrow;
	medicine * current = new medicine;
	int ill = 1;
	int comp = 0;
	do
	{
		current->data.setAddition(0);
	} while (verifyName(product, current) || verifyCode(product, current));
		current->ages.setAgeRange();
		current->alergic.setAllergyMain();
		current->recept.setPrescriptionMain();
		current->date.setDate();
		current->ref.setRefundMain();
		current->addToStringList(current,ill);
		current->addToStringList(current,comp);
		current->next = nullptr;
		

		while (circle)
		{
		system("cls");
		std::cout << "Chcesz zachowac utworzony lek? (y/n)";
		arrow = _getch();
		
		
			switch (tolower(arrow))
			{
			case 'y':

				adding(current);
				circle = false;
				break;
			case 'n':
				circle = false;
				current->removeList(current->dise);
				current->removeList(current->compo);
				delete current;
				break;
			}
		}


		
	}

void inventory::adding(medicine *current) //funkcja dodania
{
	if (product == nullptr)
	{
		product = current;
	}
	else if (current->data.getName() < product->data.getName())
	{
		current->next = product;
		product = current;
	}
	else {
		medicine * current2 = new medicine;
		current2 = product;
		bool circle = true;
		while (circle)
		{
			if (current2->next == nullptr)
			{
				current2->next = current;
				circle = false;
			}

			else if (current2->next->data.getName() > current->data.getName())
			{
				current->next = current2->next;
				current2->next = current;
				circle = false;
			}
			current2 = current2->next;
		}
	}
}

void inventory::removeProduct() //usuwanie leku z naszej bazy
{
	if (product == nullptr)
	{
		std::cout << "Nie ma zadnych lekow do usuniecia.\n";
		system("pause");
	}
	else
	{
		medicine* temp = nullptr;
		char arrow = ' ';
		bool circle = true;
		while (circle)
		{
			std::cout << "Podaj kod lub nazwe leku do usuniecia. (k/n)";
			arrow = _getch();
			switch (tolower(arrow))
			{
			case 'n':
				temp = searchName::writeAndSearch(product);
				circle = false;
				break;
			case 'k':
				temp = searchCode::writeAndSearch(product);
				circle = false;
				break;
			}
				
		}
		removing(temp);
	}
}

void inventory::removing(medicine *temp) //funkcja usuniecia
{
	if (temp == product)
	{
		product = product->next;
		std::cout << "Usuwam:\n";
		temp->showMedicine(temp);
		temp->removeList(temp->dise);
		temp->removeList(temp->compo);
		system("pause");
		delete temp;
		temp = nullptr;
	}
	else if (temp == nullptr)
	{
		std::cout << "Nie ma takiego leku\n";
		system("pause");
	}
	else
	{
		medicine* current = product;

		while (current->next != temp)
		{
			current = current->next;
		}
		current->next = temp->next;
		std::cout << "Usuwam:\n";
		temp->showMedicine(temp);
		temp->removeList(temp->dise);
		temp->removeList(temp->compo);
		system("pause");
		delete temp;
		temp = nullptr;
	}
}

void inventory::searchProduct(medicine* head) //menu wyszukiwania leku - umozliwia wybor za posrednictwem czego lek zostanie wybrany
{
	system("cls");
	std::cout << "Z pomoca czego chcesz wyszukac lek?\n1. Nazwa\n2. Kod\n3. Kompleksowe wyszukiwanie\n4. Powrot";
	int code;

	medicine* current = head;
	std::string temp;
	char arrow;
	bool circle = true;
	while (circle)
	{
		arrow = _getch();
		switch (arrow)
		{
		case '1':
			current = searchName::writeAndSearch(product);
			current->edit();
			circle = false;
			break;
		case '2':
			current = searchCode::writeAndSearch(product);
			current->edit();
			circle = false;
			break;
		case '3':
			searchComplex::complexSearch(product);
			circle = false;
			break;
		case'4':
			circle = false;
			break;
		}
	}
}

void inventory::printExpired(medicine *head, const int &today) //wyswietla przeterminowane leki
{

	system("cls");
	std::cout << "PRZETERMINOWANE LEKI:\n";
	medicine * current = head;
	if (head == nullptr)
	{
		std::cout << "Brak jakichkolwiek lekow.\n";
	}
	while (current != nullptr)
	{
		if (current->date < today)
		{
			current->showMedicine(current);
		}
		current = current->next;
	}
	system("pause");
}

void inventory::deleteExpired(medicine *head, const int & today) //usuwa przeterminowane leki
{
	system("cls");
	std::cout << "Chcesz usunac wszystkie przeterminowane leki?(y/n)\n";
	medicine* current = head;
	medicine * current2 = head;
	char arrow;
	arrow = _getch();
	switch (tolower(arrow))
	{
	case 'y':
		while (current2)
		{
			if (current->date < today)
			{
				current2 = current2->next;
				removing(current);
				current = current2;
			}
			else
			{
				current = current->next;
				current2 = current2->next;
			}
		}

			break;
	case 'n':
		return;
		break;
	}

}

bool inventory::verifyCode(medicine *head, medicine * newMedicine)//analogicznie do verifyName
{
	medicine * current = head;

	int _quant;
	while (current != nullptr)
	{
		if (current->data.getCode() == newMedicine->data.getCode())
		{
			system("cls");
			std::cout << "Lek z takim kodem juz istnieje po wybraniu opcji zostaniesz przeniesiony z powrotem do podania danych.\n" << current->data << "\nCzy chcesz dodac ilosc lekow do istniejacego?(y/n)";
			char arrow = ' ';
			arrow = _getch();
			switch (tolower(arrow))
			{
			case 'y':
				system("cls");
				std::cout << "Ile sztuk chcesz dodac: ";
				while (!(std::cin >> _quant))
				{
					std::cout << "Zla ilosc sztuk!\nPodaj poprawna: " << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n'); //czyszczenie strumienia ze wszystkich znakow
				}
				current->data += _quant;
				return true;
				break;
			case 'n':

				return true;
				break;
			}


		}
		current = current->next;
	}
	return false;
}

bool inventory::verifyName(medicine *head, medicine * newMedicine) //weryfikacja czy lek o danej nazwie (przy dodawaniu leku) juz istnieje. Jesli tak nastepuje zapytanie czy zwiekszyc ilosc, a nastepnie powrot do podania nowego leku.
{
	medicine * current = head;

	int _quant;
	while (current != nullptr)
	{
		if (current->data == newMedicine->data)
		{
			system("cls");
			std::cout << "Lek z taka nazwa juz istnieje po wybraniu opcji zostaniesz przeniesiony z powrotem do podania danych.\n" << current->data << "\nCzy chcesz dodac ilosc lekow do istniejacego?(y/n)";
			char arrow = ' ';
			arrow = _getch();
			switch (tolower(arrow))
			{
			case 'y':

				system("cls");
				std::cout << "Ile sztuk chcesz dodac: ";
				while (!(std::cin >> _quant))
				{
					std::cout << "Zla ilosc sztuk!\nPodaj poprawna: " << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n'); //czyszczenie strumienia ze wszystkich znakow
				}
				current->data += _quant;
				return true;
				break;
			case 'n':

				return true;
				break;
			}


		}
		current = current->next;
	}
	return false;
}

void inventory::saveAll()
{
	remove("baza.txt");
	if (product != nullptr)
	{
		std::fstream temp("baza.txt");
		temp.open("baza.txt", std::ios::out);

		medicine* current = product;

		while (current != nullptr)
		{
			temp << current;
			current = current->next;
		}
	}
}

void inventory::loadFromFile(const std::string &fileName)
{
	using namespace std;

	fstream file;
	file.open(fileName, ios::in);
	try
	{
		if (file.good())
		{
			if (file.is_open())
			{


				while (!file.eof())
				{
					medicine* temp = new medicine;
					file >> temp;

					if (product == nullptr)
					{
						product = temp;
					}
					else
					{
						medicine* temp2 = product;
						while (temp2->next != nullptr)
						{
							temp2 = temp2->next;
						}
						temp2->next = temp;
					}
				}
			}
			else
			{
				throw std::string("Blad otwarcia pliku...");
			}
		}
		else
		{
			throw invalid_argument("Blad odczytywania pliku...");
		}
	}
	catch (std::string tmp)
	{
		std::cout << "Nie udalo sie otworzyc twojej bazy danych. Mozliwe, ze zostala zle zapisana, badz istnieje juz baza o zlym rozszerzeniu. Skopiuj wnetrze pliku baza.txt, nastepnie usun go i uruchom ponownie program. Zostanie wygenerowana nowa podstawowa baza do ktorej nalezy wkleic to co zostalo skopiowane z poprzedniej."<<std::endl;
		system("Pause");
	}
	catch (invalid_argument c)
	{
		std::cout << "Otwierasz program pierwszy raz badz usunales baze danych. Nic sie nie martw, program wygeneruje nowa podstawe za Ciebie!Niestety dane bedziesz musial uzupelnic samodzielnie.\n\nW programie w glownej mierze bedziesz poruszac sie za pomoca strzalek zatwierdzajac enterem lub ESC.Jesli zobaczysz w menu cyfry obok mozliwych wyborow to znaczy, ze musisz wybrac jedna z nich z klawiatury.\nZycze przyjemnej pracy oraz dziekuje za zaufanie. "<<std::endl;
		system("PAUSE");
	}
	}
