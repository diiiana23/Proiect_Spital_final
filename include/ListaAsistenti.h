#ifndef LISTAASISTENTI_H
#define LISTAASISTENTI_H

#include "AsistentMedical.h"
#include <iostream>
#include <string>
#include <vector>

class ListaAsistenti {
public:
    // citesc asistentii
    static std::vector<AsistentMedical> creeazaAsistenti();

    // creeaza un obiect AsistentMedical pentru fiecare linie din fisier (ii pune in vector pe toti)
    static std::vector<AsistentMedical> citesteA_fisier();

    // salvez lista de asistenti in fisier
    static void salvezA_fisier(const std::vector<AsistentMedical>& lista);

    // Afișarea (virtuala; mostenita din Persoana)
    static void afiseazaAsistenti(const std::vector<AsistentMedical>& lista);

    // Filtrez (in funcție de diagnostic) - ii elimina pe restul
    static std::vector<AsistentMedical> filtreazaDupaDiagnostic(const std::vector<AsistentMedical>& lista, const std::string& diagnostic);

    // Sortare dupa: review, ani_experienta, ani_angajare (il dau eu de la tastatura)
    static void sorteazaAsistenti(std::vector<AsistentMedical>& lista, const std::string& criteriu);

    static void adaugaReview(AsistentMedical& asistent, int nota);
};

#endif