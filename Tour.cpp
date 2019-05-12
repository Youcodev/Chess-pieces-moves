/********************************************
* Titre: Travail pratique #4 - Tour.cpp
* Date: 24/02/2017
* Auteur: Gergi Younis
*******************************************/

#include "Tour.h"

Tour::Tour() :Piece("defaultId", "blanc", 0, 0){
}

Tour::Tour(const string& id, const string& couleur, int positionX, int positionY) : Piece(id, couleur, positionX, positionY){
}

Tour::Tour(const Pion & pion) : Piece(pion.obtenirId(), pion.obtenirCouleur(), pion.obtenirPositionX(), pion.obtenirPositionY()){
}

Tour::~Tour(){
}


bool Tour::estMouvementValide(int toX, int toY) const {
	if (Piece::estMouvementValide(toX, toY) &&
	((obtenirPositionX() == toX) || (obtenirPositionY() == toY)))
		return true;
		return false;
}

bool Tour::deplacer(int toX, int toY) {
	if (estMouvementValide(toX, toY)) {
		modifierPositionX(toX);
		modifierPositionY(toY);
		cout << "Deplacement de la piece reussi" << endl;
		return true;
	}
	cout << "Mouvement non valide" << endl;
	return false;
}

ostream& Tour::afficher(ostream& stream) const {
	stream << obtenirType() << ", ";
	Piece::afficher(stream);
	return stream;
}