//
//  main.cpp
//  ProjectUML
//
//  Created by Clement Guittat on 30/04/2018.
//  Copyright © 2018 Clement Guittat. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "./models/DoctorManager.h"
#include "./models/PrintManager.h"
#include "./models/QualitativeAttribute.h"
#include "./models/QuantitativeAttribute.h"
#include "./fileOperations/fileReader.h"
#include "./fileOperations/fileWriter.h"

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
    /*vector<Attribute *> l1;
	vector<Attribute *> l2;
	string disease = "";
    Attribute * A1 = new QualitativeAttribute("A1", "OUI");
	Attribute * A1bis = new QualitativeAttribute("A1", "NON");
    Attribute * A2 = new QuantitativeAttribute("A2", 2.2);
	Attribute * A2bis = new QuantitativeAttribute("A2", 3.3);
    l1.push_back(A1);
    l1.push_back(A2);
	l2.push_back(A1bis);
	l2.push_back(A2bis);
    PrintManager pm = PrintManager();
    pm.CreatePrint(l1, 1, disease);
    pm.CreatePrint(l2, 2, disease);
    vector<Print *> lp = pm.GetPrints();
    for(vector<Print *>::iterator it=lp.begin(); it!=lp.end(); ++it)
    {
        cout << **it << endl;
    }*/
	
    //cout << *pm.getPrint(2);
	
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
    listPrints = pm.GetPrints();
	
	for (vector<Print *>::const_iterator i = listPrints.begin(); i != listPrints.end(); ++i) {
		cout << **i << endl;
	}
	
	/*for (unsigned int i = 0; i < listPrints.size(); i++) {
		cout << *listPrints[i] << endl;
	}*/
	
    /*for (int i =0; i< listPrints.size();i++){
        cout << listPrints[i] << endl;
    }*/
    
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
    return 0;
}
