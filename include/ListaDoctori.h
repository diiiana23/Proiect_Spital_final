#ifndef LISTADOCTORI_H
#define LISTADOCTORI_H

#include "Doctor.h"
#include <vector>

class ListaDoctori {
public:
    static std::vector<Doctor> creeazaDoctori();   //lista initiala cu doctori

    // citesc obiectele de tip DOCTOR din fisier
    static std::vector<Doctor> citire_fisier();      // citesc datele

    // functia de salvare in fisier a vectorului
    static void salvez_fisier(const std::vector<Doctor>& lista);    // salvez datele modificate
};

#endif