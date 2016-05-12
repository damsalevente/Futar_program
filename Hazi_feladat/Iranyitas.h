#include<iostream>
#include <vector>
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
		//be�ll�tja a posx posy-t destx �s desty-ra , desteket meg 0,0 -ra 
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
		//Virtu�lis destruktor ? 
		Futar(int _posX, int _posY, bool _isEmpty, int _azonosito);
		//Megrendeles�ket pointerk�nt kapja, az egyes elemek mindegyik�nek van egy default �rt�ke, �gy rossz inicializ�l�s eset�n ezeket az �rt�keket kapja
		//a megrendel�s alapesetben NULL, csak a set tudja be�ll�tani, amit csak a c�g fog kezelni
		//try-catch : ha b�rmelyik adat hib�san van bev�ve, ki�rja, hogy hib�s a bemenet, �s mindent null�ra �ll�t be
		int getX()const;
		//X pozici�j�t kiadja
		int getY() const;
		//Y pozici�j�t kiadja
		bool getIsEmpty() const;
		//kiadja, hogy �res-e 
		int getAzonosito() const;
		//azonos�t�
		void setX(int x);
		//Be�ll�tja x �rt�k�t, a C�g fogja haszn�lni, hogy tudja mozgatni 
		void setY(int y);
		//Be�ll�tja y �rt�ket, a C�g fogja haszn�lni, hogy tudja mozgatni
		void setIsEmpty(bool a);
		//Beall�tja �resnek vagy telinek a j�rm�vet
		void setAzonosito(int a);
		//belehet �ll�tani �j azonos�t�t
		void setMegrendeles(Megrendeles *m);
		//egy megrendeles c�met kap �s arra �ll�tja a megrendeles nev� pointert
		Megrendeles * getMegrendeles();
		//Visszaadja a megrendel�st, ha nincs megrendel�se akkor NULL
		double getDistance(const Megrendeles &m) const;
		//Megadja, hogy milyen t�vol van egy adott csomagt�l, ezt sem kell k�l�n kisz�molni k�l�nb�z� t�pusnak
		double getDestDistance(const Megrendeles &m) const;
		//megadja, hogy milyen t�vol van a csomag t�vols�ga
		virtual bool available(const Megrendeles &m) const;
		//megn�zi minden esetben, hogy el�rhet�-e a fut�r, legyen sz� biciklist�r�l, fut�rral sat�bbi 
		// Ha ez h�v�dik meg, akkor biztos, hogy nem el�rhet�
		virtual int preference(const Megrendeles &m)const;
		//egy sz�mot ad visssza, ami megmondja minden esetben, hogy mennyire akarjuk, hogy � vigye el a csomagot. Min�l nagyobb a sz�m ann�l jobb


		friend ostream & operator<<(ostream & o, const Futar &a);
		//felesleges,k�ls� f�ggv�nyk�nt van meg�rva, nem kell friendnek lennie

	};
	class Teherauto :public Futar {
	public:
		Teherauto() {};
		Teherauto(int px, int py, bool isEmptyy, int az);
		bool available(const Megrendeles &m) const;
		//akkor el�rhet�, ha �res
		int preference(const Megrendeles &m)const;
		//Ha 15km-n�l t�volabb van, +1, ha 60 km-n�l t�volabbra kell sz�ll�tani +2
		//Megmondja, hogy nincs tele, �s �ppen nincs megrendel�se 

	};
	class Szemelygepjarmu :public Futar {
	public:
		Szemelygepjarmu() {};
		Szemelygepjarmu(int px, int py, bool isEmptyy, int az) :Futar(px, py, isEmptyy, az) {};
		bool available(const Megrendeles &m)const;
		//akkor el�rhet�, ha �res 
		int preference(const Megrendeles &m)const;
		//ha 15km-n�l t�volabb van a csomag +1, ha 60km-n�l t�volabb kell kisz�ll�tani akkor +2
		// ha �res �s a m�rete a csomagnak 1, akkor el�rhet� 


	};
	class Bicikli : public Futar {
	public:
		Bicikli() {};
		Bicikli(int px, int py, bool isEmptyy, int az) :Futar(px, py, isEmptyy, az) {};
		bool available(const Megrendeles &m) const;
		//el�rhet� ha �res �s 15km-en bel�l van
		int preference(const Megrendeles &m)const;
		// ha k�zel kell sz�ll�tani, akkor nagyon j�, egy�bk�nt meg 1-es �rt�ket kap



	};


	class Ceg {
	private:

		vector <Futar * > futar;
		//vector t�pus� lett a fut�r, nem fogok csillagokat l�tni
		Megrendeles *megrendeles;
		//dinamikus t�mb
		int mNum;
		int num;
	public:
		Ceg();
		//inicializ�lja a sz�ks�ges t�mb�ket, darabsz�mokat null�ra �ll�tja
		void hire(Futar *a);
		//ellen�rizni kell hozz�, hogy m�k�dik-e a m�sol� konstruktor defaultk�nt, vagy �jra kell �rni...check
		//be�ll�tja az utols� helyre az �j fut�rt, default konstruktork�nt h�vja, a felhaszn�l�t�l elv�rja hogy inicializ�lja
		//ha param�terk�nt new Futar(...)-t kap, akkor mem�riasziv�rg�s lesz
		void addOrder(const Megrendeles &m);
		//felvesz egy �j megrendel�st
		//a megadott megrendel�snek m�r L�TEZNIE KELL 
		Futar getFutar(int index);
		//A megadott index� Fut�r pointer �rt�k�t adja vissza
		~Ceg();
		//Destruktor, let�r�lj�k a pointert
		void printFutarList() const;
		//ki�rja a standart kimenetre a fut�rokat
		void log()const;
		//ki�rja a fut�rok list�j�t
		//f�jlkezel�s 
		void select(Futar &a, Megrendeles *m);
		//fut�rt(vektort) b�ntani fogjuk, ez�rt nem constans
		//be�ll�tja az a fut�r megrendel�s tagv�ltoz�j�t m-re null helyett, ha nem null akkor throw isFullexception 
		int track(Megrendeles &m) const;
		//megadja az azonos�t�t, ha nem viszi senki, akkor 0
		void  giveOrder(Megrendeles *m);
		//megkeresi a legjobb fut�rt a feladathoz
		//haszn�lja a setpreference �s a select f�ggv�nyt-->nem constans

	};
	bool operator <(const Futar & first, const Futar & second);
	//Ezzel fogom 
	template <typename T>
	void step(T& container)
	{

	}

#endif