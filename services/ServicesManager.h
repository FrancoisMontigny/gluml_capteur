/*************************************************************************
 ServicesManager  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
 clement.guittat@insa-lyon.fr
 *************************************************************************/

//---------- Interface de la classe <ServicesManager> (fichier ServicesManager.h) ----------------
#if ! defined ( ServicesManager_H )
#define ServicesManager_H

//--------------------------------------------------- Interfaces utilisées

#include <string>
#include <vector>

#include "../models/Doctor.h"
#include "../models/DoctorManager.h"
#include "../models/DiseaseManager.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ServicesManager>
//
//
//------------------------------------------------------------------------

class ServicesManager
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
    Doctor* Connection(string name);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    Doctor * CreateNewDoctor(string name, string firstName, string speciality);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    void DisplayDiseases();
    // Mode d'emploi :
    //
    // Contrat :
    //
	
	void DisplayDisease(string name);
    // Mode d'emploi :
    //
    // Contrat :
    //
	
	void RunAnalysis(string path);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //-------------------------------------------- Constructeurs - destructeur
    ServicesManager(const ServicesManager & aServicesManager);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    ServicesManager();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    virtual ~ServicesManager();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <ServicesManager>

#endif // ServicesManager_H

