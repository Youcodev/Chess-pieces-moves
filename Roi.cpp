/********************************************
* Titre: Travail pratique #4 - Roi.cpp
* Date: 24/02/2017
* Auteur: Gergi Younis
*******************************************/

#include "Roi.h"

Roi::Roi(): Piece("defaultId", "blanc", 0, 0) {}

Roi::Roi(const string& id, const string& couleur, int positionX, int positionY) : Piece( id,  couleur, positionX, positionY) {
}

bool Roi::estMouvementValide(int toX, int toY) const  {
	if (Piece::estMouvementValide(toX, toY) &&
		(abs(obtenirPositionX() - toX) == 1 && abs(obtenirPositionY() - toY) == 1 ||
		abs(obtenirPositionX() - toX) == 0 && abs(obtenirPositionY() - toY) == 1 ||
		abs(obtenirPositionX() - toX) == 1 && abs(obtenirPositionY() - toY) == 0))	
		return true;
		return false;
}

Roi::~Roi() {}

bool Roi::deplacer(int toX, int toY)  {
	if (estMouvementValide(toX, toY)) {
		modifierPositionX(toX);
		modifierPositionY(toY);
		cout << "Deplacement de la piece reussi" << endl;
		return true;
	}
	cout << "Mouvement non valide" << endl;
	return false;
}