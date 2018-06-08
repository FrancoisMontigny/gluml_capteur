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
#include <vector>

#include "./Doctor.h"
#include "../fileOperations/fileReader.h"
#include "../fileOperations/fileWriter.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

typedef vector<Doctor *> ListDoctor;

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

    static DoctorManager * Get();
    // Mode d'emploi : récupérer l'instance unique de la classe. 
    //
    // Contrat :
    //

	Doctor * CreateDoctor(string name, string firstName, string speciality);
    // Mode d'emploi :
    //
    // Contrat :
    //

	ListDoctor GetDoctors();
	// Mode d'emploi :
	//
	// Contrat :
	//

	Doctor* GetDoctor(string nom);
	// Mode d'emploi :
	//
	// Contrat :
	//

	int Save(string path = "identification.txt");
	// Mode d'emploi :
	//
	// Contrat :
	//

	vector <string> Load(string path);
	// Mode d'emploi :
	//
	// Contrat :
	//
	
	DoctorManager& operator = (const DoctorManager&) = delete;

//-------------------------------------------- Constructeurs - destructeur
		
	DoctorManager (const DoctorManager &) = delete;
	// Copier un singleton est illégal

    virtual ~DoctorManager();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    unsigned int AutoNumber();
    
	DoctorManager(string path = "identification.txt");
    // Mode d'emploi :
    //
    // Contrat :
    //

//----------------------------------------------------- Attributs protégés
	ListDoctor doctors;
	
	static DoctorManager * singleton;
};

//-------------------------------- Autres définitions dépendantes de <DoctorManager>

#endif // DoctorManager_H

