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
	//a.add(b);	//lehessen biciklit,aut�t,teheraut�t hozz�adni
	//a.add(sz);
	//a.add(t);
	//a.getClosest(m); //tal�ljuk meg a legk�zelebbi fut�rt 
	//a.select(b, m); //kapcsoljon �ssze egy fut�rt egy csomaggal, onnan fogom tudni, hogy kin�l van a csomag, hogy a pozici�juk megegyezik
	//a.select(sz, m);
	//a.select(t, m);
	//a.track(m);	  //keresse meg, hogy melyik fut�rn�l van, visszaadja az azonos�t�j�t

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

	
	//csillaggal lehet megh�vni a printel�st (ez sem valami univerz�lis ) 
	

/*	----------------------------------------A c�g tesztel�se vector form�j�ban	 -----------------------------------------------------------------------------------------------  */
	
	
		 //itt a k�ls� egy futar*k�nt �tadott valami , ami az &b lenne 
	//ceg.push_back(p);
	//ceg.at(0)->available(megrendeles);

	//  // ---------deletezes
	//
	//
	//ceg.clear();

	  //--------------------------------------------------------------itt �r v�get a c�g tesztel�se	   -----------------------------------------------------------------------------------
	
	Futar futi(-1, 1, true, 666);//�rd�gt�l val� 
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
	teherauto.available(megrendeles);	  //ezzel is j� f�ggv�nyt�rzsre ugrik

	
	





	return 0;
}