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
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Measurement>
//
//
//------------------------------------------------------------------------

class Measurement
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
    
    //-------------------------------------------- Constructeurs - destructeur
    
    Measurement ();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    virtual ~Measurement();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    string attribute;
};

//-------------------------------- Autres définitions dépendantes de <Measurement>

#endif // Measurement_H

