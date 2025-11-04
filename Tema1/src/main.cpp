#include "filme.h"

Film creeazaFilmTemporar() {
    Film f("Alien", 3);
    f.setRating(0, 9);
    f.setRating(1, 10);
    f.setRating(2, 8);
    cout << "Se returneaza un Film temporar" << endl;
    return f;
}

int main() {
    cout << "----- Demo Filme -----" << endl;

    Film f1("Predator", 3);
    f1.setRating(0, 8);
    f1.setRating(1, 9);
    f1.setRating(2, 7);
    f1.afiseaza();

    cout << "\n----- Copiere -----" << endl;
    Film f2 = f1;
    f2.setRating(0, 10);
    f2.afiseaza();
    f1.afiseaza();

    cout << "\n----- Mutare (move) -----" << endl;
    //Film f3 = creeazaFilmTemporar();
    Film f3 = std::move(f2);
    f3.afiseaza();

    cout << "\nSfarsit program" << endl;
    return 0;
}