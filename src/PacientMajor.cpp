#include "PacientMajor.h"
#include "StareDonator.h"

#include <iostream>
#include <sstream>
#include <fstream>

PacientMajor::PacientMajor(const std::string& nume,
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
                           const std::string& asigurare)
    : Pacient(nume, prenume, CNP, sex, varsta, data_nasterii,
        localitate, sector, cetatenie, ocupatie, nivel_instruire,
        grupa_sanguina, RH, alergii, asigurare)
{}

void PacientMajor::setStareDonare(StareDonare* stare)    // verific daca e deja o stare alocata ( sa nu fie nullptr)
{
    if (stare_donare)
        delete stare_donare;
    stare_donare = stare;
}

void PacientMajor::afiseazaStareDonare() const
{
    if (stare_donare)   // daca am stare alocata
        stare_donare->afiseazaStare();
}

PacientMajor::~PacientMajor()
{
    delete stare_donare;
}


void PacientMajor::procesareSpeciala()
{
    std::string raspuns;
    std::cout << "Doriti sa donati sange? (DA/NU): ";
    std::cin >> raspuns;
    std::cout << "\n";

    // PacientMajor* self = const_cast<PacientMajor*>(this);  // pentru a modifica membrii non-const

    if (raspuns == "DA" || raspuns == "da")
    {
        this->setStareDonare(new ADonat());

        std::ofstream fout("donatori.txt", std::ios::app);
        fout << this->getNume() <<", "<< this->getPrenume() <<", "<< this->getVarsta() <<", "<< this->getGrupaSanguina() << "\n";
        fout.close();
    }
    else
    {
        this->setStareDonare(new NuADonat());
    }
    std::cout << "\n";
    this->afiseazaStareDonare();
}