/*************************************************************************
 fileWriter  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
 clement.guittat@insa-lyon.fr
 *************************************************************************/

//---------- Interface de la classe <fileWriter> (fichier fileWriter.h) ----------------
#if ! defined ( fileWriter_H )
#define fileWriter_H

//--------------------------------------------------- Interfaces utilisées

#include <string>

#include "../models/Print.h"
#include "../models/Doctor.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <fileWriter>
//
//
//------------------------------------------------------------------------

class fileWriter
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
	
	ofstream & writePrint(ofstream & of, Print * p);
	
	ofstream & writeDoctor(ofstream & of, Doctor * doc);
    
    
    //-------------------------------------------- Constructeurs - destructeur
    fileWriter(const fileWriter & afileWriter);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    fileWriter();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    virtual ~fileWriter();
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

//-------------------------------- Autres définitions dépendantes de <fileWriter>

#endif // fileWriter_H

