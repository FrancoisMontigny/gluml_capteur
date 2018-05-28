/*************************************************************************
 fileReader  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
 clement.guittat@insa-lyon.fr
 *************************************************************************/

//---------- Réalisation de la classe <fileReader> (fichier fileReader.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <sstream>
#include <vector>
using namespace std;

//------------------------------------------------------ Include personnel
#include "fileReader.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
vector<Attribute *> fileReader::descriptionFile(ifstream & fi)
// Algorithme :
//
{
    vector<Attribute *> res;
    int ligne1 = 2;
    while(fi.good()) {
        string line;
        getline ( fi, line);
        if (ligne1 == 0) {
            if (line.size() != 0) {
                stringstream ss (line);
                res.push_back(this->attrFromFile(ss));
            }
        }
        else {
            ligne1 --;
        }
    }
    return res;
} //----- Fin de Méthode

Attribute * fileReader::attrFromFile(istream & is)
// Algorithme :
//
{
    Attribute * attr;
    string nom;
    string type;
    getline(is, nom, ';');
    getline(is, type, '\r');
    if (! type.compare("string") ) {
        attr = new QualitativeAttribute(nom);
    }
    else {
        attr = new QuantitativeAttribute(nom);
    }
    return attr;
}

void fileReader::etalonFile(ifstream & fi, PrintManager & pm, vector<Attribute*> & la)
// Algorithme :
//
{
    int ligne1 = 1;
    while(fi.good()){
        string line;
        getline (fi, line);
        if (ligne1 == 0) {
            if (line.size() != 0){
                stringstream ss (line);
                string idString;
                getline(ss,idString,';');
                double id = stod(idString);
                for (int i=0; i<la.size(); i++){
                    string att;
                    getline(ss,att,';');
                    la[i]->setValue(att);
                }
                string maladie;
                getline(ss, maladie, '\r');
                pm.createPrint(la, id, maladie);
            }
        }
        else {
            ligne1 = 0;
        }
    }
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
/*fileReader::fileReader ( const fileReader & unfileReader )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <fileReader>" << endl;
#endif
} //----- Fin de fileReader (constructeur de copie)*/


fileReader::fileReader ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <fileReader>" << endl;
#endif
} //----- Fin de fileReader


fileReader::~fileReader ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <fileReader>" << endl;
#endif
} //----- Fin de ~fileReader


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

