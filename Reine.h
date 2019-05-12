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

class Reine : public Tour, public Fou {  // Une reine est à la fois une tour et un fou

public:
	// Constructeurs
	Reine();
	Reine(const string& id, const string& couleur, int positionX, int positionY);
	Reine(const Pion& pion);

	// Destructeur
	virtual ~Reine();

	/*************************************************************************************************************
	* Fonction : estMouvementValide																			     *
	* Description : Vérifie si le déplacement d'une reine sur l'échiquier est valide						     *
	* Paramètres : La nouvelle case (abscisse et ordonnée) sur l'échiquier vers laquelle la reine se déplace     *
	* Valeur de retour : Booléen; true si la reine change de position dans la limite des 64 cases de l'échiquier *
						 et que son déplacement se fait selon la diagonale, la ligne ou la colonne				 *
	*************************************************************************************************************/
	virtual bool estMouvementValide(int toX, int toY) const;

	/*****************************************************************************************
	* Fonction : deplacer																	 *
	* Description : Déplace la reine vers une nouvelle position sur l'échiquier			     *
	* Paramètres : La nouvelle case (abscisse et ordonnée) vers laquelle la reine se déplace *
	* Valeur de retour : Booléen; true si la reine a pu se déplacer							 *
	*****************************************************************************************/
	virtual bool deplacer(int toX, int toY);

	/**************************************************************************************
	* Fonction : afficher()																  *
	* Description : Permet d'afficher les informations d'une reine selon un format donné  *
	* Paramètres : Flux de sortie (stream)												  *
	* Valeur de retour : Référence au flux de sortie (appel en cascade)					  *
	**************************************************************************************/
	virtual ostream&  afficher(ostream& stream) const;
};

#endif