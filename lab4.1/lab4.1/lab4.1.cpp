
#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string nume;
    int speranta_de_viata;

public:
    Animal(string rasa, int speranta_de_viata) {
        this->nume = nume;
        this->speranta_de_viata = speranta_de_viata;

    }
        void afisare_informatii() {
            cout << "Animal: " << nume << " Durata de viata: " << speranta_de_viata << " ani" << endl;
        }
};

class Pasare : public Animal {
private:
    float lungime_aripi;

public:
    Pasare(string nume, int speranta_de_viata, float lungime_aripi) : Animal(nume, speranta_de_viata), lungime_aripi(lungime_aripi) {
        this->nume = nume;
        this->speranta_de_viata = speranta_de_viata;
        this->lungime_aripi = lungime_aripi;
    }

    void afisare_informatii() {
        cout << "Pasare: " << nume << " Speranta de viata: " << speranta_de_viata << " ani " << "Lungime aripi: " << lungime_aripi << " cm"<< endl;
    }

};


class Caine : Animal {
private:
    string rasa;
    string tip;

public:
    Caine(string nume, int speranta_de_viata, string rasa, string tip) : Animal(nume, speranta_de_viata), rasa(rasa), tip(tip) {
        this->nume = nume;
        this->speranta_de_viata = speranta_de_viata;
        this->rasa = rasa;
        this->tip = tip;
    }

    void afisare_informatii() {
        cout << "Caine: " << nume << " Rasa: " << rasa << " Tip: " << tip << " Speranta de viata: " << speranta_de_viata << " ani" << endl;
    }
};


int main()
{
    const int nr_animale = 1;

    Caine caine[nr_animale] = {
    Caine("Spike", 15, "Husky", "caine de munte")
    };
    Pasare pasare[nr_animale] = {
        Pasare("Lary", 10, 15.3)

    };

    for (int i = 0; i < nr_animale; i++) {
        caine[i].afisare_informatii();
        pasare[i].afisare_informatii();
    }




    return 0;

}