#include <iostream>
#include <stack>
using namespace std;

class Hanoi {
private:
	stack<int> Tower[3];
	int numberOfDisks;
public:
	Hanoi(int n) : numberOfDisks(n) {}
	void StartGame()
	{
		//start gry, dodanie dyskow na pierwsza wieze
		for (int i = numberOfDisks; i > 0; i--)
		{
			Tower[0].push(i);
		}
	}
	//wyswietlanie gry
	void DisplayGame()
	{
		for (int i = 0; i < 3; i++)
		{
			cout << i + 1 << " Wieza : ";
			//tworzenie chwilowego stacka do ktorego przypisywane sa wartosci danej wiezy
			stack<int> temp = Tower[i];
			while (!temp.empty())
			{
				//wypiswanie najwzeszego elementu stacku, a nastepnie usuwanie go
				cout << temp.top() << " ";
				temp.pop();
			}
			cout << endl;
		}
		cout << "-------------------" << endl;
	}

	void MoveDisk(int source, int destination)
	{
		//sprawdzenie czy wieza nie jest pusta
		if (!Tower[source].empty())
		{
			//przypisanie wartosci najwyzszego dysku do zmiennej
			int movableDisk = Tower[source].top();
			//jesli docelowa wieza jest pusta lub dysk już ta bedacy jest wiekszy od wybrnaego
			if (Tower[destination].empty() || Tower[destination].top() > movableDisk)
			{
				//dodajemy na koniec docelowego stacku nasz dysk
				Tower[destination].push(movableDisk);
				//usuwany z wybranego stacku dysk
				Tower[source].pop();
				DisplayGame();
			}
			else {
				cout << "Niewlasiwy ruch, sprobuj jeszcze raz" << endl;
			}
		}
		else {
			cout << "Wieza " << source + 1 << " jest pusta" << endl;
		}

	}

	//jedyny przypadek gdy gra bedzie wygrana jest wtedy gdy wieza 1 i 2 są puste
	bool isSolved() {
		return Tower[0].empty() && Tower[1].empty();
	}
};


int main()
{
	int disk;
	cout << "Podaj ilosc dyskow : ";
	cin >> disk;
	Hanoi Gra(disk);

	Gra.StartGame();
	Gra.DisplayGame();

	while (!Gra.isSolved())
	{
		int sourceTower, destinationTower;
		cout << "Z ktorej wiezy? : ";
		cin >> sourceTower;
		if (sourceTower == 1 || sourceTower == 2 || sourceTower == 3)
		{
			cout << "Na jaka wieze? :";
			cin >> destinationTower;
			if (destinationTower == 1 || destinationTower == 2 || destinationTower == 3)
			{
				sourceTower--;
				destinationTower--;
				Gra.MoveDisk(sourceTower, destinationTower);
			}
			else
			{
				cout << "Nie ma takiej wiezy!" << endl;
				continue;
			}
		}
		else
		{
			cout << "Nie ma takiej wiezy!" << endl;
			continue;
		}
	}

	cout << "Gratualcje! Wygrales!" << endl;

}

