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
	//a.add(b);	//lehessen biciklit,aut�t,teheraut�t hozz�adni
	//a.add(sz);
	//a.add(t);
	//a.getClosest(m); //tal�ljuk meg a legk�zelebbi fut�rt 
	//a.select(b, m); //kapcsoljon �ssze egy fut�rt egy csomaggal, onnan fogom tudni, hogy kin�l van a csomag, hogy a pozici�juk megegyezik
	//a.select(sz, m);
	//a.select(t, m);
	//a.track(m);	  //keresse meg, hogy melyik fut�rn�l van, visszaadja az azonos�t�j�t
	Ceg a;
	Bicikli elso(1, 2, true, 5);
	cout << elso;
	Futar b;
	Bicikli c(1,2,false,3);
	b = c;
	//�jra kell defini�lni a m�sol� konstruktort, amikor alt�pusb�l csin�lom
	c.setType();
	cout << b.getFutarType();
	
	
	return 0;
}