/*************************************************************************
                           Attribute  -  description
                             -------------------
    début                : 30 avril 2018
    copyright            : (C) 2018 par François Montigny et Clément Guittat
    e-mail               : francois.montigny@insa-lyon.fr 
						   clement.guittat@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Attribute> (fichier Attribute.h) ----------------
#if ! defined ( Attribute_H )
#define Attribute_H

//--------------------------------------------------- Interfaces utilisées

#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Attribute>
//
//
//------------------------------------------------------------------------

class Attribute
{
//----------------------------------------------------------------- PUBLIC

public:
    
//----------------------------------------------------- Méthodes publiques
    
    virtual string description () const;
    
    virtual void setValue(string value) = 0;
    
//-------------------------------------------- Constructeurs - destructeur

    Attribute ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Attribute ();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	string name;
};

//-------------------------------- Autres définitions dépendantes de <Attribute>

#endif // Attribute_H

