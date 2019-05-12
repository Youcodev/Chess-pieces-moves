/********************************************
* Titre: Travail pratique #4 - Roi.h
* Date: 24/02/2017
* Auteur: Gergi Younis
*******************************************/

#ifndef ROI_H
#define ROI_H


#include "Piece.h"
#include <string>

using namespace std;

class Roi : public Piece{ // un roi est une pièce de l'échiquier

public :
	// Constructeurs
	Roi();
	Roi(const string& id, const string& couleur, int positionX, int positionY);

	// Destructeur
	virtual ~Roi();	

	/***********************************************************************************************************
	* Fonction : estMouvementValide																			   *
	* Description : Vérifie si le déplacement d'un roi sur l'échiquier est valide						       *
	* Paramètres : La nouvelle case (abscisse et ordonnée) sur l'échiquier vers laquelle le roi se déplace     *
	* Valeur de retour : Booléen; true si le roi change de position dans la limite des 64 case de l'échiquier  *
						 et que son déplacement se fait uniquement d'une seule case (dans tous les sens)       *
	***********************************************************************************************************/
	bool estMouvementValide(int toX, int toY) const;  

	/*****************************************************************************************
	* Fonction : deplacer																	 *
	* Description : Déplace le roi vers une nouvelle position sur l'échiquier			     *
	* Paramètres : La nouvelle case (abscisse et ordonnée) vers laquelle le roi se déplace   *
	* Valeur de retour : Booléen; true si le roi a pu se déplacer							 *
	*****************************************************************************************/
	virtual bool deplacer(int toX, int toY);

};

#endif