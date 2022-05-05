#include "Client.h"
#include "ID.h"
#include "Agence.h"

void Client::addClient()
{
	bool valide = false;
	cout << "id de l'agence\n";
	cin >> idAgence;

	ifstream FichierListAgence("Agence.txt");
	if (!FichierListAgence)
	{
		cout << "Impossible d'ouvrir le fichier Agence.txt";
	}
	Agence* agence = NULL;
	while (!FichierListAgence.eof()) {
		agence = new Agence;
		FichierListAgence >> agence;
		if (idAgence == agence->getIdAgence())
		{
			valide = true;
			cout << "Nom du client\n";
			cin >> nom;

			cout << "Prenom du client\n";
			cin >> prenom;

			cout << "Adresse du client\n";
			cin >> adresse;
			idClient = generateUUID();


			cout << "Client ajoute\n";
		}
		delete agence;
		agence = NULL;
	}
	FichierListAgence.close();
	if (!valide)
	{
		cout << "idAgence incorrecte";
		exit(1);
	}

}

ostream& operator<<(ostream& out, Client* client) {
	out << "\n" << client->idAgence << ";";
	out << client->idClient << ";";
	out << client->nom << ";";
	out << client->prenom << ";";
	out << client->adresse << ";";

	return out;
}

istream& operator>>(istream& in, Client* client) {
	string ligne;
	in >> ligne;
	string delimiter = ";";
	size_t pos = 0;

	pos = ligne.find(delimiter);
	client->idAgence = stoi(ligne.substr(0, pos));
	ligne.erase(0, pos + delimiter.length());

	pos = ligne.find(delimiter);
	client->idClient = stoi(ligne.substr(0, pos));
	ligne.erase(0, pos + delimiter.length());


	pos = ligne.find(delimiter);
	client->nom = ligne.substr(0, pos);
	ligne.erase(0, pos + delimiter.length());

	pos = ligne.find(delimiter);
	client->prenom = ligne.substr(0, pos);
	ligne.erase(0, pos + delimiter.length());

	pos = ligne.find(delimiter);
	client->adresse = ligne.substr(0, pos);
	ligne.erase(0, pos + delimiter.length());

	return in;
}

void Client::afficherClient()
{
	if (idAgence != '\0' && idClient != '\0' && nom[0] != '\0' && prenom[0] != '\0' && adresse[0] != '\0') {
		cout << "idAgence : " << idAgence;
		cout << " idClient : " << idClient;
		cout << " Nom : " << nom;
		cout << " Prenom : " << prenom;
		cout << " Adresse : " << adresse << "\n";
	}
}
int Client::getIdClient()
{
	return idClient;
}
int Client::getIdAgence()
{
	return idAgence;
}