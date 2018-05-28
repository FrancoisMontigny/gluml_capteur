//
//  main.cpp
//  ProjectUML
//
//  Created by Clement Guittat on 30/04/2018.
//  Copyright © 2018 Clement Guittat. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "./models/DoctorManager.h"
#include "./models/PrintManager.h"
#include "./models/QualitativeAttribute.h"
#include "./models/QuantitativeAttribute.h"
#include "./fileOperations/fileReader.h"
#include "./fileOperations/fileWriter.h"
#include "./services/ServicesManager.h"
#include "./services/PrintAnalyzer.h"

int AffichageMenu(ServicesManager & sm);

int main(int argc, const char * argv[]) {
    /*DoctorManager dm = DoctorManager();
    dm.createDoctor("Charles", "Dupond", "chirurgien");
    dm.createDoctor("Pierre", "Goutu", "neuro");
    list<Doctor*> ld = dm.getDoctors();
    for(ListDoctor::iterator it=ld.begin(); it!=ld.end(); ++it)
    {
        cout << *(*it);
    }*/
    //cout << *dm.getDoctor(2);
    /*list<Attribute*> la;
    Attribute* A1 = new QualitativeAttribute("A1", "OUI");
    Attribute* A2 = new QuantitativeAttribute("A2", 2.2);
    la.push_back(A1);
    la.push_back(A2);
    PrintManager pm = PrintManager();
    pm.createPrint(la, "-");
    pm.createPrint(la, "M1");
    list <Print *> lp = pm.getPrints();
    for(list <Print *>::iterator it=lp.begin(); it!=lp.end(); ++it)
    {
        cout << *(*it);
    }*/
    //cout << *pm.getPrint(2);
    
    /*ofstream of;
    fileWriter fw = fileWriter();
    
    cout << "Indiquer le nom du fichier où écrire les empreintes" << endl;
    string nomFichierEcrire;
    getline(cin,nomFichierEcrire);
    fichierOpen = "fichiersTest/"+nomFichierEcrire;
    of.open(fichierOpen);
    for (int i =0; i< listPrints.size();i++){
        fw.writePrint(of, *listPrints[i]);
    }
    of.close();*/
    ServicesManager sm = ServicesManager();
    cout << "Bonjour veuillez vous connecter pour continuer en entrant un nom"<< endl;
    string nom;
    getline(cin, nom);
    cout << nom << endl;
    Doctor* d = sm.Connection(nom);
    if (d == nullptr){
        cout << "Vous n'existez pas en tant que docteur, demandez un ajout par un administrateur" << endl;
    }
    else {
        int continu = 1;
        while (continu !=0){
            continu = AffichageMenu(sm);
        }
    }
        
    return 0;
}

int AffichageMenu(ServicesManager & sm) {
    cout << "1. Initialisation des données à partir des fichiers enregistrés" << endl;
    cout << "2. Créer un nouveau docteur" << endl;
    cout << "3. Quitter l'app" << endl;
    string nb;
    getline(cin,nb);
    if (!(nb.compare("1"))){
        ifstream fi;
        fileReader fr = fileReader();
        PrintManager pm = PrintManager();
        cout << "Indiquer le nom du fichier de description des attributs à lire avec l'extension" << endl;
        vector<Attribute *> listeAttributs;
        string nomFichierDescription;
        getline(cin,nomFichierDescription);
        string fichierOpen = "fichiersTest/"+nomFichierDescription;
        fi.open(fichierOpen);
        listeAttributs = fr.descriptionFile(fi);
        fi.close();
        
        cout << "Indiquer le nom du fichier étalon des empreintes à lire" << endl;
        string nomFichierEtalon;
        getline(cin,nomFichierEtalon);
        fichierOpen = "fichiersTest/"+nomFichierEtalon;
        fi.open(fichierOpen);
        fr.etalonFile(fi, pm, listeAttributs);
        fi.close();
        vector <Print *> listPrints;
        listPrints = pm.getPrints();
        for (int i =0; i< listPrints.size();i++){
            cout << *listPrints[i] << endl;
        }
    }
    else if (!(nb.compare("2"))){
        cout << "Entrez le nom, prénom et la spécialité du nouveau docteur séparé par des virgules" << endl;
        string name;
        string firstName;
        string speciality;
        getline(cin, name, ',');
        getline(cin, firstName, ',');
        getline(cin, speciality);
        sm.CreateNewDoctor(name, firstName, speciality);
    }
    else if (!(nb.compare("3"))){
        return 0;
    }
    else {
        cout << "choix non autorisée" << endl;
    }
    return 1;
}
