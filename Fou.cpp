/********************************************
* Titre: Travail pratique #4 - Fou.cpp
* Date: 24/02/2017
* Auteur: Gergi Younis
*******************************************/
#include "Fou.h"

Fou::Fou():Piece() {}

Fou::Fou(const string& id, const string& couleur, int positionX, int positionY):Piece(id, couleur, positionX, positionY) {}

Fou::Fou(const Pion& pion): Piece(pion) {}

Fou::~Fou() {}

bool Fou::estMouvementValide (int toX, int toY) const {
	if (Piece::estMouvementValide(toX, toY) &&  // On vérifie d'abord que le mouvement est valide en tant que pièce
			// Ensuite on vérifie que le déplacement se fait uniquement selon la diagonale
		(abs(toX - obtenirPositionX()) == abs(toY - obtenirPositionY())))
		return true;
	return false;
}

bool Fou::deplacer(int toX, int toY) {
	if (estMouvementValide(toX, toY)) { // On vérifie que le mouvement du fou est valide
		modifierPositionX(toX);
		modifierPositionY(toY);
		cout << "Deplacement de la piece reussi" << endl;
		return true;
	}
	// Sinon (mouvement pas valide)
	cout << "Mouvement non valide" << endl;
		return false;
}

ostream& Fou::afficher(ostream& stream) const {
	stream << obtenirType() << ", ";
	Piece::afficher(stream);
	return stream;
}