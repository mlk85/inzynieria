#include <iostream>
#include <string>

using namespace std;

struct DaneSamochodu {
	string rejestracja;
	string VIN;
	string typNadwozia;
};

struct DaneKlienta {
	string imie;
	string nazwisko;
	int pesel;
	string adres;
	int nr_tel;
	DaneSamochodu samochod;
};

class Warsztat {
private:
	DaneKlienta * listaKlientow;
	int liczbaKlientow;

public:
	Warsztat() : listaKlientow(nullptr), liczbaKlientow(0) {}

	~Warsztat() {
		delete[] listaKlientow;
	}

	void noweZgloszenie() {
		DaneKlienta nowyKlient;

		cout << "Imie: ";
		cin >> nowyKlient.imie;

		cout << "Nazwisko: ";
		cin >> nowyKlient.nazwisko;

		cout << "PESEL: ";
		cin >> nowyKlient.pesel;

		cout << "Adres: ";
		cin >> nowyKlient.adres;

		cout << "Nr telefonu: ";
		cin >> nowyKlient.nr_tel;

		cout << "Rejestracja samochodu: ";
		cin >> nowyKlient.samochod.rejestracja;

		cout << "VIN samochodu: ";
		cin >> nowyKlient.samochod.VIN;

		cout << "Typ nadwozia samochodu: ";
		cin >> nowyKlient.samochod.typNadwozia;

		// Dodaj nowego klienta do listy
		dodajKlienta(nowyKlient);

		cout << "Nowe zgloszenie dodane." << endl;
	}

	void serwis() {
		//serwis
		cout << "Serwis w toku..." << endl;
	}

	void wystawienieFaktury() {
		//wystawiania faktury
		cout << "Faktura wystawiona." << endl;
	}

private:
	void dodajKlienta(DaneKlienta nowyKlient) {
		DaneKlienta* nowaLista = new DaneKlienta[liczbaKlientow + 1];

		for (int i = 0; i < liczbaKlientow; ++i) {
			nowaLista[i] = listaKlientow[i];
		}

		nowaLista[liczbaKlientow] = nowyKlient;

		delete[] listaKlientow;
		listaKlientow = nowaLista;

		++liczbaKlientow;
	}
};

int main() {
	Warsztat warsztat;

	int wybor;

	do {
		cout << "Menu:" << endl;
		cout << "1. Nowe zgloszenie" << endl;
		cout << "2. Serwis" << endl;
		cout << "3. Wystawienie faktury" << endl;
		cout << "0. Wyjdz" << endl;
		cout << "Wybierz opcje: ";
		cin >> wybor;

		switch (wybor) {
		case 1:
			warsztat.noweZgloszenie();
			break;
		case 2:
			warsztat.serwis();
			break;
		case 3:
			warsztat.wystawienieFaktury();
			break;
		case 0:
			cout << "Zakonczono program." << endl;
			break;
		default:
			cout << "Nieprawidlowa opcja. Sprobuj ponownie." << endl;
		}

	} while (wybor != 0);

	system("pause");
	return 0;
}
