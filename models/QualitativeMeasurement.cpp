/*************************************************************************
 QualitativeMeasurement  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
 clement.guittat@insa-lyon.fr
 *************************************************************************/

//---------- Réalisation de la classe <QualitativeMeasurement> (fichier QualitativeMeasurement.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "QualitativeMeasurement.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

QualitativeMeasurement::QualitativeMeasurement (const QualitativeMeasurement & unQualitativeMeasurement)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <QualitativeMeasurement>" << endl;
#endif
} //----- Fin de QualitativeMeasurement (constructeur de copie)


QualitativeMeasurement::QualitativeMeasurement ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <QualitativeMeasurement>" << endl;
#endif
} //----- Fin de QualitativeMeasurement


QualitativeMeasurement::~QualitativeMeasurement ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <QualitativeMeasurement>" << endl;
#endif
} //----- Fin de ~QualitativeMeasurement


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

