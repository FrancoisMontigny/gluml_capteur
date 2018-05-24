/*************************************************************************
 DoctorManager  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
 clement.guittat@insa-lyon.fr
 *************************************************************************/

//---------- Réalisation de la classe <DoctorManager> (fichier DoctorManager.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <list>
#include <algorithm>
using namespace std;

//------------------------------------------------------ Include personnel
#include "DoctorManager.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

// Initialisation du pointeur de singleton à null

DoctorManager * DoctorManager::singleton = nullptr;

//----------------------------------------------------- Méthodes publiques

static DoctorManager * Get() 
{ 
	if (!singleton) 
	{
		singleton = new DoctorManager;
	}
	return singleton;
}

Doctor * DoctorManager::CreateDoctor(string name, string firstName, string speciality)
// Algorithme :
//
{
    Doctor * d = new Doctor (name, firstName, speciality);
    this->doctors.push_back(d);
    return d;
} //----- Fin de Méthode

ListDoctor DoctorManager::GetDoctors()
// Algorithme :
//
{
    return this->doctors;
} //----- Fin de Méthode

Doctor * DoctorManager::GetDoctor(unsigned int id)
// Algorithme :
//
{
    ListDoctor::iterator findIter = find_if(this->doctors.begin(), this->doctors.end(), [id](Doctor * d)-> bool {return (d->getDoctorId() == id); } );
    return *findIter;
} //----- Fin de Méthode

int DoctorManager::Save(string path)
 // Algorithme :
 //
 {
	 return -1; //TODO
 } //----- Fin de Méthode
 
 int DoctorManager::Load(string path)
 // Algorithme :
 //
 {
	 return -1; //TODO
 } //----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur


DoctorManager::~DoctorManager()
// Algorithme :
//
{
    ListDoctor::const_iterator ItList;
    for (ItList = this->doctors.begin(); ItList != this->doctors.end(); ItList++){
        delete (*ItList);
    }
#ifdef MAP
    cout << "Appel au destructeur de <DoctorManager>" << endl;
#endif
} //----- Fin de ~DoctorManager


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

protected:



DoctorManager::DoctorManager()
// Algorithme :
//
{
	//TODO : load doctors 
#ifdef MAP
    cout << "Appel au constructeur de <DoctorManager>" << endl;
#endif
} //----- Fin de DoctorManager


