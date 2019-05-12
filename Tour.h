/********************************************
* Titre: Travail pratique #4 - Tour.h
* Date: 24/02/2017
* Auteur: Gergi Younis
*******************************************/

#ifndef TOUR_H
#define TOUR_H

#include "Piece.h"
#include <string>
#include "Pion.h"

using namespace std;

class Tour : virtual public Piece { // une tour est une pièce de l'échiquier

public:
	// Constructeurs
	Tour();
	Tour(const string& id, const string& couleur, int positionX, int positionY);
	Tour(const Pion& pion);

	// Destructeur
	virtual ~Tour();
	
	/************************************************************************************************************
	* Fonction : estMouvementValide																			    *
	* Description : Vérifie si le déplacement d'une tour sur l'échiquier est valide						        *
	* Paramètres : La nouvelle case (abscisse et ordonnée) sur l'échiquier vers laquelle la tour se déplace     *
	* Valeur de retour : Booléen; true si la tour change de position dans la limite des 64 cases de l'échiquier *
						 et que son déplacement se fait uniquement suivant les lignes ou les colonnes		    *
	************************************************************************************************************/
	bool estMouvementValide(int toX, int toY) const;

	/*****************************************************************************************
	* Fonction : deplacer																	 *
	* Description : Déplace la tour vers une nouvelle position sur l'échiquier			     *
	* Paramètres : La nouvelle case (abscisse et ordonnée) vers laquelle la tour se déplace  *
	* Valeur de retour : Booléen; true si la tour a pu se déplacer							 *
	*****************************************************************************************/
	virtual bool deplacer(int toX, int toY);

	/**************************************************************************************
	* Fonction : afficher()																  *
	* Description : Permet d'afficher les informations d'une tour selon un format donné   *
	* Paramètres : Flux de sortie (stream)												  *
	* Valeur de retour : Référence au flux de sortie (appel en cascade)					  *
	**************************************************************************************/
	virtual ostream& afficher(ostream& stream) const;
};

#endif