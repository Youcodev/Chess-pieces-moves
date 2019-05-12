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

class Fou : virtual public Piece {  // Un fou est une pi�ce de l'�chiquier

public:
	// Constructeurs
	Fou();
	Fou(const string& id, const string& couleur, int positionX, int positionY);
	Fou(const Pion& pion);

	// Destructeur
	virtual ~Fou();

	/************************************************************************************************************
	* Fonction : estMouvementValide																			    *
	* Description : V�rifie si le d�placement d'un fou sur l'�chiquier est valide						        *
	* Param�tres : La nouvelle case (abscisse et ordonn�e) sur l'�chiquier vers laquelle le fou se d�place      *
	* Valeur de retour : Bool�en; true si le fou change de position dans la limite des 64 cases de l'�chiquier  *
						 et que son d�placement se fait uniquement suivant la diagonale							*
	************************************************************************************************************/
	bool estMouvementValide(int toX, int toY) const;

	/*****************************************************************************************
	* Fonction : deplacer																	 *
	* Description : D�place le fou vers une nouvelle position sur l'�chiquier			     *
	* Param�tres : La nouvelle case (abscisse et ordonn�e) vers laquelle le fou se d�place   *
	* Valeur de retour : Bool�en; true si le fou a pu se d�placer							 *
	*****************************************************************************************/
	virtual bool deplacer(int toX, int toY);

	/**************************************************************************************
	* Fonction : afficher()																  *
	* Description : Permet d'afficher les informations d'un fou selon un format donn�     *
	* Param�tres : Flux de sortie (stream)												  *
	* Valeur de retour : R�f�rence au flux de sortie (appel en cascade)					  *
	**************************************************************************************/
	virtual ostream& afficher(ostream& stream) const;
};

#endif