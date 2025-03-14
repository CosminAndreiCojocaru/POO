
#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string nume;
    int varsta;
    float medie;

public:
    Student(string nume1, int varsta1, float medie1) {
        nume = nume1;
        varsta = varsta1;
        medie = medie1;
        cout << "Student creat: " << nume << endl;
    }

    Student() {
        nume = "";
        varsta = 0;
        medie = 0.0;
    }

    ~Student() {
        cout << "Destructor apelat pentru: " << nume << endl;
    }

    void afisare_informatii() {
        cout << "Nume: " << nume << ", Varsta: " << varsta << ", Medie: " << medie << endl;
    }

    void a(string nume1, int varsta1, float medie1) {
        nume = nume1;
        varsta = varsta1;
        medie = medie1;
    }

    float medieM() {
        return medie;
    }

    string nume1() {
        return nume;
    }

    void copie_student(const Student& alt) {
        nume = alt.nume;
        varsta = alt.varsta;
        medie = alt.medie;
    }
};

void bubbleSort(Student* studenti, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (studenti[j].medieM() < studenti[j + 1].medieM()) {
                Student s = studenti[j];
                studenti[j].copie_student(studenti[j + 1]);
                studenti[j + 1].copie_student(s);
            }
        }
    }

};

int main() {
    int n;
    cout << "Introduceti numarul de studenti: ";
    cin >> n;

    Student* studenti = new Student[n];

    float sumaMedii = 0.0;
    int max = 0;

    for (int i = 0; i < n; i++) {
        string nume;
        int varsta;
        float medie;

        cout << "Introduceti nume " << i + 1 << ": "; cin >> nume;
        cout << "Introduceti varsta " << i + 1 << ": "; cin >> varsta;
        cout << "Introduceti medie " << i + 1 << ": "; cin >> medie;

        studenti[i].a(nume, varsta, medie);
        sumaMedii += medie;

        if (medie > studenti[max].medieM()) {
            max = i;
        }
    }

    cout << "\nStudentul cu cea mai mare medie este:\n";
    studenti[max].afisare_informatii();

    cout << "\nMedia mediilor este: " << sumaMedii / n << endl;

    studenti[n].bubbleSort(studenti, n);

    cout << "\nLista studentilor sortata dupa medie:\n";
    for (int i = 0; i < n; i++) {
        studenti[i].afisare_informatii();
    }


    delete[] studenti;

    return 0;
}
