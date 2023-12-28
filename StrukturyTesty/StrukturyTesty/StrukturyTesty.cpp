#include <iostream>

using namespace std;

struct figuryStruct {
	string name;//nazwa
	float area;//pole
	float obw;//obwod
	figuryStruct* next;//wskaznik na nastepy elemnt listy
	figuryStruct* prev;//wskaznik na poprzedni element listy
};

//wskaznik na poczatek listy
figuryStruct* head = nullptr;

void AddFigure(string name, float area, float obw)
{
	//tworzy nowa strukture figury
	figuryStruct* newFigure = new figuryStruct;
	//dodanie wartosci
	newFigure->name = name;
	newFigure->area = area;
	newFigure->obw = obw;
	newFigure->next = nullptr;

	//sprawdzenie czy lista jest pusta
	if (head == nullptr)
	{
		//jesli lista jest pusta to nasz element staje sie jedynym elementem listy - head
		newFigure->prev = nullptr;
		head = newFigure;
	}
	else
	{
		newFigure->prev = nullptr;
		//current to wskaźnik na aktualny element listy, który jest używany do iteracji przez listę.
		figuryStruct* current = head;
		//przechodzimy na ostanie miejsce
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = newFigure;
		newFigure->prev = current;
	}
	cout << "Dodano figure: " << name << endl;
}

void RemoveFigure(string name)
{
	//current to wskaźnik na aktualny element listy, który jest używany do iteracji przez listę.
	figuryStruct* current = head;
	while (current != nullptr)
	{
		//Pętla while sprawdza każdy element listy, czy jego nazwa odpowiada podanej nazwie name
		if (current->name == name)
		{
			if (current->prev != nullptr)
			{
				//usuwamy figure która nie jest pierwszym elementem listy. W takim przypadku ustawiamy current->prev->next na current->next.
				//usuwamy powiązanie z listą current
				current->prev->next = current->next;
			}
			else
			{
				//usuwamy pierwszy element listy
				head = current->next;
			}
			//Ustawiamy również current->next->prev na current->prev, aby poprawnie zachować strukturę dwukierunkową listy.
			if (current->next != nullptr)
			{
				current->next->prev = current->prev;
			}
			//usuwamy current 
			delete current;
			cout << "Usunieto figure : " << name << endl;
			return;
		}
		current = current->next;
	}
	cout << "Nie znaleziono takiej figury" << endl;
}

void ShowFigures() {
	figuryStruct* current = head;
	cout << "Lista figur:" << endl;
	//tak dlugo jak istnieje kolejna figura w liscie
	while (current != nullptr) {
		cout << "Nazwa: " << current->name << ", Pole: " << current->area << ", Obwod: " << current->obw << endl;
		//przejscie na kolejne miejsce
		current = current->next;
	}
	cout << "-------------------" << endl;
}


int main()
{
	while (true)
	{
		int wybor;
		cout << "1. Dodaj" << endl;
		cout << "2. Usun" << endl;
		cout << "3. Wyswietl" << endl;
		cin >> wybor;

		switch (wybor)
		{
		case 1: {
			string nazwaF;
			float pole, obw;
			cout << "Podaj nazwe : ";
			cin >> nazwaF;
			cout << "Podaj pole : ";
			cin >> pole;
			cout << "Podaj obwod : ";
			cin >> obw;
			AddFigure(nazwaF, pole, obw);
			break;
		}
		case 2: {
			string nazwaU;
			cout << "Podaj nazwe figury do usuniecia : ";
			cin >> nazwaU;
			RemoveFigure(nazwaU);
		}
		case 3:
			ShowFigures();
			break;
		default:
			cout << "Brak takiej opcji!" << endl;
			break;
		}
	}
	return 0;
}

