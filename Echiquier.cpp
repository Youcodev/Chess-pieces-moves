/********************************************
* Titre: Travail pratique #4 - Echiquier.cpp
* Date: 24/02/2017
* Auteur: Gergi Younis
*******************************************/

#include "Echiquier.h"
#include <cstdlib> // pour l'utilisation de srand() et de rand()
#include <ctime>  // pour l'utilisation de time()

Echiquier::Echiquier() {}

Echiquier::~Echiquier() {
	// On consid�re une relation de composition entre l��chiquier et les diff�rentes pi�ces
	// On d�truit les pi�ces au moment de d�truire l'�chiquier

	// Destruction des pi�ces blanches
	for (unsigned int i = 0; i < vecteurPiecesBlanches_.size(); ++i)
		delete vecteurPiecesBlanches_[i];
	vecteurPiecesBlanches_.clear();

	// Destruction des pi�ces noires
	for (unsigned int i = 0; i < vecteurPiecesNoires_.size(); ++i)
		delete vecteurPiecesNoires_[i];
	vecteurPiecesNoires_.clear();
}

bool Echiquier::deplacerPiece(const string& id, int toX, int toY) {
	// On cherche d'abord dans le vecteur des pi�ces blanches
	for (unsigned int i = 0; i < vecteurPiecesBlanches_.size(); ++i) {
		if (vecteurPiecesBlanches_[i]->obtenirId() == id) {
			vecteurPiecesBlanches_[i]->deplacer(toX, toY);
			return true;
		}
	}
	// Puis dans le vecteur des pi�ces noires
	for (unsigned int i = 0; i < vecteurPiecesNoires_.size(); ++i) {
		if (vecteurPiecesNoires_[i]->obtenirId() == id) {
			vecteurPiecesNoires_[i]->deplacer(toX, toY);
			return true;
		}
	}
			// Sinon, i.e. la pi�ce recherch�e n'est dans aucun des vecteurs
			return false;
		}

Echiquier& Echiquier::operator+=(Piece* piece) {
	// D'abord on v�rifie si la pi�ce pass�e en param�tre existe dans le vecteur de pi�ces
	// et si tel est le cas, elle ne sera pas �t� ajout�e
	for (unsigned int i = 0; i < vecteurPiecesBlanches_.size(); ++i) {
		if (vecteurPiecesBlanches_[i]->obtenirId() == piece->obtenirId())
			return *this;
	}
	for (unsigned int i = 0; i < vecteurPiecesNoires_.size(); ++i) {
		if (vecteurPiecesNoires_[i]->obtenirId() == piece->obtenirId())
			return *this;
	}
	// Sinon, i.e. la pi�ce n'est dans aucun des vecteurs de pi�ces 
	// On l'ajoute au vecteur correspondant en fonction de sa couleur
	if (piece->obtenirCouleur() == "Blanc")
		vecteurPiecesBlanches_.push_back(piece);
	else  // S'il s'agit d'une pi�ce noire
		vecteurPiecesNoires_.push_back(piece);
	return *this;
}

Echiquier& Echiquier::operator-=(const string& id) {
	// On parcourt d'abord le vecteur des pi�ces blanches
	for (unsigned int i = 0; i < vecteurPiecesBlanches_.size(); ++i) {
		// Si la pi�ce � retirer existe dans le vecteur de pi�ces
		if (vecteurPiecesBlanches_[i]->obtenirId() == id) {
			// elle en sera retir�e
			delete vecteurPiecesBlanches_[i];
			vecteurPiecesBlanches_[i] = vecteurPiecesBlanches_.back(); // on suppose que l'ordre n'est pas important
			vecteurPiecesBlanches_.pop_back();
			return *this;
		}
	}
	// on poursuit �ventuellement dans le vecteur des pi�ces noires
	for (unsigned int i = 0; i < vecteurPiecesNoires_.size(); ++i) {
		// Si la pi�ce � retirer existe dans le vecteur de pi�ces
		if (vecteurPiecesNoires_[i]->obtenirId() == id) {
			// elle en sera retir�e
			delete vecteurPiecesNoires_[i];
			vecteurPiecesNoires_[i] = vecteurPiecesNoires_.back(); // on suppose que l'ordre n'est pas important
			vecteurPiecesBlanches_.pop_back();
			return *this;
		}
	}
	return *this;
}

bool Echiquier::promouvoir(const string& id) {
	enum Trois_pieces {REINE, TOUR, FOU};
	Trois_pieces choixAleatoire;
	srand((unsigned)time(NULL));
	// rand() % n pour obtenir un entier al�atoire dans l'intervalle [0, n-1]
	choixAleatoire = static_cast<Trois_pieces>(rand() % 3);
// On v�rifie s'il s'agit d'un pion en cherchant d'abord dans le vecteur de pi�ces blanches
	for (unsigned int i = 0; i < vecteurPiecesBlanches_.size(); ++i) {
		if (vecteurPiecesBlanches_[i]->obtenirId() == id) {
			if (typeid(*vecteurPiecesBlanches_[i]) == typeid(Pion)) {
				switch (choixAleatoire) {

				case REINE: // On cr�e une reine � partir d'un pion
				{
					Reine* reine = new Reine(*dynamic_cast<Pion*>(vecteurPiecesBlanches_[i]));
					vecteurPiecesBlanches_.push_back(reine); // Et on ajoute la nouvelle reine au vecteur des pi�ces

				}
				break;

				case TOUR: // Ou on cr�e une tour � partir d'un pion 
				{
					Tour* tour = new Tour(*dynamic_cast<Pion*>(vecteurPiecesBlanches_[i]));
					vecteurPiecesBlanches_.push_back(tour); // Et on ajoute la nouvelle tour au vecteur des pi�ces
															// Ou alors un fou
				}
				break;

				case FOU: // Ou alors on cr�e un fou � partir d'un pion 
					Fou* fou = new Fou(*dynamic_cast<Pion*>(vecteurPiecesBlanches_[i]));
					vecteurPiecesBlanches_.push_back(fou); // Et on ajoute le nouveau fou au vecteur des pi�ces
				}
				*this -= id; // On supprime ensuite le pion remplac�
				cout << "Promotion reussie" << endl;
				return true;
			}
		}
	}
	// Puis on poursuit �ventuellement dans le vecteur de pi�ces noires
	for (unsigned int i = 0; i < vecteurPiecesNoires_.size(); ++i) {
		if (vecteurPiecesNoires_[i]->obtenirId() == id)
			if (typeid(*vecteurPiecesNoires_[i]) == typeid(Pion)) {
				switch (choixAleatoire) {
					
				case REINE: // On cr�e une reine � partir d'un pion
				{
					Reine* reine = new Reine(*dynamic_cast<Pion*>(vecteurPiecesNoires_[i]));
					vecteurPiecesNoires_.push_back(reine); // Et on ajoute la nouvelle reine au vecteur des pi�ces
				}
					break;

				case TOUR: // Ou on cr�e une tour � partir d'un pion
				{
					Tour* tour = new Tour(*dynamic_cast<Pion*>(vecteurPiecesNoires_[i]));
					vecteurPiecesNoires_.push_back(tour); // Et on ajoute la nouvelle tour au vecteur des pi�ces
				}
					break;

				case FOU: // Ou alors on cr�e un fou � partir d'un pion 
					Fou* fou = new Fou(*dynamic_cast<Pion*>(vecteurPiecesNoires_[i]));
					vecteurPiecesNoires_.push_back(fou); // Et on ajoute le nouveau fou au vecteur des pi�ces
				}
				*this -= id; // On supprime ensuite le pion remplac�
					cout << "Promotion reussie" << endl;
					return true;
				}
	}
	cout << "Promotion impossible" << endl;
	return false;
}


std::ostream & operator<<(std::ostream & out, const Echiquier & echiquier)
{
	out << endl << "------------INFORMATION PIECES BLANCHES------------" << endl << endl;
	out << "Il y a " << echiquier.vecteurPiecesBlanches_.size() << " Pieces blanches" << endl << endl;
	for (unsigned int i = 0; i < echiquier.vecteurPiecesBlanches_.size(); ++i)
			echiquier.vecteurPiecesBlanches_[i]->afficher(out);

	out << endl << "------------INFORMATION PIECES NOIRES--------------" << endl << endl;
	out << "Il y a " << echiquier.vecteurPiecesNoires_.size() << " Pieces noires" << endl << endl;
	for (unsigned int i = 0; i<echiquier.vecteurPiecesNoires_.size(); ++i)
			echiquier.vecteurPiecesNoires_[i]->afficher(out);
	return out;
}
