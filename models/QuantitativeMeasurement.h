/*************************************************************************
 QuantitativeMeasurement  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
 clement.guittat@insa-lyon.fr
 *************************************************************************/

//---------- Interface de la classe <QuantitativeMeasurement> (fichier QuantitativeMeasurement.h) ----------------
#if ! defined ( QuantitativeMeasurement_H )
#define QuantitativeMeasurement_H

//--------------------------------------------------- Interfaces utilisées

#include "Measurement.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <QuantitativeMeasurement>
//
//
//------------------------------------------------------------------------

class QuantitativeMeasurement: public Measurement
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
    
    //-------------------------------------------- Constructeurs - destructeur
    
    QuantitativeMeasurement (const QuantitativeMeasurement & aQuantitativeMeasurement);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    QuantitativeMeasurement ();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    virtual ~QuantitativeMeasurement ();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    double value;
	double standardDeviation;
};

//-------------------------------- Autres définitions dépendantes de <QuantitativeMeasurement>

#endif // QuantitativeMeasurement_H

