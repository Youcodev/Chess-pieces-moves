/********************************************
* Titre: Travail pratique #4 - Pion.cpp
* Date: 24/02/2017
* Auteur: Gergi Younis
*******************************************/

#include "Pion.h"


Pion::Pion():Piece("defaultId","blanc",0,0),estPositionInitiale_(true){
}


Pion::Pion(const string& id, const string& couleur, int positionX, int positionY) : 
	Piece(id, couleur, positionX, positionY) { estPositionInitiale_ = true; }

Pion::~Pion() {}

bool Pion::obtenirEstPositionInitiale() const{
	return estPositionInitiale_;
}

void Pion::setEstPositionInitiale(bool estPositionInitiale) {
	estPositionInitiale_ = estPositionInitiale;
}

bool Pion::estMouvementValide(int toX, int toY) const {
	if (Piece::estMouvementValide(toX, toY) &&  // On vérifie d'abord que le mouvement est valide en tant que pièce
												// Ensuite on vérifie que le déplacement se fait au maximum de deux cases quand le pion est à sa position initiale
												// Dans le cas d'un pion blanc, l'ordonnée ne peut augmenter de plus de deux cases 
		((estPositionInitiale_ && (obtenirCouleur() == "Blanc") && (toX == obtenirPositionX()) &&
		(toY == obtenirPositionY() + 1 || toY == obtenirPositionY() + 2)) ||
			// Dans le cas d'un pion noir, l'ordonnée ne peut diminuer de plus de deux cases
			(estPositionInitiale_ && (obtenirCouleur() == "Noir") && (toX == obtenirPositionX()) &&
			(toY == obtenirPositionY() - 1 || toY == obtenirPositionY() - 2)) ||
			// Si le pion blanc n'est pas à sa position initiale, l'ordonnée ne peut augmenter de plus d'une case  
				(!estPositionInitiale_ && (obtenirCouleur() == "Blanc") && (toX == obtenirPositionX()) &&
			(toY == obtenirPositionY() + 1)) ||
			// Si le pion noir n'est pas à sa position initiale, l'ordonnée ne peut diminuer de plus d'une case  
					(!estPositionInitiale_ && (obtenirCouleur() == "Noir") && (toX == obtenirPositionX()) &&
			(toY == obtenirPositionY() - 1)))) 
		return true;
	return false;
}


bool Pion::deplacer(int toX, int toY) {
	if (estMouvementValide(toX, toY)) {
		
		modifierPositionX(toX);
		modifierPositionY(toY);
		estPositionInitiale_ = false;	
		cout << "Deplacement de la piece reussi" << endl;
		return true;
	}
	cout << "Mouvement non valide" << endl;
	return false;
}