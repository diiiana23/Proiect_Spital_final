#include "gtest/gtest.h"
#include "Pacient.h"
#include "Exceptii.h"

class TestPacient : public Pacient {
public:
    using Pacient::Pacient;
    void procesareSpeciala() const override {}
    void setDiagnosticPrincipal(const std::string& diag) {
        diagnostic_principal = diag;
    }
};

class PacientTest : public ::testing::Test {
protected:
    TestPacient* p;

    void SetUp() override {
        p = new TestPacient("Ion", "Popescu", "1234567890123", 'M', 35, "01.01.2005", "Bucuresti", 2, "romana", "inginer", "universitar",
                "AB", "+", "Nu", "da");
    }

    void TearDown() override {
        delete p;
    }
};

TEST_F(PacientTest, Gett) {
    EXPECT_EQ(p->getGrupaSanguina(), "AB");
    EXPECT_EQ(p->getRH(), "+");
    EXPECT_EQ(p->getAlergii(), "Nu");
    EXPECT_EQ(p->getAsigurare(), "da");
}

TEST_F(PacientTest, EsteAsiguratTrue) {
    EXPECT_TRUE(p->esteAsigurat());
}

TEST_F(PacientTest, EsteMinorFalse) {
    EXPECT_FALSE(p->esteMinor());
}

TEST_F(PacientTest, CompatibilitateOrasTrue) {
    EXPECT_TRUE(p->compatibilitateOras("bucuresti"));
}

TEST_F(PacientTest, CompatibilitateOrasFalse) {
    EXPECT_FALSE(p->compatibilitateOras("Cluj"));
}

TEST_F(PacientTest, GradProblemaTipMedic) {
    p->setDiagnosticPrincipal("Pneumonie");
    EXPECT_EQ(p->gradProblema(), 3);
    EXPECT_EQ(p->tipMedic(), "Specialist");

    p->setDiagnosticPrincipal("Apendicita acuta");
    EXPECT_EQ(p->gradProblema(), 5);
    EXPECT_EQ(p->tipMedic(), "Primar");
}