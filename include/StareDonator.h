#ifndef STARE_DONATOR_H
#define STARE_DONATOR_H

#include <iostream>

// design pattern: STATE PATTERN

class StareDonare {         // Interfața de stare
public:
    virtual void afiseazaStare() const = 0;

    virtual ~StareDonare() = default;
};

class ADonat : public StareDonare {       // stare : da
public:
    void afiseazaStare() const override;
};

class NuADonat : public StareDonare {    // stare : NU
public:
    void afiseazaStare() const override;
};


#endif