/*************************************************************************
 ServicesManager  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
						clement.guittat@insa-lyon.fr
 *************************************************************************/

//Réalisation de la classe <ServicesManager> (fichier ServicesManager.cpp)

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ServicesManager.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

Doctor * ServicesManager::Connection(string nom)
{
	DoctorManager * dom = DoctorManager::Get();
	
	Doctor * d = dom->GetDoctor(nom);
    
	return d;	
} //----- Fin de Connection

Doctor * ServicesManager::CreateDoctor(string name, string firstName, string speciality)
{
    DoctorManager * dom = DoctorManager::Get();
    return dom->CreateDoctor(name, firstName, speciality);
} //----- Fin de CreateDoctor

void ServicesManager::RunAnalysis(string file)
{
    PrintManager * pm = PrintManager::Get();
    unsigned int posInList = pm->Load(file);
    vector<Print *> prints = pm->GetPrints();
    PrintAnalyzer pa = PrintAnalyzer();
    for (unsigned int i = posInList; i < prints.size(); i++)
	{
		vector<Disease *> diseases = pa.Analyze(*prints[i]);
        cout << "Résultats de l'analyse pour l'empreinte " << prints[i]->GetId()<<" :" << endl;
		if (diseases.size() == 0)
		{
			cout << "Cette empreinte ne montre aucun risque de maladie." << endl;
		}
		else
		{
			cout << "Cette présente des risques ; il est possible que le patient ait la ou les maladies suivantes :" << endl;
			for (unsigned int j = 0; j < diseases.size(); j++)
			{
				cout << diseases[i]->GetName() << endl;
			}
		}
    }
}

void ServicesManager::DisplayDiseases()
{
	DiseaseManager * dm = DiseaseManager::Get();
    vector<Disease *> diseases = dm->GetDiseases();
	
	for (unsigned int i = 0; i < diseases.size(); i++)
	{
		diseases[i]->Display();
	}
}

void ServicesManager::DisplayDisease(string name)
{
	DiseaseManager * dm = DiseaseManager::Get();
	Disease * disease = dm->GetDisease(name);
    disease->Display();
}

//-------------------------------------------- Constructeurs - destructeur

ServicesManager::ServicesManager()
// Algorithme :
//
{
    PrintManager::Get();
    DoctorManager::Get();
    DiseaseManager::Get();
#ifdef MAP
    cout << "Appel au constructeur de <ServicesManager>" << endl;
#endif
} //----- Fin de ServicesManager

ServicesManager::~ServicesManager()
// Algorithme :
//
{
    DoctorManager * dom = DoctorManager::Get();
    PrintManager * pm = PrintManager::Get();
    DiseaseManager * dism = DiseaseManager::Get();
    delete(dom);
    delete(pm);
    delete(dism);
#ifdef MAP
    cout << "Appel au destructeur de <ServicesManager>" << endl;
#endif
} //----- Fin de ~ServicesManager


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

