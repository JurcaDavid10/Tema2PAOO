#ifndef CONTBANCARPREMIUM_H
#define CONTBANCARPREMIUM_H

#include "ContBancar.h"

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
    ~ContBancarPremium() { 
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

#endif // CONTBANCARPREMIUM_H
