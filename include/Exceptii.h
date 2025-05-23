#ifndef EXCEPTII_H
#define EXCEPTII_H

#include <exception>
#include <string>

class ExceptieMeniu : public std::exception {
private:
    std::string mesaj;
public:
    explicit ExceptieMeniu(const std::string& msg);
    const char* what() const noexcept override;
};


class ExceptiePersoana : public std::exception {
private:
    std::string mesaj;
public:
    explicit ExceptiePersoana(const std::string& msg);
    const char* what() const noexcept override;
};


class ExceptieFisier : public std::exception {
private:
    std::string mesaj;
public:
    explicit ExceptieFisier(const std::string& msg);
    const char* what() const noexcept override;
};


#endif