#include<iostream>
#pragma once
#ifndef IRANYITAS_H
#define IRANYITAS_H

using namespace std;
//TODO: write your code here
class Megrendeles {	 //getterek, �s konstruktor kell 
private:
	int size;
	int posX;
	int posY;
	int destX;
	int destY;
public:
	Megrendeles(int, int px, int py, int dx, int dy);
	//Azt kell ellen�rizni, hogy mindegyik pozit�v,ha nem akkor ne csin�ljon semmit, majd try catch blockba szervez�s sz�ks�ges
	int getSize()const;
	//m�retet visszaadja
	int getPosX()const;
	//x pozici�t megadja
	int getPosY()const;
	//y pozici�t megadja
	int getDestX()const;
	//hova akar menni x ir�nyba
	int getDestY()const;
	//hova akar menni y ir�nyba
	void setPos();

	//�t�ll�tjuk x-et �s y-t dest X-re �s destY-ra, �s k�l�n kell majd vizsg�lni, hogyha ezek megegyeznek ,akkor ne keress�nk nekik j�rm�vet, hogy elvigye
	//update: be�ll�tottam 0-ra a size-t �gy ezzel r� tudunk sz�rni a val�di csomagokra

};
class Futar {
	int posX;						//nem felt�tlen�l sz�ks�ges, hogy legyen a futaroknak is pozici�juk, lehet �gy egyszer�bb, ha csak egy megrendel�st kapnak 
	int posY;
	bool isEmpty;
	int azonosito;
public:
	Futar(int, int , bool, int );
	//Megrendeles�ket pointerk�nt kapja, az egyes elemek mindegyik�nek van egy default �rt�ke, �gy rossz inicializ�l�s eset�n ezeket az �rt�keket kapja
	int getX()const;
	//X pozici�j�t kiadja
	int getY() const;
	//Y pozici�j�t kiadja
	bool getIsEmpty() const;
	//kiadja, hogy �res-e 
	int getAzonosito() const;
	//virtual char callType() const=0;
	//Minden j�rm� elmondja, hogy milyen tipus�, b->bicikli, a->szemelygepjarm�, t->teherauto
	void setX(int);
	//Be�ll�tja x �rt�k�t, a C�g fogja haszn�lni, hogy tudja mozgatni 
	void setY(int);
	//Be�ll�tja y �rt�ket, a C�g fogja haszn�lni, hogy tudja mozgatni
	void setIsEmpty(bool);
	//Beall�tja �resnek,telinek a j�rm�vet
	void setAzonosito(int);
	//azonos�t�t csak egyszer kap, ezt nem fogjuk haszn�lni
	double getDistance(const Megrendeles &m) const;
	//Megadja, hogy milyen t�vol van egy adott csomagt�l, ezt sem kell k�l�n kisz�molni k�l�nb�z� t�pusnak
	void print();
	//kiprintel mindent, ostream operator overload el�tti �llapot
	friend ostream & operator<<(ostream & o, const Futar &a);

};
//class Teherauto :public Futar {
//private:
//	int capacity;
//public:
//	Teherauto(int _posX = 0, int _posY = 0, bool _isEmpty = false, int _azonosito = 0, int _capacity = 0) { capacity = _capacity; };
//
//
//};
//class Szemelygepjarmu :public Futar {
//public:
//
//
//
//};
//class Bicikli : public Futar {
//public:
//	bool inRadius(const Megrendeles &m);
//
//
//};
//
//
class Ceg {
private:

	Futar *futar;
	int num;
public:
	Ceg() {
		futar = NULL;
		num = 0;
	}
	void printFutarList() const;
	Futar *getClosest(const Megrendeles &m) const;
	void add(Futar &a);
	void select(Futar &a, Megrendeles &m);
	int track(Megrendeles &m) const;	//megadja az azonos�t�t, ha nem viszi senki, akkor 0


};


#endif