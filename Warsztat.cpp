#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

// Klasa Samochod
class Samochod {
private:
	string rejestracja;
	string vin;
	string typNadwozia;

public:
	Samochod() {}
	Samochod(const string& rejestracja, const string& vin, const string& typNadwozia)
		: rejestracja(rejestracja), vin(vin), typNadwozia(typNadwozia) {}

	string getRejestracja() const { return rejestracja; }
	string getVin() const { return vin; }
	string getTypNadwozia() const { return typNadwozia; }
};

// Klasa Klient
class Klient {
private:
	string pesel;
	string imie;
	string nazwisko;
	string adres;
	string nrTelefonu;
	Samochod samochod;

public:
	Klient() {}
	Klient(const string& pesel, const string& imie, const string& nazwisko,
		const string& adres, const string& nrTelefonu, const Samochod& samochod)
		: pesel(pesel), imie(imie), nazwisko(nazwisko), adres(adres), nrTelefonu(nrTelefonu), samochod(samochod) {}

	string getPesel() const { return pesel; }
	string getImie() const { return imie; }
	string getNazwisko() const { return nazwisko; }
	string getAdres() const { return adres; }
	string getNrTelefonu() const { return nrTelefonu; }
	Samochod getSamochod() const { return samochod; }

	void wczytajDane() {
		cout << "Podaj PESEL: ";
		cin >> pesel;
		cout << "Podaj imie: ";
		cin >> imie;
		cout << "Podaj nazwisko: ";
		cin >> nazwisko;
		cout << "Podaj adres: ";
		cin.ignore(); // Ignoruje pozosta³y bufor
		getline(cin, adres);
		cout << "Podaj numer telefonu: ";
		cin >> nrTelefonu;
	}

	void zapiszDoPliku(const string& nazwaPliku) {
		ofstream plik(nazwaPliku, ios::app);
		if (plik.is_open()) {
			plik << "PESEL: " << pesel << "\n"
				<< "Imie: " << imie << "\n"
				<< "Nazwisko: " << nazwisko << "\n"
				<< "Adres: " << adres << "\n"
				<< "Nr telefonu: " << nrTelefonu << "\n\n";
			plik.close();
		}
		else {
			cerr << "Nie mozna otworzyc pliku do zapisu." << endl;
		}
	}
};
// Klasa Zgloszenie
class Zgloszenie {
private:
	Klient klient;
	string opisProblemu;

public:
	Zgloszenie(const Klient& klient, const string& opisProblemu)
		: klient(klient), opisProblemu(opisProblemu) {}

	Klient getKlient() const { return klient; }
	string getOpisProblemu() const { return opisProblemu; }
};

// Klasa Us³uga
class Usluga {
public:
	virtual void wykonaj() = 0;
	virtual ~Usluga() {}
};

class Przeglad : public Usluga {
public:
	void wykonaj() override {
		cout << "Wykonano przeglad." << endl;
	}
};

class Naprawa : public Usluga {
public:
	void wykonaj() override {
		cout << "Wykonano naprawe." << endl;
	}
};

class Faktura : public Usluga {
public:
	void wykonaj() override {
		cout << "Wystawiono fakture." << endl;
	}
};

void wykonajUsluge(Usluga& usluga) {
	usluga.wykonaj();
}

// Klasa SerwisSamochodowy
class SerwisSamochodowy {
private:
	vector<Klient> klienci;
	vector<Zgloszenie> zgloszenia;
	map<string, Klient*> bazaKlientow;

public:
	void dodajKlienta(const Klient& klient) {
		if (bazaKlientow.find(klient.getPesel()) == bazaKlientow.end()) {
			klienci.push_back(klient);
			bazaKlientow[klient.getPesel()] = &klienci.back();
		}
	}

	void dodajZgloszenie(const Zgloszenie& zgloszenie) {
		zgloszenia.push_back(zgloszenie);
	}

	void wykonajUsluge(Usluga& usluga) {
		usluga.wykonaj();
	}

};

int main() {
	Klient klient;
	klient.wczytajDane();
	klient.zapiszDoPliku("dane_klientow.txt");
	
	return 0;

	return 0;
}
