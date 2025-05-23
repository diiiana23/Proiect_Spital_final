#ifndef PERSOANA_H
#define PERSOANA_H

#include <string>

class Persoana {      // clasa abstracta (pt: Doctor, Pacient)
protected:             // o sa le pot accesa in clasele derivate DAR nu in main
    std::string nume;
    std::string prenume;
    std::string CNP;
    char sex;
    int varsta;
    std::string data_nasterii;
    std::string localitate;
    int sector;
    std::string cetatenie;
    std::string ocupatie;         // elev, student, ...
    std::string nivel_instruire;    // cata scoala a facut

public:
    // Constructor (tb sa setezi toate valorile astea cand creezi o persoana)
    Persoana(const std::string& nume,
             const std::string& prenume,
             const std::string& CNP,
             char sex,
             int varsta,
             const std::string& data_nasterii,
             const std::string& localitate,
             int sector,
             const std::string& cetatenie,
             const std::string& ocupatie,
             const std::string& nivel_instruire
           );

    // Destructor virtual (polimorfism)
    virtual ~Persoana() = default;   // apelat cand iese din memorie, se distruge ce e in obiect

    // Functie virtuala pura (clasa devine abstracta =0)
    virtual void afiseaza() const = 0;      // fiecare "Persoana" o sa aiba propria implementare de afisare

    // FUNCTII de Get (imi dau acces la variabilele create mai sus)
    // const inceput = referinta nu poate fi modif
    // & = returnez o referinta (fara copiere)
    // const final = fct nu modifica obiectul
    const std::string& getNume() const;
    const std::string& getPrenume() const;
    const std::string& getCNP() const;
    char getSex() const;
    int getVarsta() const;
    const std::string& getDataNasterii() const;
    const std::string& getLocalitate() const;
    int getSector() const;
    const std::string& getCetatenie() const;
    const std::string& getOcupatie() const;
    const std::string& getNivelInstruire() const;

    // FUNCTII de validare
    virtual void validCNP() const;      //13cif
    virtual void validSex() const;       // M/F
    virtual void validDataNasterii() const;  //zz.ll.aaaa
    virtual void validSector() const;       //o cif
};

// verif daca 2 persoane sunt puse de 2 ori
bool operator==(const Persoana& p1, const Persoana& p2);

#endif
