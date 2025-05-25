#include "gtest/gtest.h"
#include "Mesaje.h"
#include <sstream>
#include <iostream>

TEST(MesajePacientiTest, TestGetNrMesaje) {
    MesajePacienti mesaje;
    mesaje.init_Mesaje();
    EXPECT_EQ(mesaje.getNrMesaje(), 4);
}

TEST(MesajePacientiTest, TestAfiseazaMesajPozitieValida) {
    MesajePacienti mesaje;
    mesaje.init_Mesaje();

    std::stringstream buffer;
    std::streambuf* original = std::cout.rdbuf(buffer.rdbuf());

    mesaje.afiseaza_Mesaj(1);

    std::cout.rdbuf(original);

    std::string output = buffer.str();
    EXPECT_NE(output.find("Mesajul de incurajare pentru pacient este"), std::string::npos);
}

TEST(MesajePacientiTest, TestAfiseazaMesajPozitieInvalida) {
    MesajePacienti mesaje;
    mesaje.init_Mesaje();

    std::stringstream buffer;
    std::streambuf* original = std::cout.rdbuf(buffer.rdbuf());

    mesaje.afiseaza_Mesaj(10000);     //poz invalida

    std::cout.rdbuf(original);

    std::string output = buffer.str();
    EXPECT_NE(output.find("Pozitie invalida"), std::string::npos);
}