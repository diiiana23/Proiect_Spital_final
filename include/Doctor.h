#ifndef DOCTOR_H
#define DOCTOR_H

#include "Persoana.h"
#include <string>

class Doctor : public Persoana {
private:
    std::string specializare;
    std::string cod_oficial;         // codul de identificare
    std::string grad_profesional;     // Rezident / Specialist / Primar
    std::string sectie;             // sectia spitalului unde lucreaza
    int ani_experienta;             // pentru Specialist / Primar
    int an_rezidentiat;             // pentru Rezident
    bool disponibil = true;    //initial, toti doctorii sunt disponibili

public:
    // Constructor complet
    Doctor(const std::string& nume,
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
           const std::string& specializare,
           const std::string& cod_oficial,
           const std::string& grad_profesional,
           const std::string& sectie,
           int ani_experienta,
           int an_rezidentiat,
           bool disponibil
         );

    // Destructor virtual
    ~Doctor() override =  default;

    // Suprascrierea functiei virtuale de AFISARE din Persoana
    void afiseaza() const override;

    // Gettere
    const std::string& getSpecializare() const;
    const std::string& getCodOficial() const;
    const std::string& getGradProfesional() const;
    const std::string& getSectie() const;
    int getAniExperienta() const;
    int getAnRezidentiat() const;

    bool esteDisponibil() const;        //verific daca doctorul e sau nu disponibil
    void setDisponibil(bool disponibilNou);      //modific starea doctorului
    std::string descriereExperienta() const;

    // OPERATORI SUPRESCRISI
    friend std::ostream& operator<<(std::ostream& out, const Doctor& d);     // << pt afisare
    bool operator==(const Doctor& other) const;                              // == pt cnp egal
};

#endif