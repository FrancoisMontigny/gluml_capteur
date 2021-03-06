/*************************************************************************
 QualitativeAttribute  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
 clement.guittat@insa-lyon.fr
 *************************************************************************/

//---------- Réalisation de la classe <QualitativeAttribute> (fichier QualitativeAttribute.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "QualitativeAttribute.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string QualitativeAttribute::GetValue() const
{
	return this->value;
}

void QualitativeAttribute::SetValue(string value)
{
    this->value = value;
}

string QualitativeAttribute::Description() const
// Algorithme :
{
    string s = Attribute::Description() + this->value;
    return s;
}

QualitativeAttribute * QualitativeAttribute::Copy() const
{
	return new QualitativeAttribute(*this);
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

QualitativeAttribute::QualitativeAttribute(const QualitativeAttribute & aQualitativeAttribute)
// Algorithme :
//
{
    this->name = aQualitativeAttribute.name;
    #ifdef MAP
        cout << "Appel au constructeur de copie de <QualitativeAttribute>" << endl;
    #endif
} //----- Fin de QualitativeAttribute (constructeur de copie)

QualitativeAttribute::QualitativeAttribute ( string name )
// Algorithme :
//
{
    this->name = name;
    this->value = "";
#ifdef MAP
    cout << "Appel au constructeur de <QualitativeAttribute>" << endl;
#endif
} //----- Fin de QualitativeAttribute

QualitativeAttribute::QualitativeAttribute(string name, string value)
// Algorithme :
//
{
    this->name = name;
    this->value = value;
#ifdef MAP
    cout << "Appel au constructeur de <QualitativeAttribute>" << endl;
#endif
} //----- Fin de QualitativeAttribute


QualitativeAttribute::~QualitativeAttribute ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <QualitativeAttribute>" << endl;
#endif
} //----- Fin de ~QualitativeAttribute


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

