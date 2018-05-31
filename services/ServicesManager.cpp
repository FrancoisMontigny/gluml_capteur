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
    PrintManager * pa = PrintManager::Get();
    pa->setDescriptionAttributes(descriptionFile);
    //pa->createPrints(standardFile);
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

void ServicesManager::RunAnalysis(ifstream & fi)
{
    PrintAnalyzer pa = PrintAnalyzer();
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
    delete(dom);
#ifdef MAP
    cout << "Appel au destructeur de <ServicesManager>" << endl;
#endif
} //----- Fin de ~ServicesManager


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

