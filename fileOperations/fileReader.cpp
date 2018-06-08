/*************************************************************************
 FileReader  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
						clement.guittat@insa-lyon.fr
 *************************************************************************/

//---- Réalisation de attributes cattributessse <FileReader> (fichier FileReader.cpp) ----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

//------------------------------------------------------ Include personnel
#include "FileReader.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
vector<Attribute *> FileReader::ReadDescriptionFile(string path)
{
    ifstream fi;
    fi.open("fichiersTest/" + path);
    vector<Attribute *> res;
    int firstLines = 2;
    while(fi.good())
	{
        string line;
        getline(fi, line);
        if (firstLines == 0)
		{
            if (line.size() != 0)
			{
                stringstream ss(line);
                res.push_back(this->ReadAttribute(ss));
            }
        }
        else
		{
            firstLines--;
        }
    }
    fi.close();
    return res;
} //----- Fin de ReadDescriptionFile

Attribute * FileReader::ReadAttribute(istream & is)
{
    Attribute * attr;
    string nom;
    string type;
    getline(is, nom, ';');
    getline(is, type, '\r');
    if (! type.compare("string"))
	{
        attr = new QualitativeAttribute(nom);
    }
    else
	{
        attr = new QuantitativeAttribute(nom);
    }
    return attr;
} //----- Fin de ReadAttribute

vector<DataLine> FileReader::EtalonFile(string path, vector<Attribute *> & attributes)
{
    ifstream fi;
    fi.open("fichiersTest/" + path);
    int firstLines = 1;
    vector<DataLine> dataLines;
    while (fi.good()) {
        string line;
        getline(fi, line);
        if (firstLines == 0)
		{
            if (line.size() != 0)
			{
				
				vector<Attribute *> attributes;
				stringstream ss (line);
                string idString;
                getline(ss, idString, ';');
                unsigned int id = stoi(idString);
                
				for (vector<Attribute *>::const_iterator it = attributes.begin(); it != attributes.end(); ++it) 
				{
					string att;
                    getline(ss, att, ';');
					Attribute * a = (*it)->Copy();
					a->SetValue(att);
					attributes.push_back(a);
				}

                string maladie;
                getline(ss, maladie, '\r');
                dataLines.push_back(DataLine(id, maladie, attributes));
				attributes.clear();								
            }
        }
        else 
		{
            firstLines = 0;
        }
    }
    fi.close();
    return dataLines;
}

vector<string> FileReader::Identification(string path)
{
    ifstream fi;
    fi.open("fichiersTest/" + path);
    vector<string> res;
    while (fi.good()) 
	{
        string line;
        getline(fi, line);
        if (line.size() != 0) 
		{
            res.push_back(line);
        }
    }
    fi.close();
    return res;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

FileReader::FileReader()
{
#ifdef MAP
    cout << "Appel au constructeur de <FileReader>" << endl;
#endif
} //----- Fin de FileReader


FileReader::~FileReader()
{
#ifdef MAP
    cout << "Appel au destructeur de <FileReader>" << endl;
#endif
} //----- Fin de ~FileReader


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

