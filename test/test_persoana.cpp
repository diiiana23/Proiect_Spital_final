#include "gtest/gtest.h"
#include "Persoana.h"
#include "Exceptii.h"

class PersoanaTest : public Persoana {
public:
    PersoanaTest(const std::string& nume,
                 const std::string& prenume,
                 const std::string& CNP,
                 char sex,
                 int varsta,
                 const std::string& data_nasterii,
                 const std::string& localitate,
                 int sector,
                 const std::string& cetatenie,
                 const std::string& ocupatie,
                 const std::string& nivel_instruire)
        : Persoana(nume, prenume, CNP, sex, varsta, data_nasterii, localitate, sector, cetatenie, ocupatie, nivel_instruire) {}

    void afiseaza() const override {}
};

TEST(PersoanaTest, ValidCNP_Corect) {
    PersoanaTest p("Ion", "Popescu", "1234567890123", 'M', 30, "01.01.1990", "Bucuresti", 1, "romana", "Inginer", "Licenta");
    EXPECT_NO_THROW(p.validCNP());
}

TEST(PersoanaTest, ValidCNP_Gresit) {
    PersoanaTest p("Ion", "Popescu", "1234", 'F', 28, "01.01.1995", "Bucuresti", 1, "romana", "Medic", "Master");
    EXPECT_THROW(p.validCNP(), ExceptiePersoana);
}

TEST(PersoanaTest, ValidSex_Corect) {
    PersoanaTest p("Ion", "Popescu", "1234567890123", 'M', 30, "01.01.1990", "Bucuresti", 1, "romana", "Inginer", "Licenta");
    EXPECT_NO_THROW(p.validSex());
}

TEST(PersoanaTest, ValidSex_Gresit) {
    PersoanaTest p("Ion", "Popescu", "1234567890123", 'A', 28, "01.01.1995", "Bucuresti", 1, "romana", "Medic", "Master");
    EXPECT_THROW(p.validSex(), ExceptiePersoana);
}

TEST(PersoanaTest, ValidDataNasterii_Corect) {
    PersoanaTest p("Ion", "Popescu", "1234567890123", 'M', 30, "15.06.1985", "Bucuresti", 1, "romana", "Inginer", "Licenta");
    EXPECT_NO_THROW(p.validDataNasterii());
}

TEST(PersoanaTest, ValidDataNasterii_Gresit) {
    PersoanaTest p("Ion", "Popescu", "1234567890123", 'F', 28, "125.06.1985", "Bucuresti", 1, "romana", "Medic", "Master");
    EXPECT_THROW(p.validDataNasterii(), ExceptiePersoana);
}

TEST(PersoanaTest, ValidSector_Corect) {
    PersoanaTest p("Ion", "Popescu", "1234567890123", 'M', 30, "15.06.1985", "Bucuresti", 4, "romana", "Inginer", "Licenta");
    EXPECT_NO_THROW(p.validSector());
}

TEST(PersoanaTest, ValidSector_Gresit) {
    PersoanaTest p("Ion", "Popescu", "1234567890123", 'F', 28, "15.06.1985", "Bucuresti", 10, "romana", "Medic", "Master");
    EXPECT_THROW(p.validSector(), ExceptiePersoana);
}