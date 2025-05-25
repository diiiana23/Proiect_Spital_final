#include "Pacient.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>    // generarea de nume aleatorii
#include <ctime>      // la diagnostic schimbat mereu
#include <string>
#include <algorithm>

Pacient::Pacient( const std::string& nume,
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
                  const std::string& asigurare
                )
    : Persoana(nume, prenume, CNP, sex, varsta, data_nasterii,
        localitate, sector, cetatenie,
        ocupatie, nivel_instruire),
    grupa_sanguina(grupa_sanguina), RH(RH),
    alergii(alergii),
    asigurare(asigurare),                                  // dat de la tastatura
    diagnostic_principal(""), diagnostic_secundar("")      // sir gol momentan
{}

// Gett
const std::string& Pacient::getGrupaSanguina() const
{
    return grupa_sanguina;
}

const std::string& Pacient::getRH() const
{
    return RH;
}

const std::string& Pacient::getAlergii() const
{
    return alergii;
}

const std::string& Pacient::getAsigurare() const
{
    return asigurare;
}

const std::string& Pacient::getDiagnosticPrincipal() const
{
    return diagnostic_principal;
}

const std::string& Pacient::getDiagnosticSecundar() const
{
    return diagnostic_secundar;
}

// Functii
bool Pacient::compatibilitateOras (const std::string& orasSpital) const
{
    std::string orasPacient = getLocalitate();
    std::string orasSpital_cop = orasSpital;
    orasPacient[0] = std::toupper(orasPacient[0]);
    orasSpital_cop[0] = std::toupper(orasSpital_cop[0]);
    if (orasPacient == orasSpital_cop)
      return true;
    return false;
}

bool Pacient::esteAsigurat() const
{
    std::string asigurare_cop = asigurare;
    std::transform(asigurare_cop.begin(), asigurare_cop.end(), asigurare_cop.begin(), ::tolower);
    if (asigurare_cop == "da")
        return true;
    return false;
}

bool Pacient::esteMinor() const
{
    if (getVarsta() < 18)
      return true;
    return false;
}

void Pacient::genereazaDiagnostic()
{
    std::vector <std::string> principal =
    {
        "Infectie respiratorie acuta",
        "Gastroenterita",
        "Fractura membru superior",
        "Boli si tulburari ale sistemului nervos",
        "Hipertensiune arteriala",
        "Apendicita acuta",
        "Pneumonie",
        "Meningita virala",
        "Criza de astm bronsic",
        "Diabet zaharat dezechilibrat",
        "Accident vascular ischemic",
        "Angina pectorala",
        "Infectiile acute majore ale ochiului",
        "Covid-19",
        "Laringotraheita"
    };
    std::vector <std::string> secundar =
    {
        "Anemie feripriva",
        "Alergie sezoniera",
        "Oboseala cronica",
        "Durere lombara",
        "Migrena",
        "Hipocalcemie",
        "Hipotiroidism",
        "Otita medie",
        "Boala de reflux gastroesofagian",
        "Infectie urinara",
        "Insomnie",
        "Tulburari de ritm cardiac",
        "Dermatita atopica",
        "Sinuzita",
        "Deficit de vitamina D"
    };
    std::srand(std::time(nullptr));     // la fiecare sec de rulare da altceva
    diagnostic_principal = principal[std::rand() % principal.size()];
    diagnostic_secundar = secundar[std::rand() % secundar.size()];
}

int Pacient::gradProblema() const
{
    if (diagnostic_principal == "Infectie respiratorie acuta" ||
        diagnostic_principal == "Gastroenterita" ||
        diagnostic_principal == "Laringotraheita" ||
        diagnostic_principal == "Alergie sezoniera")
        return 1;
    else if (diagnostic_principal == "Fractura membru superior" ||
        diagnostic_principal == "Covid-19" ||
        diagnostic_principal == "Oboseala cronica" ||
        diagnostic_principal == "Anemie")
        return 2;
    else if (diagnostic_principal == "Hipertensiune arteriala" ||
        diagnostic_principal == "Criza de astm bronsic" ||
        diagnostic_principal == "Pneumonie" ||
        diagnostic_principal == "Migrena severa")
        return 3;
    else if (diagnostic_principal == "Diabet zaharat dezechilibrat" ||
        diagnostic_principal == "Boli si tulburari ale sistemului nervos" ||
        diagnostic_principal == "Angina pectorala" ||
        diagnostic_principal == "Infectiile acute majore ale ochiului")
        return 4;
    else if (diagnostic_principal == "Apendicita acuta" ||
        diagnostic_principal == "Meningita virala" ||
        diagnostic_principal == "Accident vascular ischemic")
        return 5;
    else
        return 0;
}

std::string Pacient::tipMedic() const
{
    int grad = gradProblema();
    if (grad == 1)
        return "Rezident";
    if (grad == 2 || grad == 3)
        return "Specialist";
    return "Primar";
}

//Functia de AFISARE
void Pacient::afiseaza() const
{
    std::cout << "     - INFORMATII PACIENT -     \n";
    std::cout << "Nume complet: " << getNume() <<" "<< getPrenume() << "\n";
    std::cout << "Sex: " << getSex() << "\n";
    std::cout << "Data nasterii: " << getDataNasterii() << "\n";
    std::cout << "Varsta: " << getVarsta() << "\n";
    if (esteMinor() == true)
        std::cout << "     Este minor: DA \n";
    else
        std::cout << "     Este minor: NU \n";
    std::cout << "CNP: " << getCNP() << "\n";
    std::cout << "Cetatenie: " << getCetatenie() << "\n";
    std::cout << "Ocupatie: " << getOcupatie() << "\n";
    std::cout << "Nivel instruire: " << getNivelInstruire() << "\n";
    std::cout << "Domiciliul legal: \n     Localitate: " << getLocalitate() << "\n";
    std::cout << "     Sector: " << getSector() <<"\n";
    std::cout << "\n";
    std::cout << "Grupa sangvina: " << getGrupaSanguina() << "\n";
    std::cout << "RH: " << getRH() << "\n";
    std::cout << "Alergii: " << getAlergii() << "\n";
    std::cout << "\n";
    std::cout << "Asigurat: " << getAsigurare() << "\n";
    std::cout << "\n";
    std::cout << "Diagnostice: \n     - Principal: " << getDiagnosticPrincipal() << "\n";
    std::cout << "     - Secundar: " << getDiagnosticSecundar() << "\n";
    std::cout << "\n";
}


// fct de salvare in fisier
void Pacient::salveazaInFisier() const
{
    std::ifstream in("pacienti_inregistrati.txt");
    std::string linie;

    // verific daca am acelasi CNP in fisier cu cel citit curent
    while (std::getline(in, linie))
    {
        std::istringstream format(linie);
        std::string numeF, prenumeF, cnp_fisier;

        std::getline(format, numeF, ',');
        std::getline(format, prenumeF, ',');
        std::getline(format, cnp_fisier, ',');

        if (cnp_fisier == this->getCNP())
        {
            std::cout << "Pacientul cu CNP-ul " << cnp_fisier << " este deja inregistrat. \n";
            return;
        }
    }
    in.close();

    // daca e pacient nou, il adaug
    std::ofstream out("pacienti_inregistrati.txt", std::ios::app);
    out << getNume() <<" "<< getPrenume() <<" - "<< getCNP() << "\n";
    out.close();

    std::cout << "Pacientul a fost salvat cu succes în fisier. \n";
    std::cout << "\n";
}

