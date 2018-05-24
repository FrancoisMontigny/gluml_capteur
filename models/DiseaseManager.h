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
#include <vector>

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
    Disease createDisease(string name, vector<Measurement> measurements);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    vector<Disease> GetDiseases();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    Disease GetDisease(double id);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    Disease update(Disease d);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    int Save(string path, Disease Diseases[]);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    int Load(string path);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //-------------------------------------------- Constructeurs - destructeur
    DiseaseManager(const DiseaseManager & aDiseaseManager);
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
    vector<Disease> diseases;
};

//-------------------------------- Autres définitions dépendantes de <DiseaseManager>

#endif // DiseaseManager_H

