/*************************************************************************
 DiseaseManager  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
						clement.guittat@insa-lyon.fr
 *************************************************************************/

//Réalisation de la classe <DiseaseManager> (fichier DiseaseManager.cpp) -

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "DiseaseManager.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

// Initialisation du pointeur de singleton à null

DiseaseManager *  DiseaseManager::singleton = nullptr;

//----------------------------------------------------- Méthodes publiques

DiseaseManager * DiseaseManager::Get()
{
    if (!singleton)
    {
        singleton = new DiseaseManager;
    }
    return singleton;
} //----- Fin de Get

Disease * DiseaseManager::CreateDisease(string name, vector<Measurement *> measurements)
{
	Disease * newDisease = new Disease(name, measurements);
    this->diseases.push_back(newDisease);
    return newDisease;
} //----- Fin de CreateDisease

vector<Disease *> DiseaseManager::GetDiseases()
{
	return this->diseases;
} //----- Fin de GetDiseases

Disease * DiseaseManager::GetDisease(string name)
{
	vector<Disease *>::iterator it = this->diseases.begin();
	
	while (it != this->diseases.end() && (*it)->GetName() != name)
	{
		++it;
	}
	
	if (it == this->diseases.end())
	{
        return nullptr;
	}
	
	return *(it);
} //----- Fin de GetDisease

Disease * DiseaseManager::Update(Disease * d)
{
    // recalcul des valeurs de Disease
	return d; //TODO
} //----- Fin de Update

int DiseaseManager::Save(string path)
// Algorithme :
//
{
	ofstream of;
    of.open("fichiersTest/" + path);
    FileWriter fw = FileWriter();
    for (int i = 0; i < this->diseases.size(); i++)
	{
        fw.WriteDisease(of, this->diseases[i]);
    }
    of.close();
    return 0;
} //----- Fin de Save

int DiseaseManager::Load(string path)
// Algorithme :
//
{
	return -1;
} //----- Fin de Load

//-------------------------------------------- Constructeurs - destructeur

DiseaseManager::~DiseaseManager()
// Algorithme :
//
{
    vector<Disease *>::const_iterator ItList;
    for (ItList = this->diseases.begin(); ItList != this->diseases.end(); ItList++){
        delete (*ItList);
    }
#ifdef MAP
    cout << "Appel au destructeur de <DiseaseManager>" << endl;
#endif
} //----- Fin de ~DiseaseManager


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
DiseaseManager::DiseaseManager()
// Algorithme :
//
{
    
#ifdef MAP
    cout << "Appel au constructeur de <DiseaseManager>" << endl;
#endif
} //----- Fin de DiseaseManager
