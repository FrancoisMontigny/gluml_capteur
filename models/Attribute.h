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
using namespace std;
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Attribute> : Attribute est une classe abstraite
// permettant de représenter n'importe quel attribut, qu'il soit 
// qualitatif ou quantitatif, grâce à l'héritage et au polymorphisme.
//
//------------------------------------------------------------------------

class Attribute
{
//----------------------------------------------------------------- PUBLIC

public:
    
//----------------------------------------------------- Méthodes publiques
    
    virtual string Description() const;
    // Mode d'emploi : Affiche le nom de l'attribut et sa valeur.
    //
    // Contrat : Aucun.
    //
    
    virtual void SetValue(string value) = 0;
    // Mode d'emploi : Affecte la valeur de l'attribut.
    //
    // Contrat : value n'est pas null.
    //
    
    virtual string GetValue() const = 0;
    // Mode d'emploi : Récupère la valeur de l'attribut.
    //
    // Contrat : Aucun.
    //
	
	string GetName() const;
    // Mode d'emploi : Récupère le nom de l'attribut.
    //
    // Contrat : Aucun.
    //
	
	virtual Attribute * Copy() const = 0;
    // Mode d'emploi : Retourne un pointeur sur une copie de l'objet 
	// support.
    //
    // Contrat : Aucun.
    //
    
//-------------------------------------------- Constructeurs - destructeur

    Attribute();

    virtual ~Attribute();

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	string name;
};

//-------------------------------- Autres définitions dépendantes de <Attribute>

#endif // Attribute_H

