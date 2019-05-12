/********************************************
* Titre: Travail pratique #4 - Echiquier.h
* Date: 24/02/2017
* Auteur: Gergi Younis
*******************************************/

#ifndef ECHIQUIER_H
#define ECHIQUIER_H

//#include "Piece.h"
#include "Pion.h"
#include "Roi.h"
#include "Tour.h"
#include "Fou.h"
#include "Reine.h"
#include "vector"

#include <string>

class Echiquier {
public:
	// Constructeur par défaut
	Echiquier();

	// Destructeur
	virtual ~Echiquier();

	// Méthodes publiques
	/**************************************************************************
	* Fonction : deplacerPiece   											  *
	* Description : Deplace une pièce sur l'échiquier						  *
	* Paramètres : L'identifiant de la pièce à déplacer et la nouvelle		  *
	*              case (abscisse et ordonnée) vers laquelle elle se déplace  *
	* Valeur de retour : Booléen; true si la pièce peut se déplacer			  *
	**************************************************************************/
	bool deplacerPiece(const string& id, int toX, int toY);

	/*****************************************************************
	* Fonction : Surcharge de l'opérateur +=						 *
	* Description : Ajoute une pièce au vecteur des pièces			 *
	* Paramètres : L'adresse de la pièce à ajouter					 *
	* Valeur de retour : Référence à un échiquier (ajout en cascade) *
	*****************************************************************/
	Echiquier& operator+=(Piece* piece);

	/**********************************************************************
	* Fonction : Surcharge de l'opérateur -=   						      *
	* Description : Supprime une pièce au vecteur des pièces			  *
	* Paramètres : L'identité de la pièce à supprimer					  *
	* Valeur de retour : Référence à un échiquier (supression en cascade) *
	**********************************************************************/
	Echiquier& operator-=(const string& id);

	/*******************************************************************************************
	* Fonction : promouvoir     															   *
	* Description : Transforme un pion aléatoirement en une autre pièce (Reine, Tour ou Fou)   *
	* Paramètres : L'identifiant d'une pièce												   *
	* Valeur de retour : Booléen; true si la pièce est un pion (i.e. elle a pu se transformer) *
	*******************************************************************************************/
	bool promouvoir(const string& id);
	
	/**********************************************************************************************
	* Fonction : surcharge de l'opérateur de flux de sortie <<								      *
	* Description : Permet d'afficher les informations d'un échiquier selon un format donné       *
	* Paramètres : Flux de sortie (stream) et l'échiquier dont les informations seront affichées  *
	* Valeur de retour : Référence au flux de sortie (appel en cascade)							  *
	**********************************************************************************************/
	friend std::ostream& operator<<(std::ostream& out, const Echiquier& echiquier);	

private :
	vector<Piece*>   vecteurPiecesBlanches_;
	vector<Piece*>   vecteurPiecesNoires_;	
};

#endif