/********************************************
* Titre: Travail pratique #4 - Fou.h
* Date: 24/02/2017
* Auteur: Gergi Younis
*******************************************/

#ifndef FOU_H
#define FOU_H

#include "Piece.h"
#include "Pion.h"
using namespace std;

class Fou : virtual public Piece {  // Un fou est une pièce de l'échiquier

public:
	// Constructeurs
	Fou();
	Fou(const string& id, const string& couleur, int positionX, int positionY);
	Fou(const Pion& pion);

	// Destructeur
	virtual ~Fou();

	/************************************************************************************************************
	* Fonction : estMouvementValide																			    *
	* Description : Vérifie si le déplacement d'un fou sur l'échiquier est valide						        *
	* Paramètres : La nouvelle case (abscisse et ordonnée) sur l'échiquier vers laquelle le fou se déplace      *
	* Valeur de retour : Booléen; true si le fou change de position dans la limite des 64 cases de l'échiquier  *
						 et que son déplacement se fait uniquement suivant la diagonale							*
	************************************************************************************************************/
	bool estMouvementValide(int toX, int toY) const;

	/*****************************************************************************************
	* Fonction : deplacer																	 *
	* Description : Déplace le fou vers une nouvelle position sur l'échiquier			     *
	* Paramètres : La nouvelle case (abscisse et ordonnée) vers laquelle le fou se déplace   *
	* Valeur de retour : Booléen; true si le fou a pu se déplacer							 *
	*****************************************************************************************/
	virtual bool deplacer(int toX, int toY);

	/**************************************************************************************
	* Fonction : afficher()																  *
	* Description : Permet d'afficher les informations d'un fou selon un format donné     *
	* Paramètres : Flux de sortie (stream)												  *
	* Valeur de retour : Référence au flux de sortie (appel en cascade)					  *
	**************************************************************************************/
	virtual ostream& afficher(ostream& stream) const;
};

#endif