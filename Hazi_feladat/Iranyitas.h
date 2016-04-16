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
	//Csak ezzel a konstuktorral fogjuk megh�vnia a megrendel�st, nem kell settelni semmit, csak ha c�lba �rt 
	Megrendeles() {};
	//tombos�t�shez kell feault konstuktor
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
	int posX;					 
	int posY;
	bool isEmpty;
	int azonosito;
	Megrendeles *megrendeles;
	//vagy mutasson r�, vagy legyen benne egy eg�sz , a c�m szerinti t�rol�s helytakar�kosabb, c�gn�l meg �gyis vannak megrendel�sek
public:
	Futar() {};
	//A futar default konstruktora, nem csin�l semmit 

	Futar(int, int , bool, int );
	//Megrendeles�ket pointerk�nt kapja, az egyes elemek mindegyik�nek van egy default �rt�ke, �gy rossz inicializ�l�s eset�n ezeket az �rt�keket kapja
	//a megrendel�s alapesetben NULL, csak a set tudja be�ll�tani, amit csak a c�g fog kezelni 
	int getX()const;
	//X pozici�j�t kiadja
	int getY() const;
	//Y pozici�j�t kiadja
	bool getIsEmpty() const;
	//kiadja, hogy �res-e 
	int getAzonosito() const;
	//Minden j�rm� elmondja, hogy milyen tipus�, b->bicikli, a->szemelygepjarm�, t->teherauto
	void setX(int);
	//Be�ll�tja x �rt�k�t, a C�g fogja haszn�lni, hogy tudja mozgatni 
	void setY(int);
	//Be�ll�tja y �rt�ket, a C�g fogja haszn�lni, hogy tudja mozgatni
	void setIsEmpty(bool);
	//Beall�tja �resnek,telinek a j�rm�vet
	void setAzonosito(int);
	//azonos�t�t csak egyszer kap, ezt nem fogjuk haszn�lni
	void setMegrendeles(Megrendeles *m);
	//egy megrendeles c�met kap �s arra �ll�tja a megrendeles nev� pointert
	Megrendeles * getMegrendeles();
	double getDistance(const Megrendeles &m) const;
	//Megadja, hogy milyen t�vol van egy adott csomagt�l, ezt sem kell k�l�n kisz�molni k�l�nb�z� t�pusnak
	void print();
	//kiprintel mindent, ostream operator overload el�tti �llapot
	friend ostream & operator<<(ostream & o, const Futar &a);

};
class Teherauto :public Futar {
public:
	Teherauto() {};
	Teherauto(int px, int py, bool isEmptyy, int az);
	char callType() const;
};
class Szemelygepjarmu :public Futar {
public:
	Szemelygepjarmu() {};
	Szemelygepjarmu(int px, int py, bool isEmptyy, int az) :Futar(px, py, isEmptyy, az) {};
	char callType() const;

};
class Bicikli : public Futar {
public:
	Bicikli() {};
	Bicikli(int px, int py, bool isEmptyy, int az) :Futar(px, py, isEmptyy, az) {};
	char callType() const;

};


class Ceg {
private:

	Futar *futar;
	Megrendeles *megrendeles;
	int mNum;
	int num;
public:
	Ceg();
	void hire(const Futar &a);
	//ellen�rizni kell hozz�, hogy m�k�dik-e a m�sol� konstruktor defaultk�nt, vagy �jra kell �rni.
	//be�ll�tja az utols� helyre az �j fut�rt, default konstruktork�nt h�vja, a felhaszn�l�t�l elv�rja hogy inicializ�lja 
	void addOrder(const Megrendeles &m);
	//felvesz egy �j megrendel�st
	//a megadott megrendel�snek m�r L�TEZNIE KELL 
	~Ceg();
	//Destruktor, let�r�lj�k a futart
	void printFutarList() const;
	//ki�rja a standart kimenetre a fut�rokat
	Futar *getClosest(const Megrendeles &m) const;
	void select(Futar &a, Megrendeles &m);
	int track(Megrendeles &m) const;	
	//megadja az azonos�t�t, ha nem viszi senki, akkor 0


};


#endif