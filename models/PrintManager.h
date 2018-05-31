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

#include <algorithm>

#include "./Print.h"
#include "./Attribute.h"
#include "../fileOperations/fileReader.h"
#include "../fileOperations/fileWriter.h"
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
    
//----------------------------------------------------- Méthodes publiques

	Print * CreatePrint(vector<Attribute *> & attributes, unsigned int id, const string disease);

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
	
	Print * CreatePrintCopie(Print & aPrint);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
	void createPrints(string standardFile);
    // Mode d'emploi :
    //
    // Contrat :
    //

	vector<Print *> GetPrints();
	// Mode d'emploi :
	//
	// Contrat :
	//

	Print* GetPrint(unsigned int id);
	// Mode d'emploi :
	//
	// Contrat :
	//

	Print* Update(Print * p, string diseaseName);
	// Mode d'emploi :
	//
	// Contrat :
	//

	int Save(string path="writePrints.txt");
	// Mode d'emploi :
	//
	// Contrat :
	//

	int Load(string path);
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

