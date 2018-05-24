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
#include <list>
#include "Attribute.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Print>
//
//
//------------------------------------------------------------------------

class Print
{
//----------------------------------------------------------------- PUBLIC

public:
    
    friend ostream & operator << (ostream &, const Print &);

//----------------------------------------------------- Méthodes publiques
    unsigned int getPrintId() const;

//-------------------------------------------- Constructeurs - destructeur
	Print ( const Print & unPrint );
	// Mode d'emploi :
	//
	// Contrat :
	//

    Print (list<Attribute *> & attributes, string disease);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Print();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    unsigned int AutoNumber();

//----------------------------------------------------- Attributs protégés
	unsigned int id;
	string diseaseName;
    list<Attribute *> caract;
};

//-------------------------------- Autres définitions dépendantes de <Print>

#endif // Print_H

