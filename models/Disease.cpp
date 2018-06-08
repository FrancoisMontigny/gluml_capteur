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
#include "iostream"
using namespace std;

//------------------------------------------------------ Include personnel
#include "Disease.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Disease::Display()
// Algorithme :
//
{
	cout << "La maladie " << this->name << " a les caractéristiques suivantes : " << "this->caracteristics" << endl;
} //----- Fin de Display

string Disease::GetName()
// Algorithme :
//
{
	return this->name;
} //----- Fin de GetName

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Disease::Disease(const Disease & aDisease)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Disease>" << endl;
#endif
} //----- Fin de Disease (constructeur de copie)

Disease::Disease(const string name, const vector<Measurement> & caracteristics)
// Algorithme :
//
{
	this->name = name;
	this->caracteristics = caracteristics;
#ifdef MAP
    cout << "Appel au constructeur de <Disease>" << endl;
#endif
} //----- Fin de Disease


Disease::Disease()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de <Disease>" << endl;
#endif
} //----- Fin de Disease


Disease::~Disease()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Disease>" << endl;
#endif
} //----- Fin de ~Disease


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

