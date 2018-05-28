/*************************************************************************
 QuantitativeAttribute  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
 clement.guittat@insa-lyon.fr
 *************************************************************************/

//---------- Interface de la classe <QuantitativeAttribute> (fichier QuantitativeAttribute.h) ----------------
#if ! defined ( QuantitativeAttribute_H )
#define QuantitativeAttribute_H

//--------------------------------------------------- Interfaces utilisées

#include "Attribute.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <QuantitativeAttribute>
//
//
//------------------------------------------------------------------------

class QuantitativeAttribute: public Attribute
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    
    //----------------------------------------------------- Méthodes publiques
	
	string getValue() const;
    
    void setValue(string value);
	
    string description() const;
	
	QuantitativeAttribute * Copy(const QuantitativeAttribute & aQuantitativeAttribute);
	
    //-------------------------------------------- Constructeurs - destructeur
    
    QuantitativeAttribute (const QuantitativeAttribute & aQuantitativeAttribute);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    QuantitativeAttribute (string name);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    QuantitativeAttribute (string name, double value);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    virtual ~QuantitativeAttribute ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    double value;
};

//-------------------------------- Autres définitions dépendantes de <QuantitativeAttribute>

#endif // QuantitativeAttribute_H

