#ifndef PACIENTINTERNAT_H
#define PACIENTINTERNAT_H

#include <iostream>
#include <string>
#include <vector>
#include "UnitateMedicala.h"
#include "Doctor.h"

class PacientInternat {
private:
    std::string nume;
    std::string prenume;
    std::string diagnostic;
    std::string localitate;
    std::string cod_doctor;
    int zile_ramase;

public:
    // Constructori
    //PacientInternat() = default;
    PacientInternat() : zile_ramase(0) {}

    PacientInternat(const std::string& nume,
                    const std::string& prenume,
                    const std::string& diagnostic,
                    const std::string& localitate,
                    const std::string& cod_doctor,
                    int zile_ramase = 0);

    // Gett
    const std::string& getNume() const;
    const std::string& getPrenume() const;
    const std::string& getDiagnostic() const;
    const std::string& getLocalitate() const;
    const std::string& getCodDoctor() const;
    int getZileRamase() const;

    void salveazaInFisier() const;
    static std::vector<PacientInternat> citescPacient_fisier();
    static void salvez_Internari(const std::vector<PacientInternat>& lista);
    static void salvez_Vindecati(const PacientInternat& p);
    static void actualizare_Internari(std::vector<Doctor>& doctori, UnitateMedicala& spital);
};

#endif