#include <iostream>
using namespace std;

class Employe {
protected:
    string nom;
    int id;
    float salaireDeBase;

public:
    Employe(string n, int i, float s) : nom(n), id(i), salaireDeBase(s) {}

    virtual void afficherInfos() {
        cout << "Employe: " << nom << ", ID: " << id << ", Salaire de base: " << salaireDeBase << " €" << endl;
    }

    virtual ~Employe() {}
};

class Permanent : public Employe {
private:
    float primeAnnuelle;

public:
    Permanent(string n, int i, float s, float prime) : Employe(n, i, s), primeAnnuelle(prime) {}

    void afficherInfos() override {
        cout << "Permanent: " << nom << ", ID: " << id << ", Salaire de base: " << salaireDeBase
             << " €, Prime annuelle: " << primeAnnuelle << " €" << endl;
    }
};

class Contractuel : public Employe {
private:
    int dureeContrat;
    float tauxHoraire;

public:
    Contractuel(string n, int i, float s, int duree, float taux)
        : Employe(n, i, s), dureeContrat(duree), tauxHoraire(taux) {}

    float calculerSalaireMensuel(int heures) {
        return heures * tauxHoraire;
    }

    void afficherInfos() override {
        cout << "Contractuel: " << nom << ", ID: " << id << ", Salaire de base: " << salaireDeBase
             << " €, Durée contrat: " << dureeContrat << " mois, Taux horaire: " << tauxHoraire << " €" << endl;
    }
};

int main() {
    Employe* employes[3];

    employes[0] = new Permanent("Alice", 101, 3000.0, 500.0);
    employes[1] = new Contractuel("Bob", 102, 2000.0, 12, 15.0);
    employes[2] = new Permanent("Charlie", 103, 3200.0, 600.0);

    for(int i = 0; i < 3; i++) {
        employes[i]->afficherInfos();
    }

    for(int i = 0; i < 3; i++) {
        delete employes[i];
    }

    return 0;
}
