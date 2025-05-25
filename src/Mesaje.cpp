#include "Mesaje.h"

std::list<std::string> MesajePacienti::mesaje;

void MesajePacienti::init_Mesaje() {
    mesaje = {
        "Capul sus si fii puternic! Iti dorim multa sanatate si sa stii ca sunt alaturi de tine!",
        "Pentru orice problema, suntem aici 24/7! ",
        "Nu uitati sa va urmati tratamentul pe care il veti primi si sa aveti grija de sanatatea dumneavoastra!",
        "Sanatatea dumneavoastra este prioritatea noastra!"
    };
}

int MesajePacienti::getNrMesaje()
{
    return static_cast<int>(mesaje.size());
}

void MesajePacienti::afiseaza_Mesaj(int poz)
{
    if (poz<1 || poz>getNrMesaje())
    {
        std::cout << "Pozitie invalida. Alegeti un numar intre 1 si " << getNrMesaje() << ". \n";
    }
    int i=1;
    for (const auto& mesaj : mesaje)
    {
        if (poz == i)
        {
            std::cout << "Mesajul de incurajare pentru pacient este: \n";
            std::cout << "\n";
            std::cout << mesaj << "\n";
            std::cout << "\n";
            return;
        }
        i++;
    }
}

