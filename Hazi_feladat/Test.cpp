#include "Iranyitas.h"
#include <iostream>
using namespace std;
int main()
{

	//Ceg a;
	//Bicikli b;
	//Szemelygepjarmu sz;
	//Teherauto t;
	//Megrendeles m;
	//a.init();
	//a.add(b);	//lehessen biciklit,autót,teherautót hozzáadni
	//a.add(sz);
	//a.add(t);
	//a.getClosest(m); //találjuk meg a legközelebbi futárt 
	//a.select(b, m); //kapcsoljon össze egy futárt egy csomaggal, onnan fogom tudni, hogy kinél van a csomag, hogy a poziciójuk megegyezik
	//a.select(sz, m);
	//a.select(t, m);
	//a.track(m);	  //keresse meg, hogy melyik futárnál van, visszaadja az azonosítóját
	Ceg a;
	Futar *elso=new Futar(1, 2, false, 5);
	elso->print();
	

	
	return 0;
}