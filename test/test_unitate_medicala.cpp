#include "gtest/gtest.h"
#include "UnitateMedicala.h"

TEST(UnitateMedicalaTest, TestGetNume) {
    UnitateMedicala* spital = UnitateMedicala::getInstanta();
    EXPECT_EQ(spital->getNume(), "Spitalul Clinic Universitar");
}

TEST(UnitateMedicalaTest, TestGetNrPaturi) {
    UnitateMedicala* spital = UnitateMedicala::getInstanta();
    EXPECT_EQ(spital->getNrPaturiTotale(), 240);
}

TEST(UnitateMedicalaTest, TestGetNrDoctori) {
    UnitateMedicala* spital = UnitateMedicala::getInstanta();
    EXPECT_EQ(spital->getNrMediciTotali(), 40);
}