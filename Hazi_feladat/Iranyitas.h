#include<iostream>
#pragma once
#ifndef IRANYITAS_H
#define IRANYITAS_H

using namespace std;
//TODO: write your code here
class Megrendeles {	 //getterek, és konstruktor kell 
private:
	int size;
	int posX;
	int posY;
	int destX;
	int destY;
public:
	Megrendeles(int, int px, int py, int dx, int dy);
	//Azt kell ellenõrizni, hogy mindegyik pozitív,ha nem akkor ne csináljon semmit, majd try catch blockba szervezés szükséges
	int getSize()const;
	//méretet visszaadja
	int getPosX()const;
	//x poziciót megadja
	int getPosY()const;
	//y poziciót megadja
	int getDestX()const;
	//hova akar menni x irányba
	int getDestY()const;
	//hova akar menni y irányba
	void setPos();

	//átállítjuk x-et és y-t dest X-re és destY-ra, és külön kell majd vizsgálni, hogyha ezek megegyeznek ,akkor ne keressünk nekik jármûvet, hogy elvigye
	//update: beállítottam 0-ra a size-t így ezzel rá tudunk szûrni a valódi csomagokra

};
class Futar {
	int posX;						//nem feltétlenül szükséges, hogy legyen a futaroknak is poziciójuk, lehet úgy egyszerûbb, ha csak egy megrendelést kapnak 
	int posY;
	bool isEmpty;
	int azonosito;
public:
	Futar(int, int , bool, int );
	//Megrendeleséket pointerként kapja, az egyes elemek mindegyikének van egy default értéke, így rossz inicializálás esetén ezeket az értékeket kapja
	int getX()const;
	//X pozicióját kiadja
	int getY() const;
	//Y pozicióját kiadja
	bool getIsEmpty() const;
	//kiadja, hogy üres-e 
	int getAzonosito() const;
	//virtual char callType() const=0;
	//Minden jármû elmondja, hogy milyen tipusú, b->bicikli, a->szemelygepjarmû, t->teherauto
	void setX(int);
	//Beállítja x értékét, a Cég fogja használni, hogy tudja mozgatni 
	void setY(int);
	//Beállítja y értéket, a Cég fogja használni, hogy tudja mozgatni
	void setIsEmpty(bool);
	//Beallítja üresnek,telinek a jármûvet
	void setAzonosito(int);
	//azonosítót csak egyszer kap, ezt nem fogjuk használni
	double getDistance(const Megrendeles &m) const;
	//Megadja, hogy milyen távol van egy adott csomagtól, ezt sem kell külön kiszámolni különbözõ típusnak
	void print();
	//kiprintel mindent, ostream operator overload elõtti állapot
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
	int track(Megrendeles &m) const;	//megadja az azonosítót, ha nem viszi senki, akkor 0


};


#endif