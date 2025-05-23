#ifndef FUNCTIIAJUTATOARE_H
#define FUNCTIIAJUTATOARE_H

#include <string>
#include <vector>
#include "Doctor.h"
#include "Pacient.h"

class FunctiiAjutatoare {
public:
    static int calculezCostul(int grad);
    static int zileInternare(const Pacient& p);
    static std::string Specializare_Problema(const std::string& problema);
    static std::string trim(const std::string& s);
    static std::vector<int> gasesc_DoctoriPotriviti(const Pacient& pacient, const std::vector<Doctor>& doctori);
};

#endif
