#include <iostream>
using namespace std;

class Produit {
protected:
    string nom;
    double prix;

public:
    Produit(string n, double p) : nom(n), prix(p) {}

    virtual void afficherInfos() {
        cout << "Produit: " << nom << ", Prix: " << prix << " €" << endl;
    }

    virtual ~Produit() {}
};

class ProduitAlimentaire : public Produit {
private:
    string dateExpiration;

public:
    ProduitAlimentaire(string n, double p, string date) : Produit(n, p), dateExpiration(date) {}

    void afficherInfos() override {
        cout << "Produit Alimentaire: " << nom << ", Prix: " << prix << " €, Date d'expiration: " << dateExpiration << endl;
    }
};

class ProduitElectronique : public Produit {
private:
    int garantie; // en mois

public:
    ProduitElectronique(string n, double p, int g) : Produit(n, p), garantie(g) {}

    void afficherInfos() override {
        cout << "Produit Electronique: " << nom << ", Prix: " << prix << " €, Garantie: " << garantie << " mois" << endl;
    }
};

int main() {
    ProduitAlimentaire pa1("Lait", 1.5, "2025-12-31");
    ProduitElectronique pe1("Smartphone", 500.0, 24);

    pa1.afficherInfos();
    pe1.afficherInfos();

    return 0;
}
