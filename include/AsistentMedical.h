#ifndef ASISTDMEDICAL_H
#define ASISTDMEDICAL_H

#include "Persoana.h"
#include <string>

class AsistentMedical : public Persoana {
private:
    int ani_experienta;
    int ani_de_angajare;
    std::string specializare;
    int nr_consultatii = 0;
    double review = 0.0;

public:
    // Constructor complet
    AsistentMedical(const std::string& nume,
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
           int ani_experienta,
           int ani_de_angajare,
           const std::string& specializare,
           int nr_consultatii,
           double review
         );

    // Destructor virtual
    ~AsistentMedical() override =  default;

    // Suprascrierea functiei virtuale de AFISARE din Persoana
    void afiseaza() const override;

    // Gettere
    int getAniExperienta() const;
    int getAniDeAngajare() const;
    const std::string& getSpecializare() const;
    int getNrConsultatii() const;
    double getReview() const;

    void nou_Review(int nota);
};

#endif
