#ifndef MESAJE_H
#define MESAJE_H

#include <iostream>
#include <list>
#include <string>

class MesajePacienti {
private:
    static std::list<std::string> mesaje;

public:
    static void init_Mesaje();             // initializare lista
    static void afiseaza_Mesaj(int poz);
    static int getNrMesaje();
};

#endif
