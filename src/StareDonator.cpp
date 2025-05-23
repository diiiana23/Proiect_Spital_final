#include "StareDonator.h"

void ADonat::afiseazaStare() const
{
    std::cout << "STARE: Pacientul a donat sange. \n";
    std::cout << "Va multumim pentru generozitate! Donatia dvs. va ajuta foarte multi pacienti! ❤️\n";

    std::cout << "\n";
}

void NuADonat::afiseazaStare() const
{
    std::cout << "STARE: Pacientul nu a donat sange.\n";
    std::cout << "Este in regula. Sa continuam cu procedura dumneavoastra! ❤️\n";

    std::cout << "\n";
}