/*************************************************************************
 PrintAnalyzer  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
 clement.guittat@insa-lyon.fr
 *************************************************************************/

//--- Interface de la classe <PrintAnalyzer> (fichier PrintAnalyzer.h) ---
#if ! defined ( PrintAnalyzer_H )
#define PrintAnalyzer_H

//--------------------------------------------------- Interfaces utilisées

#include <string>
#include <list>

#include "Disease"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <PrintAnalyzer>
//
//
//------------------------------------------------------------------------

class PrintAnalyzer
{
//----------------------------------------------------------------- PUBLIC
    
public:
//----------------------------------------------------- Méthodes publiques

	List<Disease> Analyze(Print & p);


//-------------------------------------------- Constructeurs - destructeur
    PrintAnalyzer(const PrintAnalyzer & aPrintAnalyzer);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    PrintAnalyzer();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    virtual ~PrintAnalyzer();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE
    
protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
};

//---------------------- Autres définitions dépendantes de <PrintAnalyzer>

#endif // PrintAnalyzer_H

