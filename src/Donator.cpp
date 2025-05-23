// Donator.cpp
#include "Donator.h"

Donator::Donator(const std::string& nume,
                 const std::string& prenume,
                 int varsta,
                 const std::string& grupa_sanguina)
    : nume(nume), prenume(prenume), varsta(varsta), grupa_sanguina(grupa_sanguina) {}

std::string Donator::format() const
{
    return nume +" "+ prenume +", "+ std::to_string(varsta) +", "+ grupa_sanguina;
}