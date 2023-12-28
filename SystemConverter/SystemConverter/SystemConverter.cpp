#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string ConvertBase(string number, int from, int to)
{
	//konwertujemy z bazowego systemu na system dziesietny
	int decimal = 0;
	int power = 0;
	for (int i = number.size() - 1; i >= 0; --i)
	{
		char digit = number[i];
		int digitVal;
		//sprawdzenie czy digit jest cyfra, jesli tak przypisujemy odpowednia wartosc liczbowa
		if (isdigit(digit))
		{
			digitVal = digit -'0';
		}
		//jesli nie jest przeksztalcamy ja na odpowednia wartosc w systemie 16
		else
		{
			digitVal = toupper(digit)-'A'+10;
		}
		//power, potega do ktorej podnosimy
		decimal += digitVal * pow(from, power);
		++power;
	}

	//konwertujemy z 10 na docelowy
	//decimal to zmienna przechowująca liczbe w systemie 10
	string result = "";
	while (decimal > 0)
	{
		//leftover to reszta z dzielenie przez baze systemu do ktorego chcemy przejsc
		int leftover = decimal % to;
		char digitChar;

		//jesli reszta jest mniejsza od 10 jest ona cyfra i jest dodawana do wyniku
		if (leftover < 10)
		{
			digitChar = leftover + '0';
		}
		//jesli jest wieksza jest konwertowana na litery 
		else
		{
			digitChar = leftover - 10 + 'A';
		}
		//dodajemy znak na poczatek
		result = digitChar + result;
		//dzielimy liczbe w 10tnym przez baze nowego systemu
		decimal /= to;

	}
	if (result.empty())
	{
		return "0";
	}
	else
	{
		return result;
	}

}

int main()
{
	while (true)
	{
		int fromWhat, toWhat;
		string userNumber;
		cout << "Wybierz system poczatkowy : ";
		cin >> fromWhat;
		if (fromWhat < 2 || fromWhat>16)
		{
			continue;
			cout << "Niepoprwany system!" << endl;
		}
		else
		{
			cout << "Wybierz system docelowy : ";
			cin >> toWhat;
			if (toWhat < 2 || toWhat>16)
			{
				continue;
				cout << "Niepoprwany system!" << endl;
			}
			else
			{
				cout << "Podaj liczbe w systemie " << fromWhat << " : ";
				cin >> userNumber;
				cout << "Liczba w systmie " << toWhat << " to : " << ConvertBase(userNumber, fromWhat, toWhat) << endl;
			}
		}
	}
}
