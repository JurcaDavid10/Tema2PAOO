#include "ContBancar.h"
#include <iostream>
#include <stdexcept>  // pentru std::invalid_argument

// Constructor
ContBancar::ContBancar(int numar) 
    : numarConturi(numar), 
      numeTitulari(nullptr), 
      solduri(nullptr) {
    // Verificăm dacă numărul de conturi este valid
    if (numarConturi <= 0) {
        std::cerr << "Eroare: numarConturi trebuie să fie mai mare decât 0.\n";
        throw std::invalid_argument("Numărul de conturi nu este valid");
    }

    // Alocăm memoria pentru nume și solduri, prindem eventuale excepții
    try {
        numeTitulari = new std::string[numarConturi];
        solduri = new double[numarConturi];
        std::cout << "Constructor: Obiectul ContBancar a fost creat cu " << numarConturi << " conturi.\n";
    } catch (const std::bad_alloc& e) {
        std::cerr << "Alocare memorie eșuată: " << e.what() << "\n";
        throw; // Re-lansează excepția
    }
}

// Destructor
ContBancar::~ContBancar() {
    delete[] numeTitulari;
    delete[] solduri;
    std::cout << "Destructor: Memoria pentru obiectul ContBancar a fost eliberată.\n";
}

// Operator de atribuire
ContBancar& ContBancar::operator=(const ContBancar& other) {
    // Verificare auto-atribuire
    if (this == &other) {
        std::cout << "Auto-atribuire detectată, nu este necesară copierea.\n";
        return *this;
    }

    // Eliberăm memoria existentă pentru a evita scurgerile
    delete[] numeTitulari;
    delete[] solduri;

    // Copiem numărul de conturi
    numarConturi = other.numarConturi;

    // Alocăm memorie pentru noile array-uri de nume și solduri
    try {
        numeTitulari = new std::string[numarConturi];
        solduri = new double[numarConturi];
        std::cout << "Operator de atribuire: Memoria pentru conturi a fost realocată.\n";
    } catch (const std::bad_alloc& e) {
        std::cerr << "Alocare memorie eșuată: " << e.what() << "\n";
        throw; // Re-lansează excepția
    }

    // Copiem valorile din obiectul sursă în obiectul curent
    for (int i = 0; i < numarConturi; ++i) {
        numeTitulari[i] = other.numeTitulari[i];
        solduri[i] = other.solduri[i];
        std::cout << "Cont " << i + 1 << ": Nume - " << numeTitulari[i] << ", Sold - " << solduri[i] << "\n";
    }

    // Returnăm obiectul curent pentru a permite lanțuri de atribuiri
    return *this;
}

// Getters și Setters
std::string ContBancar::getNumeTitular(int index) const {
    return numeTitulari[index];
}

void ContBancar::setNumeTitular(int index, const std::string& nume) {
    numeTitulari[index] = nume;
}

double ContBancar::getSold(int index) const {
    return solduri[index];
}

void ContBancar::adaugaSuma(int index, double suma) {
    solduri[index] += suma;
}

// Metoda pentru afisarea conturilor
void ContBancar::afiseazaConturi() const {
    for (int i = 0; i < numarConturi; ++i) {
        std::cout << "Cont " << i + 1 << ": Nume - " << numeTitulari[i]
                  << ", Sold - " << solduri[i] << "\n";
    }
}

class ContBancarPremium : public ContBancar {
private:
    double rataDobanda; // Dobanda anuala pentru solduri

public:
    // Constructor
    ContBancarPremium(int numar, double rata) 
        : ContBancar(numar), rataDobanda(rata) {
        std::cout << "S-a creat un obiect ContBancarPremium derivat din clasa ContBancar.\n";
    }

    // Destructor
    ~ContBancarPremium() override {
        std::cout << "Destructor: Obiectul ContBancarPremium a fost distrus.\n";
    }

    // Setare rata dobanda
    void setRataDobanda(double rata) {
        rataDobanda = rata;
    }

    // Aplica dobanda la solduri
    void aplicaDobanda() {
        for (int i = 0; i < getNumarConturi(); ++i) {
            double soldActual = getSold(i);
            adaugaSuma(i, soldActual * rataDobanda / 100);
        }
        std::cout << "Dobânda a fost aplicată cu rata de " << rataDobanda << "%.\n";
    }

    // Afisare informatii
    void afiseazaConturiPremium() const {
        std::cout << "Conturi premium:\n";
        afiseazaConturi();
    }
};
