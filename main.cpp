#ifndef TD_h
#define TD_h
#include<iostream>
#include<string>
#include<conio.h>
#include<Windows.h>
#include <fstream> 
#include <ctime> 

using namespace std;
static int DataPamier[7][6];	//pour reserver les datas de pamier
static bool Joueur1;	
static int GetNb;				//pour recevoir numero par l'ordinateur ou par le clavier

/*********************  CPamier  *****************************/
class CPamier{
private:
	const static string SignePamier[3];
public:
	CPamier(){}
	~CPamier(){}
	void InitialiserPamier() const;
	void DessinPamier() const;
};
/*********************  CMenu  *****************************/
class CMenu{
public:
	void MenuSelectionModele();
	void MenuSelectionColor();
	int NbSelecte();
	void MenuReset();
	//void MenuInformation(int temps);
	CMenu(){}
	~CMenu(){}
};
/*********************  CPion  *****************************/
class CPion{
private:
	int TempsJ[7];
	int NbPion;
	int PionAvance[42];
	int i;
public:
	CPion();
	~CPion(){
		NbPion = 0;
		for (int i=0; i<7; i++) TempsJ[i] = 5;
	}
	void PlacerUnPion();
	void PlacerUnPionAI1();
	void PlacerUnPionAI2();
	void Save();
	void Load();
	int JugerVictoire();

};
/*********************  CControle  *****************************/
class CControle{
private:
	CPamier pamier;
	CMenu menu;
	int menuColor;
	int menuModele;
	CPion pion;
public:
	CControle():menuColor(0), menuModele(0){}
	~CControle(){}
	void start();
};
/*********************  CComputer  *****************************/
class CComputer{
private:
	int ComputerReturn;
public:
	CComputer():ComputerReturn(10){}
	~CComputer(){}
	int SetComputerReturn();

};






#endif
