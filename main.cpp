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
#include "./models/PrintManager.h"
#include "./services/ServicesManager.h"
#include "./services/PrintAnalyzer.h"

DiseaseManager * dm;

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
    cout << "1. Créer un nouveau docteur." << endl;
    cout << "2. Analyser une ou plusieurs empreintes." << endl;
    cout << "3. Afficher les maladies connues" << endl;
	cout << "4. Afficher les détails d'une maladie" << endl;
    cout << "5. Quitter l'application." << endl;
    string nb;
    getline(cin, nb);
	switch (stoi(nb)) 
	{
    case 1: 
		{
			cout << "Entrez le nom, prénom et la spécialité du nouveau docteur, séparés par des virgules" << endl;
			string name;
			string firstName;
			string speciality;
			getline(cin, name, ',');
			getline(cin, firstName, ',');
			getline(cin, speciality);
			sm.CreateDoctor(name, firstName, speciality);        
			break;
		}
    case 2:  
		{	
			cout << "Entrez le nom du fichier avec la/les nouvelle(s) empreinte(s)." << endl;
			string fileName;
			getline(cin, fileName);
			sm.RunAnalysis(fileName);        
			break;
		}
	case 3:
		{
			dm = DiseaseManager::Get();
			vector<Disease *> vdm = dm->GetDiseases();
			for (unsigned int i = 0; i < vdm.size(); i++)
			{
				cout << i << endl;
				cout << vdm[i]->GetName() << endl;
			}
			break; 
		}		
    /*case 3:
        {
            PrintManager * pm = PrintManager::Get();
            vector<Print *> vpm = pm->GetPrints();
            for (unsigned int i = 0; i < vpm.size(); i++)
			{
                cout << vpm[i]->Serialize() << endl;
            }
        }
        break;*/
	case 4:		
		{
			cout << "Entrez le nom de la maladie dont vous voulez les détails." << endl;
			string diseaseName;
			getline(cin, diseaseName);
			DiseaseManager * dm = DiseaseManager::Get();
			Disease * disease = dm->GetDisease(diseaseName);
			if (disease != nullptr)
			{
				cout << disease->Serialize() << endl;		
			}
			else
			{
				cout << "Cette maladie est inconnue." << endl;
			}
			break;
		}
	case 5:
        return 0;

    default:
        cout << "Choix non autorisé." << endl;
		break;
	}
    return 1;
}
