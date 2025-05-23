#include "Doctor.h"
#include <iostream>

// Constructor
Doctor::Doctor(const std::string& nume,
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
               )
    : Persoana(nume, prenume, CNP, sex, varsta, data_nasterii,
           localitate, sector, cetatenie,
           ocupatie, nivel_instruire),
    specializare(specializare), cod_oficial(cod_oficial),
    grad_profesional(grad_profesional), sectie(sectie),
    ani_experienta(ani_experienta), an_rezidentiat(an_rezidentiat),
    disponibil(disponibil)
{}

// Gett
const std::string& Doctor::getSpecializare() const
{
    return specializare;
}

const std::string& Doctor::getCodOficial() const
{
    return cod_oficial;
}

const std::string& Doctor::getGradProfesional() const
{
    return grad_profesional;
}

const std::string& Doctor::getSectie() const
{
    return sectie;
}

int Doctor::getAniExperienta() const
{
    return ani_experienta;
}

int Doctor::getAnRezidentiat() const
{
    return an_rezidentiat;
}

bool Doctor::esteDisponibil() const
{
    return disponibil;
}

void Doctor::setDisponibil(bool disponibilNou)         // doar aici pot MODIFICA starea doctorului
{
    disponibil = disponibilNou;
}

std::string Doctor::descriereExperienta() const
{
    if (grad_profesional == "Rezident")
        return "Anul " + std::to_string(an_rezidentiat) + " de rezidentiat";
    return std::to_string(ani_experienta) + " ani experienta";
}

//Functie AFISARE
void Doctor::afiseaza() const
{
    std::cout << "     - INFORMATII DOCTOR -     \n";
    std::cout << "Nume complet: " << getNume() <<" "<< getPrenume() << "\n";
    std::cout << "Sex: " << getSex() << "\n";
    std::cout << "Varsta: " << getVarsta() << "\n";
    std::cout << "Specializare: " << getSpecializare() << "\n";
    std::cout << "Grad profesional:  " << getGradProfesional() << "\n";
    if (getGradProfesional() == "Rezident")
        std::cout << "Anul: " << getAnRezidentiat() << "\n";
    else
        std::cout << "Ani experienta: " << getAniExperienta() << "\n";
    std::cout << "\n";
    std::cout << "Cod oficial: " << getCodOficial() << "\n";
    std::cout << "Sectie: " << getSectie() <<"\n";
    std::cout << "\n";
}

//operator suprascris <<    (scriu: out << doctor si merge)
std::ostream& operator<<(std::ostream& os, const Doctor& d)
{
    os << d.getNume() <<","<< d.getPrenume() <<","<< d.getCNP() <<","<< d.getSex() <<","
       << d.getVarsta() <<","<< d.getDataNasterii() <<","
       << d.getLocalitate() <<","<< d.getSector() <<","<< d.getCetatenie() <<","
       << d.getOcupatie() <<","<< d.getNivelInstruire() <<","<< d.getSpecializare() <<","
       << d.getCodOficial() <<","<< d.getGradProfesional() <<","<< d.getSectie() <<","
       << d.getAniExperienta() <<","<< d.getAnRezidentiat() <<","
       << (d.esteDisponibil() ? "disponibil" : "indisponibil");

    return os;
}

//operator suprascris ==    (cnp + varsta>= : doctori)
bool Doctor::operator==(const Doctor& other) const
{
    return (this->getCNP() == other.getCNP()) && (this->getVarsta() >= varsta);
}