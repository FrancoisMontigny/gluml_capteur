/*************************************************************************
                           Doctor  -  description
                             -------------------
    début                : 30 avril 2018
    copyright            : (C) 2018 par François Montigny et Clément Guittat
    e-mail               : francois.montigny@insa-lyon.fr 
						   clement.guittat@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Doctor> (fichier Doctor.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Doctor.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
unsigned int Doctor::getDoctorId() const
{
    return this->id;
}
//------------------------------------------------- Surcharge d'opérateurs

ostream & operator << (ostream & os, const Doctor & d)
// Algorithme :
// surcharge d'opérator <<  pour afficher les informations récupérée
{
    os << "The Doctor " << d.firstName <<" "<<d.name << " a comme spécialité " << d.speciality << " et son id est "<< d.id << endl;
    return os;
} //----- Fin de operator <<


//-------------------------------------------- Constructeurs - destructeur
Doctor::Doctor ( const Doctor & unDoctor )
// Algorithme :
//
{
    this->id = AutoNumber();
    this->name = unDoctor.name;
    this->firstName = unDoctor.firstName;
    this->speciality = unDoctor.speciality;
#ifdef MAP
    cout << "Appel au constructeur de copie de <Doctor>" << endl;
#endif
} //----- Fin de Doctor (constructeur de copie)


Doctor::Doctor (string name, string firstName, string speciality)
// Algorithme :
//
{
    this->id = AutoNumber();
    this->name = name;
    this->firstName = firstName;
    this->speciality = speciality;
#ifdef MAP
    cout << "Appel au constructeur de <Doctor>" << endl;
#endif
} //----- Fin de Doctor


Doctor::~Doctor ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Doctor>" << endl;
#endif
} //----- Fin de ~Doctor


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
unsigned int Doctor::AutoNumber()
{
    static unsigned int ID = 0;
    return ++ID;
}