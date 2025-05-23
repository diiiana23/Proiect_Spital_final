// Donator.h
#ifndef DONATOR_H
#define DONATOR_H

#include <string>

class Donator {
private:
    std::string nume;
    std::string prenume;
    int varsta;
    std::string grupa_sanguina;

public:
    Donator(const std::string& nume,
            const std::string& prenume,
            int varsta,
            const std::string& grupa_sanguina);

    std::string format() const;
};

#endif