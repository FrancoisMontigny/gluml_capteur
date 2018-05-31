/*************************************************************************
                           PrintManager  -  description
                             -------------------
    début                : 30 avril 2018
    copyright            : (C) 2018 par François Montigny et Clément Guittat
    e-mail               : francois.montigny@insa-lyon.fr 
						   clement.guittat@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <PrintManager> (fichier PrintManager.h) ----------------
#if ! defined ( PrintManager_H )
#define PrintManager_H

//--------------------------------------------------- Interfaces utilisées

#include <string>
#include <vector>
#include "./Print.h"
#include "./Attribute.h"
#include "../fileOperations/fileReader.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <PrintManager>
//
//
//------------------------------------------------------------------------

class PrintManager
{
//----------------------------------------------------------------- PUBLIC

public:

//------------------------------------------------- Surcharge d'opérateurs
    
    friend class ServicesManager;
//----------------------------------------------------- Méthodes publiques
    
    static PrintManager * Get();
    // Mode d'emploi : récupérer l'instance unique de la classe.
    //
    // Contrat :
    //
    
    void setDescriptionAttributes(string descriptionFile);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
	vector<Print *> createPrints(string standardFile);
    // Mode d'emploi :
    //
    // Contrat :
    //

	vector<Print *> getPrints();
	// Mode d'emploi :
	//
	// Contrat :
	//

	Print* getPrint(unsigned int id);
	// Mode d'emploi :
	//
	// Contrat :
	//

	Print* update(Print * p, string diseaseName);
	// Mode d'emploi :
	//
	// Contrat :
	//

	int save(string path, Print prints[]);
	// Mode d'emploi :
	//
	// Contrat :
	//

	int load(string path);
	// Mode d'emploi :
	//
	// Contrat :
	//
    
    PrintManager& operator = (const PrintManager&) = delete;

//-------------------------------------------- Constructeurs - destructeur
    PrintManager (const PrintManager &) = delete;
    // Copying a singleton is illegal
    
    virtual ~PrintManager();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    PrintManager ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//----------------------------------------------------- Attributs protégés
    vector<Attribute *> descriptionAttributes;
	vector<Print *> prints;
    
    static PrintManager * singleton;
};

//-------------------------------- Autres définitions dépendantes de <PrintManager>

#endif // PrintManager_H

