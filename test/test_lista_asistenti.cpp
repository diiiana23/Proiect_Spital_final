#include "gtest/gtest.h"
#include "ListaAsistenti.h"

TEST(ListaAsistentiTest, FiltrareDupaDiagnostic) {
    auto lista = ListaAsistenti::creeazaAsistenti();
    auto rezultat = ListaAsistenti::filtreazaDupaDiagnostic(lista, "Neurologie");

    for (const auto& a : rezultat) {
        EXPECT_EQ(a.getSpecializare(), "Neurologie");
    }
}

TEST(ListaAsistentiTest, SortareDupaReview) {
    std::vector<AsistentMedical> lista = {
        AsistentMedical("Ana", "Pop", "123", 'F', 28, "01.01.1996", "Bucuresti", 1, "romana", "asistent", "mediu", 3, 2, "ORL", 2, 7.1),
        AsistentMedical("Ion", "Radu", "124", 'M', 30, "02.02.1994", "Bucuresti", 1, "romana", "asistent", "mediu", 5, 3, "ORL", 4, 9.2)
    };

    ListaAsistenti::sorteazaAsistenti(lista, "review");

    EXPECT_GE(lista[0].getReview(), lista[1].getReview());
}

TEST(ListaAsistentiTest, SortareDupaExperienta) {
    std::vector<AsistentMedical> lista = {
        AsistentMedical("Ana", "Pop", "123", 'F', 28, "01.01.1996", "Bucuresti", 1, "romana", "asistent", "mediu", 3, 2, "ORL", 2, 8.1),
        AsistentMedical("Ion", "Radu", "124", 'M', 30, "02.02.1994", "Bucuresti", 1, "romana", "asistent", "mediu", 6, 3, "ORL", 4, 7.9)
    };

    ListaAsistenti::sorteazaAsistenti(lista, "experienta");

    EXPECT_GE(lista[0].getAniExperienta(), lista[1].getAniExperienta());
}

TEST(ListaAsistentiTest, AdaugaReview) {
    AsistentMedical a("Ana", "Pop", "123", 'F', 28, "01.01.1996", "Bucuresti", 1, "romana", "asistent", "mediu", 3, 2, "ORL", 2, 8.0);

    ListaAsistenti::adaugaReview(a, 10);

    EXPECT_EQ(a.getNrConsultatii(), 3);
    EXPECT_NEAR(a.getReview(), (8.0 * 2 + 10) / 3.0, 0.01);
}