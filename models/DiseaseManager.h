/*************************************************************************
 DiseaseManager  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
 clement.guittat@insa-lyon.fr
 *************************************************************************/

//---------- Interface de la classe <DiseaseManager> (fichier DiseaseManager.h) ----------------
#if ! defined ( DiseaseManager_H )
#define DiseaseManager_H

//--------------------------------------------------- Interfaces utilisées

#include <string>
#include <list>

#include "Disease.h"
#include "Measurement.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <DiseaseManager>
//
//
//------------------------------------------------------------------------

class DiseaseManager
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
    Disease createDisease(string name, list<Measurement> measurements);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    list<Disease> getDiseases();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    Disease getDisease(double id);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    Disease update(Disease p, string diseaseName);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    int save(string path, Disease Diseases[]);
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
    DiseaseManager(const DiseaseManager & unDiseaseManager);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    DiseaseManager ();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    virtual ~DiseaseManager ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    list<Disease> Diseases;
};

//-------------------------------- Autres définitions dépendantes de <DiseaseManager>

#endif // DiseaseManager_H

