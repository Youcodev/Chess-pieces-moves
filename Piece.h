/********************************************
* Titre: Travail pratique #4 - Piece.h
* Date: 24/02/2017
* Auteur: Gergi Younis
*******************************************/

#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <string>

using namespace std;

class Piece {
public :
	// constructeurs
	Piece() {}
	Piece(const string& id, const string& couleur, int positionX, int positionY):id_(id), couleur_(couleur), positionX_(positionX), positionY_(positionY){}

	// destructeur
	virtual ~Piece() {}

	// acesseur et modificateur
	string obtenirId() const {
		return id_; 
	}

	void modifierId(const string& id) {
		id_ = id;
	}

	string obtenirCouleur() const { 
		return couleur_;
	}

	void modifierCouleur(const string& couleur) {
		couleur_ = couleur; 
	}

	int obtenirPositionX() const {
		return positionX_; 
	}
	void modifierPositionX(int x) {
		positionX_ = x; 
	}

	int obtenirPositionY() const {
		return positionY_; 
	}

	void modifierPositionY(int y) {
		positionY_ = y;
	}

	/*********************************************************************************************************
	* Fonction : estMouvementValide																			 *
	* Description : Vérifie si le déplacement d'une pièce sur l'échiquier est valide						 *
	* Paramètres : La nouvelle case (abscisse et ordonnée) sur l'échiquier vers laquelle la pièce se déplace *
	* Valeur de retour : Booléen; true si la position de la pièce change et que la nouvelle position soit 	 *
						 comprise dans les 64 cases de l'échiquier											 *
	*********************************************************************************************************/
	bool estMouvementValide(int toX, int toY) const{
		if ((toX != positionX_ || toY != positionY_) &&  // On vérifie que la pièce s'est déplacée ET
			toX >= 0 && toX <= 7 &&  // que l'abscisse de la nouvelle case est valide (parmi les 64 cases définies)
			toY >= 0 && toY <= 7)  // et la même chose pour l'ordonnée
			return true;
		return false;
	} 

	virtual bool deplacer(int toX, int toY) = 0; // Méthode virtuelle pure, ce qui rend la classe Piece abstraite
	// (on ne peut pas instancier un objet de type Piece). Cette méthode doit être définie dans les classes dérivées
	
	/****************************************************************************
	* Fonction : obtenirType()													*
	* Description : Retourne le type d'une pièce								*
	* Paramètres : Aucun													    *
	* Valeur de retour : Chaîne de caractères représentant le type de la pièce	*
	****************************************************************************/
	string obtenirType() const 	{ 
		string s = typeid(*this).name();
		s.erase(0, 5); // pour éliminer le mot "class" précédent le type de la classe, retourné par le compilateur
		s.erase(0, 1); // pour éliminer l'espace de début introduit par le précédent erase()
		return s;
	}

	/*******************************************************************************************
	* Fonction : surcharge de l'opérateur de flux de sortie <<								   *
	* Description : Permet d'afficher les informations d'une pièce selon un format donné       *
	* Paramètres : Flux de sortie (stream) et la pièce dont les informations seront affichées  *
	* Valeur de retour : Référence au flux de sortie (appel en cascade)						   *
	*******************************************************************************************/
	friend std::ostream& operator<<(std::ostream& out, const Piece& piece)
	{
		piece.afficher(out);
	}

	/**************************************************************************************
	* Fonction : afficher()																  *
	* Description : Permet d'afficher les informations d'une pièce selon un format donné  *
	* Paramètres : Flux de sortie (stream)												  *
	* Valeur de retour : Référence au flux de sortie (appel en cascade)					  *
	**************************************************************************************/
	virtual ostream&  afficher(ostream& stream) const {
		stream << "Piece " << couleur_ << " d'id " << id_ << " : " << endl;
		stream << "Position (" << positionX_ << ", " << positionY_ << ")" << endl;
		return stream;
	}

private:
	string id_;
	string couleur_;
	int positionX_;
	int positionY_;
};

#endif