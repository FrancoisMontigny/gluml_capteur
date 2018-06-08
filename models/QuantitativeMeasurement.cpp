/*************************************************************************
 QuantitativeMeasurement  -  description
 -------------------
 début                : 30 avril 2018
 copyright            : (C) 2018 par François Montigny et Clément Guittat
 e-mail               : francois.montigny@insa-lyon.fr
						clement.guittat@insa-lyon.fr
 *************************************************************************/

// Réalisation de la classe <QuantitativeMeasurement> (fichier QuantitativeMeasurement.cpp)

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <math.h>
using namespace std;

//------------------------------------------------------ Include personnel
#include "QuantitativeMeasurement.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string QuantitativeMeasurement::GetSerializedValue()
{
	return to_string(value) + ':' + to_string(standardDeviation);
}

QuantitativeMeasurement * QuantitativeMeasurement::GetSignificantValues(string diseaseName, vector<Print *> prints)
{
	double average, standardDeviation, sum = 0, squaredSum = 0;
	unsigned int n = 0;
	for (unsigned int i = 0; i < prints.size(); i++)
	{
		vector<Attribute *> printAttributes = prints[i]->GetAttributes();
		for (unsigned int j = 0; j < printAttributes.size(); j++) 
		{
			Attribute * testedAttribute = printAttributes[j];
			if (this->attribute.compare(testedAttribute->GetName()) == 0)
			{
				double value = stod(testedAttribute->GetValue());
				sum += value;
				squaredSum += value * value;
				n++;
			}
		}
	}
	
	average = sum / n;
	
	standardDeviation = sqrt(squaredSum / n - average * average);
	
	return new QuantitativeMeasurement(this->attribute, average, standardDeviation);
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

QuantitativeMeasurement::QuantitativeMeasurement()
{
#ifdef MAP
    cout << "Appel au constructeur de <QuantitativeMeasurement>" << endl;
#endif
} //----- Fin de QuantitativeMeasurement

QuantitativeMeasurement::QuantitativeMeasurement(string attribute, double average, double stdDeviation): Measurement(attribute), value(average), standardDeviation(stdDeviation)
{
#ifdef MAP
    cout << "Appel au constructeur de <QuantitativeMeasurement>" << endl;
#endif
} //----- Fin de QuantitativeMeasurement

QuantitativeMeasurement::~QuantitativeMeasurement()
{
#ifdef MAP
    cout << "Appel au destructeur de <QuantitativeMeasurement>" << endl;
#endif
} //----- Fin de ~QuantitativeMeasurement


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

