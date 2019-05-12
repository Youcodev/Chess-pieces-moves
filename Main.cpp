/**************************************************
* Titre: Travail pratique #4 - Main.cpp
* Date: 24/02/2017
* Auteur: Gergi Younis
**************************************************/

#include "Piece.h"
#include "Roi.h"
#include "Tour.h"
#include "Pion.h"
#include "Echiquier.h"
#include <clocale>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	//1-  Creez les huit pions blancs avec les coordonnées (i,1) i : 0-->7 et les id A2-->H2
	// Les pions blancs sont bien à leur position de départ 
	Pion* pionBlanc1 = new Pion("A2", "Blanc", 0, 1);
	Pion* pionBlanc2 = new Pion("B2", "Blanc", 1, 1);
	Pion* pionBlanc3 = new Pion("C2", "Blanc", 2, 1);
	Pion* pionBlanc4 = new Pion("D2", "Blanc", 3, 1);
	Pion* pionBlanc5 = new Pion("E2", "Blanc", 4, 1);
	Pion* pionBlanc6 = new Pion("F2", "Blanc", 5, 1);
	Pion* pionBlanc7 = new Pion("G2", "Blanc", 6, 1);
	Pion* pionBlanc8 = new Pion("H2", "Blanc", 7, 1);
	
	//2-Creez les huit pions noirs avec les coordonnées (i,6) i : 0-->7 et les id A7-->H7
	// Les pions noirs sont bien à leur position de départ 
	Pion* pionNoir1 = new Pion("A7", "Noir", 0, 6);
	Pion* pionNoir2 = new Pion("B7", "Noir", 1, 6);
	Pion* pionNoir3 = new Pion("C7", "Noir", 2, 6);
	Pion* pionNoir4 = new Pion("D7", "Noir", 3, 6);
	Pion* pionNoir5 = new Pion("E7", "Noir", 4, 6);
	Pion* pionNoir6 = new Pion("F7", "Noir", 5, 6);
	Pion* pionNoir7 = new Pion("G7", "Noir", 6, 6);
	Pion* pionNoir8 = new Pion("H7", "Noir", 7, 6);

	//3-  Creez les deux tours blanches d'id "A1" et "H1" dans les positions respectives (0,0) et (7,0)
	// Les tours blanches sont bien à leur position de départ
	Tour* tourBlanc1 = new Tour("A1", "Blanc", 0, 0);
	Tour* tourBlanc2 = new Tour("H1", "Blanc", 7, 0);

	//4-  Creez les deux tours noires  d'id "A8" et "H8" dans les positions respectives (0,7) et (7,7)
	// Les tours noires sont bien à leur position de départ
	Tour* tourNoir1 = new Tour("A8", "Noir", 0, 7);
	Tour* tourNoir2 = new Tour("H8", "Noir", 7, 7);

	//5-  Creez les Fous blanc et noirs
	// Les fous blancs sont bien à leur position de départ
	Fou* fouBlanc1 = new Fou("C1", "Blanc", 2, 0);
	Fou* fouBlanc2 = new Fou("F1", "Blanc", 5, 0);
	// Les fous noirss sont bien à leur position de départ
	Fou* fouNoir1 = new Fou("C8", "Noir", 2, 7);
	Fou* fouNoir2 = new Fou("F8", "Noir", 5, 7);

	//6-  Creez les deux reines E1 et E8
	// Les deux reines sont bien à leur position de départ
	Reine* reineBlanc = new Reine("E1", "Blanc", 4, 0);
	Reine* reineNoir = new Reine("E8", "Noir", 4, 7);

	//7-  Creez les deux rois D1 et D8
	// Les deux rois sont bien à leur position de départ
	Roi* roiBlanc = new Roi("D1", "Blanc", 3, 0);
	Roi* roiNoir = new Roi("D8", "Noir", 3, 7);

	// 8- Creez un echiquier 
	Echiquier echiquier;
	
	cout << "----------AJOUT DES PIECES----------" << endl << endl;
	//9- Ajoutez toutes les pièces précidament définies à l'echiquier	
	// Ajout des rois
	echiquier += roiBlanc;
	echiquier += roiNoir;
	// Ajout des tours
	echiquier += tourBlanc1;
	echiquier += tourBlanc2;
	echiquier += tourNoir1;
	echiquier += tourNoir2;
	// Ajout des reines
	echiquier += reineBlanc;
	echiquier += reineNoir;
	// Ajout des fous
	echiquier += fouBlanc1;
	echiquier += fouBlanc2;
	echiquier += fouNoir1;
	echiquier += fouNoir2;
	// Ajout des pions
	echiquier += pionBlanc1;
	echiquier += pionBlanc2;
	echiquier += pionBlanc3;
	echiquier += pionBlanc4;
	echiquier += pionBlanc5;
	echiquier += pionBlanc6;
	echiquier += pionBlanc7;
	echiquier += pionBlanc8;
	echiquier += pionNoir1;
	echiquier += pionNoir2;
	echiquier += pionNoir3;
	echiquier += pionNoir4;
	echiquier += pionNoir5;
	echiquier += pionNoir6;
	echiquier += pionNoir7;
	echiquier += pionNoir8;
	
	cout << "----------TEST DES DEPLACEMENTS------------" << endl << endl;
	//10-  Deplacer la piece d'id A2 à la position (0,2)  --Deplacement de Pion
	echiquier.deplacerPiece("A2", 0, 2);
	
	//11-  Deplacer le piece d'id H7 à la position (7,4)  --Deplacement du Pion
	echiquier.deplacerPiece("H7", 7, 4);

	//12-  Deplacer la piece d'id A2 à la position (0,4)  --Deplacement du Pion
	echiquier.deplacerPiece("A2", 0, 4);

	//13-  Deplacer la piece d'id H8 à la position (7,6)  --Deplacement de la Tour
	echiquier.deplacerPiece("H8", 7, 6);

	//14-  Deplacer la piece d'id H8 à la position (7,6)  --Deplacement de la Tour
	echiquier.deplacerPiece("H8", 7, 6);

	/******************************************************************
	* Quelques tests supplémentaires relatifs au rois, reines et fous *
	******************************************************************/
	echiquier.deplacerPiece("E1", 4, 3);
	echiquier.deplacerPiece("E1", 1, 4);
	echiquier.deplacerPiece("F8", 5, 4);
	echiquier.deplacerPiece("F8", 1, 3);
	echiquier.deplacerPiece("F8", 0, 4);
	echiquier.deplacerPiece("F8", 0, 4);
	echiquier.deplacerPiece("E1", 1, 4);
	echiquier.deplacerPiece("D8", 2, 6);
	echiquier.deplacerPiece("D8", 0, 4);
	echiquier.deplacerPiece("D8", 2, 6);
	//*****************************************************************
	
	//15-  Enlever la piece d'id A2 
	echiquier -= "A2";

	cout << endl << "----------TEST DES PROMOTIONS------------" << endl << endl;
	
	//16- Promouvoir la piece d'id F6.
	echiquier.promouvoir("F6");
	
	//17- Promouvoir la piece d'id B2.	
	echiquier.promouvoir("B2");

	//18- Affichage de l'Echiquier
	cout << echiquier;
	//Si vous avez besoin de lancer avec un arret a la fin, faites ctrl+F5;

	return 0;
}
