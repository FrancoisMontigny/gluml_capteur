/*************************************************************************
                           DoctorManager  -  description
                             -------------------
    début                : 30 avril 2018
    copyright            : (C) 2018 par François Montigny et Clément Guittat
    e-mail               : francois.montigny@insa-lyon.fr 
						   clement.guittat@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <DoctorManager> (fichier DoctorManager.h) ----------------
#if ! defined ( DoctorManager_H )
#define DoctorManager_H

//--------------------------------------------------- Interfaces utilisées

#include <string>
#include <list>

#include "Doctor.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

typedef list<Doctor*> ListDoctor;

//------------------------------------------------------------------------
// Rôle de la classe <DoctorManager>
//
//
//------------------------------------------------------------------------

class DoctorManager
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	Doctor* createDoctor(string name, string firstName, string speciality);
    // Mode d'emploi :
    //
    // Contrat :
    //

	ListDoctor getDoctors();
	// Mode d'emploi :
	//
	// Contrat :
	//

	Doctor* getDoctor(unsigned int id);
	// Mode d'emploi :
	//
	// Contrat :
	//

	int save(string path);
	// Mode d'emploi :
	//
	// Contrat :
	//

	int load(string path);
	// Mode d'emploi :
	//
	// Contrat :
	//

//-------------------------------------------- Constructeurs - destructeur
    DoctorManager ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~DoctorManager ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	ListDoctor doctors;
};

//-------------------------------- Autres définitions dépendantes de <DoctorManager>

#endif // DoctorManager_H

