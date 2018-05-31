/*************************************************************************
                           Print  -  description
                             -------------------
    début                : 30 avril 2018
    copyright            : (C) 2018 par François Montigny et Clément Guittat
    e-mail               : francois.montigny@insa-lyon.fr 
						   clement.guittat@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Print> (fichier Print.h) ----------------
#if ! defined ( Print_H )
#define Print_H

//--------------------------------------------------- Interfaces utilisées

#include <string>
#include <vector>
#include "Attribute.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Print>
//
//
//------------------------------------------------------------------------

class PrintManager;

class Print
{
//----------------------------------------------------------------- PUBLIC

public:
    
    friend ostream & operator << (ostream &, const Print &);
	friend PrintManager;

//----------------------------------------------------- Méthodes publiques
    unsigned int GetId() const;
	
	string Serialize() const;

//-------------------------------------------- Constructeurs - destructeur

    virtual ~Print();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:

	Print(const Print & aPrint);
	// Mode d'emploi :
	//
	// Contrat :
	//

    Print(vector<Attribute *> & attributes, unsigned int id, string disease);
    // Mode d'emploi :
    //
    // Contrat :
    //

//----------------------------------------------------- Méthodes protégées
    unsigned int AutoNumber();

//----------------------------------------------------- Attributs protégés
	unsigned int id;
	string diseaseName;
    vector<Attribute *> caract;
};

//-------------------------------- Autres définitions dépendantes de <Print>

#endif // Print_H

