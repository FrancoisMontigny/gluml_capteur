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
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

//------------------------------------------------------ Include personnel
#include "fileReader.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
vector<Attribute *> fileReader::descriptionFile(string descriptionFile)
// Algorithme :
//
{
    ifstream fi;
    fi.open("fichiersTest/"+descriptionFile);
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
    fi.close();
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

vector<DonneesSup> fileReader::etalonFile(string standardFile, vector<Attribute *> & la)
// Algorithme :
//
{
    ifstream fi;
    fi.open("fichiersTest/"+standardFile);
    int ligne1 = 1;
    vector<DonneesSup> vds;
    while (fi.good()) {
        string line;
        getline(fi, line);
        if (ligne1 == 0) {
            if (line.size() != 0) {
				
				vector<Attribute *> attributes;
				stringstream ss (line);
                string idString;
                getline(ss, idString, ';');
                unsigned int id = stoi(idString);
                
				for (vector<Attribute *>::const_iterator it = la.begin(); it != la.end(); ++it) 
				{
					string att;
                    getline(ss, att, ';');
					Attribute * a = (*it)->Copy();
					a->setValue(att);
					attributes.push_back(a);
				}

                string maladie;
                getline(ss, maladie, '\r');
                vds.push_back(DonneesSup(id, maladie, attributes));
				attributes.clear();								
            }
        }
        else {
            ligne1 = 0;
        }
    }
    fi.close();
    return vds;
}

vector <string> fileReader::identification(string path){
    ifstream fi;
    fi.open("fichiersTest/"+path);
    vector <string> res;
    while(fi.good()) {
        string line;
        getline ( fi, line);
        if (line.size() != 0) {
            res.push_back(line);
        }
    }
    fi.close();
    return res;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

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

