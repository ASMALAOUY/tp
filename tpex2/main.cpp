#include <iostream>
using namespace std;

class Compte {
protected:
    int numero;
    double solde;

public:
    Compte(int num, double s) : numero(num), solde(s) {}

    void deposer(double montant) {
        solde += montant;
    }

    void retirer(double montant) {
        if (montant <= solde)
            solde -= montant;
        else
            cout << "Solde insuffisant !" << endl;
    }

    void afficher() {
        cout << "Compte n:" << numero << ", Solde: " << solde << " €" << endl;
    }
};

class CompteEpargne : public Compte {
private:
    double tauxInteret;

public:
    CompteEpargne(int num, double s, double taux) : Compte(num, s), tauxInteret(taux) {}

    double calculerInteret() {
        return solde * tauxInteret / 100;
    }

    void afficher() {
        cout << "Compte Epargne n :" << numero << ", Solde: " << solde << " €, Taux: " << tauxInteret << "%" << endl;
    }
};

int main() {
    CompteEpargne ce1(101, 1000.0, 5.0);

    ce1.afficher();
    ce1.deposer(500);
    ce1.afficher();
    cout << "Interet: " << ce1.calculerInteret() << " €" << endl;

    ce1.retirer(2000);
    ce1.retirer(200);
    ce1.afficher();

    return 0;
}
