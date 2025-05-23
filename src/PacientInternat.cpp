#include "UnitateMedicala.h"
#include "Doctor.h"
#include "PacientInternat.h"
#include "ListaDoctori.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

PacientInternat::PacientInternat(const std::string& nume,
                                 const std::string& prenume,
                                 const std::string& diagnostic,
                                 const std::string& localitate,
                                 const std::string& cod_doctor,
                                 int zile_ramase)
    : nume(nume), prenume(prenume), diagnostic(diagnostic),
      localitate(localitate), cod_doctor(cod_doctor), zile_ramase(zile_ramase)
{}


//Gett
const std::string& PacientInternat::getNume() const
{
    return nume;
}

const std::string& PacientInternat::getPrenume() const
{
    return prenume;
}

const std::string& PacientInternat::getDiagnostic() const
{
    return diagnostic;
}

const std::string& PacientInternat::getLocalitate() const
{
    return localitate;
}

const std::string& PacientInternat::getCodDoctor() const
{
    return cod_doctor;
}

int PacientInternat::getZileRamase() const
{
    return zile_ramase;
}

// adaug pacientul nou in fisier si il salvez acolo
void PacientInternat::salveazaInFisier() const
{
    std::ofstream out("internari.txt", std::ios::app);   //nu sterg ce e in fisier, scriu la final
    out << nume <<","<< prenume <<","<< localitate << ",";
    out << diagnostic << "," << cod_doctor << "," << zile_ramase << "\n";

    out.close();
}

// creez vectorul cu pacientii din fisier
std::vector<PacientInternat> PacientInternat::citescPacient_fisier()
{
    std::vector<PacientInternat> lista;
    std::ifstream in("internari.txt");

    std::string linie;
    while (std::getline(in, linie))
    {
        std::istringstream input(linie);
        std::string nume, prenume, localitate, diagnostic, cod_doctor;
        int zile_ramase;

        std::getline(input, nume, ',');
        std::getline(input, prenume, ',');
        std::getline(input, localitate, ',');
        std::getline(input, diagnostic, ',');
        std::getline(input, cod_doctor, ',');
        input >> zile_ramase;

        lista.emplace_back(nume, prenume, diagnostic, localitate, cod_doctor, zile_ramase);
    }
    return lista;
}

// salvez fisierul dupa modificari
void PacientInternat::salvez_Internari(const std::vector<PacientInternat>& lista)
{
    std::ofstream out("internari.txt");       //rescriere, sterge ce e deja acolo

    for (const auto& p : lista) {
        out << p.nume <<","<< p.prenume <<","<< p.localitate <<",";
        out<< p.diagnostic <<","<< p.cod_doctor <<","<< p.zile_ramase << "\n";
    }
}

// mut pacientul la VINDECATi
void PacientInternat::salvez_Vindecati(const PacientInternat& p)
{
    std::ofstream out("vindecati.txt", std::ios::app);    //append (nu sterg ce e acolo)

    out << p.nume <<","<< p.prenume <<","<< p.localitate <<",";
    out<< p.diagnostic <<","<< p.cod_doctor <<","<< p.zile_ramase << "\n";
}


// functie de actualizare (internari, vindecati, zile_ramase, disponibilitate, pat)
void PacientInternat::actualizare_Internari(std::vector<Doctor>& doctori, UnitateMedicala& spital)
{
    std::vector<PacientInternat> internati = PacientInternat::citescPacient_fisier();   //creez vectorul
    std::vector<PacientInternat> raman;       //pacientii care tb sa ramana internati in continuare

    for (auto& p : internati)
    {
        if (p.zile_ramase > 0)
            p.zile_ramase--;
        if (p.zile_ramase == 0)        // salvam in vindecati si il stergem din internati
        {
            salvez_Vindecati(p);
            std::cout << "Pacient vindecat cu succes: " << p.nume << " " << p.prenume << "\n";
            std::cout << "\n";

            for (Doctor& d : doctori)
                if (p.cod_doctor == d.getCodOficial())
                {
                    d.setDisponibil(true);
                    spital.elibereazaMedic();     // din UnitateMedicala.cpp
                    break;                     //am gasit medicul care il trata
                }
            spital.elibereazaPat();            // din UnitateMedicala.cpp
        }
        else
            raman.push_back(p);
    }
    PacientInternat::salvez_Internari(raman);        // rescriu internari.txt
    ListaDoctori::salvez_fisier(doctori);             // salvez fisierul doctori.txt (ListaDoctori.cpp)
}
