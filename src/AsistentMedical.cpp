#include "AsistentMedical.h"
#include <iostream>

// Constructor complet
AsistentMedical::AsistentMedical(const std::string& nume,
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
                                 double review)
    : Persoana(nume, prenume, CNP, sex, varsta, data_nasterii, localitate, sector,
               cetatenie, ocupatie, nivel_instruire),
    ani_experienta(ani_experienta),
    ani_de_angajare(ani_de_angajare),
    specializare(specializare),
    nr_consultatii(nr_consultatii), review(review)
{}

// Functie afisare
void AsistentMedical::afiseaza() const
{
    std::cout << "     - INFORMATII ASISTENT MEDICAL -     \n";
    std::cout << "Nume complet: " << getNume() <<" "<< getPrenume() << "\n";
    std::cout << "CNP: " << getCNP() << "\n";
    std::cout << "Sex: " << getSex() << "\n";
    std::cout << "Varsta: " << getVarsta() << "\n";
    std::cout << "Specializare: " << specializare << "\n";
    std::cout << "Ani experienta: " << ani_experienta << "\n";
    std::cout << "Ani de angajare: " << ani_de_angajare << "\n";
    std::cout << "Numar consultatii: " << nr_consultatii << "\n";
    std::cout << "Review actual: " << review << "\n";
    std::cout << "\n";
}

// Gett
int AsistentMedical::getAniExperienta() const
{
    return ani_experienta;
}

int AsistentMedical::getAniDeAngajare() const
{
    return ani_de_angajare;
}

std::string AsistentMedical::getSpecializare() const
{
    return specializare;
}

int AsistentMedical::getNrConsultatii() const
{
    return nr_consultatii;
}

double AsistentMedical::getReview() const
{
    return review;
}

// Functie care actualizeaza review ul  (adauga o nota noua)
void AsistentMedical::nou_Review(int nota)
{
    review = (review * nr_consultatii + nota) / (nr_consultatii + 1);
    nr_consultatii++;
}
