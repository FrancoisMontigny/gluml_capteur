/*************************************************************************
 Disease  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
						clement.guittat@insa-lyon.fr
 *************************************************************************/

//-------- Interface de la classe <Disease> (fichier Disease.h) ----------
#if ! defined ( Disease_H )
#define Disease_H

//--------------------------------------------------- Interfaces utilisées

#include <string>
#include <vector>

#include "./Measurement.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Disease> : Disease représente une maladie et toutes
// les informations qu'on a sur elle, à savoir la valeur moyenne et l'écart
// type (respectivement la valeur la plus fréquente) pour chaque attribut 
// quantitatif (respectivement quantitatif) qui la concerne.
//
//------------------------------------------------------------------------

class Disease
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
    void Display();
    // Mode d'emploi : Affiche la maladie et ses caractéristiques.
    //
    // Contrat : Aucun.
    //
	
	string GetName();
    // Mode d'emploi : Récupère le nom de la maladie.
    //
    // Contrat : Aucun.
    //
    
    //-------------------------------------------- Constructeurs - destructeur
	
    Disease(const Disease & aDisease);
    
    Disease();
	
	Disease(const string name, const vector<Measurement> & caracteristics);
    
    virtual ~Disease();
	
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    string name;
    vector<Measurement> caracteristics;
};

//-------------------------------- Autres définitions dépendantes de <Disease>

#endif // Disease_H

