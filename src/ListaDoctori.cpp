#include "ListaDoctori.h"
#include "FunctiiAjutatoare.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

std::vector<Doctor> ListaDoctori::creeazaDoctori()
{
    std::vector<Doctor> lista_doctori = {
        // CARDIOLOGIE
        Doctor("Popescu", "Daniel", "1900101123456", 'M', 44, "10.01.1980", "Bucuresti", 1, "romana", "cardiolog", "studii superioare", "Cardiologie", "D835", "Primar", "Cardiologie", 20, 0, true),
        Doctor("Stanciu", "Roxana", "2851105123456", 'F', 38, "05.11.1985", "Bucuresti", 2, "romana", "cardiolog", "studii superioare", "Cardiologie", "D627", "Specialist", "Cardiologie", 10, 0, true),
        Doctor("Dinu", "Alexandru", "1900112223456", 'M', 34, "12.01.1990", "Bucuresti", 3, "romana", "cardiolog", "studii superioare", "Cardiologie", "D938", "Rezident", "Cardiologie", 0, 2, true),
        Doctor("Marinescu", "Raul", "2910810123456", 'F', 33, "10.08.1991", "Brasov", 1, "romana", "cardiolog", "studii superioare", "Cardiologie", "D283", "Specialist", "Cardiologie", 8, 0, true),
        Doctor("Oprea", "Alexandru", "1890512123456", 'M', 35, "12.05.1989", "Constanta", 6, "romana", "cardiolog", "studii superioare", "Cardiologie", "D465", "Primar", "Cardiologie", 12, 0, true),

        // PNEUMOLOGIE
        Doctor("Ionescu", "Marius", "2910523123456", 'M', 33, "23.05.1991", "Bucuresti", 1, "romana", "pneumolog", "studii superioare", "Pneumologie", "D487", "Specialist", "Pneumologie", 6, 0, true),
        Doctor("Raducanu", "Ionut", "1891222123456", 'M', 35, "22.12.1989", "Bucuresti", 4, "romana", "pneumolog", "studii superioare", "Pneumologie", "D283", "Primar", "Pneumologie", 12, 0, true),
        Doctor("Tomescu", "Iustina", "2960214123456", 'F', 28, "14.02.1996", "Bucuresti", 2, "romana", "pneumolog", "studii superioare", "Pneumologie", "D194", "Rezident", "Pneumologie", 0, 1, true),
        Doctor("Lupu", "Ioana", "2940301123456", 'F', 30, "01.03.1994", "Cluj-Napoca", 2, "romana", "pneumolog", "studii superioare", "Pneumologie", "D166", "Rezident", "Pneumologie", 0, 1, true),
        Doctor("Vasilescu", "Mihnea", "1900705123456", 'M', 34, "05.07.1990", "Bucuresti", 5, "romana", "pneumolog", "studii superioare", "Pneumologie", "D824", "Specialist", "Pneumologie", 7, 0, true),

        // ORTOPEDIE
        Doctor("Dragut", "Valentin", "1950618123456", 'M', 28, "18.06.1995", "Bucuresti", 3, "romana", "ortoped", "studii superioare", "Ortopedie", "D387", "Rezident", "Ortopedie", 0, 2, true),
        Doctor("Stan", "Andrei", "1910330123456", 'M', 33, "30.03.1991", "Bucuresti", 5, "romana", "ortoped", "studii superioare", "Ortopedie", "D947", "Specialist", "Ortopedie", 7, 0, true),
        Doctor("Grigore", "Oana", "2841109123456", 'F', 40, "09.11.1984", "Bucuresti", 1, "romana", "ortoped", "studii superioare", "Ortopedie", "D837", "Primar", "Ortopedie", 16, 0, true),
        Doctor("Iliescu", "Dan", "2950411123456", 'F', 29, "11.04.1995", "Iasi", 4, "romana", "ortoped", "studii superioare", "Ortopedie", "D526", "Rezident", "Ortopedie", 0, 2, true),
        Doctor("Stefanescu", "Luca", "1880912123456", 'M', 36, "12.09.1988", "Bucuresti", 1, "romana", "ortoped", "studii superioare", "Ortopedie", "D746", "Specialist", "Ortopedie", 6, 0, true),

        // NEUROLOGIE
        Doctor("Enache", "Sorin", "2890505123456", 'M', 35, "05.05.1989", "Bucuresti", 6, "romana", "neurolog", "studii superioare", "Neurologie", "D987", "Primar", "Neurologie", 15, 0, true),
        Doctor("Rosu", "Daniel", "1870124123456", 'M', 37, "24.01.1987", "Bucuresti", 2, "romana", "neurolog", "studii superioare", "Neurologie", "D366", "Specialist", "Neurologie", 10, 0, true),
        Doctor("Teodorescu", "Camelia", "2940530123456", 'F', 30, "30.05.1994", "Bucuresti", 3, "romana", "neurolog", "studii superioare", "Neurologie", "D287", "Rezident", "Neurologie", 0, 1, true),
        Doctor("Costache", "Elena", "2930605123456", 'F', 31, "05.06.1993", "Craiova", 3, "romana", "neurolog", "studii superioare", "Neurologie", "D823", "Specialist", "Neurologie", 9, 0, true),
        Doctor("Nistor", "Alexandru", "1860317123456", 'M', 38, "17.03.1986", "Timisoara", 2, "romana", "neurolog", "studii superioare", "Neurologie", "D486", "Primar", "Neurologie", 14, 0, true),

        // BOLI INFECȚIOASE
        Doctor("Georgescu", "Radu", "1920317123456", 'M', 32, "17.03.1992", "Bucuresti", 5, "romana", "infectiolog", "studii superioare", "Boli Infectioase", "D927", "Specialist", "Boli Infectioase", 9, 0, true),
        Doctor("Alexe", "Simona", "2910419123456", 'F', 33, "19.04.1991", "Bucuresti", 1, "romana", "infectiolog", "studii superioare", "Boli Infectioase", "D834", "Rezident", "Boli Infectioase", 0, 2, true),
        Doctor("Grigore", "Stefan", "1830825123456", 'M', 41, "25.08.1983", "Bucuresti", 6, "romana", "infectiolog", "studii superioare", "Boli Infectioase", "D764", "Primar", "Boli Infectioase", 17, 0, true),
        Doctor("Preda", "Andreea", "2950501123456", 'F', 29, "01.05.1995", "Sibiu", 5, "romana", "infectiolog", "studii superioare", "Boli Infectioase", "D254", "Rezident", "Boli Infectioase", 0, 1, true),
        Doctor("Crudu", "Ana-Maria", "1900223123456", 'M', 34, "23.02.1990", "Bucuresti", 6, "romana", "infectiolog", "studii superioare", "Boli Infectioase", "D237", "Specialist", "Boli Infectioase", 9, 0, true),

        // CHIRURGIE GENERALĂ
        Doctor("Barbu", "Lucian", "1941220123456", 'M', 30, "20.12.1994", "Bucuresti", 4, "romana", "chirurg", "studii superioare", "Chirurgie Generala", "D737", "Specialist", "Chirurgie Generala", 10, 0, true),
        Doctor("Neagu", "Cristian", "1860222123456", 'M', 38, "22.02.1986", "Bucuresti", 2, "romana", "chirurg", "studii superioare", "Chirurgie Generala", "D280", "Primar", "Chirurgie Generala", 14, 0, true),
        Doctor("Enache", "Adina", "1921011123456", 'F', 32, "11.10.1992", "Bucuresti", 1, "romana", "chirurg", "studii superioare", "Chirurgie Generala", "D902", "Rezident", "Chirurgie Generala", 0, 2, true),
        Doctor("Petrescu", "Irina", "2931018123456", 'F', 31, "18.10.1993", "Cluj-Napoca", 1, "romana", "chirurg", "studii superioare", "Chirurgie Generala", "D966", "Rezident", "Chirurgie Generala", 0, 2, true),
        Doctor("Sorescu", "Vlad", "1851211123456", 'M', 39, "11.12.1985", "Bucuresti", 3, "romana", "chirurg", "studii superioare", "Chirurgie Generala", "D258", "Primar", "Chirurgie Generala", 16, 0, true),

        // MEDICINĂ INTERNĂ
        Doctor("Iliescu", "Sabina", "2970118123456", 'F', 27, "18.01.1997", "Bucuresti", 6, "romana", "internist", "studii superioare", "Medicina Interna", "D514", "Rezident", "Medicina Interna", 0, 1, true),
        Doctor("Dragomir", "Raluca", "2901104123456", 'F', 34, "04.11.1990", "Bucuresti", 3, "romana", "internist", "studii superioare", "Medicina Interna", "D251", "Specialist", "Medicina Interna", 8, 0, true),
        Doctor("Zamfir", "Ioan", "1850318123456", 'M', 39, "18.03.1985", "Bucuresti", 4, "romana", "internist", "studii superioare", "Medicina Interna", "D165", "Primar", "Medicina Interna", 16, 0, true),
        Doctor("Grigore", "Marius", "2910305123456", 'F', 33, "05.03.1991", "Bucuresti", 2, "romana", "internist", "studii superioare", "Medicina Interna", "D982", "Specialist", "Medicina Interna", 7, 0, true),
        Doctor("Toma", "Robert", "1870711123456", 'M', 37, "11.07.1987", "Ploiesti", 4, "romana", "internist", "studii superioare", "Medicina Interna", "D276", "Primar", "Medicina Interna", 15, 0, true),

        // OFTALMOLOGIE
        Doctor("Mihai", "Cristian", "1871229123456", 'M', 36, "29.12.1987", "Bucuresti", 1, "romana", "oftalmolog", "studii superioare", "Oftalmologie", "D726", "Primar", "Oftalmologie", 18, 0, true),
        Doctor("Ignat", "Iustina", "1931209123456", 'F', 31, "09.12.1993", "Bucuresti", 5, "romana", "oftalmolog", "studii superioare", "Oftalmologie", "D263", "Specialist", "Oftalmologie", 9, 0, true),
        Doctor("Banciu", "Sebastian", "1960811123456", 'M', 28, "11.08.1996", "Bucuresti", 6, "romana", "oftalmolog", "studii superioare", "Oftalmologie", "D363", "Rezident", "Oftalmologie", 0, 1, true),
        Doctor("Ionescu", "Eliza", "2941111123456", 'F', 30, "11.11.1994", "Suceava", 1, "romana", "oftalmolog", "studii superioare", "Oftalmologie", "D665", "Specialist", "Oftalmologie", 9, 0, true),
        Doctor("Voinea", "Cristina", "2890415123456", 'F', 35, "15.04.1989", "Bucuresti", 4, "romana", "oftalmolog", "studii superioare", "Oftalmologie", "D455", "Specialist", "Oftalmologie", 8, 0, true)
    };
    return lista_doctori;
}


// functia de CITIRE din FISIER
std::vector<Doctor> ListaDoctori::citire_fisier()
{
    std::vector<Doctor> lista;
    std::ifstream in("doctori.txt");

    std::string linie;
    while (std::getline(in, linie))
    {
        std::istringstream input(linie);     //formatul
        std::string nume, prenume, CNP, data_nasterii, localitate, cetatenie, ocupatie, nivel_instruire;
        std::string specializare, cod_oficial, grad_profesional, sectie, disponibil_stare;
        char sex;
        int varsta, sector, ani_experienta, an_rezidentiat;
        bool disponibil;     // o setez dupa in fct de ce citesc in "disponibil_stare"

        std::getline(input, nume, ',');
        std::getline(input, prenume, ',');
        std::getline(input, CNP, ',');
        input >> sex;
        input.ignore();         // sare peste delimitator (pt int, char)
        input >> varsta;
        input.ignore();
        std::getline(input, data_nasterii, ',');
        std::getline(input, localitate, ',');
        input >> sector;
        input.ignore();
        std::getline(input, cetatenie, ',');
        std::getline(input, ocupatie, ',');
        std::getline(input, nivel_instruire, ',');
        std::getline(input, specializare, ',');
        std::getline(input, cod_oficial, ',');
        std::getline(input, grad_profesional, ',');
        std::getline(input, sectie, ',');
        input >> ani_experienta;
        input.ignore();
        input >> an_rezidentiat;
        input.ignore();
        std::getline(input, disponibil_stare);

        // elimin spatiile din fata, daca sunt
        disponibil_stare.erase(0, disponibil_stare.find_first_not_of(' '));     // find_first_not_of() - returneaza pozitia pe care nu e ' '

        // setez disponibilitate (variabila bool)
        if (disponibil_stare == "disponibil")
            disponibil = true;
        else
            disponibil = false;

        // adaug obiectul de tip DOCTOR in lista  (a primit parametrii constructorului)
        lista.emplace_back(nume, prenume, CNP, sex, varsta, data_nasterii, localitate, sector,
                   cetatenie, ocupatie, nivel_instruire, specializare,
                   cod_oficial, grad_profesional, sectie,
                   ani_experienta, an_rezidentiat, disponibil);
    }
    in.close();
    return lista;
}


// functia de SALVARE a vectorului IN FISIER  (de fiecare data)
void ListaDoctori::salvez_fisier(const std::vector<Doctor>& lista)
{
    std::ofstream out("doctori.txt");     //folosesc asa pt ca mereu se sterge ce e aici (o sa se adauge dupa modificat)

    for (const Doctor& doc : lista)
    {
        out << FunctiiAjutatoare::trim(doc.getNume()) <<","<< FunctiiAjutatoare::trim(doc.getPrenume()) <<","<< FunctiiAjutatoare::trim(doc.getCNP()) <<",";
        out << doc.getSex() <<","<< doc.getVarsta() <<","<< FunctiiAjutatoare::trim(doc.getDataNasterii()) <<",";
        out << FunctiiAjutatoare::trim(doc.getLocalitate()) << "," << doc.getSector() << ",";
        out << FunctiiAjutatoare::trim(doc.getCetatenie()) <<","<< FunctiiAjutatoare::trim(doc.getOcupatie()) <<",";
        out << FunctiiAjutatoare::trim(doc.getNivelInstruire()) <<","<< FunctiiAjutatoare::trim(doc.getSpecializare()) <<",";
        out << FunctiiAjutatoare::trim(doc.getCodOficial()) <<","<< FunctiiAjutatoare::trim(doc.getGradProfesional()) <<","<< FunctiiAjutatoare::trim(doc.getSectie()) <<",";
        out << doc.getAniExperienta() <<","<< doc.getAnRezidentiat() <<",";
        if (doc.esteDisponibil() == true)
            out << "disponibil";
        else
            out << "indisponibil";
        out << "\n";
    }
    out.close();
}