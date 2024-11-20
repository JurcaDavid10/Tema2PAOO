#include "ContBancar.h"
#include "ContBancarPremium.h"

int main() {
    try {
        // Test pentru clasa de bază ContBancar
        std::cout << "Test pentru clasa de bază ContBancar:\n";
        ContBancar cont1(2);
        cont1.setNumeTitular(0, "Ion Tiriac");
        cont1.setNumeTitular(1, "Donald Trump");
        cont1.adaugaSuma(0, 100.50);
        cont1.adaugaSuma(1, 200.75);
        cont1.afiseazaConturi();

        // Test operator= pentru clasa de bază
        ContBancar cont2(1);
        cont2 = cont1;
        std::cout << "\nDupă operator=:\n";
        cont2.afiseazaConturi();

        // Test pentru clasa derivată ContBancarPremium
        std::cout << "\nTest pentru clasa derivată ContBancarPremium:\n";
        ContBancarPremium contPremium(2, 5.0); // 2 conturi, dobândă 5%
        contPremium.setNumeTitular(0, "Elon Musk");
        contPremium.setNumeTitular(1, "Jeff Bezos");
        contPremium.adaugaSuma(0, 1000);
        contPremium.adaugaSuma(1, 2000);

        std::cout << "\nÎnainte de aplicarea dobânzii:\n";
        contPremium.afiseazaConturiPremium();

        // Aplică dobânda
        contPremium.aplicaDobanda();

        std::cout << "\nDupă aplicarea dobânzii:\n";
        contPremium.afiseazaConturiPremium();

    } catch (const std::exception& e) {
        std::cerr << "Eroare: " << e.what() << "\n";
    }

    return 0;
}
