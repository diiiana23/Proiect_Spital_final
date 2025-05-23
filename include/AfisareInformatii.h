#ifndef AFISAREINFORMATII_H
#define AFISAREINFORMATII_H

#include <iostream>
#include <vector>

template <class T>

class AfisareInformatii {
private:
    std::vector<T> obiect;

public:
    void adauga(const T& obi)
    {
        obiect.push_back(obi);
    }

    void afiseaza() const
    {
        for (const auto& obi : obiect)
        {
            obi.afiseaza();
            std::cout << "\n";
        }
    }
};

#endif
