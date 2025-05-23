#ifndef UNITATEMEDICALA_H
#define UNITATEMEDICALA_H

#include <string>

class UnitateMedicala {
private:
    // SINGLETON
    static UnitateMedicala* instanta;
    UnitateMedicala();  // constructor privat

    std::string nume = "Spitalul Clinic Universitar";
    std::string cod = "SCU-2025";
    std::string oras = "Bucuresti";
    int nr_paturi_total = 240;
    int nr_paturi_disponibile = 240;
    int nr_medici_total = 40;
    int nr_medici_disponibili = 24;

public:
    // Acces global la instanta Singleton
    static UnitateMedicala* getInstanta();

    void afiseaza() const;

    // Gett (doar asa am acces la aceste variabile)
    const std::string& getNume() const;
    const std::string& getCod() const;
    const std::string& getOras() const;
    int getNrPaturiTotale() const;
    int getNrPaturiDisponibile() const;
    int getNrMediciTotali() const;
    int getNrMediciDisponibili() const;

    // Functii alocate Dinamic
    void ocupaPat();
    void elibereazaPat();
    void ocupaMedic();
    void elibereazaMedic();
};

#endif