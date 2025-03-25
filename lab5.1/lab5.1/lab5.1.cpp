
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
};


class Student : Persoana {
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


}
