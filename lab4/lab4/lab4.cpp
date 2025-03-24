//3 modificatori : private: datele sunt , public, protected-datele sun accesibile in aceeasi clasa si in clasele derivate
// sa se faca un vector de studenti
// media mediilor
//plecand de la acest exemplu sa se scrie un prigram in c++ pentru gestiunea unei gradini zoologice folosind clase,obiecte si concepul de mostenire. Vom crea o clasa animal para lungimea aripilor durata de viata. pt caine vom avea rasa, tipul cainelui de exemplu de vanatoare, de casa

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Persoana
{

protected:
    string nume;
    int varsta;

public: 
    Persoana(string nume, int varsta) {
        this->nume = nume;
        this->varsta = varsta;
    }

    void afisare_detalii() {
        cout << "Nume " << nume << "Varsta: "<<varsta<< endl;
    }


   

};

class Student : public Persoana {
private:
    float medie;
public:
    Student(string nume, int varsta, float medie) 
        : Persoana(nume, varsta), medie(medie) {
        this->medie = medie;
    }

    float medieAD(){
       return medie;
    };

    void afiseazainformatii() {
        cout << "Nume: " << nume << " Varsta: " << varsta << " Medie: " << medie<<endl;
    }

    float MediaMediilor() {
        return medie;
    }

};

int main()
{

    const int nr_studenti = 5;
    float sumaM = 0.0;
    

    Student studenti[nr_studenti] = {
        Student("Ion", 22, 9.5),
        Student("Alexandru", 23, 10),
        Student("Marian", 20, 8),
        Student("Stefania", 22, 9),
        Student("Cornel", 24, 8)

    };

    for (int i = 0; i < nr_studenti; i++) {
        studenti[i].afiseazainformatii();
        sumaM += studenti[i].MediaMediilor();
    }
    float MediaM = sumaM / nr_studenti;

    cout << "Media mediilor: " << MediaM << endl;
    return 0;
}