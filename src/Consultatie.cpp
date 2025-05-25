#include "Consultatie.h"
#include "Pacient.h"
#include "Doctor.h"
#include <fstream>

// Initializare statica din fisier
int Consultatie::nr_consultatii = Consultatie::citesteConsultatii_fisier();

// Constructor
Consultatie::Consultatie(const std::string& spital,
                         const Pacient& pacient,
                         const Doctor& doctor)
    : spital(spital),
      nume_pacient(pacient.getNume()), prenume_pacient(pacient.getPrenume()),
      varsta_pacient(pacient.getVarsta()), diagnostic(pacient.getDiagnosticPrincipal()),
      nume_doctor(doctor.getNume()), prenume_doctor(doctor.getPrenume()),
      specializare(doctor.getSpecializare()), cod_oficial(doctor.getCodOficial())
{
    nr_consultatii++;
    setNrConsultatii(nr_consultatii);    //am actualizat fisierul
}

// Gett
int Consultatie::getNrConsultatii()
{
    return nr_consultatii;
}

void Consultatie::setNrConsultatii(int val)
{
    nr_consultatii = val;
    std::ofstream fout("consultatii.txt");
    fout << val;
    fout.close();
}

// Citire din fisier
int Consultatie::citesteConsultatii_fisier() {
    std::ifstream fin("consultatii.txt");
    int nr = 0;
    if (fin >> nr)
        return nr;
    return 0;
}

// op += MEMBRU
Consultatie& Consultatie::operator+=(int nr)
{
    nr_consultatii += nr;
    setNrConsultatii(nr_consultatii);  // actualizez si fișierul
    return *this;
}

// op + NON-MEMBRU
Consultatie operator+(const Pacient& p, const Doctor& d)
{
    //return Consultatie("Spitalul Clinic Universitar", p, d);
    return {"Spitalul Clinic Universitar", p, d};
}

// op << AFISARE
std::ostream& operator<<(std::ostream& out, const Consultatie& c)
{
    out << "     - CONSULTATIE -     \n";
    out << "Spital: " << c.spital << "\n";
    out << "Date pacient: " << c.nume_pacient <<" "<< c.prenume_pacient;
    out << "   Varsta: " << c.varsta_pacient << "\n";
    out << "   Diagnosticul acordat: " << c.diagnostic << "\n";
    out << "Doctor: " << c.nume_doctor <<" "<< c.prenume_doctor;
    out << "   Specializarea: " << c.specializare << "\n";
    out << "   Cod oficial: " << c.cod_oficial << "\n";
    out << "\n";

    return out;
}