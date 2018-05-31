/*************************************************************************
 ServicesManager  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
 clement.guittat@insa-lyon.fr
 *************************************************************************/

//---------- Réalisation de la classe <ServicesManager> (fichier ServicesManager.cpp) ------------

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

Doctor* ServicesManager::Connection(string nom)
// Algorithme :
//
{
	DoctorManager * dom = DoctorManager::Get();
	
	Doctor * d = dom->GetDoctor(nom);
    
	return d;	
} //----- Fin de Connection

Doctor * ServicesManager::CreateNewDoctor(string name, string firstName, string speciality)
// Algorithme :
//
{
    DoctorManager * dom = DoctorManager::Get();
    return dom->CreateDoctor(name, firstName, speciality);
}

void ServicesManager::initializeBDPrints(string descriptionFile, string standardFile)
// Algorithme
//
{
    PrintManager * pm = PrintManager::Get();
    pm->setDescriptionAttributes(descriptionFile);
    pm->createPrints(standardFile);
    /*vector<Print *> vp = pa->GetPrints();
    for (int i = 0; i< vp.size(); i++){
        cout << vp[i]->Serialize() << endl;
    }*/
}

void ServicesManager::RunAnalysis(string file)
{
    PrintManager * pm = PrintManager::Get();
    pm->createPrints(file);
    vector<Print *> vp = pm->GetPrints();
    for (int i=0; i< vp.size(); i++){
        cout << vp[i]->Serialize() << endl;
    }
    //PrintAnalyzer pa = PrintAnalyzer();
}

void ServicesManager::DisplayDiseases()
// Algorithme :
//
{
	//TODO check if singleton with DoctorManager works, apply to DiseaseManager and implement	
}

void ServicesManager::DisplayDisease(string name)
{
	//TODO
}

//-------------------------------------------- Constructeurs - destructeur
ServicesManager::ServicesManager(const ServicesManager & aServicesManager)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ServicesManager>" << endl;
#endif
} //----- Fin de ServicesManager (constructeur de copie)


ServicesManager::ServicesManager()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ServicesManager>" << endl;
#endif
} //----- Fin de ServicesManager


ServicesManager::~ServicesManager ( )
// Algorithme :
//
{
    DoctorManager * dom = DoctorManager::Get();
    PrintManager * pm = PrintManager::Get();
    delete(dom);
    delete(pm);
#ifdef MAP
    cout << "Appel au destructeur de <ServicesManager>" << endl;
#endif
} //----- Fin de ~ServicesManager


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

