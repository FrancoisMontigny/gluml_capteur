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
#include <string>
#include <vector>
using namespace std;

//------------------------------------------------------ Include personnel
#include "PrintManager.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

// Initialisation du pointeur de singleton à null

PrintManager * PrintManager::singleton = nullptr;

//----------------------------------------------------- Méthodes publiques

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

vector<Print*> PrintManager::getPrints()
// Algorithme :
//
{
    return this->prints;
} //----- Fin de Méthode

Print* PrintManager::getPrint(unsigned int id)
// Algorithme :
//
{
    vector<Print*>::iterator findIter = find_if(this->prints.begin(), this->prints.end(), [id](Print * p)-> bool {return (p->getPrintId() == id); } );
    return *findIter;
} //----- Fin de Méthode

/*Print* PrintManager::update(Print* p, string diseaseName)
// Algorithme :
//
{
} //----- Fin de Méthode*/

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

PrintManager::~PrintManager ( )
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
