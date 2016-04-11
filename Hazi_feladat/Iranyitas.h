#pragma once
#ifndef IRANYITAS_H
#define IRANYITAS_H
//TODO: write your code here
class Futar {
	int posX;						//nem felt�tlen�l sz�ks�ges, hogy legyen a futaroknak is pozici�juk, lehet �gy egyszer�bb, ha csak egy megrendel�st kapnak 
	int posY;
	bool isEmpty;
	int azonosito;
public:
	Futar(int, int, bool, int);
	int getX()const;
	int getY() const;
	bool getIsEmpty() const;
	int getAzonosito() const;
	void setX(int);
	void setY(int);
	void setIsEmpty(bool);
	void setAzonosito(int);

};
class Teherauto:public Futar {
private:
	int capacity;
public:
	Teherauto(int _posX, int _posY, bool _isEmpty, int _azonosito, int _capacity);

	
};
class Szemelygepjarmu :public Futar {
public:
	
	

};
class Bicikli : public Futar {
public:
	bool inRadius(const Megrendeles &m);
	

};
class Megrendeles {	 //getterek, �s konstruktor kell 
private:
	int size;
	int posX;
	int posY;
	int destX;
	int destY;	

};
class Ceg {
private:
	Teherauto *teherautok;
	Szemelygepjarmu *szemelygepjarmuvek;
	Bicikli *biciklik;
	int tDb;
	int szDb;
	int bDb;
public:
	void init();
	Futar *getClosest(const Megrendeles &m) const;
	void add(Bicikli &a);
	void add(Teherauto &a);
	void add(Szemelygepjarmu &a);
	void select(Bicikli &a, Megrendeles &m);
	void select(Teherauto &a,Megrendeles &m);
	void select(Szemelygepjarmu &a,Megrendeles &m);
	int track(Megrendeles &m);	//megadja az azonos�t�t, ha nem viszi senki, akkor 0
	
	
};


#endif