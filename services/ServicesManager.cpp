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

Doctor Connection(unsigned int id)
// Algorithme :
//
{
	DoctorManager * dm = DoctorManager::get();
	
	Doctor d = dm->GetDoctor(id);
	
	if (d == dm->GetDoctors().end())
	{
		return nullptr;
	}
	return d;	
} //----- Fin de Méthode


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

