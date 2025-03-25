
#include <iostream>
#include <string>
using namespace std;

class Persoana {

protected:
	string nume;
	int varsta;

public:
	Persoana(string nume, int varsta) {
		this->nume = nume;
		this->varsta = varsta;
	}

	void afiseaza_informatii() {
		cout << "Nume " << nume << " Varsta " << varsta << endl;
	}

	string GetNume() const {
		return nume;
	}

	int GetVarsta() const {
		return varsta;
	}
};


class Student : public Persoana {
private:
	float medie;

	//clasa prietena
	friend class Admin;

public:
	Student(string nume, int varsta, float medie) : Persoana(nume, varsta) {
		this->medie = medie;
	}

	void afiseaza_informatii() {
		cout << "Nume " << nume << " Varsta " << varsta << " Medie: "<<medie<<endl;
	}

	//suprascrierea operatorului
	bool operator>(const Student& celalalt_obiect) const {
		return this->medie > celalalt_obiect.medie;
	}

};

class Admin {
public:
	//folosing & inseamna ca lucram cu o referinta pt o variabila existenta. nu o copie
	void modifica_medie(Student& s, float nouaMedie) {
		cout << "Modific media pt " << s.nume << " de la " << s.medie << " la " << nouaMedie << endl;
		s.medie = nouaMedie;
	}

	void detaliiStudent(const Student& s) {
		cout << "Admin -> student: " << s.nume << " Varsta: " << s.varsta << " Medie: " << s.medie << endl;
	}
};

int main()
{
	Student s1("Mihai", 20, 7.5);
	Student s2("Victor", 20, 10);
	

	s1.afiseaza_informatii();
	s2.afiseaza_informatii();

	//Adminu-l modifica media
	Admin admin;
	admin.modifica_medie(s2, 11);
	admin.detaliiStudent(s2);

	//verificam comparatia
	if (s1 > s2) {
		cout << s1.GetNume() << " are media mai mare decat " << s2.GetNume() << endl;
	}
	else {
		cout << s2.GetNume() << " are media mai mare decat " << s1.GetNume() << endl;
	}


}
