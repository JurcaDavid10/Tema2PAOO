#ifndef CONTBANCAR_H
#define CONTBANCAR_H

#include <iostream>
#include <string>

class ContBancar {
private:
    std::string* numeTitulari;
    double* solduri;
    int numarConturi;

protected:
    // Permitem accesul claselor derivate la numarConturi
    int getNumarConturi() const { return numarConturi; }

public:
    // Constructor și Destructor
    ContBancar(int numar);
    virtual ~ContBancar(); // Destructor virtual

    // Operator de atribuire
    ContBancar& operator=(const ContBancar& other);

    // Gettere și Settere
    std::string getNumeTitular(int index) const;
    void setNumeTitular(int index, const std::string& nume);
    double getSold(int index) const;

    // Metodă pentru a adăuga sumă la un cont (acum publică)
    void adaugaSuma(int index, double suma); 

    // Metodă pentru afișarea conturilor
    void afiseazaConturi() const;
};

#endif // CONTBANCAR_H
