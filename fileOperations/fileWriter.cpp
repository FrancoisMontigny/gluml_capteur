/*************************************************************************
 FileWriter  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
						clement.guittat@insa-lyon.fr
 *************************************************************************/

//---- Réalisation de la classe <FileWriter> (fichier FileWriter.cpp) ----

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

ofstream & FileWriter::WritePrint(ofstream & of, Print * p)
{
	string print = p->Serialize();
    of << print << endl;
    return of;
} //----- Fin de WritePrint

ofstream & FileWriter::WritePrint(ofstream & of, Disease * d)
{
	string disease = d->Serialize();
    of << disease << endl;
    return of;
} //----- Fin de WritePrint

ofstream & FileWriter::WriteDoctor(ofstream & of, Doctor * doc)
{
	string doctor = doc->Serialize();
	of << doctor << endl;
    return of;
} //----- Fin de WriteDoctor

//-------------------------------------------- Constructeurs - destructeur

FileWriter::FileWriter()
{
#ifdef MAP
    cout << "Appel au constructeur de <FileWriter>" << endl;
#endif
} //----- Fin de FileWriter


FileWriter::~FileWriter()
{
#ifdef MAP
    cout << "Appel au destructeur de <FileWriter>" << endl;
#endif
} //----- Fin de ~FileWriter


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

