/********************************************
* Titre: Travail pratique #4 - Pion.h
* Date: 24/02/2017
* Auteur: Gergi Younis
*******************************************/

#ifndef PION_H
#define PION_H

#include "Piece.h"
#include <string>

using namespace std;

class Pion : public Piece { // un pion est une pi�ce de l'�chiquier

public:
	// Constructeurs
	Pion();
	Pion(const string& id, const string & couleur, int positionX, int positionY);

	// Destructeur
	virtual ~Pion();
	
	// Acesseur et modificateur
	bool obtenirEstPositionInitiale() const;
	void setEstPositionInitiale(bool estPositionInitiale);

	/***********************************************************************************************************
	* Fonction : estMouvementValide																			   *
	* Description : V�rifie si le d�placement d'un pion sur l'�chiquier est valide						       *
	* Param�tres : La nouvelle case (abscisse et ordonn�e) sur l'�chiquier vers laquelle le pion se d�place    *
	* Valeur de retour : Bool�en; true si le pion change de position dans la limite des 64 case de l'�chiquier *
						 et que son d�placement se fait uniquement d'une case (ou deux s'il s'agit de la	   *
						 position initiale) suivant sa colonne, en direction de l'adversaire				   *
	***********************************************************************************************************/
	bool estMouvementValide(int toX, int toY) const;

	/*****************************************************************************************
	* Fonction : deplacer																	 *
	* Description : D�place le pion vers une nouvelle position sur l'�chiquier			     *
	* Param�tres : La nouvelle case (abscisse et ordonn�e) vers laquelle le pion se d�place  *
	* Valeur de retour : Bool�en; true si le pion a pu se d�placer							 *
	*****************************************************************************************/
	virtual bool deplacer(int toX, int toY);

private:
	bool estPositionInitiale_;
};

#endif
