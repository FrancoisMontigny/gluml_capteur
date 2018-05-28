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
    static DiseaseManager * Get();
    // Mode d'emploi : récupérer l'instance unique de la classe.
    //
    // Contrat :
    //
    
    Disease* createDisease(string name, vector<Measurement> measurements);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    vector<Disease *> GetDiseases();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    Disease* GetDisease(string name);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    Disease * update(Disease * d);
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
    DiseaseManager (const DiseaseManager &) = delete;
    // Copying a singleton is illegal
    
    virtual ~DiseaseManager ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    DiseaseManager();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //----------------------------------------------------- Attributs protégés
    vector<Disease *> diseases;
    
    static DiseaseManager * singleton;
};

//-------------------------------- Autres définitions dépendantes de <DiseaseManager>

#endif // DiseaseManager_H

