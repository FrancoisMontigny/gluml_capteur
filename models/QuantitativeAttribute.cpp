/*************************************************************************
 QuantitativeAttribute  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
 clement.guittat@insa-lyon.fr
 *************************************************************************/

//---------- Réalisation de la classe <QuantitativeAttribute> (fichier QuantitativeAttribute.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;


//------------------------------------------------------ Include personnel
#include "QuantitativeAttribute.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string QuantitativeAttribute::GetValue() const
{
	return to_string(this->value);
}

void QuantitativeAttribute::SetValue(string value) {
    double finalValue = stod(value);
    this->value = finalValue;
}

string QuantitativeAttribute::Description() const
// Algorithme :
{
    string s = Attribute::Description() + to_string(this->value);
    return s;
}

QuantitativeAttribute * QuantitativeAttribute::Copy() const
{
	return new QuantitativeAttribute(*this);
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

QuantitativeAttribute::QuantitativeAttribute (const QuantitativeAttribute & aQuantitativeAttribute)
// Algorithme :
//
{
    this->name = aQuantitativeAttribute.name;
#ifdef MAP
    cout << "Appel au constructeur de copie de <QuantitativeAttribute>" << endl;
#endif
} //----- Fin de QuantitativeAttribute (constructeur de copie)

QuantitativeAttribute::QuantitativeAttribute (string name)
// Algorithme :
//
{
    this->name = name;
    this->value = 0;
#ifdef MAP
    cout << "Appel au constructeur de <QuantitativeAttribute>" << endl;
#endif
} //----- Fin de QuantitativeAttribute

QuantitativeAttribute::QuantitativeAttribute (string name, double value)
// Algorithme :
//
{
    this->name = name;
    this->value = value;
#ifdef MAP
    cout << "Appel au constructeur de <QuantitativeAttribute>" << endl;
#endif
} //----- Fin de QuantitativeAttribute


QuantitativeAttribute::~QuantitativeAttribute ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <QuantitativeAttribute>" << endl;
#endif
} //----- Fin de ~QuantitativeAttribute


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

