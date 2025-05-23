#include "Exceptii.h"


ExceptieMeniu::ExceptieMeniu(const std::string& x) : mesaj("Eroare meniu: " + x) {}
const char* ExceptieMeniu::what() const noexcept {
    return mesaj.c_str();
}


ExceptiePersoana::ExceptiePersoana(const std::string& msg) : mesaj("Eroare date invalide: " + msg) {}
const char* ExceptiePersoana::what() const noexcept {
    return mesaj.c_str();
}


ExceptieFisier::ExceptieFisier(const std::string& x) :mesaj("Eroare fisier: " + x) {}
const char* ExceptieFisier::what() const noexcept {
    return mesaj.c_str();
}
