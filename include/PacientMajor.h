#ifndef PACIENTMAJOR_H
#define PACIENTMAJOR_H

#include "Pacient.h"
#include "StareDonator.h"

class PacientMajor : public Pacient {
private:
    StareDonare* stare_donare = nullptr;

public:
    PacientMajor(const std::string& nume,
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
                 const std::string& asigurare);

    void procesareSpeciala() const override;  // donare sange

    void setStareDonare(StareDonare* stare);
    void afiseazaStareDonare() const;

    ~PacientMajor();
};

#endif