#include "gtest/gtest.h"
#include "Consultatie.h"
#include "Pacient.h"
#include "Doctor.h"

class TestPacient : public Pacient {
public:
    TestPacient(const std::string& diagnostic)
        : Pacient("Ion", "Popescu", "1234567890123", 'M', 40, "01.01.1984", "Bucuresti", 1, "romana", "profesor", "universitar", "A", "+", "nu", "da")
	{
        diagnostic_principal = diagnostic;
    }

    void procesareSpeciala() const override {}
};

class TestDoctor : public Doctor {
public:
    TestDoctor()
        : Doctor("Andrei", "Vasilescu", "1234567890123", 'M', 50, "01.01.1974", "Bucuresti", 1, "romana", "medic", "superior", "Cardiologie", "DOC123", "Primar", "Cardiologie",
                 25, 0, true) {}
};

// constructor + operator <<
TEST(ConsultatieTest, ConstructorCorect) {
    TestPacient pacient("Hipertensiune arteriala");
    TestDoctor doctor;

    Consultatie c("Spitalul Clinic Universitar", pacient, doctor);

    std::stringstream buffer;
    buffer << c;

    std::string out = buffer.str();
    EXPECT_NE(out.find("CONSULTATIE"), std::string::npos);
    EXPECT_NE(out.find("Ion Popescu"), std::string::npos);
    EXPECT_NE(out.find("Hipertensiune arteriala"), std::string::npos);
    EXPECT_NE(out.find("Andrei Vasilescu"), std::string::npos);
    EXPECT_NE(out.find("Cardiologie"), std::string::npos);
}

// operator += membru
TEST(ConsultatieTest, OperatorPlusEqual) {
    TestPacient pacient("Migrena");
    TestDoctor doctor;

    Consultatie c("Spital Test", pacient, doctor);
    int inainte = Consultatie::getNrConsultatii();

    c += 3;
    EXPECT_EQ(Consultatie::getNrConsultatii(), inainte + 3);
}

// operator + non-membru
TEST(ConsultatieTest, OperatorPlus) {
    TestPacient pacient("Apendicita acuta");
    TestDoctor doctor;

    Consultatie c = pacient + doctor;

    std::stringstream buffer;
    buffer << c;

    std::string out = buffer.str();
    EXPECT_NE(out.find("Apendicita acuta"), std::string::npos);
    EXPECT_NE(out.find("Spitalul Clinic Universitar"), std::string::npos);
}