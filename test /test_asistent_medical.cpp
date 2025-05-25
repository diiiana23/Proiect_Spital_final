#include "gtest/gtest.h"
#include "AsistentMedical.h"

class AsistentMedicalTest : public ::testing::Test {
protected:
    AsistentMedical* asistent;

    void SetUp() override {
        asistent = new AsistentMedical("Laura", "Dumitru", "1234567890123", 'F', 30, "10.03.1994", "Bucuresti", 3, "romana", "asistent", "postliceala",
               							5, 3, "Generalist", 0, 0.0);
    }

    void TearDown() override {
        delete asistent;
    }
};

TEST_F(AsistentMedicalTest, TestConstructorsiGett) {
    EXPECT_EQ(asistent->getNume(), "Laura");
    EXPECT_EQ(asistent->getPrenume(), "Dumitru");
    EXPECT_EQ(asistent->getVarsta(), 30);
    EXPECT_EQ(asistent->getAniExperienta(), 5);
    EXPECT_EQ(asistent->getAniDeAngajare(), 3);
    EXPECT_EQ(asistent->getSpecializare(), "Generalist");
    EXPECT_EQ(asistent->getNrConsultatii(), 0);
    EXPECT_DOUBLE_EQ(asistent->getReview(), 0.0);
}

TEST_F(AsistentMedicalTest, TestReviewMulteNote) {
    asistent->nou_Review(10);
    EXPECT_EQ(asistent->getNrConsultatii(), 1);
    EXPECT_DOUBLE_EQ(asistent->getReview(), 10.0);

    asistent->nou_Review(8);
    EXPECT_EQ(asistent->getNrConsultatii(), 2);
    EXPECT_NEAR(asistent->getReview(), 9.0, 0.01);

    asistent->nou_Review(7);
    EXPECT_EQ(asistent->getNrConsultatii(), 3);
    EXPECT_NEAR(asistent->getReview(), 8.33, 0.01);     //review = (review * nr_consultatii + notaNoua) / (nr_consultatii + 1)
}