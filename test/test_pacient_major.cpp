// #include "gtest/gtest.h"
// #include "PacientMajor.h"
// #include "StareDonator.h"
// #include <sstream>
// #include <iostream>
//
// TEST(PacientMajorTest, ConstructorsiGett) {
//     PacientMajor pacient("Maria", "Ionescu", "1234567890123", 'F', 45, "10.03.2000", "Bucuresti", 1, "romana", "inginer", "universitar", "B", "+", "nu", "da");
//
//     EXPECT_EQ(pacient.getNume(), "Maria");
//     EXPECT_EQ(pacient.getVarsta(), 45);
//     EXPECT_EQ(pacient.getGrupaSanguina(), "B");
//     EXPECT_FALSE(pacient.esteMinor());
// }
//
// // setStareDonare + afiseazaStareDonare
// TEST(PacientMajorTest, DonareSange_ADonat) {
//     PacientMajor pacient("Maria", "Ionescu", "1234567890123", 'F', 45, "10.03.2000", "Bucuresti", 1, "romana", "inginer", "universitar", "B", "+", "nu", "da");
//
//     std::stringstream buffer;
//     std::streambuf* originalCout = std::cout.rdbuf(buffer.rdbuf());
//
//     pacient.setStareDonare(new ADonat());
//     pacient.afiseazaStareDonare();
//
//     std::cout.rdbuf(originalCout);
//
//     std::string output = buffer.str();
//     EXPECT_NE(output.find("Pacientul a donat sange"), std::string::npos);
//     EXPECT_NE(output.find("Va multumim pentru generozitate"), std::string::npos);
// }
//
// TEST(PacientMajorTest, DonareSange_NuADonat) {
//     PacientMajor pacient("Maria", "Ionescu", "1234567890123", 'F', 45, "10.03.2000", "Bucuresti", 1, "romana", "inginer", "universitar", "B", "+", "nu", "da");
//
//     std::stringstream buffer;
//     std::streambuf* originalCout = std::cout.rdbuf(buffer.rdbuf());
//
//     pacient.setStareDonare(new NuADonat());
//     pacient.afiseazaStareDonare();
//
//     std::cout.rdbuf(originalCout);
//
//     std::string output = buffer.str();
//     EXPECT_NE(output.find("Pacientul nu a donat sange"), std::string::npos);
//     EXPECT_NE(output.find("Este in regula"), std::string::npos);
// }