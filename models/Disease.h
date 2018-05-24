/*************************************************************************
 Disease  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
 clement.guittat@insa-lyon.fr
 *************************************************************************/

//---------- Interface de la classe <Disease> (fichier Disease.h) ----------------
#if ! defined ( Disease_H )
#define Disease_H

//--------------------------------------------------- Interfaces utilisées

#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Disease>
//
//
//------------------------------------------------------------------------

class Disease
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
    void Display();
    // Mode d'emploi :
    //
    // Contrat :
    //
	
	string GetName();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //-------------------------------------------- Constructeurs - destructeur
    Disease(const Disease & aDisease);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    Disease();
    // Mode d'emploi :
    //
    // Contrat :
    //
	
	Disease(const string name, const list<Measurement> & caracteristics);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    virtual ~Disease();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    string name;
    list<Measurement> caracteristics;
};

//-------------------------------- Autres définitions dépendantes de <Disease>

#endif // Disease_H

