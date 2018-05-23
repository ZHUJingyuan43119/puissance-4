
//悔棋，打印有误，无法消去颜色


#include"TD.h"
#include<iostream>
#include<string>
#include<conio.h>
#include<Windows.h>
#include <stdlib.h> 
#include <time.h>  
#include <fstream> 
#include <ctime> 

using namespace std;
/******************************************************
**class CPamier
*******************************************************/

const string CPamier::SignePamier[3] = {"□","●","●"};

void CPamier::InitialiserPamier() const {
	unsigned int i,j;
	for(i=0;i<7;i++){
		for(j=0;j<6;j++){ DataPamier[i][j] = 0; }
	}
	
}

void CPamier::DessinPamier() const {
	system("cls");
	cout<<"******* PUISSANCE 4 *******"<<endl<<endl;
	for(unsigned int j=0;j<6;j++){
		for(unsigned int i=0;i<7;i++){
			if(DataPamier[i][j] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
			}
			if(DataPamier[i][j] == 2) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
			}
			if(DataPamier[i][j] == 0) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN);
			}
			cout<<SignePamier[DataPamier[i][j]]<<" ";
			
		}

		cout<<endl<<endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	for (unsigned int i=1; i<=7; i++){ cout<<"-"<<i<<"-"; }
	cout<<endl<<"****************************"<<endl<<"****************************"<<endl<<endl;
}

/******************************************************
**class CMenu
*******************************************************/

void CMenu::MenuSelectionModele(){
	system("cls");
	cout<<"******* PUISSANCE 4 *******"<<endl<<endl;
	cout<<"Import le numero de votre choix："<<endl<<endl;
	cout<<"1.Personne VS Ordinateur"<<endl;
	cout<<"2.Personne VS Personne"<<endl;
}

void CMenu::MenuSelectionColor(){
	system("cls");
	cout<<"******* PUISSANCE 4 *******"<<endl<<endl;
	cout<<"Importer le tour de votre choix："<<endl<<endl;
	cout<<"1.Premier (JAUNE)"<<endl;
	cout<<"2.Dernier (ROUGE)"<<endl<<endl;
	cout<<"Presser 'esc' pour quitter"<<endl;
}

void CMenu::MenuReset(){
	int c=0;
	while(1){ 
	 c=_getch();
	 if(c==27) break;
	}
}

int CMenu::NbSelecte() {
	int c=0;
	c=_getch();
	if(c==49)
		return 1;
	if(c==50)
		return 2;
	return 0;
}

//void CMenu::MenuInformation(int temps) {}
	


/******************************************************
**class CPion
*******************************************************/

CPion::CPion(){
	NbPion = 0;
	for (int i=0; i<7; i++) TempsJ[i] = 5;
}

void CPion::PlacerUnPion() {
	if(TempsJ[GetNb-49] != -1) {
		PionAvance[NbPion]=GetNb-49;
		if(Joueur1 == true){	//tour de joueur JAUNE
			
			if(  GetNb == 49 ||GetNb == 50 || GetNb == 51 || GetNb == 52 || GetNb == 53 || GetNb == 54 || GetNb == 55){
				DataPamier[GetNb-49][TempsJ[GetNb-49]] = 1;
				TempsJ[GetNb-49]--;
				NbPion++;
				Joueur1 = false;
			}	
		}
		else {		//tour de joueur ROUGE
			if( GetNb == 49 ||GetNb == 50 || GetNb == 51 || GetNb == 52 || GetNb == 53 || GetNb == 54 || GetNb == 55){
				DataPamier[GetNb-49][TempsJ[GetNb-49]] = 2;
				TempsJ[GetNb-49]--;
				NbPion++;
				Joueur1 = true;
			}

		}
		if(GetNb == 57){
			if(NbPion>0){
				NbPion--;
				TempsJ[PionAvance[NbPion]]++;
				DataPamier[PionAvance[NbPion]][TempsJ[PionAvance[NbPion]]] = 0;
				cout<<"Faux, ! "<<PionAvance[NbPion]<<endl;
				i=NbPion % 2;
				if(i==0 ){Joueur1 = true;}
				else{Joueur1 = false;}
			}
			}
	}	//TempsJ != 1
	else {
		cout<<"Faux,ne pas pouvoir placer ! "<<endl;
		system("pause");
	}

}

void CPion::PlacerUnPionAI1() {
	if(TempsJ[GetNb-49] != -1) {
		PionAvance[NbPion]=GetNb-49;
		if(Joueur1 == true){	//tour de joueur JAUNE
			
			if(  GetNb == 49 ||GetNb == 50 || GetNb == 51 || GetNb == 52 || GetNb == 53 || GetNb == 54 || GetNb == 55){
				DataPamier[GetNb-49][TempsJ[GetNb-49]] = 1;
				TempsJ[GetNb-49]--;
				NbPion++;
				Joueur1 = false;
			}	
		}
		else {		//tour de joueur ROUGE
			if( GetNb == 49 ||GetNb == 50 || GetNb == 51 || GetNb == 52 || GetNb == 53 || GetNb == 54 || GetNb == 55){
				DataPamier[GetNb-49][TempsJ[GetNb-49]] = 2;
				TempsJ[GetNb-49]--;
				NbPion++;
				Joueur1 = true;
			}

		}
		if(GetNb == 57){
			if(NbPion>0){
				NbPion--;
				TempsJ[PionAvance[NbPion]]++;
				DataPamier[PionAvance[NbPion]][TempsJ[PionAvance[NbPion]]] = 0;
				NbPion--;
				TempsJ[PionAvance[NbPion]]++;
				DataPamier[PionAvance[NbPion]][TempsJ[PionAvance[NbPion]]] = 0;
				Joueur1 = true;
			}
		}
	}	//TempsJ != 1
	else {
		cout<<"Faux,ne pas pouvoir placer ! "<<endl;
		system("pause");
	}

}

void CPion::PlacerUnPionAI2() {
	if(TempsJ[GetNb-49] != -1) {
		PionAvance[NbPion]=GetNb-49;
		if(Joueur1 == true){	//tour de joueur JAUNE
			
			if(  GetNb == 49 ||GetNb == 50 || GetNb == 51 || GetNb == 52 || GetNb == 53 || GetNb == 54 || GetNb == 55){
				DataPamier[GetNb-49][TempsJ[GetNb-49]] = 1;
				TempsJ[GetNb-49]--;
				NbPion++;
				Joueur1 = false;
			}	
		}
		else {		//tour de joueur ROUGE
			if( GetNb == 49 ||GetNb == 50 || GetNb == 51 || GetNb == 52 || GetNb == 53 || GetNb == 54 || GetNb == 55){
				DataPamier[GetNb-49][TempsJ[GetNb-49]] = 2;
				TempsJ[GetNb-49]--;
				NbPion++;
				Joueur1 = true;
			}

		}
		if(GetNb == 57){
			if(NbPion>0){
				NbPion--;
				TempsJ[PionAvance[NbPion]]++;
				DataPamier[PionAvance[NbPion]][TempsJ[PionAvance[NbPion]]] = 0;
				Joueur1 = false;
			}
			}
	}	//TempsJ != 1
	else {
		cout<<"Faux,ne pas pouvoir placer ! "<<endl;
		system("pause");
	}

}

void CPion::Save(){
	if(GetNb==27){
		int num;
		cout<<"do you want to save"<<endl;
		cin>>num;
		if(num==49){
			ofstream put;
			put.open("game.txt");
			for(int i=0;i<7;i++){
				for(int j=0;j<6;j++){
				   put<<DataPamier[i][j]<<endl;}}
			put<<flush;
			put.close();
		}
	}
}
void CPion::Load(){
	system("cls");
	cout<<"do you want to load"<<endl;
	if(GetNb==27){
			ifstream fin("game.txt");
			for(int i=0;i<7;i++){
				for(int j=0;j<6;j++){
				   fin>>DataPamier[i][j];}}
		}
}


int CPion::JugerVictoire(){				//return 4: jaune win, return 5 : rouge win, return 0: null, return 1: pas de victoire
	int i,j;
	for(j=0; j<6;j++){				// juger "-"
		for(i=0; i<7; i++){
			if(DataPamier[i][j] == 1 && DataPamier[i+1][j] == 1 && DataPamier[i+2][j] == 1 && DataPamier[i+3][j] == 1){
				return 4;
				break;
			}
			else if(DataPamier[i][j] == 2 && DataPamier[i+1][j] == 2 && DataPamier[i+2][j] == 2 && DataPamier[i+3][j] == 2){
				return 5;
				break;
			}
		}
	}
	for(i=0; i<7; i++){		//juger "|"
		for(j=0; j<6; j++){
			if(DataPamier[i][j] == 1 && DataPamier[i][j+1] == 1 && DataPamier[i][j+2] == 1 && DataPamier[i][j+3] == 1){
				return 4;
				break;
			}
			else if(DataPamier[i][j] == 2 && DataPamier[i][j+1] == 2 && DataPamier[i][j+2] == 2 && DataPamier[i][j+3] == 2){
				return 5;
				break;
			}
		}
	}
	for(i=0; i<7; i++){		//juger "\"
		for(j=0; j<6; j++){
			if(DataPamier[i][j] == 1 && DataPamier[i+1][j+1] == 1 && DataPamier[i+2][j+2] == 1 && DataPamier[i+3][j+3] == 1){
				return 4;
				break;
			}
			else if(DataPamier[i][j] == 2 && DataPamier[i+1][j+1] == 2 && DataPamier[i+2][j+2] == 2 && DataPamier[i+3][j+3] == 2){
				return 5;
				break;
			}
		}
	}
	for(i=0; i<7; i++){		//juger "/"
		for(j=0; j<6; j++){
			if(DataPamier[i][j] == 1 && DataPamier[i-1][j+1] == 1 && DataPamier[i-2][j+2] == 1 && DataPamier[i-3][j+3] == 1){
				return 4;
				break;
			}
			else if(DataPamier[i][j] == 2 && DataPamier[i-1][j+1] == 2 && DataPamier[i-2][j+2] == 2 && DataPamier[i-3][j+3] == 2){
				return 5;
				break;
			}
		}
	}
	if(CPion::NbPion == 42) {
		return 0;
	}
	return 1;
}


/******************************************************
**class CControle
*******************************************************/

void CControle::start() {
	while(1) {
		menu.MenuSelectionModele();
		menuModele = menu.NbSelecte();
		pamier.InitialiserPamier();
		pion.~CPion();
		if(menuModele == 1)	{		//  ******personne VS ordinateur********
			menu.MenuSelectionColor();
			menuColor = menu.NbSelecte();
			if(menuColor == 1) {	//premier jaune
				Joueur1 = true;
				pamier.DessinPamier();
				while(pion.JugerVictoire() == 1){
					if(Joueur1 == true){
						cout<<"Joueur : "<<"JAUNE"<<endl<<"Votre choix(9 : Annuler): ";
						GetNb = getchar();
					}
					if(Joueur1 == false) {srand((unsigned)time(NULL)); GetNb = (rand() % (55-49+1))+ 49;}
					pion.PlacerUnPionAI1();
					pamier.DessinPamier();
					if(pion.JugerVictoire() == 4){
						cout<<"Joueur JAUNE remporte la victoire ! "<<endl;
						system("pause");
					}
					else if(pion.JugerVictoire() == 5){
						cout<<"Ordinateur ROUGE remporte la victoire ! "<<endl;
						system("pause");
						}
					else if(pion.JugerVictoire() == 0){
						cout<<"Faire match null"<<endl;
						system("pause");
						}
				}
			}
			else if(menuColor == 2) {		//dernier rouge
				Joueur1 = true;
				pamier.DessinPamier();
				while(pion.JugerVictoire() == 1){
					if(Joueur1 == false){
						cout<<"Joueur : "<<"ROUGE"<<endl<<"Votre choix(9 : Annuler): ";
						GetNb = getchar();
					}
					if(Joueur1 == true) {srand((unsigned)time(NULL)); GetNb = (rand() % (55-49+1))+ 49;}		//computer input
					pion.PlacerUnPionAI2();
					pamier.DessinPamier();
					if(pion.JugerVictoire() == 4){
						cout<<"Ordinateur JAUNE remporte la victoire ! "<<endl;
						system("pause");
					}
					else if(pion.JugerVictoire() == 5){
						cout<<"Joueur ROUGE remporte la victoire ! "<<endl;
						system("pause");
						}
					else if(pion.JugerVictoire() == 0){
						cout<<"Faire match null"<<endl;
						system("pause");
						}
				}
			}
		}
		else if(menuModele == 2) {  // ******* personne VS personne *******
			Joueur1 = true;
			pamier.DessinPamier();
			while(pion.JugerVictoire() == 1){
				if(Joueur1 == true)
					cout<<"Joueur : "<<"JAUNE"<<endl<<"Votre choix(9 : Annuler): ";
				else cout<<"Joueur : "<<"ROUGE"<<endl<<"Votre choix(9 : Annuler): ";
				GetNb = getchar();
				pion.PlacerUnPion();
				pamier.DessinPamier();
				if(pion.JugerVictoire() == 4){
					cout<<"Joueur JAUNE remporte la victoire ! "<<endl;
					system("pause");
				}
				else if(pion.JugerVictoire() == 5){
					cout<<"Joueur ROUGE remporte la victoire ! "<<endl;
					system("pause");
					}
				else if(pion.JugerVictoire() == 0){
					cout<<"Faire match null"<<endl;
					system("pause");
					}
			}
		}
		else {menu.MenuReset();}
	}
}


/******************************************************
**class COrdinateur
*******************************************************/

int CComputer::SetComputerReturn(){
	ComputerReturn = 1;
	return ComputerReturn;
}             
