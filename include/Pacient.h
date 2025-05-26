#ifndef PACIENT_H
#define PACIENT_H

#include "Persoana.h"
#include <iostream>
#include <string>
#include <exception>

class Pacient : public Persoana {
protected:
    std::string grupa_sanguina;
    std::string RH;
    std::string alergii;
    std::string asigurare;
    std::string diagnostic_principal;      // generate automat, deci nu tb sa se afle in constructor
    std::string diagnostic_secundar;

public:
    // Constructor - fara diagnostic
    Pacient(const std::string& nume,
            const std::string& prenume,
            const std::string& CNP,
            char sex,
            int varsta,
            const std::string& data_nasterii,
            const std::string& localitate,
            int sector,
            const std::string& cetatenie,
            const std::string& ocupatie,
            const std::string& nivel_instruire,
            const std::string& grupa_sanguina,
            const std::string& RH,
            const std::string& alergii,
            const std::string& asigurare
          );

    // Constructor de copiere
    Pacient(const Pacient& other);

    // Operator= de copiere
    Pacient& operator=(const Pacient& other);

    // Destructor virtual
    ~Pacient() override = default;

    // Suprascrierea functiei virtuale de AFISARE din Persoana
    void afiseaza() const override;

    // Gettere
    const std::string& getGrupaSanguina() const;
    const std::string& getRH() const;
    const std::string& getAlergii() const;
    const std::string& getAsigurare() const;
    const std::string& getDiagnosticPrincipal() const;
    const std::string& getDiagnosticSecundar() const;

    bool compatibilitateOras(const std::string& orasSpital) const;    // oras pacient = oras spital
    bool esteAsigurat() const;
    bool esteMinor() const;

    void genereazaDiagnostic();          // generez AUTOMAT de diagnostic
    virtual int gradProblema() const;            // 1 (rezident), 2/3 (specialist), 4/5 (primar)
    std::string tipMedic() const;        // rezident, specialist, primar

    virtual void procesareSpeciala() = 0;  //clasa devine abstracta

    void salveazaInFisier() const;     // salvez pacientii in "pacienti_inregistrati.txt"
};

#endif