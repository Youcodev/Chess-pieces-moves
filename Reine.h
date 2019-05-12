/********************************************
* Titre: Travail pratique #4 - Reine.h
* Date: 24/02/2017
* Auteur: Gergi Younis
*******************************************/

#ifndef REINE_H
#define REINE_H

#include "Piece.h"
#include "Pion.h"
#include "Fou.h"
#include "Tour.h"

using namespace std;

class Reine : public Tour, public Fou {  // Une reine est � la fois une tour et un fou

public:
	// Constructeurs
	Reine();
	Reine(const string& id, const string& couleur, int positionX, int positionY);
	Reine(const Pion& pion);

	// Destructeur
	virtual ~Reine();

	/*************************************************************************************************************
	* Fonction : estMouvementValide																			     *
	* Description : V�rifie si le d�placement d'une reine sur l'�chiquier est valide						     *
	* Param�tres : La nouvelle case (abscisse et ordonn�e) sur l'�chiquier vers laquelle la reine se d�place     *
	* Valeur de retour : Bool�en; true si la reine change de position dans la limite des 64 cases de l'�chiquier *
						 et que son d�placement se fait selon la diagonale, la ligne ou la colonne				 *
	*************************************************************************************************************/
	virtual bool estMouvementValide(int toX, int toY) const;

	/*****************************************************************************************
	* Fonction : deplacer																	 *
	* Description : D�place la reine vers une nouvelle position sur l'�chiquier			     *
	* Param�tres : La nouvelle case (abscisse et ordonn�e) vers laquelle la reine se d�place *
	* Valeur de retour : Bool�en; true si la reine a pu se d�placer							 *
	*****************************************************************************************/
	virtual bool deplacer(int toX, int toY);

	/**************************************************************************************
	* Fonction : afficher()																  *
	* Description : Permet d'afficher les informations d'une reine selon un format donn�  *
	* Param�tres : Flux de sortie (stream)												  *
	* Valeur de retour : R�f�rence au flux de sortie (appel en cascade)					  *
	**************************************************************************************/
	virtual ostream&  afficher(ostream& stream) const;
};

#endif