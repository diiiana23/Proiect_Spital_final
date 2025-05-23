#ifndef CONSULTATIE_H
#define CONSULTATIE_H

#include "Pacient.h"
#include "Doctor.h"
#include <iostream>
#include <string>

class Consultatie {
private:
    static int nr_consultatii;

    std::string spital;
    std::string nume_pacient;
    std::string prenume_pacient;
    int varsta_pacient;
    std::string diagnostic;

    std::string nume_doctor;
    std::string prenume_doctor;
    std::string specializare;
    std::string cod_oficial;

public:
    Consultatie(const std::string& spital,
                const Pacient& pacient,
                const Doctor& doctor);

    static int getNrConsultatii();
    static void setNrConsultatii(int val);
    static int citesteConsultatii_fisier();

    //OPERATORI
    Consultatie& operator+=(int); // crește nr consultatii   ( += membru)

    friend Consultatie operator+(const Pacient& p, const Doctor& d); // (+ non-membru)

    friend std::ostream& operator<<(std::ostream& out, const Consultatie& c);  // (<<)
};

#endif