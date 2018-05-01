/*************************************************************************
 Disease  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
 clement.guittat@insa-lyon.fr
 *************************************************************************/

//---------- Réalisation de la classe <Disease> (fichier Disease.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "Disease.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Disease::display()
// Algorithme :
//
{
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Disease::Disease ( const Disease & unDisease )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Disease>" << endl;
#endif
} //----- Fin de Disease (constructeur de copie)


Disease::Disease ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Disease>" << endl;
#endif
} //----- Fin de Disease


Disease::~Disease ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Disease>" << endl;
#endif
} //----- Fin de ~Disease


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

