#ifndef PACIENTMINOR_H
#define PACIENTMINOR_H

#include "Pacient.h"

class PacientMinor : public Pacient {
public:
    PacientMinor(const std::string& nume,
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

    void procesareSpeciala() override;  // acord parinte
};

#endif