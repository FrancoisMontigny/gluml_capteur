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

string Doctor::Serialize() const
{
	string answer = to_string(this->id);
	answer += ";";
    answer += this->name;
	answer += ";";
    answer += this->firstName;
	answer += ";";
	answer += this->speciality;	
	
	return answer;
}

//------------------------------------------------- Surcharge d'opérateurs

ostream & operator << (ostream & os, const Doctor & d)
// Algorithme :
// surcharge d'opérator <<  pour afficher les informations récupérée
{
    os << "Le docteur " << d.firstName << " " << d.name << " a comme spécialité " << d.speciality << " et son id est " << d.id << endl;
    return os;
} //----- Fin de operator <<


//-------------------------------------------- Constructeurs - destructeur
Doctor::Doctor(const Doctor & aDoctor)
// Algorithme :
//
{
    this->id = AutoNumber();
    this->name = aDoctor.name;
    this->firstName = aDoctor.firstName;
    this->speciality = aDoctor.speciality;
#ifdef MAP
    cout << "Appel au constructeur de copie de <Doctor>" << endl;
#endif
} //----- Fin de Doctor (constructeur de copie)


Doctor::Doctor(string name, string firstName, string speciality)
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


Doctor::~Doctor()
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
