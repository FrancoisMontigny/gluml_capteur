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

#include "Print.h"
#include "Attribute.h"
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
//----------------------------------------------------- Méthodes publiques
	Print * CreatePrint(vector<Attribute *> & attributes, unsigned int id, string disease);
    // Mode d'emploi :
    //
    // Contrat :
    //
	
	Print * CreatePrint(Print & aPrint);
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

	int Save(string path, Print prints[]);
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
	PrintManager(const PrintManager & aPrintManager);
	// Mode d'emploi :
	//
	// Contrat :
	//

    PrintManager ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~PrintManager ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	vector<Print *> prints;
};

//-------------------------------- Autres définitions dépendantes de <PrintManager>

#endif // PrintManager_H

