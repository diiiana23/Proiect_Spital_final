// #include "gtest/gtest.h"
// #include "FunctiiAjutatoare.h"
// #include "Pacient.h"
//
// class TestPacient : public Pacient {
//     int grad;
// public:
//     TestPacient(int grad_)
//         : Pacient("Nume", "Prenume", "1234567890123", 'F', 30, "01.01.1994",
//                   "Bucuresti", 2, "romana", "programator", "universitar",
//                   "A", "+", "nu", "da"),
//           grad(grad_) {}
//
//     void procesareSpeciala() const override {}
//
//     int gradProblema() const override {
//         return grad;
//     }
// };
//
// TEST(FunctiiAjutatoareTest, CalculezCostulValoriCorecte) {
//     EXPECT_EQ(FunctiiAjutatoare::calculezCostul(1), 150);
//     EXPECT_EQ(FunctiiAjutatoare::calculezCostul(3), 300);
//     EXPECT_EQ(FunctiiAjutatoare::calculezCostul(5), 600);
// }
//
// TEST(FunctiiAjutatoareTest, CalculezCostulValoriInvalide) {
//     EXPECT_EQ(FunctiiAjutatoare::calculezCostul(0), 0);
//     EXPECT_EQ(FunctiiAjutatoare::calculezCostul(-5), 0);
//     EXPECT_EQ(FunctiiAjutatoare::calculezCostul(9), 0);
// }
//
// TEST(FunctiiAjutatoareTest, ZileInternareCorecte) {
//     TestPacient p1(1);
//     TestPacient p3(3);
//     TestPacient p5(5);
//
//     EXPECT_EQ(FunctiiAjutatoare::zileInternare(p1), 0);
//     EXPECT_EQ(FunctiiAjutatoare::zileInternare(p3), 2);
//     EXPECT_EQ(FunctiiAjutatoare::zileInternare(p5), 4);
// }
//
// TEST(FunctiiAjutatoareTest, SpecializareProblemaCorecta) {
//     EXPECT_EQ(FunctiiAjutatoare::Specializare_Problema("Pneumonie"), "Pneumologie");
//     EXPECT_EQ(FunctiiAjutatoare::Specializare_Problema("Infectie urinara"), "Nefrologie");
//     EXPECT_EQ(FunctiiAjutatoare::Specializare_Problema("Durere lombara"), "Neurologie");
//     EXPECT_EQ(FunctiiAjutatoare::Specializare_Problema("Ceva random"), "Medicina Generala");
// }
//
// TEST(FunctiiAjutatoareTest, TrimEliminaSpatii) {
//     std::string input = "   test   ";
//     std::string output = FunctiiAjutatoare::trim(input);
//     EXPECT_EQ(output, "test");
// }