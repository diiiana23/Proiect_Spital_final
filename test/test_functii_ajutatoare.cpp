#include "gtest/gtest.h"
#include "FunctiiAjutatoare.h"
#include "Pacient.h"

class TestPacient : public Pacient {
    int grad;
public:
    TestPacient(int grad_)
        : Pacient("Test", "Pacient", "1234567890123", 'F', 30, "01.01.1994",
                  "Bucuresti", 1, "romana", "test", "test",
                  "A", "+", "nu", "da"), grad(grad_) {}

    void procesareSpeciala() const override {}

    int gradProblema() const override {
        return grad;
    }
};

TEST(FunctiiAjutatoareTest, CalculezCostulCorect) {
    EXPECT_EQ(FunctiiAjutatoare::calculezCostul(1), 150);
    EXPECT_EQ(FunctiiAjutatoare::calculezCostul(3), 300);
    EXPECT_EQ(FunctiiAjutatoare::calculezCostul(5), 600);
}

TEST(FunctiiAjutatoareTest, CalculezCostulInvalid) {
    EXPECT_EQ(FunctiiAjutatoare::calculezCostul(0), 0);
    EXPECT_EQ(FunctiiAjutatoare::calculezCostul(-2), 0);
    EXPECT_EQ(FunctiiAjutatoare::calculezCostul(99), 0);
}

TEST(FunctiiAjutatoareTest, SpecializareCorectaPentruDiagnostic) {
    EXPECT_EQ(FunctiiAjutatoare::Specializare_Problema("Pneumonie"), "Pneumologie");
    EXPECT_EQ(FunctiiAjutatoare::Specializare_Problema("Hipotiroidism"), "Endocrinologie");
    EXPECT_EQ(FunctiiAjutatoare::Specializare_Problema("Durere lombara"), "Neurologie");
    EXPECT_EQ(FunctiiAjutatoare::Specializare_Problema("Infectie urinara"), "Nefrologie");
    EXPECT_EQ(FunctiiAjutatoare::Specializare_Problema("Ceva random"), "Medicina Generala");
}

TEST(FunctiiAjutatoareTest, EliminareSpatii) {
    EXPECT_EQ(FunctiiAjutatoare::trim("   abc   "), "abc");
    EXPECT_EQ(FunctiiAjutatoare::trim("test"), "test");
    EXPECT_EQ(FunctiiAjutatoare::trim("      "), "");
}