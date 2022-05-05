#ifndef Client_H
#define Client_H

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Client
{
protected:
	int idClient;
	string nom;
	string prenom;
	string adresse;
	int idAgence;
public:
	void addClient();
	void afficherClient();
	int getIdClient();
	int getIdAgence();

	friend ostream& operator << (ostream& out, Client* client);
	friend istream& operator >> (istream& in, Client* client);
};
#endif