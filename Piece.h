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
	* Description : V�rifie si le d�placement d'une pi�ce sur l'�chiquier est valide						 *
	* Param�tres : La nouvelle case (abscisse et ordonn�e) sur l'�chiquier vers laquelle la pi�ce se d�place *
	* Valeur de retour : Bool�en; true si la position de la pi�ce change et que la nouvelle position soit 	 *
						 comprise dans les 64 cases de l'�chiquier											 *
	*********************************************************************************************************/
	bool estMouvementValide(int toX, int toY) const{
		if ((toX != positionX_ || toY != positionY_) &&  // On v�rifie que la pi�ce s'est d�plac�e ET
			toX >= 0 && toX <= 7 &&  // que l'abscisse de la nouvelle case est valide (parmi les 64 cases d�finies)
			toY >= 0 && toY <= 7)  // et la m�me chose pour l'ordonn�e
			return true;
		return false;
	} 

	virtual bool deplacer(int toX, int toY) = 0; // M�thode virtuelle pure, ce qui rend la classe Piece abstraite
	// (on ne peut pas instancier un objet de type Piece). Cette m�thode doit �tre d�finie dans les classes d�riv�es
	
	/****************************************************************************
	* Fonction : obtenirType()													*
	* Description : Retourne le type d'une pi�ce								*
	* Param�tres : Aucun													    *
	* Valeur de retour : Cha�ne de caract�res repr�sentant le type de la pi�ce	*
	****************************************************************************/
	string obtenirType() const 	{ 
		string s = typeid(*this).name();
		s.erase(0, 5); // pour �liminer le mot "class" pr�c�dent le type de la classe, retourn� par le compilateur
		s.erase(0, 1); // pour �liminer l'espace de d�but introduit par le pr�c�dent erase()
		return s;
	}

	/*******************************************************************************************
	* Fonction : surcharge de l'op�rateur de flux de sortie <<								   *
	* Description : Permet d'afficher les informations d'une pi�ce selon un format donn�       *
	* Param�tres : Flux de sortie (stream) et la pi�ce dont les informations seront affich�es  *
	* Valeur de retour : R�f�rence au flux de sortie (appel en cascade)						   *
	*******************************************************************************************/
	friend std::ostream& operator<<(std::ostream& out, const Piece& piece)
	{
		piece.afficher(out);
	}

	/**************************************************************************************
	* Fonction : afficher()																  *
	* Description : Permet d'afficher les informations d'une pi�ce selon un format donn�  *
	* Param�tres : Flux de sortie (stream)												  *
	* Valeur de retour : R�f�rence au flux de sortie (appel en cascade)					  *
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