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

class Roi : public Piece{ // un roi est une pi�ce de l'�chiquier

public :
	// Constructeurs
	Roi();
	Roi(const string& id, const string& couleur, int positionX, int positionY);

	// Destructeur
	virtual ~Roi();	

	/***********************************************************************************************************
	* Fonction : estMouvementValide																			   *
	* Description : V�rifie si le d�placement d'un roi sur l'�chiquier est valide						       *
	* Param�tres : La nouvelle case (abscisse et ordonn�e) sur l'�chiquier vers laquelle le roi se d�place     *
	* Valeur de retour : Bool�en; true si le roi change de position dans la limite des 64 case de l'�chiquier  *
						 et que son d�placement se fait uniquement d'une seule case (dans tous les sens)       *
	***********************************************************************************************************/
	bool estMouvementValide(int toX, int toY) const;  

	/*****************************************************************************************
	* Fonction : deplacer																	 *
	* Description : D�place le roi vers une nouvelle position sur l'�chiquier			     *
	* Param�tres : La nouvelle case (abscisse et ordonn�e) vers laquelle le roi se d�place   *
	* Valeur de retour : Bool�en; true si le roi a pu se d�placer							 *
	*****************************************************************************************/
	virtual bool deplacer(int toX, int toY);

};

#endif