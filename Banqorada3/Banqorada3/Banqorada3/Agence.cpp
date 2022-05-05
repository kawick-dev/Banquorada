#include "Agence.h"
#include "ID.h"


ostream& operator<<(ostream& out, Agence* c) {
	out << "\n" << c->idAgence << ";";
	out << c->nom << ";";
	out << c->adresse << ";";

	return out;
}

istream& operator>>(istream& in, Agence* c) {
	string ligne;
	in >> ligne;
	string delimiter = ";";
	size_t pos = 0;

	pos = ligne.find(delimiter);
	c->idAgence = stoi(ligne.substr(0, pos));
	ligne.erase(0, pos + delimiter.length());

	pos = ligne.find(delimiter);
	c->nom = ligne.substr(0, pos);
	ligne.erase(0, pos + delimiter.length());

	pos = ligne.find(delimiter);
	c->adresse = ligne.substr(0, pos);
	ligne.erase(0, pos + delimiter.length());

	return in;
}

void Agence::afficherAgence()
{
	if (idAgence != '\0' && nom[0] != '\0' && adresse[0] != '\0') {
		cout << "idAgence : " << idAgence;
		cout << " Nom : " << nom;
		cout << " Adresse : " << adresse << "\n";
	}
}
int Agence::getIdAgence()
{
	return idAgence;
}