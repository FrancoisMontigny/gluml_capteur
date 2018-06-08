/*************************************************************************
 DiseaseManager  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
						clement.guittat@insa-lyon.fr
 *************************************************************************/
 
 //------------------------ Module <main.cpp> -----------------------------

#include <iostream>
#include <fstream>
#include <vector>
#include "./models/DoctorManager.h"
#include "./models/PrintManager.h"
#include "./models/QualitativeAttribute.h"
#include "./models/QuantitativeAttribute.h"
#include "./fileOperations/FileReader.h"
#include "./fileOperations/FileWriter.h"
#include "./services/ServicesManager.h"
#include "./services/PrintAnalyzer.h"

int AffichageMenu(ServicesManager & sm);

int main(int argc, const char * argv[])
{

    ServicesManager sm = ServicesManager();
    cout << "Bonjour, veuillez vous connecter pour continuer en entrant un nom"<< endl;
    string nom;
    getline(cin, nom);
    Doctor * d = sm.Connection(nom);
    if (d == nullptr)
	{
        cout << "Cet identifiant n'existe pas, veuillez réessayer ou demander un ajout par un administrateur." << endl;
    }
    else
	{
        int running = 1;
        while (running != 0)
		{
            running = AffichageMenu(sm);
        }
    }
        
    return 0;
}

int AffichageMenu(ServicesManager & sm)
{
    cout << "1. Initialisation des données à partir des fichiers enregistrés." << endl;
    cout << "2. Créer un nouveau docteur." << endl;
    cout << "3. Analyser une ou plusieurs empreintes." << endl;
    cout << "4. Quitter l'application." << endl;
    string nb;
    getline(cin,nb);
	switch (stoi(nb)) 
	{
    case 1:
        cout << "Indiquer le nom du fichier de description des attributs à lire avec l'extension" << endl;
        string descriptionFileName;
        getline(cin, descriptionFileName);
        cout << "Indiquer le nom du fichier étalon des empreintes à lire" << endl;
        string etalonFileName;
        getline(cin, etalonFileName);
        sm.InitializePrints(descriptionFileName, etalonFileName);
		break;
    case 2:
        cout << "Entrez le nom, prénom et la spécialité du nouveau docteur, séparés par des virgules" << endl;
        string name;
        string firstName;
        string speciality;
        getline(cin, name, ',');
        getline(cin, firstName, ',');
        getline(cin, speciality);
        sm.CreateDoctor(name, firstName, speciality);
		break;
    case 3:
        cout << "Entrez le nom du fichier avec la/les nouvelle(s) empreinte(s)" << endl;
        string fileName;
        getline(cin, fileName);
        sm.RunAnalysis(fileName);
		break;
    case 4:
        return 0;
		
    default:
        cout << "Choix non autorisé." << endl;
		break;
	}
    return 1;
}
