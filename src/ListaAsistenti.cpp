#include "ListaAsistenti.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

std::vector<AsistentMedical> ListaAsistenti::creeazaAsistenti()
{
    std::vector<AsistentMedical> lista ={
        AsistentMedical("Pop", "Ioana", "2940101123456", 'F', 30, "01.01.1994", "Bucuresti", 2, "romana", "asistent", "studii superioare", 5, 2, "Medicina Interna", 1, 8.5),
        AsistentMedical("Culercu", "Mihai", "1930202123456", 'M', 31, "02.02.1993", "Bucuresti", 3, "romana", "asistent", "studii superioare", 7, 1, "Alergologie", 2, 9.2),
        AsistentMedical("Marin", "Elena", "2910303123456", 'F', 33, "03.03.1991", "Bucuresti", 4, "romana", "asistent", "studii superioare", 4, 5, "Medicina Interna", 7, 7.8),
        AsistentMedical("Stan", "Andrei", "1880404123456", 'M', 36, "04.04.1988", "Bucuresti", 5, "romana", "asistent", "studii superioare", 10, 1, "Neurologie", 1, 9.0),
        AsistentMedical("Vasile", "Ana", "2950505123456", 'F', 29, "05.05.1995", "Bucuresti", 1, "romana", "asistent", "studii superioare", 3, 4, "Neurologie", 5, 7.0),
        AsistentMedical("Matei", "Florin", "1920606123456", 'M', 32, "06.06.1992", "Bucuresti", 6, "romana", "asistent", "studii superioare", 6, 8, "Endocrinologie", 9, 8.3),
        AsistentMedical("Preda", "Irina", "2930707123456", 'F', 31, "07.07.1993", "Bucuresti", 2, "romana", "asistent", "studii superioare", 8, 8, "Endocrinologie", 11, 8.9),
        AsistentMedical("Tudor", "Bogdan", "1900808123456", 'M', 34, "08.08.1990", "Bucuresti", 3, "romana", "asistent", "studii superioare", 9, 5, "ORL", 4, 9.4),
        AsistentMedical("Luca", "Andreea", "2890909123456", 'F', 35, "09.09.1989", "Bucuresti", 1, "romana", "asistent", "studii superioare", 7, 4, "Gastroenterologie", 3, 9.0),
        AsistentMedical("Radu", "Marius", "1871010123456", 'M', 37, "10.10.1987", "Bucuresti", 5, "romana", "asistent", "studii superioare", 11, 1, "Nefrologie", 2, 9.6),
        AsistentMedical("Sucescu", "Simona", "1961111123456", 'F', 28, "11.11.1996", "Bucuresti", 2, "romana", "asistent", "studii superioare", 4, 4, "Psihiatrie", 6, 8.0),
        AsistentMedical("Crin", "Sorin", "1901212123456", 'M', 34, "12.12.1990", "Bucuresti", 3, "romana", "asistent", "studii superioare", 6, 3, "Cardiologie", 4, 7.7),
        AsistentMedical("Dimitrian", "Alina", "2950101123456", 'F', 29, "01.01.1995", "Bucuresti", 4, "romana", "asistent", "studii superioare", 3, 4, "Dermatologie", 4, 8.2),
        AsistentMedical("Petrescu", "Alex", "1880202123456", 'M', 36, "02.02.1988", "Bucuresti", 6, "romana", "asistent", "studii superioare", 10, 6, "ORL", 5, 9.1),
        AsistentMedical("Ardei", "Cristina", "2910303123456", 'F', 33, "03.03.1991", "Bucuresti", 3, "romana", "asistent", "studii superioare", 6, 7, "Nutritie", 10, 8.0)
    };
    return lista;
}


// CITESTE din fisier
std::vector<AsistentMedical> ListaAsistenti::citesteA_fisier()
{
    std::vector<AsistentMedical> lista;
    std::ifstream in("asistenti.txt");

    std::string linie;
    while (std::getline(in, linie))
    {
        std::istringstream input(linie);         //formatul
        std::string nume, prenume, CNP, data_nasterii, localitate, cetatenie, ocupatie, nivel_instruire, specializare;
        char sex;
        int varsta, sector, ani_experienta, ani_angajare, nr_consultatii;
        double review;

        std::getline(input, nume, ',');
        std::getline(input, prenume, ',');
        std::getline(input, CNP, ',');
        input >> sex;
        input.ignore();             // sare peste delimitator (pt int, char)
        input >> varsta;
        input.ignore();
        std::getline(input, data_nasterii, ',');
        std::getline(input, localitate, ',');
        input >> sector;
        input.ignore();
        std::getline(input, cetatenie, ',');
        std::getline(input, ocupatie, ',');
        std::getline(input, nivel_instruire, ',');
        input >> ani_experienta;
        input.ignore();
        input >> ani_angajare;
        input.ignore();
        std::getline(input, specializare, ',');
        input >> nr_consultatii;
        input.ignore();
        input >> review;

        // adaug obiectul de tip ASISTENT in lista  (a primit parametrii constructorului)
        lista.emplace_back(nume, prenume, CNP, sex, varsta, data_nasterii, localitate, sector,
            cetatenie, ocupatie, nivel_instruire, ani_experienta, ani_angajare,
            specializare, nr_consultatii, review);
    }
    in.close();
    return lista;
}

// Salvareaza fisierul dupa modiicari (suprascriere)
void ListaAsistenti::salvezA_fisier(const std::vector<AsistentMedical>& lista)
{
    std::ofstream out("asistenti.txt");

    for (const auto& a : lista)
    {
        out << a.getNume() <<","<< a.getPrenume() <<","<< a.getCNP() <<",";
        out << a.getSex() <<","<< a.getVarsta() <<","<< a.getDataNasterii() <<",";
        out << a.getLocalitate() <<","<< a.getSector() <<","<< a.getCetatenie() <<",";
        out << a.getOcupatie() <<","<< a.getNivelInstruire() <<","<< a.getAniExperienta() <<",";
        out << a.getAniDeAngajare() <<","<< a.getSpecializare() <<",";
        out << a.getNrConsultatii() <<","<< a.getReview();
        out << "\n";
    }
    out.close();
}

// Afișarea fiecărui asistent (cu polimorfism)
void ListaAsistenti::afiseazaAsistenti(const std::vector<AsistentMedical>& lista)
{
    for (const auto& a : lista) {
        Persoana* p = new AsistentMedical(a);
        p->afiseaza();
        delete p;
    }
}

// Filtrare în funcție de specializare  (sa se potriveasca cu diagnosticul)
std::vector<AsistentMedical> ListaAsistenti::filtreazaDupaDiagnostic(const std::vector<AsistentMedical>& lista, const std::string& diagnostic)
{
    std::vector<AsistentMedical> filtrati;

    for (const auto& a : lista) {
        if (a.getSpecializare() == diagnostic)
            filtrati.push_back(a);
    }
    return filtrati;
}

// Sortaez dupa criteriu (review, experienta, angajare) - cu lambda
void ListaAsistenti::sorteazaAsistenti(std::vector<AsistentMedical>& lista, const std::string& criteriu)
{
    if (criteriu == "review") {
        std::sort(lista.begin(), lista.end(), [](const AsistentMedical& a1, const AsistentMedical& a2) {
            return a1.getReview() > a2.getReview();
        });
    } else if (criteriu == "experienta") {
        std::sort(lista.begin(), lista.end(), [](const AsistentMedical& a1, const AsistentMedical& a2) {
            return a1.getAniExperienta() > a2.getAniExperienta();
        });
    } else if (criteriu == "angajare") {
        std::sort(lista.begin(), lista.end(), [](const AsistentMedical& a1, const AsistentMedical& a2) {
            return a1.getAniDeAngajare() > a2.getAniDeAngajare();
        });
    }
    else
        std::cout << "Criteriu invalid. \n";
}

// review nou
void ListaAsistenti::adaugaReview(AsistentMedical& asistent, int nota)
{
    asistent.nou_Review(nota);
}
