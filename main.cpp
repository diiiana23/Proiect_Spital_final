#include "Meniu.h"
#include "AfisareInformatii.h"
#include "Exceptii.h"
#include "Mesaje.h"
#include "FunctiiAjutatoare.h"
#include "UnitateMedicala.h"
#include "Persoana.h"
#include "Pacient.h"
#include "PacientMinor.h"
#include "PacientMajor.h"
#include "StareDonator.h"
#include "Donator.h"
#include "PacientInternat.h"
#include "Doctor.h"
#include "ListaDoctori.h"
#include "AsistentMedical.h"
#include "ListaAsistenti.h"
#include "Consultatie.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

int main()
{
    // date SPITAL
    UnitateMedicala* spital = UnitateMedicala::getInstanta(); // SINGLETON
    spital->incarc_Fisier();
    std::cout << "\n";
    std::cout << "Bine ati venit in sistemul nostru medical! 🩺 \n";
    std::cout << "\n";
    spital->afiseaza();

    // Mesaj incurajator
    MesajePacienti::init_Mesaje();
    int nr_mes = MesajePacienti::getNrMesaje();
    std::cout << "Alegeti un numar intre 1 si " << nr_mes << " pentru a primi un mesaj incurajator 😊: ";
    int poz;
    std::cin >> poz;
    MesajePacienti::afiseaza_Mesaj(poz);


    // MENIU
    Meniu meniu;
    meniu.afisez_Meniu(*spital);    // trimit referinta, nu pointer


    // INTRODUCERE
    std::cout << "\n";
    std::cout << "Totul va fi bine! Va asiguram ca sunteti pe maini bune. \nExpertii nostri din domeniu fiind pregatiti pentru orice fel de urgenta. \n";
    std::cout << "Pentru a va putea oferi ajutorul calificat de care aveti nevoie, va rugam sa completati urmatoarele date. \nNoi, pe parcursul completarii dumneavoastra, va vom informa cu privire le fiecare mic detaliu. \n";
    std::cout << "Va dorim insanatosire grabnica si multa putere! ❤️ \n";
    std::cout << "\n";

    std::cout << "Pentru a va oferi ingrijirile medicale corespunzatoare, va vom ruga sa introduceti datele urmatoare: \n";
    std::cout << "\n";

    // date PACIENT
    // declar datele
    std::string nume, prenume, CNP, data_nasterii, localitate, cetatenie, ocupatie, nivel_instruire;    // de la PERSOANA
    std::string grupa_sanguina, RH, alergii, asigurare;
    char sex;
    int varsta, sector;

    // citesc datele
    std::cout << "Numele: ";
    std::getline(std::cin, nume);

    std::cout << "Prenumele: ";
    std::getline(std::cin, prenume);

    std::cout << "Sex (format: M/F): ";
    std::cin >> sex;
    std::cin.ignore();  // elimin ENTER-ul de dupa char

    std::cout << "CNP (13 cifre): ";
    std::getline(std::cin, CNP);

    std::cout << "Data nasterii (format: dd.mm.yyyy): ";
    std::getline(std::cin, data_nasterii);

    std::cout << "Varsta: ";
    std::cin >> varsta;
    std::cin.ignore();

    std::cout << "Domiciliul legal: \n";
    std::cout << "    Localitate: ";
    std::getline(std::cin, localitate);
    std::cout << "    Sector: ";
    std::cin >> sector;
    std::cin.ignore();

    std::cout << "Cetatenie: ";
    std::getline(std::cin, cetatenie);

    std::cout << "Ocupatie: ";
    std::getline(std::cin, ocupatie);

    std::cout << "Nivel instruire: ";
    std::getline(std::cin, nivel_instruire);

    std::cout << "Grupa sanguina: ";
    std::getline(std::cin, grupa_sanguina);

    std::cout << "RH: ";
    std::getline(std::cin, RH);

    std::cout << "Alergii: ";
    std::getline(std::cin, alergii);

    std::cout << "Asigurare: ";
    std::cin >> asigurare;

    // creez obiectul de tip Pacient
    Pacient* pacient = nullptr;

    if (varsta < 18)
    {
        pacient = new PacientMinor(nume, prenume, CNP, sex, varsta, data_nasterii,
            localitate, sector, cetatenie, ocupatie, nivel_instruire,
            grupa_sanguina, RH, alergii, asigurare);
    }
    else
    {
        pacient = new PacientMajor(nume, prenume, CNP, sex, varsta, data_nasterii,
            localitate, sector, cetatenie, ocupatie, nivel_instruire,
            grupa_sanguina, RH, alergii, asigurare);
    }
    std::cout << "\n";

    // afisez mesajele in caz de FORMAT PROST
    try {
        pacient->validCNP();
        pacient->validSex();
        pacient->validDataNasterii();
        pacient->validSector();
    } catch (const ExceptiePersoana& e) {
        std::cerr << "Eroare la validarea datelor: " << e.what() << "\n";
        delete pacient;
        return 0;
    }

    // mesaj (daca ORASELE NU COINCID)
    if (pacient->compatibilitateOras(spital->getOras()) == false)
    {
        std::cout << "Ne cerem scuze pentru eventualul disconfort creat.\n";
        std::cout << "Se pare ca sunteti din alt oras, asa ca va recomandam sa cautati o unitate medicala mai aproape de";
        std::cout << pacient->getLocalitate() << "\n";
        std::cout << "Va dorim multa sanatate! ❤️ \n";
        std::cout << "\n";
        return 0;
    }

    //salvare PACIENT in "pacienti_inregistrati.txt"
    pacient->salveazaInFisier();

    // INFORMATII PACIENT
    pacient->genereazaDiagnostic();     // diagnostic random la fiecare rolare
    pacient->afiseaza();

    // verific daca pacientul e ASIGURAT
    if (pacient->esteAsigurat() == false)         // daca NU e asigurat
    {
        int grad, cost;
        grad = pacient->gradProblema();
        cost = FunctiiAjutatoare::calculezCostul(grad);

        std::cout << "Pretul consultatiei de specialitate este de: " << cost << " RON.\n";
        std::cout << "Sunteti de acord cu tariful si doriti sa continuam evaluarea conditiei dumneavoastra? \n";
        std::cout << "(DA/NU): ";
        std::string raspuns_asig;
        std::cin >> raspuns_asig;
        std::transform(raspuns_asig.begin(), raspuns_asig.end(), raspuns_asig.begin(), ::tolower);   //litere mici
        std::cout << "\n";
        if (raspuns_asig != "da")
        {
            std::cout << "Ne pare rau ca ati ales sa nu continuati.\n";
            std::cout << "Va dorim multa sanatate si insanatosire grabnica! ❤️ \n";
            return 0;
        }
        std::cout << "Va multumim ca ati ales sa continuati alaturi de echipa noastra medicala!";
        std::cout << "\n";
    }

    // verific daca pacientul e MINOR
    pacient->procesareSpeciala();


    // DOCTORI
    // fisierul in care am DOCTORII
    std::vector<Doctor> doctori;

    std::ifstream in("doctori.txt");
    if (!in.good())      // verific daca fisierul e sau nu creat (daca e prima rulare sau nu)
    {
        std::cout << "doctori.txt nu exista. Se genereaza lista initiala de doctori... \n";
        std::cout << "Lista de doctori a fost salvata! \n";
        std::cout << "\n";

        doctori = ListaDoctori::creeazaDoctori();
        ListaDoctori::salvez_fisier(doctori);             // salvez lista initiala in fisier
    }
    else
    {
        std::cout << "doctori.txt exista. Se incarca lista doctorilor existenti... \n";
        std::cout << "Lista a fost incarcata cu succes! \n";
        std::cout << "\n";

        doctori = ListaDoctori::citire_fisier();
    }

    PacientInternat::actualizare_Internari(doctori, *spital);     //fct mare de ACTUALIZARE pacient + doctor
    spital->salvez_Fisier();

    // lista doctori potriviti pt un anumit pacient
    std::vector<int> indici_aux = FunctiiAjutatoare::gasesc_DoctoriPotriviti(*pacient, doctori);       //fct care imi determina vector de indici

    std::cout << "Va vom informa cu privire la disponibilitatea medicilor cu expertiza necesara: \n";
    if (indici_aux.empty())         // daca nu e niciun medic disponibil
    {
        std::cout << "Ne cerem scuze, se pare ca toti medicii specializati in " << FunctiiAjutatoare::Specializare_Problema(pacient->getDiagnosticPrincipal())
                  << " sunt la momentul actual ocupati. 😔 \n";
        std::cout << "Va rugam sa reveniti mai tarziu pentru a putea beneficia de o procedura completa! \n";
        return 0;
    }
    for (int i=0; i<indici_aux.size(); i++)
    {
        const Doctor& doc = doctori[indici_aux[i]];
        std::cout << i+1 <<" : "<< FunctiiAjutatoare::trim(doc.getNume()) <<" "<< FunctiiAjutatoare::trim(doc.getPrenume()) <<", ";
        std::cout << FunctiiAjutatoare::trim(doc.getSpecializare()) <<", "<< FunctiiAjutatoare::trim(doc.getGradProfesional()) <<", "<< doc.descriereExperienta() << "\n";

    }
    std::cout << "Va rugam sa alegeti medicul care va inspira cea mai multa incredere \n";
    std::cout << "(mentionati cifra corespunzatoare acestuia): ";

    int alg;
    std::cin >> alg;
    if (alg<1 || alg > indici_aux.size())             //verific daca e valida alegerea
    {
        std::cout << "Alegere invalida. \n";
        std::cout << "Va rugam sa introduceti un numar valid, din lista de mai sus, pentru a continua operatiunea! \n";
        std::cout << "(mentionati cifra corespunzatoare acestuia): ";
        std::cin >> alg;
        if (alg<1 || alg > indici_aux.size())
        {
            std::cout << "Alegere invalida. Procedura anulata. \n";
            return 0;
        }
    }
    std::cout << "\n";
    int ind = indici_aux[alg-1];
    std::cout <<"O alegere excelenta! L-ati ales pe Dr. " << FunctiiAjutatoare::trim(doctori[ind].getNume()) <<" " << FunctiiAjutatoare::trim(doctori[ind].getPrenume()) << " \n";
    std::cout << "\n";

    doctori[ind].setDisponibil(false);        // marchez doctorul INDISPONIBIL
    ListaDoctori::salvez_fisier(doctori);

    //CONSULTATIA
    // op + (non-membru) - afisare consultatie
    Consultatie operator+(const Pacient& p, const Doctor& d);
    Consultatie consultatie = (*pacient) + doctori[ind];
    std::cout << consultatie;
    std::cout << "\n";

    // op += (membru) - creste de fiecare data nr de consultatii totale
    //consultatie += 1;
    static_cast<void>(consultatie += 1);
    int total = Consultatie::getNrConsultatii();
    std::cout << "Numar total de consultatii efectuate: " << total << "\n";
    std::cout << "\n";

    // INTERNARILE
    int zile = FunctiiAjutatoare::zileInternare(*pacient);
    if (zile > 0)
    {
        std::cout << "Pentru a va reface complet, va recomandam cu caldura sa ramaneti sub supravegherea personalului medical timp de: " << "\n";
        std::cout << zile << " zile. \n";
        std::cout << "\n";

        //creez PACIENT INTERNAT
        PacientInternat p_internat(
            pacient->getNume(),
            pacient->getPrenume(),
            pacient->getDiagnosticPrincipal(),
            pacient->getLocalitate(),
            doctori[ind].getCodOficial(),
            zile
        );

        p_internat.salveazaInFisier();      // adaug in internari.txt

        spital->ocupaPat();
        spital->ocupaMedic();

        spital->salvez_Fisier();
    }

    // DIAGNOSTIC SECUNDAR
    std::cout << "De asemenea, daca va ingrijoreaza diagnoscitul secundar, va putem acorda ajutorul necesar!";

    // ASISTENTI in fisier
    std::vector<AsistentMedical> asistenti;

    std::ifstream fin("asistenti.txt");
    if (!fin.good())            // util la prima rulare
    {
        std::cout << "\n";
        std::cout << "asistenti.txt nu exista. Se genereaza lista initiala de asistenti medicali... \n";
        std::cout << "Lista de asistenti medicali a fost salvata! \n";
        std::cout << "\n";

        asistenti = ListaAsistenti::creeazaAsistenti();
        ListaAsistenti::salvezA_fisier(asistenti);
    }
    else
    {
        std::cout << "\n";
        std::cout << "asistenti.txt exista. Se incarca lista cu asistentii medicali... \n";
        std::cout << "Lista de asistenti medicali a fost incarcata cu succes! \n";
        std::cout << "\n";

        asistenti = ListaAsistenti::citesteA_fisier();
    }

    // specializarea buna + afisarea asistentilor care o au
    std::string diagnostic_secundar = pacient->getDiagnosticSecundar();
    std::string specializare_asistent = FunctiiAjutatoare::Specializare_Problema(diagnostic_secundar);
    std::vector<AsistentMedical> potriviti = ListaAsistenti::filtreazaDupaDiagnostic(asistenti, specializare_asistent);

    if (potriviti.empty())
        std::cout << "Ne pare rau, momentan nu avem asistenti calificati pentru specializarea " << specializare_asistent << ". \n";
    else
    {
        std::cout << "Lista asistentilor care va pot ajuta: \n";

        // for (size_t i=0; i < potriviti.size(); i++)
        // {
        //     std::cout << i+1 << ". ";
        //     Persoana* p = new AsistentMedical(potriviti[i]);     // UPCAST la pointer ul de baza
        //     p->afiseaza();          // apel polimorfic
        //     delete p;
        // }
        ListaAsistenti::afiseazaAsistenti(potriviti);

        std::string criteriu;
        std::cout << "Doriti sa sortati lista dupa un anumit criteriu? (experienta / angajare / review): ";
        std::cin >> criteriu;
        std::cout << "\n";

        ListaAsistenti::sorteazaAsistenti(potriviti, criteriu);        // sortez in fct de criteriul dat

        std::cout << "Lista sortata: \n";
        for (size_t i=0; i < potriviti.size(); i++)
        {
            std::cout << i+1 << ". ";
            Persoana* p = new AsistentMedical(potriviti[i]);
            p->afiseaza();
            delete p;
        }
        std::cout << "\n";

        int alegere;
        std::cout << "Alegeti asistentul dorit (numar): ";
        std::cin >> alegere;
        if (alegere<1 && alegere > (int)potriviti.size())
        {
            std::cout << "Alegere invalida. \n";
            std::cout << "Va rugam introduceti un nr valid, din lista de mai sus, pentru a continua operatiunea! \n";
            std::cout << "(mentionati cifra corespunzatoare acestuia): ";
            std::cin >> alegere;
            if (alegere<1 && alegere > (int)potriviti.size())
            {
                std::cout << "Alegere invalida. Procedura anulata. \n";
                return 0;
            }
        }
        std::cout << "\n";
        std::cout << "Ati ales: " << potriviti[alegere-1].getNume() <<" "<< potriviti[alegere-1].getPrenume() << "\n";
        std::cout << "\n";

        // ii dau NOTA + modificare REVIEW
        int nota_noua;
        std::cout << "Ce nota doriti sa ii acordati asistentului ales? \n";
        std::cout << "Nota: ";
        std::cin >> nota_noua;
        std::cout << "\n";

        // actualizare vector
        for (auto& asistent : asistenti)
        {
            if (asistent.getCNP() == potriviti[alegere-1].getCNP()){
                ListaAsistenti::adaugaReview(asistent, nota_noua);
                break;
            }
        }

        ListaAsistenti::salvezA_fisier(asistenti);    // suprascrie tot cu datele actualizate

        std::cout << "Multumim pentru feedback! Review-ul a fost actualizat cu succes. \n";
        std::cout << "\n";
    }

    // final
    // op += (membru) - afisez nr total consultatii de pana acum
    std::cout << "Numar total de consultatii efectuate: " << Consultatie::getNrConsultatii() << "\n";
    std::cout << "\n";

    std::cout << "Va multumim ca ati ales Spitalul Clinic Universitar! \n";
    std::cout << "Echipa noastra va doreste multa sanatate, incredere si o recuperare rapida. \n";
    std::cout << "\n";
    std::cout << "Va dorim toate cele bune, aveti grija de dumneavoastra si nu uitati ca sanatatea este cea mai de pret comoara!❤️ \n";

    delete pacient;

    return 0;
}