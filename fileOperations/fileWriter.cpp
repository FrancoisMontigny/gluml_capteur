/*************************************************************************
 fileWriter  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
 clement.guittat@insa-lyon.fr
 *************************************************************************/

//---------- Réalisation de la classe <fileWriter> (fichier fileWriter.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "fileWriter.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void fileWriter::display()
// Algorithme :
//
{
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
fileWriter::fileWriter ( const fileWriter & unfileWriter )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <fileWriter>" << endl;
#endif
} //----- Fin de fileWriter (constructeur de copie)


fileWriter::fileWriter ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <fileWriter>" << endl;
#endif
} //----- Fin de fileWriter


fileWriter::~fileWriter ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <fileWriter>" << endl;
#endif
} //----- Fin de ~fileWriter


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

