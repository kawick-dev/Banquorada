#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "ID.h"
#include "Client.h"
#include "Agence.h"
#include "Compte.h"


using namespace std;



void resetClientTmp() {
	ofstream FichierTMPReset("ClientTMP.txt");
	if (FichierTMPReset)
	{
		FichierTMPReset << "";
	}
	else {
		cout << "Impossible d'ouvrir le fichier IN";
	}
	FichierTMPReset.close();
}
void resetCompteTmp() {
	ofstream FichierCompteTMPReset("CompteTMP.txt");
	if (FichierCompteTMPReset)
	{
		FichierCompteTMPReset << "";
	}
	else {
		cout << "Impossible d'ouvrir le fichier IN";
	}
	FichierCompteTMPReset.close();
}
void resetClient() {
	ofstream FichierClientReset("Client.txt");
	if (!FichierClientReset)
	{
		cout << "Impossible d'ouvrir le fichier IN";
	}
	FichierClientReset << "";
	FichierClientReset.close();
}

void resetCompte() {
	ofstream FichierCompteReset("Compte.txt");
	if (!FichierCompteReset)
	{
		cout << "Impossible d'ouvrir le fichier IN";
	}
	FichierCompteReset << "";
	FichierCompteReset.close();
}




void choixClient() {
	int choixClient;
	do {
		cout << "----------------------------------------------------------------------------------------\n";
		cout << "Menu clients\n";
		cout << "1. Ajouter un client\n";
		cout << "2. Afficher les clients\n";
		cout << "3. Modifier un client\n";
		cout << "4. Supprimer un client\n";
		cout << "5. Retour\n";
		cout << "----------------------------------------------------------------------------------------\n";
		cout << "Choix : ";
		cin >> choixClient;

		switch (choixClient)
		{
		case 1: {

			Client* client = NULL;
			client = new Client;
			client->addClient();

			ofstream FichierSortie("Client.txt", ios_base::app);
			if (!FichierSortie)
			{
				cout << "Impossible d'ouvrir le fichier IN";
				choixClient = 5;
				break;
			}
			FichierSortie << client;
			FichierSortie.close();
			delete client;
			client = NULL;
			break;
		}

		case 2: {
			ifstream FichierEntree("Client.txt");
			if (!FichierEntree)
			{
				cout << "Impossible d'ouvrir le fichier OUT";
				choixClient = 5;
				break;
			}
			while (!FichierEntree.eof())
			{
				Client* client = NULL;
				client = new Client;
				FichierEntree >> client;
				client->afficherClient();
				delete client;
			}
			system("pause");
			break;
		}

		case 3: {
			resetClientTmp();
			int idClientModif;
			cout << "Id du client a modif \n";
			cin >> idClientModif;

			ifstream FichierClient("Client.txt");
			if (!FichierClient)
			{
				cout << "Impossible d'ouvrir le fichier Client.txt";
			}
			ofstream FichierClientTMP("ClientTMP.txt", ios_base::app);
			if (!FichierClientTMP)
			{
				cout << "Impossible d'ouvrir le fichier ClientTMP.txt";
			}
			Client* client = NULL;
			while (!FichierClient.eof()) {
				client = new Client;
				FichierClient >> client;
				if (idClientModif == client->getIdClient())
				{
					deleteUUID(client->getIdClient());
				}
				else {
					FichierClientTMP << client;
				}
				delete client;
				client = NULL;
			}
			FichierClientTMP.close();
			FichierClient.close();

			resetClient();

			ofstream FichierClientreecriture("Client.txt", ios_base::app);
			if (!FichierClientreecriture)
			{
				cout << "Impossible d'ouvrir le fichier IN";
			}

			ifstream FichierClientTmp("ClientTMP.txt");
			if (!FichierClientTmp)
			{
				cout << "Impossible d'ouvrir le fichier OUT";
			}

			while (!FichierClientTmp.eof()) {
				client = new Client;
				FichierClientTmp >> client;
				FichierClientreecriture << client;

				delete client;
				client = NULL;
			}
			FichierClientTMP.close();
			FichierClientreecriture.close();

			Client* modifClient = NULL;
			modifClient = new Client;
			modifClient->addClient();

			ofstream FichierSortie("Client.txt", ios_base::app);
			if (!FichierSortie)
			{
				cout << "Impossible d'ouvrir le fichier IN";
				choixClient = 5;
				break;
			}
			FichierSortie << modifClient;
			FichierSortie.close();
			delete modifClient;
			modifClient = NULL;
			break;

		}
			  break;

		case 4:{
			resetClientTmp();

			int supprClient;
			cout << "Id du Client a supprime \n";
			cin >> supprClient;

			ifstream FichierClient("Client.txt");
			if (!FichierClient)
			{
				cout << "Impossible d'ouvrir le fichier Client.txt";
			}

			ofstream FichierClientTMP("ClientTMP.txt", ios_base::app);
			if (!FichierClientTMP)
			{
				cout << "Impossible d'ouvrir le fichier ClientTMP.txt";
			}

			Client* client = NULL;
			while (!FichierClient.eof()) {
				client = new Client;
				FichierClient >> client;
				if (supprClient == client->getIdClient())
				{
					deleteUUID(client->getIdClient());
				}
				else {
					FichierClientTMP << client;
				}
				delete client;
				client = NULL;
			}
			FichierClientTMP.close();
			FichierClient.close();

			resetClient();

			ofstream FichierClientreecriture("Client.txt", ios_base::app);
			if (!FichierClientreecriture)
			{
				cout << "Impossible d'ouvrir le fichier IN";
			}

			ifstream FichierClientTmp("ClientTMP.txt");
			if (!FichierClientTmp)
			{
				cout << "Impossible d'ouvrir le fichier OUT";
			}


			while (!FichierClientTmp.eof()) {
				client = new Client;
				FichierClientTmp >> client;


				FichierClientreecriture << client;

				delete client;
				client = NULL;
			}
			FichierClientTMP.close();
			FichierClientreecriture.close();
			cout << "Client : " << supprClient << "\n";
		}
			break;

		case 5:
			continue;
			break;

		default:
			cout << "Erreur\n";
			break;
		}

	} while (choixClient != 5);
}

void choixAgence() {
	int choixAgence;
	do {
		cout << "----------------------------------------------------------------------------------------\n";
		cout << "Gestion des agences\n";
		cout << "1. Afficher les agences\n";
		cout << "2. Afficher la liste des client d'une agence\n";
		cout << "3. Afficher la liste des compte d'une agence\n";
		cout << "4. Retour\n";
		cout << "----------------------------------------------------------------------------------------\n";
		cout << "Choix : ";


		cin >> choixAgence;

		switch (choixAgence)
		{
		case 1:
		{
			ifstream FichierEntree("Agence.txt");
			if (!FichierEntree)
			{
				cout << "Impossible d'ouvrir le fichier OUT";
				choixAgence = 5;
				break;
			}
			while (!FichierEntree.eof())
			{
				Agence* agence = NULL;
				agence = new Agence;
				FichierEntree >> agence;
				agence->afficherAgence();
				delete agence;
			}
			system("pause");
			continue;
			break;
		}
			break;

		case 2:{
			int idagence;
			cout << "Id de l'agence \n";
			cin >> idagence;
			ifstream FichierEntreeClient("Client.txt");
			if (!FichierEntreeClient)
			{
				cout << "Impossible d'ouvrir le fichier OUT";
				choixAgence = 5;
				break;
			}
			while (!FichierEntreeClient.eof())
			{
				Client* client = NULL;
				client = new Client;
				FichierEntreeClient >> client;
				if (idagence == client->getIdAgence())
				{
					client->afficherClient();
				}
				delete client;
			}
			FichierEntreeClient.close();
	
			system("pause");
			continue;
			break;

		}
		break;

		case 3:
		{
			int idagence;
			cout << "Id de l'agence \n";
			cin >> idagence;
			ifstream FichierEntreeClient("Client.txt");
			if (!FichierEntreeClient)
			{
				cout << "Impossible d'ouvrir le fichier OUT";
				choixAgence = 5;
				break;
			}
			ifstream FichierEntreeCompte("Compte.txt");
			if (!FichierEntreeCompte)
			{
				cout << "Impossible d'ouvrir le fichier OUT";
				choixAgence = 5;
				break;
			}
			while (!FichierEntreeClient.eof())
			{
				Client* client = NULL;
				client = new Client;
				FichierEntreeClient >> client;
				if (idagence == client->getIdAgence())
				{
					while (!FichierEntreeCompte.eof())
					{
						Compte* compte = NULL;
						compte = new Compte;
						FichierEntreeCompte >> compte;
						if (client->getIdClient() == compte->getIdClient())
						{
							compte->afficherCompte();
						}
						delete compte;
					}
				}
				delete client;
			}
			FichierEntreeClient.close();
			FichierEntreeCompte.close();
			system("pause");
		}
		break;

		case 4:
			continue;
			break;

		default:
			cout << "Erreur\n";
			break;
		}

	} while (choixAgence != 4);
}

void ChoixCompte() {
	int choixCompte;
	do {
		cout << "----------------------------------------------------------------------------------------\n";
		cout << "Gestion des comptes\n";
		cout << "1. Creer un compte\n";
		cout << "2. Supprimer un compte\n";
		cout << "3. Modifier un compte\n";
		cout << "4. Afficher les comptes\n";
		cout << "5. Ajouter les interets\n";
		cout << "6. Retour\n";
		cout << "----------------------------------------------------------------------------------------\n";
		cout << "Choix : ";
		cin >> choixCompte;


		switch (choixCompte)
		{
		case 1: {

			Compte* compte = NULL;
			compte = new Compte;
			compte->addCompte();

			ofstream FichierSortie("Compte.txt", ios_base::app);
			if (!FichierSortie)
			{
				cout << "Impossible d'ouvrir le fichier IN";
				choixCompte = 5;
				break;
			}
			FichierSortie << compte;
			FichierSortie.close();
			delete compte;
			compte = NULL;
			break;
		}
			break;

		case 2:{
			resetCompteTmp();

			int supprCompte;
			cout << "Id du Compte a supprime \n";
			cin >> supprCompte;

			ifstream FichierCompte("Compte.txt");
			if (!FichierCompte)
			{
				cout << "Impossible d'ouvrir le fichier Client.txt";
			}

			ofstream FichierCompteTMP("CompteTMP.txt", ios_base::app);
			if (!FichierCompteTMP)
			{
				cout << "Impossible d'ouvrir le fichier ClientTMP.txt";
			}

			Compte* compte = NULL;
			while (!FichierCompte.eof()) {
				compte = new Compte;
				FichierCompte >> compte;
				if (supprCompte == compte->getIdCompte())
				{
					if(compte->getSoldeCompte() == 0){
						deleteUUID(compte->getIdCompte());
					}
					else
					{
						cout << "Le Solde du compte " << supprCompte << " n'est pas egal a 0 \n";
						FichierCompteTMP << compte;
					}
				}
				else {
					FichierCompteTMP << compte;
				}
				delete compte;
				compte = NULL;
			}
			FichierCompteTMP.close();
			FichierCompte.close();

			resetCompte();

			ofstream FichierComptereecriture("Compte.txt", ios_base::app);
			if (!FichierComptereecriture)
			{
				cout << "Impossible d'ouvrir le fichier IN";
			}

			ifstream FichierCompteTmp("CompteTMP.txt");
			if (!FichierCompteTmp)
			{
				cout << "Impossible d'ouvrir le fichier OUT";
			}


			while (!FichierCompteTmp.eof()) {
				compte = new Compte;
				FichierCompteTmp >> compte;
				FichierComptereecriture << compte;
				delete compte;
				compte = NULL;
			}
			FichierCompteTmp.close();
			FichierComptereecriture.close();

		}
			break;

		case 3:{
			resetCompteTmp();
			int idCompteModif;
			cout << "Id du compte a modif \n";
			cin >> idCompteModif;

			ifstream FichierCompte("Compte.txt");
			if (!FichierCompte)
			{
				cout << "Impossible d'ouvrir le fichier Compte.txt";
			}
			ofstream FichierCompteTMP("CompteTMP.txt", ios_base::app);
			if (!FichierCompteTMP)
			{
				cout << "Impossible d'ouvrir le fichier CompteTMP.txt";
			}
			Compte* compte = NULL;
			while (!FichierCompte.eof()) {
				compte = new Compte;
				FichierCompte >> compte;
				if (idCompteModif == compte->getIdCompte())
				{
					deleteUUID(compte->getIdCompte());
				}
				else {
					FichierCompteTMP << compte;
				}
				delete compte;
				compte = NULL;
			}
			FichierCompteTMP.close();
			FichierCompte.close();

			resetCompte();

			ofstream FichierComptereecriture("Compte.txt", ios_base::app);
			if (!FichierComptereecriture)
			{
				cout << "Impossible d'ouvrir le fichier IN";
			}

			ifstream FichierCompteTmp("CompteTMP.txt");
			if (!FichierCompteTmp)
			{
				cout << "Impossible d'ouvrir le fichier OUT";
			}

			while (!FichierCompteTmp.eof()) {
				compte = new Compte;
				FichierCompteTmp >> compte;
				FichierComptereecriture << compte;
				delete compte;
				compte = NULL;
			}
			FichierCompteTmp.close();
			FichierComptereecriture.close();

			Compte* modifCompte = NULL;
			modifCompte = new Compte;
			modifCompte->addCompte();

			ofstream FichierSortie("Compte.txt", ios_base::app);
			if (!FichierSortie)
			{
				cout << "Impossible d'ouvrir le fichier IN";
				choixCompte = 5;
				break;
			}
			FichierSortie << modifCompte;
			FichierSortie.close();
			delete modifCompte;
			modifCompte = NULL;
			break;

		}
			break;

		case 4:
		{
			ifstream FichierEntreeCompte("Compte.txt");
			if (!FichierEntreeCompte)
			{
				cout << "Impossible d'ouvrir le fichier OUT";
				choixCompte = 5;
				break;
			}
			while (!FichierEntreeCompte.eof())
			{
				Compte* compte = NULL;
				compte = new Compte;
				FichierEntreeCompte >> compte;
				compte->afficherCompte();
				delete compte;
			}
			system("pause");
			continue;
			break;
		}
			break;

		case 5: {
			resetCompteTmp();
			float soldemodif;
			cout << "Application des interets \n";

			ifstream FichierCompteInteret("Compte.txt");
			if (!FichierCompteInteret)
			{
				cout << "Impossible d'ouvrir le fichier Client.txt";
			}

			ofstream FichierCompteTMP("CompteTMP.txt", ios_base::app);
			if (!FichierCompteTMP)
			{
				cout << "Impossible d'ouvrir le fichier ClientTMP.txt";
			}

			Compte* compte = NULL;
			while (!FichierCompteInteret.eof()) {
				compte = new Compte;
				FichierCompteInteret >> compte;
				if (compte->getType() == 2)
				{
					soldemodif = compte->getSoldeCompte();
					soldemodif = soldemodif * 1.25;
					compte->setSolde(soldemodif);
					FichierCompteTMP << compte;
				}
				else
				{
					FichierCompteTMP << compte;
				}
				delete compte;
				compte = NULL;
			}
			FichierCompteTMP.close();
			FichierCompteInteret.close();

			resetCompte();

			ofstream FichierComptereecriture("Compte.txt", ios_base::app);
			if (!FichierComptereecriture)
			{
				cout << "Impossible d'ouvrir le fichier IN";
			}

			ifstream FichierCompteTmp("CompteTMP.txt");
			if (!FichierCompteTmp)
			{
				cout << "Impossible d'ouvrir le fichier OUT";
			}


			while (!FichierCompteTmp.eof()) {
				compte = new Compte;
				FichierCompteTmp >> compte;
				FichierComptereecriture << compte;
				delete compte;
				compte = NULL;
			}
			FichierCompteTmp.close();
			FichierComptereecriture.close();

		}
			  break;
		case 6:
			continue;
			break;

		default:
			cout << "Erreur\n";
			break;
		}

	} while (choixCompte != 6);
}

void ChoixMenuTransaction() {
	int choixTransaction;
	do {
		cout << "----------------------------------------------------------------------------------------\n";
		cout << "Transaction\n";
		cout << "1. Transfert\n";
		cout << "2. Retour\n";
		cout << "----------------------------------------------------------------------------------------\n";

		cin >> choixTransaction;

		switch (choixTransaction)
		{
		case 1: {
			int compteDebiteur;
			int compteCrediteur;
			float somme;
			float sommeFrais;
			bool solde = false;
			bool plafond = false;
			float argentDebiteur;
			float argentCrediteur;
			int typeCompte;
			cout << "Frais de transfert si Compte Courant vers Compte Epargne \nFrais de transfert : 10 Euro \n";
			cout << "Id du compte debiteur \n";
			cin >> compteDebiteur;
			cout << "Id du compte crediteur \n";
			cin >> compteCrediteur;
			cout << "Somme \n";
			cin >> somme;
			sommeFrais = somme + 10.0;
			resetCompteTmp();
			ifstream FichierCompteTransfert("Compte.txt");
			if (!FichierCompteTransfert)
			{
				cout << "Impossible d'ouvrir le fichier Compte.txt";
			}

			ofstream FichierCompteTMP("CompteTMP.txt", ios_base::app);
			if (!FichierCompteTMP)
			{
				cout << "Impossible d'ouvrir le fichier CompteTMP.txt";
			}

			Compte* compte = NULL;
			while (!FichierCompteTransfert.eof()) {
				compte = new Compte;
				FichierCompteTransfert >> compte;
				if (compteDebiteur == compte->getIdCompte()) {
						if (compte->getSoldeCompte() >= sommeFrais)
						{
							solde = true;
						}
						else
						{
							solde = false;
						}
				}
				if (compteCrediteur == compte->getIdCompte()) {
					typeCompte = compte->getType();
					if (compte->getPlafond() >= compte->getSoldeCompte() + sommeFrais)
					{
						plafond = true;
					}
				}
				delete compte;
				compte = NULL;
			}

			ifstream FichierCompteTransfertDebiteur("Compte.txt");
			if (!FichierCompteTransfertDebiteur)
			{
				cout << "Impossible d'ouvrir le fichier Compte.txt";
			}

			ofstream FichierCompteTMPDebiteur("CompteTMP.txt", ios_base::app);
			if (!FichierCompteTMPDebiteur)
			{
				cout << "Impossible d'ouvrir le fichier CompteTMP.txt";
			} 

			while (!FichierCompteTransfertDebiteur.eof()) {
				compte = new Compte;
				FichierCompteTransfertDebiteur >> compte;
				if (compteDebiteur == compte->getIdCompte()) {
					if (typeCompte == 1)
					{
						if (solde && plafond)
						{
							argentDebiteur = compte->getSoldeCompte();
							argentDebiteur = argentDebiteur - somme;
							compte->setSolde(argentDebiteur);
							FichierCompteTMPDebiteur << compte;
						}
						else
						{
							FichierCompteTMPDebiteur << compte;
							cout << "Le compte ne dispose pas d'assez de fond ou le plafond du compte sera atteint\n";
							break;
						}
					}
					else if (typeCompte == 2)
					{
						if (solde && plafond)
						{	
							
							argentDebiteur = compte->getSoldeCompte();
							argentDebiteur = argentDebiteur - sommeFrais;
							compte->setSolde(argentDebiteur);
							FichierCompteTMPDebiteur << compte;
						}
						else
						{
							FichierCompteTMPDebiteur << compte;
							cout << "Le compte ne dispose pas d'assez de fond ou le plafond du compte sera atteint\n";
						}
					}
					
				}
			
				delete compte;
				compte = NULL;
			}
				FichierCompteTMPDebiteur.close();
				FichierCompteTransfertDebiteur.close();
	



			ifstream FichierCompteTransfertCrediteur("Compte.txt");
			if (!FichierCompteTransfertCrediteur)
			{
				cout << "Impossible d'ouvrir le fichier Client.txt";
			}

			ofstream FichierCompteTMPCrediteur("CompteTMP.txt", ios_base::app);
			if (!FichierCompteTMPCrediteur)
			{
				cout << "Impossible d'ouvrir le fichier ClientTMP.txt";
			}




			while (!FichierCompteTransfertCrediteur.eof()) {
				compte = new Compte;
				FichierCompteTransfertCrediteur >> compte;
				if (compteCrediteur == compte->getIdCompte()) 
				{
					if (solde && plafond)
					{
						argentCrediteur = compte->getSoldeCompte();
						argentCrediteur += somme;
						compte->setSolde(argentCrediteur);
						FichierCompteTMPCrediteur << compte;
					}
					else
					{
						FichierCompteTMPCrediteur << compte;
					}
				}
				else if(compteDebiteur == compte->getIdCompte())
				{
					
				}
				else{
					FichierCompteTMPCrediteur << compte;

				}
				delete compte;
				compte = NULL;
			}
			FichierCompteTMPCrediteur.close();
			FichierCompteTransfertCrediteur.close();




			resetCompte();
			ofstream FichierCompteReecriture("Compte.txt", ios_base::app);
			if (!FichierCompteReecriture)
			{
				cout << "Impossible d'ouvrir le fichier IN";
			}

			ifstream FichierCompteTmpReecriture("CompteTMP.txt");
			if (!FichierCompteTmpReecriture)
			{
				cout << "Impossible d'ouvrir le fichier OUT";
			}

			while (!FichierCompteTmpReecriture.eof()) {
				compte = new Compte;
				FichierCompteTmpReecriture >> compte;
				FichierCompteReecriture << compte;
				delete compte;
				compte = NULL;
			}
			FichierCompteTmpReecriture.close();
			FichierCompteReecriture.close();
		}
			break;

		case 2:
			continue;
			break;

		default:
			cout << "Erreur\n";
			break;
		}

	} while (choixTransaction != 2);
}

int main()
{
	int choix;
	do {

		cout << "BANQUORADA\n";
		cout << "----------------------------------------------------------------------------------------\n";
		cout << "1. Gestion des clients\n";
		cout << "2. Gestion des agences\n";
		cout << "3. Gestion des comptes\n";
		cout << "4. Transaction\n";
		cout << "5. Quitter\n";
		cout << "----------------------------------------------------------------------------------------\n";
		cout << " Choix : ";
		cin >> choix;

		switch (choix)
		{
		case 1:
			choixClient();
			break;

		case 2:
			choixAgence();
			break;

		case 3:
			ChoixCompte();
			break;

		case 4:
			ChoixMenuTransaction();
			break;

		case 5:
			continue;
			break;

		default:
			cout << "Erreur\n";
			break;
		}

	} while (choix != 5);

	return 0;


}