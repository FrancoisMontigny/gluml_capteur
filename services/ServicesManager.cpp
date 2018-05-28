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
using namespace std;
#include <iostream>
#include <string>
#include <list>

//------------------------------------------------------ Include personnel
#include "ServicesManager.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

Doctor* ServicesManager::Connection(unsigned int id)
// Algorithme :
//
{
	DoctorManager * dom = DoctorManager::Get();
	
	Doctor * d = dom->GetDoctor(id);
	
	if (d == *dom->GetDoctors().end())
	{
		return nullptr;
	}
	return d;	
} //----- Fin de Connection

void ServicesManager::DisplayDiseases()
{
	//TODO check if singleton with DoctorManager works, apply to DiseaseManager and implement	
}

void ServicesManager::DisplayDisease(string name)
{
	//TODO
}

void ServicesManager::RunAnalysis(string path)
{
	//TODO
	//read path to get printf
	//create new print analyzer
	//analyser.analyze(print)
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
#ifdef MAP
    cout << "Appel au destructeur de <ServicesManager>" << endl;
#endif
} //----- Fin de ~ServicesManager


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

