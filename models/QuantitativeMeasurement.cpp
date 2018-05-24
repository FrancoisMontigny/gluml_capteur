/*************************************************************************
 QuantitativeMeasurement  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
 clement.guittat@insa-lyon.fr
 *************************************************************************/

//---------- Réalisation de la classe <QuantitativeMeasurement> (fichier QuantitativeMeasurement.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "QuantitativeMeasurement.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

QuantitativeMeasurement::QuantitativeMeasurement (const QuantitativeMeasurement & aQuantitativeMeasurement)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <QuantitativeMeasurement>" << endl;
#endif
} //----- Fin de QuantitativeMeasurement (constructeur de copie)


QuantitativeMeasurement::QuantitativeMeasurement ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <QuantitativeMeasurement>" << endl;
#endif
} //----- Fin de QuantitativeMeasurement


QuantitativeMeasurement::~QuantitativeMeasurement ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <QuantitativeMeasurement>" << endl;
#endif
} //----- Fin de ~QuantitativeMeasurement


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

