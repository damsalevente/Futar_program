#include "Iranyitas.h"

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
	Bicikli elso(1, 2, true, 5);
	cout << elso;
	Futar b;
	Bicikli c(1,2,false,3);
	b = c;
	//újra kell definiálni a másoló konstruktort, amikor altípusból csinálom
	c.setType();
	cout << b.getFutarType();
	
	
	return 0;
}