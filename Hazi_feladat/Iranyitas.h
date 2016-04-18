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
	//Csak ezzel a konstuktorral fogjuk meghívnia a megrendelést, nem kell settelni semmit, csak ha célba ért 
	Megrendeles() {};
	//tombosítéshez kell feault konstuktor
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
	//beállítja a posx posy-t destx és desty-ra , desteket meg 0,0 -ra 
	//átállítjuk x-et és y-t dest X-re és destY-ra, és külön kell majd vizsgálni, hogyha ezek megegyeznek ,akkor ne keressünk nekik jármûvet, hogy elvigye
	//update: beállítottam 0-ra a size-t így ezzel rá tudunk szûrni a valódi csomagokra

};
class Futar {
	int posX;					 
	int posY;
	bool isEmpty;
	int azonosito;
	Megrendeles *megrendeles;
	//vagy mutasson rá, vagy legyen benne egy egész , a cím szerinti tárolás helytakarékosabb, cégnél meg úgyis vannak megrendelések
public:
	Futar() {};
	//A futar default konstruktora, nem csinál semmit 
	//Virtuális destruktor ? 
	Futar(int, int , bool, int );
	//Megrendeleséket pointerként kapja, az egyes elemek mindegyikének van egy default értéke, így rossz inicializálás esetén ezeket az értékeket kapja
	//a megrendelés alapesetben NULL, csak a set tudja beállítani, amit csak a cég fog kezelni 
	int getX()const;
	//X pozicióját kiadja
	int getY() const;
	//Y pozicióját kiadja
	bool getIsEmpty() const;
	//kiadja, hogy üres-e 
	int getAzonosito() const;
	//Minden jármû elmondja, hogy milyen tipusú, b->bicikli, a->szemelygepjarmû, t->teherauto
	void setX(int);
	//Beállítja x értékét, a Cég fogja használni, hogy tudja mozgatni 
	void setY(int);
	//Beállítja y értéket, a Cég fogja használni, hogy tudja mozgatni
	void setIsEmpty(bool);
	//Beallítja üresnek,telinek a jármûvet
	
	//origótól vett távolság
	void setAzonosito(int);
	void setMegrendeles(Megrendeles *m);
	//egy megrendeles címet kap és arra állítja a megrendeles nevû pointert
	Megrendeles * getMegrendeles();
	double getDistance(const Megrendeles &m) const;
	//Megadja, hogy milyen távol van egy adott csomagtól, ezt sem kell külön kiszámolni különbözõ típusnak
	double getDestDistance(const Megrendeles &m) const;
	//megadja, hogy milyen távol van a csomag távolsága
	void print();
	//kiprintel mindent, ostream operator overload elõtti állapot
	virtual bool available(const Megrendeles &m) { return false; };
	//megnézi minden esetben, hogy elérhetõ-e a futár, legyen szó biciklistáról, futárral satöbbi 
	// Ha ez hívódik meg, akkor biztos, hogy nem elérhetõ
	virtual char  callType()const {};
	//elmondja micsoda

	friend ostream & operator<<(ostream & o, const Futar &a);

};
class Teherauto :public Futar {
public:
	Teherauto() {};
	Teherauto(int px, int py, bool isEmptyy, int az);
	bool available(Megrendeles &m) const;
	char callType()const;
	//Megmondja, hogy nincs tele, és éppen nincs megrendelése 
	
};
class Szemelygepjarmu :public Futar {
public:
	Szemelygepjarmu() {};
	Szemelygepjarmu(int px, int py, bool isEmptyy, int az) :Futar(px, py, isEmptyy, az) {};
	bool available(Megrendeles &m)const;
	
	// ha üres és a mérete a csomagnak 1, akkor elérhetõ 
	char callType()const;

};
class Bicikli : public Futar {
public:
	Bicikli() {};
	Bicikli(int px, int py, bool isEmptyy, int az) :Futar(px, py, isEmptyy, az) {};
	bool available(Megrendeles &m) const; 
	char callType()const;



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
	//ellenõrizni kell hozzá, hogy mûködik-e a másoló konstruktor defaultként, vagy újra kell írni.
	//beállítja az utolsó helyre az új futárt, default konstruktorként hívja, a felhasználótól elvárja hogy inicializálja 
	void addOrder(const Megrendeles &m);
	//felvesz egy új megrendelést
	//a megadott megrendelésnek már LÉTEZNIE KELL 
	~Ceg();
	//Destruktor, letöröljük a futart
	void printFutarList() const;
	//kiírja a standart kimenetre a futárokat
	
	void select(Futar &a,  Megrendeles *m);
	//futárt bántani fogjuk, ezért nem constans megrendelést nem
	int track(Megrendeles &m) const;	
	//megadja az azonosítót, ha nem viszi senki, akkor 0
	void  giveOrder(Megrendeles *m)
	{
		/*int minDist = futar[0].getDistance(*m);
		for (int i = 0; i < num; i++)
		{
			if (futar[i].available)
			{
				if (futar[i].callType() == 'b')
				{
					if
					select(futar[i], m);
				}
			}
		}*/
	}

};


#endif