/*************************************************************************
 DiseaseManager  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
						clement.guittat@insa-lyon.fr
 *************************************************************************/

//-- Interface de la classe <DiseaseManager> (fichier DiseaseManager.h) --
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
// Rôle de la classe <DiseaseManager> : DiseaseManager gère la 
// construction, la sauvegarde et le chargement des objets Disease.
// Ce Manager permet également de retrouver des maladies par leur nom.
//
//------------------------------------------------------------------------

class DiseaseManager
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
    
    static DiseaseManager * Get();
    // Mode d'emploi : Récupérer l'instance unique de la classe.
    //
    // Contrat : Aucun.
    //
    
    Disease* CreateDisease(string name, vector<Measurement> measurements);
    // Mode d'emploi : Créer un objet Disease.
    //
    // Contrat : Aucun.
    //
    
    vector<Disease *> GetDiseases();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    Disease * GetDisease(string name);
    // Mode d'emploi : Récupérer une maladie par son nom.
    //
    // Contrat : Aucun.
    //
    
    Disease * Update(Disease * d);
    // Mode d'emploi : Mettre à jour les caractéristiques d'une maladie.
    //
    // Contrat : Aucun.
    //
    
    int Save(string path);
    // Mode d'emploi : Sauvegarder les objets Disease dans un fichier dont
	// le chemin d'accès est donné par path.
    //
    // Contrat :
    //
    
    int Load(string path);
    // Mode d'emploi : Charger un fichier de Disease, path étant le chemin
	// d'accès du fichier.
    //
    // Contrat : Aucun.
    //
    
    //-------------------------------------------- Constructeurs - destructeur
    DiseaseManager(const DiseaseManager &) = delete;
    // Copier un singleton n'est pas autorisé
    
    virtual ~DiseaseManager();
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    DiseaseManager();
    
    //----------------------------------------------------- Attributs protégés
    vector<Disease *> diseases;
    static DiseaseManager * singleton;
};

//-------------------------------- Autres définitions dépendantes de <DiseaseManager>

#endif // DiseaseManager_H

