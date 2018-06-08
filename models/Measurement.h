/*************************************************************************
 Measurement  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
 clement.guittat@insa-lyon.fr
 *************************************************************************/

//---------- Interface de la classe <Measurement> (fichier Measurement.h) ----------------
#if ! defined ( Measurement_H )
#define Measurement_H

//--------------------------------------------------- Interfaces utilisées

#include <string>
#include <map>
#include <vector>
#include "Print.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Measurement> : Measurement désigne une mesure faite
// pour un attribut et une maladie.
//
//------------------------------------------------------------------------

class Measurement
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
	
	virtual string GetSerializedValue() = 0;
    // Mode d'emploi : Retourne la value formatée pour serialization.
    //
    // Contrat :
    //
	
	virtual Measurement * GetSignificantValues(string diseaseName, vector<Print *> prints) = 0;
    // Mode d'emploi : Retourne la valeur pertinente de l'attribut pour 
	// la maladie diseaseName, calculée sur prints.
    //
    // Contrat :
    //
    
    //-------------------------------------------- Constructeurs - destructeur
    
    Measurement();
	
	Measurement(string attributeName);
    
    virtual ~Measurement();
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    string attribute;
};

//-------------------------------- Autres définitions dépendantes de <Measurement>

#endif // Measurement_H

