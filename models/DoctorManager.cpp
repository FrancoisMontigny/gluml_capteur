/*************************************************************************
 DoctorManager  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
 clement.guittat@insa-lyon.fr
 *************************************************************************/

//---------- Réalisation de la classe <DoctorManager> (fichier DoctorManager.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "DoctorManager.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

// Initialisation du pointeur de singleton à null

DoctorManager * DoctorManager::singleton = nullptr;

//----------------------------------------------------- Méthodes publiques

DoctorManager * DoctorManager::Get()
{ 
	if (!singleton) 
	{
		singleton = new DoctorManager();
	}
	return singleton;
}

Doctor * DoctorManager::CreateDoctor(string name, string firstName, string speciality)
// Algorithme :
//
{
    unsigned int id = AutoNumber();
    Doctor * d = new Doctor (id, name, firstName, speciality);
    this->doctors.push_back(d);
    return d;
} //----- Fin de Méthode

ListDoctor DoctorManager::GetDoctors()
// Algorithme :
//
{
    return this->doctors;
} //----- Fin de Méthode

Doctor * DoctorManager::GetDoctor(unsigned int id)
// Algorithme :
//
{
    ListDoctor::iterator findIter = find_if(this->doctors.begin(), this->doctors.end(), [id](Doctor * d)-> bool {return (d->getDoctorId() == id); } );
    return *findIter;
} //----- Fin de Méthode

int DoctorManager::Save(string path)
 // Algorithme :
 //
 {
	 return -1; //TODO
 } //----- Fin de Méthode
 
vector <string> DoctorManager::Load(string path)
 // Algorithme :
 //
 {
     ifstream fi;
     fileReader fr = fileReader();
     fi.open("fichiersTest/"+path);
     vector <string> listDoc = fr.identification(fi);
     fi.close();
	 return listDoc;
 } //----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur

DoctorManager::~DoctorManager()
// Algorithme :
//
{
    ListDoctor::const_iterator ItList;
    for (ItList = this->doctors.begin(); ItList != this->doctors.end(); ItList++){
        delete (*ItList);
    }
#ifdef MAP
    cout << "Appel au destructeur de <DoctorManager>" << endl;
#endif
} //----- Fin de ~DoctorManager


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

unsigned int DoctorManager::AutoNumber()
{
    static unsigned int ID;
    if (this->doctors.size()!=0){
         ID = (unsigned int)this->doctors.size()+1;
    }
    else {
        ID = 1;
    }
    return ID;
}

DoctorManager::DoctorManager(string path)
// Algorithme :
//
{
    vector <string> listDoc = Load(path);
    for (int i=0; i< listDoc.size(); i++){
        stringstream ss (listDoc[i]);
        Doctor * doc;
        string id;
        string name;
        string firstName;
        string spe;
        getline(ss, id, ';');
        getline(ss, name, ';');
        getline(ss, firstName, ';');
        getline(ss, spe, '\r');
        doc = this->CreateDoctor(name, firstName, spe);
    }
#ifdef MAP
    cout << "Appel au constructeur de <DoctorManager>" << endl;
#endif
} //----- Fin de DoctorManager


