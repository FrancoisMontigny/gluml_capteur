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
/*Disease DiseaseManager::createDisease(string name, list<Measurement> measurements)
// Algorithme :
//
{
} //----- Fin de Méthode

list<Disease> DiseaseManager::getDiseases()
// Algorithme :
//
{
} //----- Fin de Méthode

Disease DiseaseManager::getDisease(double id)
// Algorithme :
//
{
} //----- Fin de Méthode

Disease DiseaseManager::update(Disease p, string diseaseName)
// Algorithme :
//
{
} //----- Fin de Méthode

int DiseaseManager::save(string path, Disease Diseases[])
// Algorithme :
//
{
} //----- Fin de Méthode

int DiseaseManager::load(string path)
// Algorithme :
//
{
} //----- Fin de Méthode*/

//-------------------------------------------- Constructeurs - destructeur
DiseaseManager::DiseaseManager ( const DiseaseManager & unDiseaseManager )
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

