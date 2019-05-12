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
	// Constructeur par d�faut
	Echiquier();

	// Destructeur
	virtual ~Echiquier();

	// M�thodes publiques
	/**************************************************************************
	* Fonction : deplacerPiece   											  *
	* Description : Deplace une pi�ce sur l'�chiquier						  *
	* Param�tres : L'identifiant de la pi�ce � d�placer et la nouvelle		  *
	*              case (abscisse et ordonn�e) vers laquelle elle se d�place  *
	* Valeur de retour : Bool�en; true si la pi�ce peut se d�placer			  *
	**************************************************************************/
	bool deplacerPiece(const string& id, int toX, int toY);

	/*****************************************************************
	* Fonction : Surcharge de l'op�rateur +=						 *
	* Description : Ajoute une pi�ce au vecteur des pi�ces			 *
	* Param�tres : L'adresse de la pi�ce � ajouter					 *
	* Valeur de retour : R�f�rence � un �chiquier (ajout en cascade) *
	*****************************************************************/
	Echiquier& operator+=(Piece* piece);

	/**********************************************************************
	* Fonction : Surcharge de l'op�rateur -=   						      *
	* Description : Supprime une pi�ce au vecteur des pi�ces			  *
	* Param�tres : L'identit� de la pi�ce � supprimer					  *
	* Valeur de retour : R�f�rence � un �chiquier (supression en cascade) *
	**********************************************************************/
	Echiquier& operator-=(const string& id);

	/*******************************************************************************************
	* Fonction : promouvoir     															   *
	* Description : Transforme un pion al�atoirement en une autre pi�ce (Reine, Tour ou Fou)   *
	* Param�tres : L'identifiant d'une pi�ce												   *
	* Valeur de retour : Bool�en; true si la pi�ce est un pion (i.e. elle a pu se transformer) *
	*******************************************************************************************/
	bool promouvoir(const string& id);
	
	/**********************************************************************************************
	* Fonction : surcharge de l'op�rateur de flux de sortie <<								      *
	* Description : Permet d'afficher les informations d'un �chiquier selon un format donn�       *
	* Param�tres : Flux de sortie (stream) et l'�chiquier dont les informations seront affich�es  *
	* Valeur de retour : R�f�rence au flux de sortie (appel en cascade)							  *
	**********************************************************************************************/
	friend std::ostream& operator<<(std::ostream& out, const Echiquier& echiquier);	

private :
	vector<Piece*>   vecteurPiecesBlanches_;
	vector<Piece*>   vecteurPiecesNoires_;	
};

#endif