/*************************************************************************
                           Attribute  -  description
                             -------------------
    début                : 30 avril 2018
    copyright            : (C) 2018 par François Montigny et Clément Guittat
    e-mail               : francois.montigny@insa-lyon.fr 
						   clement.guittat@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Attribute> (fichier Attribute.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Attribute.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string Attribute::description() const
{
    string s = "L'empreinte possède l'attribut " + this->name + " dont la valeur est ";
    return s;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Attribute::Attribute()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Attribute>" << endl;
#endif
} //----- Fin de Attribute

Attribute::~Attribute ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Attribute>" << endl;
#endif
} //----- Fin de ~Attribute


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

