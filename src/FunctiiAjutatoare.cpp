#include "FunctiiAjutatoare.h"

// functie in care calculez COSTUL operatiei
int FunctiiAjutatoare::calculezCostul(int grad)
{
    switch (grad) {
        case 1: return 150;
        case 2: return 200;
        case 3: return 300;
        case 4: return 450;
        case 5: return 600;
    }
    return 0;
}

//functie in care calculez cate ZILE tb sa stea PACIENTUL INTERNAT
int FunctiiAjutatoare::zileInternare(const Pacient& p)
{
    int grad = p.gradProblema();
    if (grad == 1)
        return 0;
    if (grad == 2 || grad == 3)
        return 2;
    return 4;
}

// functie pentru atribuirea unei anumite SECTII la fiecare PROBLEMA
std::string FunctiiAjutatoare::Specializare_Problema(const std::string& problema)
{
    // DIAGNOSTIC PRINCIPAL
    if (problema == "Infectie respiratorie acuta" || problema == "Criza de astm bronsic" ||
        problema == "Pneumonie" || problema == "Laringotraheita")
        return "Pneumologie";

    if (problema == "Gastroenterita" || problema == "Diabet zaharat dezechilibrat" || problema == "Hipertensiune arteriala")
        return "Medicina Interna";

    if (problema == "Fractura membru superior")
        return "Ortopedie";

    if (problema == "Boli si tulburari ale sistemului nervos" || problema == "Meningita virala" || problema == "Accident vascular ischemic")
        return "Neurologie";

    if (problema == "Apendicita acuta" || problema == "Angina pectorala")
        return "Chirurgie Generala";

    if (problema == "Infectiile acute majore ale ochiului")
        return "Oftalmologie";

    if (problema == "Covid-19")
        return "Boli Infectioase";

    // DIAGNOSTIC SECUNDAR
    if (problema == "Anemie feripriva" || problema == "Oboseala cronica")
        return "Medicina Interna";

    if (problema == "Alergie sezoniera")
        return "Alergologie";

    if (problema == "Durere lombara" || problema == "Migrena" || problema == "Insomnie")
        return "Neurologie";

    if (problema == "Hipocalcemie" || problema == "Hipotiroidism")
        return "Endocrinologie";

    if (problema == "Otita medie" || problema == "Sinuzita")
        return "ORL";

    if (problema == "Boala de reflux gastroesofagian")
        return "Gastroenterologie";

    if (problema == "Infectie urinara")
        return "Nefrologie";

    if (problema == "Tulburari de ritm cardiac")
        return "Cardiologie";

    if (problema == "Dermatita atopica")
        return "Dermatologie";

    if (problema == "Deficit de vitamina D")
        return "Nutritie";

    return "Medicina Generala";
}

// fct pestru evitarea erorilor legate de SPATII IN PLUS
std::string FunctiiAjutatoare::trim(const std::string& s)
{
    size_t start = s.find_first_not_of(" ");        // size_t (unsigned) - pt ind, dim
    size_t end = s.find_last_not_of(" ");
    if (start == std::string::npos)            // daca toate caracterele sunt " "
        return "";
    else
        return s.substr(start, end-start+1);    //sub-stringul de la primul caracter non-spațiu pana la ultimul
}

// functia de gasire a medicului potrivit pt macient (3 criterii: disponibil; grad; specializare)
std::vector<int> FunctiiAjutatoare::gasesc_DoctoriPotriviti(const Pacient& pacient, const std::vector<Doctor>& doctori)
{
    std::vector<int> aux;        // vectorul auxiliar (retinem indicii buni)
    std::string specializare_cautata = FunctiiAjutatoare::Specializare_Problema(pacient.getDiagnosticPrincipal());
    std::string grad_cautat = pacient.tipMedic();

    for (size_t i = 0; i < doctori.size(); i++) {
        const Doctor& doc = doctori[i];
        if (doc.esteDisponibil() &&
            trim(doc.getSpecializare()) == trim(specializare_cautata) &&
            trim(doc.getGradProfesional()) == trim(grad_cautat))
        {
            aux.push_back(i);
        }
    }
    return aux;
}