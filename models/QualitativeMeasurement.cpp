/*************************************************************************
 QualitativeMeasurement  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
						clement.guittat@insa-lyon.fr
 *************************************************************************/

//Réalisation de la classe <QualitativeMeasurement> (fichier QualitativeMeasurement.cpp)

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "QualitativeMeasurement.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string QualitativeMeasurement::GetSerializedValue()
{
	return this->mostFrequentValue;
}

QualitativeMeasurement * QualitativeMeasurement::GetSignificantValues(string diseaseName, PrintManager * pm)
{
	map<string, unsigned int> values;
	vector<Print *> prints = pm->GetPrints;
	for (unsigned int i = 0; i < prints.size(); i++)
	{
		vector<Attribute *> printAttributes = prints[i]->GetAttributes;
		for (unsigned int j = 0; j < printAttributes.size(); j++) 
		{
			Attribute * testedAttribute = printAttributes[j];
			if (this->attribute.compare(testedAttribute->GetName()) == 0)
			{
				if (values.find(testedAttribute->GetValue()) != values.end()) //La valeur a déjà été vue
				{
					values.find(testedAttribute->GetValue())->second++;
				}
				else
				{
					values.insert(make_pair(testedAttribute->GetName(), 1));
				}
			}
		}
	}
	
	string significantValue;
	unsigned int max = 0;
	for (i = 0; i < values.size(); i++)
	{
		if (values[i]->second > max)
		{
			max = values[i]->second;
			significantValue = values[i]->first;
		}
	}
	
	return significantValue;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

QualitativeMeasurement::QualitativeMeasurement()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <QualitativeMeasurement>" << endl;
#endif
} //----- Fin de QualitativeMeasurement


QualitativeMeasurement::~QualitativeMeasurement()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <QualitativeMeasurement>" << endl;
#endif
} //----- Fin de ~QualitativeMeasurement


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

