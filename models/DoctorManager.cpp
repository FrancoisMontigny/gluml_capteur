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
#include <vector>
#include <fstream>
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
} //----- Fin de Get

Doctor * DoctorManager::CreateDoctor(string name, string firstName, string speciality)
{
    unsigned int id = AutoNumber();
    Doctor * d = new Doctor (id, name, firstName, speciality);
    this->doctors.push_back(d);
    return d;
} //----- Fin de CreateDoctor

ListDoctor DoctorManager::GetDoctors()
{
    return this->doctors;
} //----- Fin de GetDoctors

Doctor * DoctorManager::GetDoctor(string nom)
{
    for (unsigned int i = 0; i < this->doctors.size(); i++)
	{
        if (this->doctors[i]->name == nom)
		{
            return this->doctors[i];
        }
    }
    return nullptr;
} //----- Fin de GetDoctor

int DoctorManager::Save(string path)
{
    ofstream of;
    of.open("fichiersTest/" + path);
    FileWriter fw = FileWriter();
    for (unsigned int i = 0; i < this->doctors.size(); i++)
	{
        fw.WriteDoctor(of, this->doctors[i]);
    }
    of.close();
    return 0;
} //----- Fin de Save
 
vector <string> DoctorManager::Load(string path)
{
    FileReader fr = FileReader();
    vector <string> listDoc = fr.Identification(path);
	return listDoc;
} //----- Fin de Load

//-------------------------------------------- Constructeurs - destructeur

DoctorManager::~DoctorManager()
{
    this->Save();
    ListDoctor::const_iterator itList;
    for (itList = this->doctors.begin(); itList != this->doctors.end(); itList++)
	{
        delete (*itList);
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
    if (this->doctors.size() != 0)
	{
         ID = (unsigned int)this->doctors.size() + 1;
    }
    else
	{
        ID = 1;
    }
    return ID;
}

DoctorManager::DoctorManager(string path)
{
    vector <string> listDoc = Load(path);
    for (unsigned int i = 0; i < listDoc.size(); i++)
	{
        stringstream ss (listDoc[i]);
        string id;
        string name;
        string firstName;
        string spe;
        getline(ss, id, ';');
        getline(ss, name, ';');
        getline(ss, firstName, ';');
        getline(ss, spe, '\r');
        this->CreateDoctor(name, firstName, spe);
    }
#ifdef MAP
    cout << "Appel au constructeur de <DoctorManager>" << endl;
#endif
} //----- Fin de DoctorManager


