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

void fileReader::etalonFile(string standardFile)
// Algorithme :
//
{
    ifstream fi;
    fi.open("fichiersTest/"+standardFile);
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
                /*for (int i=0; i<la.size(); i++){
                    string att;
                    getline(ss,att,';');
                    la[i]->setValue(att);//Le problème semble être ici
                }*/
                string maladie;
                getline(ss, maladie, '\r');
               // pm.createPrint(la, id, maladie);
            }
        }
        else {
            ligne1 = 0;
        }
    }
    fi.close();
    //TU peux voir sur ton terminal que seulement les attributs ne changent pas, le reste si, donc je pense que
    //Le problème se situe juste au dessus au niveau du changement de valeur des attributs.
    /*for (int i=0; i<pm.getPrints().size(); i++){
        cout << *pm.getPrints()[i] << endl;
    }*/
}

vector <string> fileReader::identification(ifstream & fi){
    vector <string> res;
    while(fi.good()) {
        string line;
        getline ( fi, line);
        if (line.size() != 0) {
            res.push_back(line);
        }
    }
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

