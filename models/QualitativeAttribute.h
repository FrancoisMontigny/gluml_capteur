/*************************************************************************
 QualitativeAttribute  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
 clement.guittat@insa-lyon.fr
 *************************************************************************/

//---------- Interface de la classe <QualitativeAttribute> (fichier QualitativeAttribute.h) ----------------
#if ! defined ( QualitativeAttribute_H )
#define QualitativeAttribute_H

//--------------------------------------------------- Interfaces utilisées

#include "Attribute.h"
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <QualitativeAttribute>
//
//
//------------------------------------------------------------------------

class QualitativeAttribute: public Attribute
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    
    //----------------------------------------------------- Méthodes publiques
	
	string GetValue() const;
        
    void SetValue(string value);
	
    string Description() const;
	
	QualitativeAttribute * Copy() const;
	
    //-------------------------------------------- Constructeurs - destructeur
    QualitativeAttribute(const QualitativeAttribute & aQualitativeAttribute);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    QualitativeAttribute(string name);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    QualitativeAttribute(string name, string value);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    virtual ~QualitativeAttribute();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    string value;
};

//-------------------------------- Autres définitions dépendantes de <QualitativeAttribute>

#endif // QualitativeAttribute_H

