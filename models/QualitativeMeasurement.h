/*************************************************************************
 QualitativeMeasurement  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
 clement.guittat@insa-lyon.fr
 *************************************************************************/

//---------- Interface de la classe <QualitativeMeasurement> (fichier QualitativeMeasurement.h) ----------------
#if ! defined ( QualitativeMeasurement_H )
#define QualitativeMeasurement_H

//--------------------------------------------------- Interfaces utilisées

#include "Measurement.h"
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <QualitativeMeasurement>
//
//
//------------------------------------------------------------------------

class QualitativeMeasurement: public Measurement
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
    
    //-------------------------------------------- Constructeurs - destructeur
    QualitativeMeasurement (const QualitativeMeasurement & unQualitativeMeasurement);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    QualitativeMeasurement ();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    virtual ~QualitativeMeasurement ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    string mostFrequentValue;
};

//-------------------------------- Autres définitions dépendantes de <QualitativeMeasurement>

#endif // QualitativeMeasurement_H

