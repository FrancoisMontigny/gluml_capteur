/*************************************************************************
 FileWriter  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
						clement.guittat@insa-lyon.fr
 *************************************************************************/

//------ Interface de la classe <FileWriter> (fichier FileWriter.h) ------
#if ! defined ( FileWriter_H )
#define FileWriter_H

//--------------------------------------------------- Interfaces utilisées

#include <string>

#include "../models/Print.h"
#include "../models/Doctor.h"
#include "../models/Disease.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <FileWriter> : FileWriter permet d'écrire dans un
// fichier à des fins de sauvegarde.
//
//------------------------------------------------------------------------

class FileWriter
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
	
	ofstream & WritePrint(ofstream & of, Print * p);
	// Mode d'emploi : écrire les informations liées à une empreinte médicale
	// dans un fichier.
	//
	// Contrat : of est un ofstream sur un fichier existant ouvert.
	
	ofstream & WriteDisease(ofstream & of, Disease * d);
	// Mode d'emploi : écrire les informations liées à une maladie
	// dans un fichier.
	//
	// Contrat : of est un ofstream sur un fichier existant ouvert.
	
	ofstream & WriteDoctor(ofstream & of, Doctor * doc);
	// Mode d'emploi : écrire les informations liées à un docteur dans un 
	// fichier.
	//
	// Contrat : of est un ofstream sur un fichier existant ouvert.
    
    
    //-------------------------------------------- Constructeurs - destructeur
        
    FileWriter();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    virtual ~FileWriter();
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

//----------------------------- Autres définitions dépendantes de <FileWriter>

#endif // FileWriter_H

