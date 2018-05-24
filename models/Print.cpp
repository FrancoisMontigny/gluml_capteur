/*************************************************************************
                           Print  -  description
                             -------------------
    début                : 30 avril 2018
    copyright            : (C) 2018 par François Montigny et Clément Guittat
    e-mail               : francois.montigny@insa-lyon.fr 
						   clement.guittat@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Print> (fichier Print.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Print.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

unsigned int Print::getPrintId() const
{
    return this->id;
}

string Print::Serialize() const
{
	string answer = to_string(this->id);
	answer += ";";
	
	vector <Attribute *>::const_iterator itAtt;
	for (itAtt = this->caract.begin(); itAtt != this->caract.end(); ++itAtt)
	{
		answer += (*itAtt)->getValue() + ";"; //TODO test with value instead of GetValue(), if OK, remove GetValue()
	}
    answer += this->diseaseName;
	
	return answer;
}

//------------------------------------------------- Surcharge d'opérateurs

ostream & operator << (ostream & os, const Print & p)
// Algorithme :
// surcharge d'opérator <<  pour afficher les informations récupérée
{
    os << "L'empreiente a pour id " << p.id <<" associé à la maladie "<< p.diseaseName << endl;
    vector<Attribute *>::const_iterator itAtt;
    for (itAtt = p.caract.begin(); itAtt != p.caract.end(); ++itAtt)
	{
        os << (*itAtt)->description() << endl;
    };
    return os;
} //----- Fin de operator <<

//-------------------------------------------- Constructeurs - destructeur
Print::Print(const Print & aPrint)
// Algorithme :
//
{
    
#ifdef MAP
    cout << "Appel au constructeur de copie de <Print>" << endl;
#endif
} //----- Fin de Print (constructeur de copie)


Print::Print(vector<Attribute *> & attributes, unsigned int id, string disease)
// Algorithme :
//
{
    this->diseaseName = disease;
    this->id = id;
    vector<Attribute *>::const_iterator itAtt;
    for (itAtt = attributes.begin(); itAtt != attributes.end(); itAtt++){
        this->caract.push_back(*itAtt);
    }
#ifdef MAP
    cout << "Appel au constructeur de <Print>" << endl;
#endif
} //----- Fin de Print


Print::~Print()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Print>" << endl;
#endif
} //----- Fin de ~Print


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
/*unsigned int Print::AutoNumber()
{
    static unsigned int ID = 0;
    return ++ID;
}*/
