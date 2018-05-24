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
#include <list>

#include "Doctor.h"
#include "DoctorManager.h"

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
    Doctor Connection(unsigned int id);
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
	
	void RunAnalysis(string[] path);
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

