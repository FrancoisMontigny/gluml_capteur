/*************************************************************************
                           PrintManager  -  description
                             -------------------
    début                : 30 avril 2018
    copyright            : (C) 2018 par François Montigny et Clément Guittat
    e-mail               : francois.montigny@insa-lyon.fr 
						   clement.guittat@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <PrintManager> (fichier PrintManager.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "PrintManager.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

// Initialisation du pointeur de singleton à null

PrintManager * PrintManager::singleton = nullptr;

//----------------------------------------------------- Méthodes publiques

Print * PrintManager::CreatePrint(vector<Attribute *> & attributes, unsigned int id, const string disease)
// Algorithme :
//
{
    Print * p = new Print(attributes, id , disease);
    this->prints.push_back(p);
    return p;
} //----- Fin de CreatePrint


PrintManager * PrintManager::Get()
{
    if (!singleton)
    {
        singleton = new PrintManager();
    }
    return singleton;
}

void PrintManager::setDescriptionAttributes(string file)
// Algorithme
//
{
    fileReader fr = fileReader();
    vector<Attribute *> va = fr.descriptionFile(file);
    for (int i=0; i<va.size();i++){
        this->descriptionAttributes.push_back(va[i]);
    }
}

vector<Print *> PrintManager::createPrints(string standardFile)
// Algorithme :
//
{
    fileReader fr = fileReader();
    fr.etalonFile(standardFile);
    vector<Print *> res;
    /*Print * p = new Print(attributes, id , disease);
    this->prints.push_back(p);*/
    return res;
} //----- Fin de Méthode


Print * PrintManager::CreatePrint(Print & aPrint)
// Algorithme :
//
{
    Print * p = new Print(aPrint);
    this->prints.push_back(p);
    return p;
} //----- Fin de CreatePrint

vector<Print *> PrintManager::GetPrints()
// Algorithme :
//
{
    return this->prints;
} //----- Fin de GetPrints

Print * PrintManager::GetPrint(unsigned int id)
// Algorithme :
//
{
    vector<Print *>::iterator findIter = find_if(this->prints.begin(), this->prints.end(), [id](Print * p)-> bool {return (p->GetId() == id); } );
    return *findIter;
} //----- Fin de GetPrint

Print * PrintManager::Update(Print * p, string diseaseName)
// Algorithme :
//
{
	Print * actualPrint = this->GetPrint(p->id);
	if (actualPrint->diseaseName.size() == 0)
	{
		actualPrint->diseaseName = diseaseName;
		return actualPrint;
	}
	Print * newPrint = this->CreatePrint(*p);
	newPrint->diseaseName = diseaseName;
	
	return newPrint;
} //----- Fin de Update

/*int PrintManager::save(string path, Print Prints[])
// Algorithme :
//
{
} //----- Fin de Méthode

int PrintManager::load(string path)
// Algorithme :
//
{
} //----- Fin de Méthode*/

//-------------------------------------------- Constructeurs - destructeur
<<<<<<< HEAD
PrintManager::PrintManager(const PrintManager & aPrintManager)
=======

PrintManager::~PrintManager ( )
>>>>>>> b2cfd08bb27ca25602c6e83a857be0317c90b2e7
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <PrintManager>" << endl;
#endif
} //----- Fin de ~PrintManager


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
PrintManager::PrintManager ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <PrintManager>" << endl;
#endif
} //----- Fin de PrintManager
