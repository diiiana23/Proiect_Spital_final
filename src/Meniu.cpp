#include "Meniu.h"
#include "AfisareInformatii.h"
#include "Consultatie.h"
#include "Exceptii.h"
#include "FunctiiAjutatoare.h"
#include "ListaDoctori.h"
#include "PacientInternat.h"
#include "AsistentMedical.h"
#include "ListaAsistenti.h"
#include "Doctor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

void Meniu::afisez_PacientiInregistrati()
{
    std::ifstream in("pacienti_inregistrati.txt");
    std::string linie;

    std::cout << "     PACIENTI INREGISTRATI     \n";
    while (std::getline(in, linie)) {
        std::cout << linie << "\n";
    }
    std::cout << "\n";
    in.close();
}

void Meniu::afisez_Vindecati()
{
    std::ifstream in("vindecati.txt");
    std::string linie;

    std::cout << "     PACIENTI VINDECATI     \n";
    while (std::getline(in, linie)) {
        std::cout << linie << "\n";
    }
    std::cout << "\n";
    in.close();
}

void Meniu::afisez_Internati()
{
    std::vector<PacientInternat> lista = PacientInternat::citescPacient_fisier();

    std::cout << "     PACIENTI INTERNATI     \n";
    for (const auto& p : lista)
    {
        std::cout << FunctiiAjutatoare::trim(p.getNume()) <<"  "<< FunctiiAjutatoare::trim(p.getPrenume()) <<", ";
        std::cout << FunctiiAjutatoare::trim(p.getDiagnostic()) << "; ";
        std::cout << "tratat de: " << FunctiiAjutatoare::trim(p.getCodDoctor()) <<", cu"<< p.getZileRamase() << " zile ramase\n";
    }
    std::cout << "\n";
}

void Meniu::afisez_DoctoriDisponibili()
{
    std::vector<Doctor> doctori = ListaDoctori::citire_fisier();

    std::cout << "     DOCTORI DISPONIBILI     \n";
    // folosec TEMPLATE
    AfisareInformatii<Doctor> info_Doctori;

    for (const auto& doc : doctori)
        if (doc.esteDisponibil())
            info_Doctori.adauga(doc);

    info_Doctori.afiseaza();

    std::cout << "\n";
}

void Meniu::afisez_AsistentiMedicali()
{
    std::vector<AsistentMedical> asistenti = ListaAsistenti::citesteA_fisier();

    std::cout << "     ASISTENTI MEDICALI     \n";
    //folosesc TEMPLATE
    AfisareInformatii<AsistentMedical> info_Asistenti;

    for (const auto& a : asistenti)
        info_Asistenti.adauga(a);

    info_Asistenti.afiseaza();

    std::cout << "\n";
}

void afiseazaListaDonatori()
{
    std::ifstream fin("donatori.txt");
    if (!fin.is_open())
    {
        std::cout << "Nu exista niciun donator inregistrat. \n";
        std::cout << "\n";
        return;
    }

    std::string linie;
    std::cout << "     DONATORII     \n";
    while (std::getline(fin, linie))
    {
        //std::replace(linie.begin(), linie.end(), ',', ' ');
        std::cout << linie << "\n";
    }
    std::cout << "\n";
    fin.close();
}


void Meniu::angajez_Doctor()
{
    std::string nume, prenume, cnp, data_nasterii, localitate, cetatenie, ocupatie, nivel_instruire;
    std::string specializare, cod, grad, sectie;
    char sex;
    int varsta, sector, experienta, an_rezidentiat;
    bool disponibil=true;

    std::cout << "Introduceti datele: \n";
    std::cout << "Nume: ";
    std::getline(std::cin, nume);

    std::cout << "Prenume: ";
    std::getline(std::cin, prenume);


    std::cout << "CNP: ";
    std::getline(std::cin, cnp);

    std::cout << "Sex (M/F): ";
    std::cin >> sex;
    if (sex != 'M' && sex != 'F' && sex != 'm' && sex != 'f')
    {
        throw ExceptieMeniu("Sex invalid (trebuie sa fie M sau F).");
    }
    std::cin.ignore();

    std::cout << "Varsta: ";
    std::cin >> varsta;
    if (std::cin.fail() || varsta < 18)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw ExceptieMeniu("Varsta invalida (trebuie sa fie un numar intre 18 si 100).");
    }
    std::cin.ignore();

    std::cout << "Data nasterii (dd.mm.yyyy): ";
    std::getline(std::cin, data_nasterii);

    std::cout << "Domiciliul legal: \n";
    std::cout << "    Localitate: ";
    std::getline(std::cin, localitate);
    std::cout << "    Sector: ";
    std::cin >> sector;
    if (std::cin.fail() || sector < 0 || sector > 6)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw ExceptieMeniu("Sector invalid (trebuie sa fie intre 1 si 6) ");
    }
    std::cin.ignore();

    std::cout << "Cetatenie: ";
    std::getline(std::cin, cetatenie);

    std::cout << "Ocupatie: ";
    std::getline(std::cin, ocupatie);

    std::cout << "Nivel instruire: ";
    std::getline(std::cin, nivel_instruire);

    std::cout << "Specializare: ";
    std::getline(std::cin, specializare);

    std::cout << "Cod oficial: ";
    std::getline(std::cin, cod);

    std::cout << "Grad profesional: ";
    std::getline(std::cin, grad);

    std::cout << "Sectie: ";
    std::getline(std::cin, sectie);

    std::cout << "Ani experienta: ";
    std::cin >> experienta;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw ExceptieMeniu("Invalid! (trebuie sa fie un numar)");
    }
    std::cin.ignore();

    std::cout << "An rezidentiat: ";
    std::cin >> an_rezidentiat;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw ExceptieMeniu("Invalid! (trebuie sa fie un numar)");
    }
    std::cin.ignore();

    std::cout << "\n";


    // UPCASTING (tratez obiectul ca si cand ar fi de tip Persoana)
    Persoana* p = new Doctor(nume, prenume, cnp, sex, varsta, data_nasterii,
        localitate, sector, cetatenie, ocupatie, nivel_instruire,
        specializare, cod, grad, sectie, experienta, an_rezidentiat, disponibil);

    std::ofstream out("doctori.txt", std::ios::app);        // il salvez in "doctori.txt"
    out << *dynamic_cast<Doctor*>(p) << "\n";
    out.close();

    std::cout << "Doctorul a fost angajat cu succes! \n";
    std::cout << "\n";

    delete p;
}


void Meniu::concediez_Doctor()
{
    std::cout << "Introduceti CNP-ul doctorului care trebuie concediat: ";
    std::string cnp;
    std::cin >> cnp;
    std::cout << "Introduceti varsta minima pe care doctorul trebuie sa o aiba: ";
    int varsta;
    std::cin >> varsta;
    std::cout << "\n";

    std::vector<Doctor> doctori = ListaDoctori::citire_fisier();
    bool ok = false;

    doctori.erase(std::remove_if(doctori.begin(), doctori.end(),
        [&](const Doctor& d) {
            if (d.getCNP() == cnp && d.getVarsta() > varsta) {
                ok = true;
                return true;
            }
            return false;
        }), doctori.end());

    if (ok == true){
        ListaDoctori::salvez_fisier(doctori);
        std::cout << "\n";
        std::cout << "Doctorul cu CNP-ul " << cnp << ", a fost concediat deoarece are varsta >= " << varsta <<"\n";
        std::cout << "\n";
    } else {
        std::cout << "Nu a fost gasit niciun doctor cu CNP-ul: " << cnp << "\n";
        std::cout << "\n";
    }
}


void Meniu::afisez_Meniu(UnitateMedicala& spital)
{
    std::vector<Doctor> doctori = ListaDoctori::citire_fisier();
    PacientInternat::actualizare_Internari(doctori, spital);

    while (true)
    {
        std::cout << "     MENIU PRINCIPAL     \n";
        std::cout << "Ce informatii suplimentare doriti sa aflati inainte de consultatie? \n";
        std::cout << "\n";
        std::cout << "1 Vizualizare pacienti inregistrati \n";
        std::cout << "2 Vizualizare pacienti vindecati \n";
        std::cout << "3 Vizualizare pacienti internati \n";
        std::cout << "4 Afiseaza doctorii disponibili \n";
        std::cout << "5 Afiseaza asistentii medicali \n";
        std::cout << "6 Angajeaza un doctor \n";
        std::cout << "7 Concediaza un doctor \n";
        std::cout << "8 Afiseaza lista donatorilor \n";
        std::cout << "\n";
        std::cout << "Selectati 0 daca nu doriti sa mai aflati nimic si doriti sa continuati cu programarea consultatiei. \n";
        std::cout << "Selectati optiunea: ";

        int optiune;
        std::cin >> optiune;
        if (std::cin.fail())      // daca esueaza citirea
        {
            std::cin.clear();          //resetez starea de eroare ca sa functioneze bine mai departe
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw ExceptieMeniu("Input invalid (nu este un numar).");
        }
        std::cin.ignore();
        if (optiune<0 || optiune>8)
            throw ExceptieMeniu("Optiune invalida (tb sa fie in intervalului 0-8).");

        std::cout << "\n";

        switch (optiune) {
            case 1: afisez_PacientiInregistrati();
                break;
            case 2: afisez_Vindecati();
                break;
            case 3: afisez_Internati();
                break;
            case 4: afisez_DoctoriDisponibili();
                break;
            case 5: afisez_AsistentiMedicali();
                break;
            case 6: angajez_Doctor();
                break;
            case 7: concediez_Doctor();
                break;
            case 8:
                afiseazaListaDonatori();
                break;
            case 0: return;
            default:
                std::cout << "Optiune invalida. Incercati din nou: \n";
        }
    }
}


