#include "Persoana.h"
#include "Exceptii.h"
#include <iostream>
#include <cctype>      // verific daca e cifra
#include <algorithm>     // std::all_of ( ) - verifica toate elem dintr-un interval cu o CONDITIE
#include <stdexcept>
#include <regex>       // verific un anumit format

// Constructor
Persoana::Persoana( const std::string& nume,
                    const std::string& prenume,
                    const std::string& CNP,
                    char sex,
                    int varsta,
                    const std::string& data_nasterii,
                    const std::string& localitate,
                    int sector,
                    const std::string& cetatenie,
                    const std::string& ocupatie,
                    const std::string& nivel_instruire
                   )
    : nume(nume), prenume(prenume), CNP(CNP), sex(sex), varsta(varsta), data_nasterii(data_nasterii),
      localitate(localitate), sector(sector), cetatenie(cetatenie),
      ocupatie(ocupatie), nivel_instruire(nivel_instruire)            // am initializat atributele
{}

// Gett
const std::string& Persoana::getNume() const
{
    return nume;
}

const std::string& Persoana::getPrenume() const
{
    return prenume;
}

const std::string& Persoana::getCNP() const
{
    return CNP;
}

char Persoana::getSex() const
{
    return sex;
}

int Persoana::getVarsta() const
{
    return varsta;
}

const std::string& Persoana::getDataNasterii() const
{
    return data_nasterii;
}

const std::string& Persoana::getLocalitate() const
{
    return localitate;
}

int Persoana::getSector() const
{
    return sector;
}

const std::string& Persoana::getCetatenie() const
{
    return cetatenie;
}

const std::string& Persoana::getOcupatie() const
{
    return ocupatie;
}

const std::string& Persoana::getNivelInstruire() const
{
    return nivel_instruire;
}

// Validari format
void Persoana::validCNP() const
{
    if (CNP.size() != 13 || std::all_of(CNP.begin(), CNP.end(), ::isdigit) == false)
        throw ExceptiePersoana("CNP invalid: trebuie sa contina exact 13 cifre.");
}

void Persoana::validSex() const
{
    if (sex != 'M' && sex != 'F')
        throw ExceptiePersoana("Sex invalid: trebuie sa fie 'M' sau 'F'.");
}

void Persoana::validDataNasterii() const
{
    std::regex format(R"(\d{2}\.\d{2}\.\d{4})");
    if (!std::regex_match(data_nasterii, format))
        throw ExceptiePersoana("Data nasterii invalida: formatul trebuie sa fie dd.mm.yyyy.");
}

void Persoana::validSector() const
{
    if (sector < 1 || sector > 6)
        throw ExceptiePersoana("Sector invalid: trebuie sa fie intre 1 si 6.");
}


// fct de verif ac. persoana - ma ajuta cand actualizez fisierul de pacienti inregistrati
bool operator==(const Persoana& p1, const Persoana& p2)
{
    return p1.getCNP() == p2.getCNP();
}