/*************************************************************************
 fileReader  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
 clement.guittat@insa-lyon.fr
 *************************************************************************/

//---------- Interface de la classe <fileReader> (fichier fileReader.h) ----------------
#if ! defined ( fileReader_H )
#define fileReader_H

//--------------------------------------------------- Interfaces utilisées

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../models/Attribute.h"
#include "../models/QualitativeAttribute.h"
#include "../models/QuantitativeAttribute.h"
#include "../models/PrintManager.h"
#include "../models/Doctor.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <fileReader>
//
//
//------------------------------------------------------------------------

class fileReader
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
    vector<Attribute *> descriptionFile(ifstream & fi);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    Attribute * attrFromFile(istream & is);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    void etalonFile(ifstream & fi, PrintManager & pm, vector<Attribute *> & la);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    vector <string> identification(ifstream & fi);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    /*fileReader ( const fileReader & unfileReader );
    // Mode d'emploi :
    //
    // Contrat :
    //*/
    
    fileReader ();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    virtual ~fileReader ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés    
};

//-------------------------------- Autres définitions dépendantes de <fileReader>

#endif // fileReader_H

