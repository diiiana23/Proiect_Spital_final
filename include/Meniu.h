#ifndef MENIU_H
#define MENIU_H

#include "UnitateMedicala.h"
#include "Doctor.h"

class Meniu {
public:
    void afisez_PacientiInregistrati();
    void afisez_Vindecati();
    void afisez_Internati();
    void afisez_DoctoriDisponibili();
    void afisez_AsistentiMedicali();
    void afisez_ListaDonatori();

    void angajez_Doctor();
    void concediez_Doctor();

    void afisez_Meniu(UnitateMedicala& spital);

};

#endif
