/*************************************************************************
 QualitativeMeasurement  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
						clement.guittat@insa-lyon.fr
 *************************************************************************/

//Interface de la classe <QualitativeMeasurement> (fichier QualitativeMeasurement.h)
#if ! defined ( QualitativeMeasurement_H )
#define QualitativeMeasurement_H

//--------------------------------------------------- Interfaces utilisées

#include "Measurement.h"
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <QualitativeMeasurement> : QualitativeMeasurement
// représente un mesurement qualitatif (attribut string).
//
//------------------------------------------------------------------------

class QualitativeMeasurement: public Measurement
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
	
	string GetSerializedValue();
    
    //-------------------------------------------- Constructeurs - destructeur
    
    QualitativeMeasurement();
    
    virtual ~QualitativeMeasurement();
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    string mostFrequentValue;
};

//-------------------------------- Autres définitions dépendantes de <QualitativeMeasurement>

#endif // QualitativeMeasurement_H

