#include "UnitateMedicala.h"
#include <iostream>
#include <fstream>

// Inițializez pointer static la SINGLETON
UnitateMedicala* UnitateMedicala::instanta = nullptr;

// Constructor privat — il pot apela doar din getInstanta()
UnitateMedicala::UnitateMedicala() = default;

//SINGLETON: intoarce instanta unica
UnitateMedicala* UnitateMedicala::getInstanta()
{
    if (instanta == nullptr)
        instanta = new UnitateMedicala();
    return instanta;
}

// Gett
const std::string& UnitateMedicala::getNume() const
{
    return nume;
}

const std::string& UnitateMedicala::getCod() const
{
    return cod;
}

const std::string& UnitateMedicala::getOras() const
{
    return oras;
}

int UnitateMedicala::getNrPaturiTotale() const
{
    return nr_paturi_total;
}

int UnitateMedicala::getNrPaturiDisponibile() const
{
    return nr_paturi_disponibile;
}

int UnitateMedicala::getNrMediciTotali() const
{
    return nr_medici_total;
}

int UnitateMedicala::getNrMediciDisponibili() const
{
    return nr_medici_disponibili;
}

// fisier pt datele pe care vreau sa le salvez dinamic
void UnitateMedicala::salvez_Fisier() const
{
    std::ofstream out("unitate_medicala.txt");
    if (!out)
    {
        std::cerr << "Eroare la deschiderea fisierului pentru actualizarea datelor medicale.\n";
        return;
    }
    out << nr_paturi_disponibile << "\n";
    out << nr_medici_disponibili << "\n";
    out.close();
}

void UnitateMedicala::incarc_Fisier()
{
    std::ifstream in("unitate_medicala.txt");
    if (!in)
    {
        std::cerr << "Fisierul unitate_medicala.txt nu a fost gasit. Se folosesc valorile implicite.\n";
        return;
    }
    in >> nr_paturi_disponibile;
    in >> nr_medici_disponibili;
    in.close();
}

// Actualizez paturi
void UnitateMedicala::ocupaPat()
{
    if(nr_paturi_disponibile > 0)
        nr_paturi_disponibile--;        //daca mai e vreun pat disponibil, ocup
}

void UnitateMedicala::elibereazaPat()
{
    if(nr_paturi_disponibile < nr_paturi_total)
        nr_paturi_disponibile++;        //eliberam patul (daca nu am trecut de maxim)
}

// Actualizez medici
void UnitateMedicala::ocupaMedic()
{
    if(nr_medici_disponibili > 0)
        nr_medici_disponibili--;
}

void UnitateMedicala::elibereazaMedic()
{
    if(nr_medici_disponibili < nr_medici_total)
        nr_medici_disponibili++;
}

//Functia de AFISARE
void UnitateMedicala::afiseaza() const
{
    std::cout << "     - UNITATE MEDICALA -     \n";
    std::cout << "Nume: " << nume << "\n";
    std::cout << "Cod: " << cod << "\n";
    std::cout << "Oras: " << oras << "\n";
    std::cout << "Capacitate: " << nr_paturi_total << "\n";
    std::cout << "Capacitate disponibila: " << nr_paturi_disponibile << "\n";
    std::cout << "Personal medical: " << nr_medici_total << "\n";
    std::cout << "Personal medical disponibil: " << nr_medici_disponibili << "\n";
    std::cout << "\n";
}