#include "PacientMinor.h"
#include <iostream>

PacientMinor::PacientMinor(const std::string& nume,
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

void PacientMinor::procesareSpeciala()
{
    std::string acord;
    std::cout << "Este necesar acordul unui parinte/tutore pentru continuarea tratamentului. \n";
    std::cout << "Introduceti acordul (DA/NU): ";
    std::cin >> acord;
    std::cout << "\n";

    if (acord == "DA" || acord == "da")
    {
        std::cout << "Ne bucuram ca ati ales sa continuati alaturi de echipa noastra medicala! \n";
        std::cout << "Ne vom da silinta pentru obtinerea celui mai bun rezultat. \n";
        std::cout << "\n";
    }
    else
    {
        std::cout << "Ne pare rau ca ati ales să nu continuați. \n";
        std::cout << "Va dorim multa sanatate si o insanatosire grabnica! \n";
    }
}

