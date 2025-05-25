#include "gtest/gtest.h"
#include "Doctor.h"

class DoctorTest : public ::testing::Test {
protected:
    Doctor* doc;

    void SetUp() override {
        doc = new Doctor("Elena", "Georgescu", "1234567890123", 'F', 40, "12.12.1983", "Bucuresti", 3, "romana", "medic", "universitar", "Pediatrie", "D567", "Specialist", "Pediatrie", 15, 0, true);
    }

    void TearDown() override {
        delete doc;
    }
};

TEST_F(DoctorTest, TestGett) {
    EXPECT_EQ(doc->getNume(), "Elena");
    EXPECT_EQ(doc->getPrenume(), "Georgescu");
    EXPECT_EQ(doc->getSpecializare(), "Pediatrie");
    EXPECT_EQ(doc->getCodOficial(), "D567");
    EXPECT_EQ(doc->getGradProfesional(), "Specialist");
    EXPECT_EQ(doc->getSectie(), "Pediatrie");
    EXPECT_EQ(doc->getAniExperienta(), 15);
    EXPECT_TRUE(doc->esteDisponibil());
}

TEST_F(DoctorTest, TestDisponibilitate) {
    doc->setDisponibil(false);
    EXPECT_FALSE(doc->esteDisponibil());
}

TEST_F(DoctorTest, TestDescriereExperientaSpecialist) {
    EXPECT_EQ(doc->descriereExperienta(), "15 ani experienta");
}

TEST_F(DoctorTest, TestDescriereExperientaRezident) {
    Doctor rez("Andrei", "Pop", "9876543210123", 'M', 28, "01.01.1996", "Cluj", 2, "romana",
               "rezident", "universitar", "Neurologie", "D999", "Rezident", "Neurologie", 0, 2, true);
    EXPECT_EQ(rez.descriereExperienta(), "Anul 2 de rezidentiat");
}

TEST_F(DoctorTest, TestOperator==) {
    Doctor d2("Elena", "Georgescu", "1234567890123", 'F', 40, "12.12.1983", "Bucuresti", 3, "romana",
              "medic", "universitar", "Pediatrie", "D567", "Specialist", "Pediatrie", 15, 0, true);
    EXPECT_TRUE(*doc == d2);
}