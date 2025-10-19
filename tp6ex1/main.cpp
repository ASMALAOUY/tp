#include <iostream>
using namespace std;

class Personne {
protected:
    string nom;
    int age;

public:
    Personne(string n, int a) : nom(n), age(a) {}

    void afficher() {
        cout << "Nom: " << nom << ", Age: " << age << endl;
    }
};

class Etudiant : public Personne {
private:
    string niveau;

public:
    Etudiant(string n, int a, string niv) : Personne(n, a), niveau(niv) {}

    void afficher() {
        cout << "Etudiant: " << nom << " (" << age << " ans), Niveau: " << niveau << endl;
    }
};

int main() {
    Etudiant e1("Amine", 20, "Licence 2");
    e1.afficher();

    return 0;
}
