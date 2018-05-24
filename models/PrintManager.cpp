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

//----------------------------------------------------- Méthodes publiques
Print * PrintManager::createPrint(vector<Attribute *> &attributes, string disease)
// Algorithme :
//
{
    Print * p = new Print(attributes, 0, disease);
    this->prints.push_back(p);
    return p;
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
PrintManager::PrintManager ( const PrintManager & unPrintManager )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <PrintManager>" << endl;
#endif
} //----- Fin de PrintManager (constructeur de copie)


PrintManager::PrintManager ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <PrintManager>" << endl;
#endif
} //----- Fin de PrintManager


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

