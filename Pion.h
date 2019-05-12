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

class Pion : public Piece { // un pion est une pièce de l'échiquier

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
	* Description : Vérifie si le déplacement d'un pion sur l'échiquier est valide						       *
	* Paramètres : La nouvelle case (abscisse et ordonnée) sur l'échiquier vers laquelle le pion se déplace    *
	* Valeur de retour : Booléen; true si le pion change de position dans la limite des 64 case de l'échiquier *
						 et que son déplacement se fait uniquement d'une case (ou deux s'il s'agit de la	   *
						 position initiale) suivant sa colonne, en direction de l'adversaire				   *
	***********************************************************************************************************/
	bool estMouvementValide(int toX, int toY) const;

	/*****************************************************************************************
	* Fonction : deplacer																	 *
	* Description : Déplace le pion vers une nouvelle position sur l'échiquier			     *
	* Paramètres : La nouvelle case (abscisse et ordonnée) vers laquelle le pion se déplace  *
	* Valeur de retour : Booléen; true si le pion a pu se déplacer							 *
	*****************************************************************************************/
	virtual bool deplacer(int toX, int toY);

private:
	bool estPositionInitiale_;
};

#endif
