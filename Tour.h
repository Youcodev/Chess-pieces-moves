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

class Tour : virtual public Piece { // une tour est une pi�ce de l'�chiquier

public:
	// Constructeurs
	Tour();
	Tour(const string& id, const string& couleur, int positionX, int positionY);
	Tour(const Pion& pion);

	// Destructeur
	virtual ~Tour();
	
	/************************************************************************************************************
	* Fonction : estMouvementValide																			    *
	* Description : V�rifie si le d�placement d'une tour sur l'�chiquier est valide						        *
	* Param�tres : La nouvelle case (abscisse et ordonn�e) sur l'�chiquier vers laquelle la tour se d�place     *
	* Valeur de retour : Bool�en; true si la tour change de position dans la limite des 64 cases de l'�chiquier *
						 et que son d�placement se fait uniquement suivant les lignes ou les colonnes		    *
	************************************************************************************************************/
	bool estMouvementValide(int toX, int toY) const;

	/*****************************************************************************************
	* Fonction : deplacer																	 *
	* Description : D�place la tour vers une nouvelle position sur l'�chiquier			     *
	* Param�tres : La nouvelle case (abscisse et ordonn�e) vers laquelle la tour se d�place  *
	* Valeur de retour : Bool�en; true si la tour a pu se d�placer							 *
	*****************************************************************************************/
	virtual bool deplacer(int toX, int toY);

	/**************************************************************************************
	* Fonction : afficher()																  *
	* Description : Permet d'afficher les informations d'une tour selon un format donn�   *
	* Param�tres : Flux de sortie (stream)												  *
	* Valeur de retour : R�f�rence au flux de sortie (appel en cascade)					  *
	**************************************************************************************/
	virtual ostream& afficher(ostream& stream) const;
};

#endif