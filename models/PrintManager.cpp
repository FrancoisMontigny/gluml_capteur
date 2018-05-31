/*************************************************************************
                           PrintManager  -  description
                             -------------------
    début                : 30 avril 2018
    copyright            : (C) 2018 par François Montigny et Clément Guittat
    e-mail               : francois.montigny@insa-lyon.fr 
						   clement.guittat@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <PrintManager> (fichier PrintManager.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "PrintManager.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

// Initialisation du pointeur de singleton à null

PrintManager * PrintManager::singleton = nullptr;

//----------------------------------------------------- Méthodes publiques

Print * PrintManager::CreatePrint(vector<Attribute *> & attributes, unsigned int id, const string disease)
// Algorithme :
//
{
    Print * p = new Print(attributes, id , disease);
    this->prints.push_back(p);
    return p;
} //----- Fin de CreatePrint


PrintManager * PrintManager::Get()
{
    if (!singleton)
    {
        singleton = new PrintManager();
    }
    return singleton;
}

void PrintManager::setDescriptionAttributes(string file)
// Algorithme
//
{
    fileReader fr = fileReader();
    vector<Attribute *> va = fr.descriptionFile(file);
    for (int i=0; i<va.size();i++){
        this->descriptionAttributes.push_back(va[i]);
    }
}

void PrintManager::createPrints(string standardFile)
// Algorithme :
//
{
    fileReader fr = fileReader();
    vector<DonneesSup> vds = fr.etalonFile(standardFile, this->descriptionAttributes);
    if (this->prints.size() == 0){
        for (int i = 0; i< vds.size(); i++){
            Print * p = new Print(vds[i].listeAtt, vds[i].idNb, vds[i].disease);
            this->prints.push_back(p);
        }
    } else {
        for (int i = 0; i< vds.size(); i++){
            Print * p = new Print(vds[i].listeAtt, (unsigned int) this->prints.size(), vds[i].disease);
            this->prints.push_back(p);
        }
    }
} //----- Fin de Méthode


Print * PrintManager::CreatePrintCopie(Print & aPrint)
// Algorithme :
//
{
    Print * p = new Print(aPrint);
    this->prints.push_back(p);
    return p;
} //----- Fin de CreatePrint

vector<Print *> PrintManager::GetPrints()
// Algorithme :
//
{
    return this->prints;
} //----- Fin de GetPrints

Print * PrintManager::GetPrint(unsigned int id)
// Algorithme :
//
{
    vector<Print *>::iterator findIter = find_if(this->prints.begin(), this->prints.end(), [id](Print * p)-> bool {return (p->GetId() == id); } );
    return *findIter;
} //----- Fin de GetPrint

Print * PrintManager::Update(Print * p, string diseaseName)
// Algorithme :
//
{
	Print * actualPrint = this->GetPrint(p->id);
	if (actualPrint->diseaseName.size() == 0)
	{
		actualPrint->diseaseName = diseaseName;
		return actualPrint;
	}
	Print * newPrint = this->CreatePrintCopie(*p);
	newPrint->diseaseName = diseaseName;
	
	return newPrint;
} //----- Fin de Update

int PrintManager::Save(string path)
// Algorithme :
//
{
    ofstream of;
    of.open("fichiersTest/"+path);
    fileWriter fw = fileWriter();
    for (int i=0; i<this->prints.size(); i++){
        fw.writePrint(of, this->prints[i]);
    }
    of.close();
    return 200;
} //----- Fin de Méthode

/*int PrintManager::load(string path)
// Algorithme :
//
{
} //----- Fin de Méthode*/

//-------------------------------------------- Constructeurs - destructeur

PrintManager::~PrintManager ( )
// Algorithme :
//
{
    this->Save();
    vector<Print *>::const_iterator ItList;
    for (ItList = this->prints.begin(); ItList != this->prints.end(); ItList++){
        delete (*ItList);
    }
#ifdef MAP
    cout << "Appel au destructeur de <PrintManager>" << endl;
#endif
} //----- Fin de ~PrintManager


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
PrintManager::PrintManager ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <PrintManager>" << endl;
#endif
} //----- Fin de PrintManager
