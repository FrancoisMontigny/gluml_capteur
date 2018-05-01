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
#include <list>

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
	Print* createPrint(list<Attribute*> & attributes, string disease);
    // Mode d'emploi :
    //
    // Contrat :
    //

	list<Print *> getPrints();
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

//-------------------------------------------- Constructeurs - destructeur
	PrintManager(const PrintManager & unPrintManager);
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
	list<Print *> prints;
};

//-------------------------------- Autres définitions dépendantes de <PrintManager>

#endif // PrintManager_H

