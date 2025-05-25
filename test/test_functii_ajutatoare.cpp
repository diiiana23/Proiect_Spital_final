#include "gtest/gtest.h"
#include "FunctiiAjutatoare.h"
#include "Pacient.h"

TEST(FunctiiAjutatoareTest, TestCalculezCostulValoriCorecte) {
    EXPECT_EQ(FunctiiAjutatoare::calculezCostul(1), 150);
    EXPECT_EQ(FunctiiAjutatoare::calculezCostul(3), 300);
    EXPECT_EQ(FunctiiAjutatoare::calculezCostul(5), 600);
}

TEST(FunctiiAjutatoareTest, TestCalculezCostulValoriInvalide) {
    EXPECT_EQ(FunctiiAjutatoare::calculezCostul(0), 0);
    EXPECT_EQ(FunctiiAjutatoare::calculezCostul(-1), 0);
    EXPECT_EQ(FunctiiAjutatoare::calculezCostul(6), 0);
    EXPECT_EQ(FunctiiAjutatoare::calculezCostul(100), 0);
}

// Clasa PACIENT – ca sa pot sa am deja gradul problemei pt ZILE INTERNARE
class TestPacient : public Pacient {
    int grad;
public:
    TestPacient(int grad_)
        : Pacient("Nume", "Prenume", "1234567890123", 'F', 35, "01.01.1990",
                  "Bucuresti", 2, "Romana", "Programator", "Universitar",
                  "A", "+", "Nu", "Da"),
          grad(grad_) {}

    // suprascriu: fct pur virtuala + grad problema
    void procesareSpeciala() const override {}

    int gradProblema() const override {
        return grad;
    }
};

TEST(FunctiiAjutatoareTest, TestZileInternare) {
    TestPacient p1(1);
    TestPacient p3(3);
    TestPacient p5(5);

    EXPECT_EQ(FunctiiAjutatoare::zileInternare(p1), 0);
    EXPECT_EQ(FunctiiAjutatoare::zileInternare(p3), 2);
    EXPECT_EQ(FunctiiAjutatoare::zileInternare(p5), 4);
}

TEST(FunctiiAjutatoareTest, TestSpecializareProblema_Pneumologie) {
    std::string specializare = FunctiiAjutatoare::Specializare_Problema("Pneumonie");
    EXPECT_EQ(specializare, "Pneumologie");
}

TEST(FunctiiAjutatoareTest, TestSpecializareProblema_Nefrologie) {
    std::string specializare = FunctiiAjutatoare::Specializare_Problema("Infectie urinara");
    EXPECT_EQ(specializare, "Nefrologie");
}

TEST(FunctiiAjutatoareTest, TestTrimSpatii) {
    std::string rezultat = FunctiiAjutatoare::trim("   test string   ");
    EXPECT_EQ(rezultat, "test string");
}