#ifndef Agence_H
#define Agence_H

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Agence
{
protected:
	int idAgence;
	string nom;
	string adresse;
public:
	
	void afficherAgence();
	int getIdAgence();

	friend ostream& operator << (ostream& out, Agence* c);
	friend istream& operator >> (istream& in, Agence* c);
};
#endif
