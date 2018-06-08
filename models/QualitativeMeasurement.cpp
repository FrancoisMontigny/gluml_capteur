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

QualitativeMeasurement * QualitativeMeasurement::GetSignificantValues(string diseaseName, vector<Print *> prints)
{
	map<string, unsigned int> values;
	for (unsigned int i = 0; i < prints.size(); i++)
	{
		vector<Attribute *> printAttributes = prints[i]->GetAttributes();
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
	for (map<string, unsigned int>::iterator it = values.begin(); it != values.end(); ++it)
	{
		if (it->second > max)
		{
			max = it->second;
			significantValue = it->first;
		}
	}
	
	return new QualitativeMeasurement(this->attribute, significantValue);
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

QualitativeMeasurement::QualitativeMeasurement(string attribute, string value): Measurement(attribute), mostFrequentValue(value)
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

