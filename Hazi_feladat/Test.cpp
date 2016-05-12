#include "Iranyitas.h"
#include <iostream>
#include <string>

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

	//important!!!:Le kell tesztelni, hogy a numot nem rontottam-e el valahol  

	Bicikli bicikli(1, 1, true, 1);
	Teherauto teherauto(1, 1, true, 2);
	Megrendeles megrendeles(1, 1, 2, 2, 1);
	Megrendeles rendeles(1, 3, 3, 3, 60);
	Ceg a;
	a.hire(&bicikli);
	a.hire(&teherauto);
	a.log();
	a.printFutarList();
	cout<<a.getFutar(0);
	a.giveOrder(&megrendeles);
	a.giveOrder(&rendeles);
	a.printFutarList();
	if (bicikli < teherauto)
		cout<< string("biciklinek az azonositoja nagyobb")<<endl;

	
	//csillaggal lehet meghívni a printelést (ez sem valami univerzális ) 
	

/*	----------------------------------------A cég tesztelése vector formájában	 -----------------------------------------------------------------------------------------------  */
	
	
		 //itt a külsõ egy futar*ként átadott valami , ami az &b lenne 
	//ceg.push_back(p);
	//ceg.at(0)->available(megrendeles);

	//  // ---------deletezes
	//
	//
	//ceg.clear();

	  //--------------------------------------------------------------itt ér véget a cég tesztelése	   -----------------------------------------------------------------------------------
	
	Futar futi(-1, 1, true, 666);//ördögtõl való 
	Szemelygepjarmu szemelygepjarmu(1, 1, true, 3);
	Futar *b = &bicikli;
	Futar *t = &teherauto;
	Futar *k = &szemelygepjarmu;
	Futar bici = bicikli;
	/*bici.available(megrendeles);*/
	b->available(megrendeles);
	t->available(megrendeles);
	k->available(megrendeles);
	/*futi.available(megrendeles);*/
	teherauto.available(megrendeles);	  //ezzel is jó függvénytörzsre ugrik

	
	





	return 0;
}