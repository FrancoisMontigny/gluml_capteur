/*************************************************************************
 DiseaseManager  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
 clement.guittat@insa-lyon.fr
 *************************************************************************/

//---------- Réalisation de la classe <DiseaseManager> (fichier DiseaseManager.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>
#include <list>

//------------------------------------------------------ Include personnel
#include "DiseaseManager.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
Disease DiseaseManager::createDisease(string name, list<Measurement> measurements)
// Algorithme :
//
{
	Disease * newDisease = new Disease(name, measurements);
	diseases.insert(diseases.end(), &newDisease);
} //----- Fin de Méthode

list<Disease> DiseaseManager::GetDiseases()
// Algorithme :
//
{
	return this->diseases;
} //----- Fin de GetDiseases

Disease DiseaseManager::GetDisease(string name)
// Algorithme :
//
{
	list<Disease>::iterator it = this->diseases.begin();
	
	while (it != this->diseases.end() && (*it).GetName() != name) 
	{
		++it;
	}
	
	if (it == this->diseases.end())
	{
		return nullptr;
	}
	
	return (*it).GetName();
} //----- Fin de GetDisease

Disease DiseaseManager::Update(Disease d)
// Algorithme :
//
{
	return d; //TODO
} //----- Fin de Update

int DiseaseManager::Save(string path, Disease Diseases[])
// Algorithme :
//
{
	return -1; //TODO
} //----- Fin de Save

int DiseaseManager::Load(string path)
// Algorithme :
//
{
	return -1;
} //----- Fin de Load

//-------------------------------------------- Constructeurs - destructeur
DiseaseManager::DiseaseManager(const DiseaseManager & aDiseaseManager)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <DiseaseManager>" << endl;
#endif
} //----- Fin de DiseaseManager (constructeur de copie)


DiseaseManager::DiseaseManager ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <DiseaseManager>" << endl;
#endif
} //----- Fin de DiseaseManager


DiseaseManager::~DiseaseManager ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <DiseaseManager>" << endl;
#endif
} //----- Fin de ~DiseaseManager


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

