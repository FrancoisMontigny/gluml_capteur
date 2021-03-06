/*************************************************************************
 PrintAnalyzer  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
 clement.guittat@insa-lyon.fr
 *************************************************************************/

//- Réalisation de la classe <PrintAnalyzer> (fichier PrintAnalyzer.cpp) -

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//------------------------------------------------------ Include personnel
#include "PrintAnalyzer.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC


//----------------------------------------------------- Méthodes publiques



//-------------------------------------------- Constructeurs - destructeur

vector<Disease *> PrintAnalyzer::Analyze(Print & p)
{
    DiseaseManager * dism = DiseaseManager::Get();
    vector<Disease *> res;
    vector<Disease *> vd = dism->GetDiseases();
    for (unsigned int i = 0; i < vd.size(); i++) {
        unsigned int compt = 0;
        vector<Measurement *> vme = vd[i]->GetMeasurements();
        for (unsigned int j = 0; j < vme.size(); j++)
		{
            compt += vme[j]->Comparison(p);
        }
        if (compt >= (unsigned int) 0.75 * vd.size())
		{
            res.push_back(vd[i]);
        }
    }
    return res;
}

PrintAnalyzer::~PrintAnalyzer()
{
#ifdef MAP
    cout << "Appel au destructeur de <PrintAnalyzer>" << endl;
#endif
} //----- Fin de ~PrintAnalyzer


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

PrintAnalyzer::PrintAnalyzer()
// Algorithme :
//
{ 
#ifdef MAP
    cout << "Appel au constructeur de <PrintAnalyzer>" << endl;
#endif
} //----- Fin de PrintAnalyzer


