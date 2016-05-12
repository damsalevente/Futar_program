#include<iostream>
#include <vector>
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
		Futar(int _posX, int _posY, bool _isEmpty, int _azonosito);
		//Megrendeleséket pointerként kapja, az egyes elemek mindegyikének van egy default értéke, így rossz inicializálás esetén ezeket az értékeket kapja
		//a megrendelés alapesetben NULL, csak a set tudja beállítani, amit csak a cég fog kezelni
		//try-catch : ha bármelyik adat hibásan van bevíve, kiírja, hogy hibás a bemenet, és mindent nullára állít be
		int getX()const;
		//X pozicióját kiadja
		int getY() const;
		//Y pozicióját kiadja
		bool getIsEmpty() const;
		//kiadja, hogy üres-e 
		int getAzonosito() const;
		//azonosító
		void setX(int x);
		//Beállítja x értékét, a Cég fogja használni, hogy tudja mozgatni 
		void setY(int y);
		//Beállítja y értéket, a Cég fogja használni, hogy tudja mozgatni
		void setIsEmpty(bool a);
		//Beallítja üresnek vagy telinek a jármûvet
		void setAzonosito(int a);
		//belehet állítani új azonosítót
		void setMegrendeles(Megrendeles *m);
		//egy megrendeles címet kap és arra állítja a megrendeles nevû pointert
		Megrendeles * getMegrendeles();
		//Visszaadja a megrendelést, ha nincs megrendelése akkor NULL
		double getDistance(const Megrendeles &m) const;
		//Megadja, hogy milyen távol van egy adott csomagtól, ezt sem kell külön kiszámolni különbözõ típusnak
		double getDestDistance(const Megrendeles &m) const;
		//megadja, hogy milyen távol van a csomag távolsága
		virtual bool available(const Megrendeles &m) const;
		//megnézi minden esetben, hogy elérhetõ-e a futár, legyen szó biciklistáról, futárral satöbbi 
		// Ha ez hívódik meg, akkor biztos, hogy nem elérhetõ
		virtual int preference(const Megrendeles &m)const;
		//egy számot ad visssza, ami megmondja minden esetben, hogy mennyire akarjuk, hogy õ vigye el a csomagot. Minél nagyobb a szám annál jobb


		friend ostream & operator<<(ostream & o, const Futar &a);
		//felesleges,külsõ függvényként van megírva, nem kell friendnek lennie

	};
	class Teherauto :public Futar {
	public:
		Teherauto() {};
		Teherauto(int px, int py, bool isEmptyy, int az);
		bool available(const Megrendeles &m) const;
		//akkor elérhetõ, ha üres
		int preference(const Megrendeles &m)const;
		//Ha 15km-nél távolabb van, +1, ha 60 km-nél távolabbra kell szállítani +2
		//Megmondja, hogy nincs tele, és éppen nincs megrendelése 

	};
	class Szemelygepjarmu :public Futar {
	public:
		Szemelygepjarmu() {};
		Szemelygepjarmu(int px, int py, bool isEmptyy, int az) :Futar(px, py, isEmptyy, az) {};
		bool available(const Megrendeles &m)const;
		//akkor elérhetõ, ha üres 
		int preference(const Megrendeles &m)const;
		//ha 15km-nél távolabb van a csomag +1, ha 60km-nél távolabb kell kiszállítani akkor +2
		// ha üres és a mérete a csomagnak 1, akkor elérhetõ 


	};
	class Bicikli : public Futar {
	public:
		Bicikli() {};
		Bicikli(int px, int py, bool isEmptyy, int az) :Futar(px, py, isEmptyy, az) {};
		bool available(const Megrendeles &m) const;
		//elérhetõ ha üres és 15km-en belül van
		int preference(const Megrendeles &m)const;
		// ha közel kell szállítani, akkor nagyon jó, egyébként meg 1-es értéket kap



	};


	class Ceg {
	private:

		vector <Futar * > futar;
		//vector típusú lett a futár, nem fogok csillagokat látni
		Megrendeles *megrendeles;
		//dinamikus tömb
		int mNum;
		int num;
	public:
		Ceg();
		//inicializálja a szükséges tömböket, darabszámokat nullára állítja
		void hire(Futar *a);
		//ellenõrizni kell hozzá, hogy mûködik-e a másoló konstruktor defaultként, vagy újra kell írni...check
		//beállítja az utolsó helyre az új futárt, default konstruktorként hívja, a felhasználótól elvárja hogy inicializálja
		//ha paraméterként new Futar(...)-t kap, akkor memóriaszivárgás lesz
		void addOrder(const Megrendeles &m);
		//felvesz egy új megrendelést
		//a megadott megrendelésnek már LÉTEZNIE KELL 
		Futar getFutar(int index);
		//A megadott indexû Futár pointer értékét adja vissza
		~Ceg();
		//Destruktor, letöröljük a pointert
		void printFutarList() const;
		//kiírja a standart kimenetre a futárokat
		void log()const;
		//kiírja a futárok listáját
		//fájlkezelés 
		void select(Futar &a, Megrendeles *m);
		//futárt(vektort) bántani fogjuk, ezért nem constans
		//beállítja az a futár megrendelés tagváltozóját m-re null helyett, ha nem null akkor throw isFullexception 
		int track(Megrendeles &m) const;
		//megadja az azonosítót, ha nem viszi senki, akkor 0
		void  giveOrder(Megrendeles *m);
		//megkeresi a legjobb futárt a feladathoz
		//használja a setpreference és a select függvényt-->nem constans

	};
	bool operator <(const Futar & first, const Futar & second);
	//Ezzel fogom 
	template <typename T>
	void step(T& container)
	{

	}

#endif