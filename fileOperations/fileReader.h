/*************************************************************************
 FileReader  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
						clement.guittat@insa-lyon.fr
 *************************************************************************/

//------ Interface de la classe <FileReader> (fichier FileReader.h) ------
#if ! defined ( FileReader_H )
#define FileReader_H

//--------------------------------------------------- Interfaces utilisées

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../models/Attribute.h"
#include "../models/QualitativeAttribute.h"
#include "../models/QuantitativeAttribute.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

// Permet de stocker toutes les informations d'une ligne d'un fichier de 
// logs
struct DataLine
{
    unsigned int idNb;
    string disease;
    vector<Attribute *> attributes;
	
    DataLine(unsigned int nb, string disease, vector<Attribute *> va) : idNb(nb), disease(disease)
    {
        for (unsigned int i = 0; i < va.size() ; i++) {
            attributes.push_back(va[i]);
        }
    }
};

//------------------------------------------------------------------------
// Rôle de la classe <FileReader> : FileReader permet de lire les 
// informations contenues dans un fichier afin de reconstituer des 
// empreintes médicales, maladies ou docteurs.
//
//------------------------------------------------------------------------

class FileReader
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
    vector<Attribute *> ReadDescriptionFile(string path);
    // Mode d'emploi : Lit le fichier de description du format des empreintes
    // pour préparer la lecture du fichier d'empreintes.
	//
    // Contrat : Aucun.
    //
    
    Attribute * ReadAttribute(istream & is);
    // Mode d'emploi : Lit la description d'un attribut dans le fichier de
	// description afin de construire son modèle.
    //
    // Contrat : is pointe sur le fichier, ouvert, de description du format 
    // des empreintes.
	//
    
    vector<DataLine> EtalonFile(string path, vector<Attribute *> & attributes);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    vector<string> Identification(string path);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    
    FileReader();
    
    virtual ~FileReader();
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés

};

//----------------------------- Autres définitions dépendantes de <FileReader>

#endif // FileReader_H

