/********************************************
* Titre: Travail pratique #4 - Reine.cpp
* Date: 24/02/2017
* Auteur: Gergi Younis
*******************************************/
#include "Reine.h"

Reine::Reine() :Piece() {}

Reine::Reine(const string& id, const string& couleur, int positionX, int positionY) : 
		Piece(id, couleur, positionX, positionY) {}

Reine::Reine(const Pion& pion) : Piece(pion) {}

Reine::~Reine() {}

bool Reine::estMouvementValide(int toX, int toY) const {
	if (Piece::estMouvementValide(toX, toY) && // On vérifie d'abord que le mouvement est valide en tant que pièce
	// Ensuite on vérifie que le déplacement se fait soit selon un fou ou selon une tour
	(Fou::estMouvementValide(toX, toY) || Tour::estMouvementValide(toX, toY)))
			return true;
	return false;
}

bool Reine::deplacer(int toX, int toY) {
	if (estMouvementValide(toX, toY)) { // On vérifie que le mouvement de la reine est valide
		Piece::modifierPositionX(toX);
		Piece::modifierPositionY(toY);
		cout << "Deplacement de la piece reussi" << endl;
		return true;
	}
	// Sinon (mouvement pas valide)
	cout << "Mouvement non valide" << endl;
	return false;
}

ostream& Reine::afficher(ostream& stream) const {
	stream << Piece::obtenirType() << ", ";
	Piece::afficher(stream);
	return stream;
}