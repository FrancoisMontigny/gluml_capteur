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
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "fileWriter.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs

ofstream & fileWriter::writePrint(ofstream & of, Print & p)
{
	string print = p.Serialize();
    of << print << endl;
	return of;
}

ofstream & fileWriter::writeDoctor(ofstream & of, Doctor * doc)
{
	string doctor = doc->Serialize();
	of << doctor << endl;
	return of;
}

//-------------------------------------------- Constructeurs - destructeur
fileWriter::fileWriter(const fileWriter & afileWriter)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <fileWriter>" << endl;
#endif
} //----- Fin de fileWriter (constructeur de copie)


fileWriter::fileWriter()
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

