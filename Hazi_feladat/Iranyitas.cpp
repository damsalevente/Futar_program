#include "Iranyitas.h"
#include <iostream>
#include <vector>
#include <fstream>	
#include <string>
using namespace std;


Ceg::Ceg()
{
	megrendeles = NULL;
	mNum = 0;
	num = 0;

}

void Ceg::hire(Futar *a)
{
	 
	
	futar.push_back(a);
	num++;

}

void Ceg::addOrder(const Megrendeles & m)
{
	mNum++;
	Megrendeles *tmp = new Megrendeles[mNum];
	for (int i = 0; i < mNum - 1; i++)
	{
		tmp[i] = megrendeles[i];
	}
	tmp[mNum - 1] = m;
	delete[] megrendeles;
	megrendeles = tmp;

}

Futar  Ceg::getFutar(int index) 
{
	if (index >= num) {
		throw string("out of the bound,first futar is returned! ");
		return *futar.at(0);
	}
	return *futar[index];
}

Ceg::~Ceg()
{
	futar.clear();
	//a clear saját magát eltakarítja, én meg a hívások során egyszer sem írtam new-ot ...könnyû elbénáznia a felhasználónak, de így mûködik
	delete[] megrendeles;
}

void Ceg::printFutarList() const
{
	for (int i = 0; i < num; i++)
	{
		cout << *futar[i];
	}
}





void Ceg::log() const
{
	ofstream logFile;
	logFile.open("CegData.txt",ios::out);
	for (int i = 0; i < num; i++)
	{
		logFile << *futar[i];
	}
	logFile.close();
}

void Ceg::select(Futar & a, Megrendeles * m)
{
	try {
		if (a.available(*m) != true)
			throw string("It has an order, nothing is changed");
		a.setMegrendeles(m);
	}
	catch (string s) {
		cout << s << endl;

	}
	
}

int Ceg::track(Megrendeles & m) const
{
	for (int i = 0; i < num; i++)
	{
		if (futar[i]->getMegrendeles() == &m && futar[i]->getMegrendeles() != 0)
			return futar[i]->getAzonosito();
	}
	return 0;
}

void Ceg::giveOrder(Megrendeles * m)
{
	int pref = 0;	//minimum kereséshez a változó. ebben tárolom a legnagyobb preferencia értékét
	int index = 0;	 //annak a futárnak az indexe,amelyik a legjobb megoldás
	for (int i = 0; i < num; i++)
	{
		if (futar[i]->available(*m))
		{

			if (futar[i]->preference(*m) >= pref) {
				pref = futar[i]->preference(*m);
				index = i;
			}
		}
	}
	if (futar[index]->available(*m) == false) {}
	else 
		futar[index]->setMegrendeles(m);
}




Futar::Futar(int _posX, int _posY, bool _isEmpty, int _azonosito)
{
	try {
		if (_posX < 0 )
		{
			throw string("X position is negative!");
		}
		if (_posY < 0)
		{
			throw("Y position is negative!");
		}
		if (_azonosito <= 0)
		{
			throw("Bad id set!");
		}
		posX = _posX;
		posY = _posY;
		isEmpty = _isEmpty;
		azonosito = _azonosito;
		megrendeles = NULL;

	}
	catch (string a)
	{
		cout << a<< " Everything set to zero."<<endl;
		posX = 0;
		posY = posX;
		azonosito = posY;
	}
}

int Futar::getX() const
{
	return posX;
}

int Futar::getY() const
{
	return posY;
}
ostream & operator<<(ostream & o, const Futar &a)
{
	o << "............................................." << endl;
	o << "Azonosito: " << a.getAzonosito() << endl;
	o << "Pozicio: (" << a.getX() << "," << a.getY() << ")" << endl;
	if (a.getIsEmpty())
		o << "Ures" << endl;
	else {
		o << "Tele" << endl;
	}
	o << "............................................." << endl;
	return o;
}

bool operator<(const Futar & first, const Futar & second)
{
	return first.getAzonosito() < second.getAzonosito();
}



bool Futar::getIsEmpty() const
{
	return isEmpty;
}

int Futar::getAzonosito() const
{
	return azonosito;
}


void Futar::setX(int x)
{
	posX = x;
}

void Futar::setY(int y)
{
	posY = y;
}

void Futar::setIsEmpty(bool a)
{
	isEmpty = a;
}



void Futar::setAzonosito(int az)
{
	azonosito = az;
}



void Futar::setMegrendeles(Megrendeles * m)
{
	megrendeles = m;
	isEmpty = false;
}

Megrendeles * Futar::getMegrendeles()
{
	return megrendeles;
}

double  Futar::getDistance(const Megrendeles & m) const
{
	return sqrt((m.getPosX() - getX())*(m.getPosX() - getX()) + (m.getPosY() - getY())*(m.getPosY() - getY()));
}

double Futar::getDestDistance(const Megrendeles & m) const
{
	return sqrt((m.getDestX() - posX)*(m.getDestX() - posX) + (m.getDestY() - posY)*(m.getDestY() - posY));
}

bool Futar::available(const Megrendeles & m) const
{
	cout << "Rossz available hívódott meg!!";
	return false;
}

int Futar::preference(const Megrendeles & m) const
{
	//Rossz konstruktor hívódott meg
	throw 	string("You shouldnt use Futar's preference");
	cout << "Rossz helyen lett meghívva a preference";
	return -1;
}

//bool Bicikli::inRadius(const Megrendeles & m)
//{
//	return false;
//}
//


Megrendeles::Megrendeles(int s, int px, int py, int dx, int dy)
{
	size = s;
	posX = px;
	posY = py;
	destX = dx;
	destY = dy;

}

int Megrendeles::getSize() const
{
	return size;
}

int Megrendeles::getPosX() const
{
	return posX;
}

int Megrendeles::getPosY() const
{
	return posY;
}

int Megrendeles::getDestX() const
{
	return destX;
}

int Megrendeles::getDestY() const
{
	return destY;
}

void Megrendeles::setPos()
{
	posX = destX;
	posY = destY;
	size = 0;

}

Teherauto::Teherauto(int px, int py, bool isEmptyy, int az) :Futar(px, py, isEmptyy, az)
{
	//Futarhoz akkor viszont kell hibakezelés!
}

bool Teherauto::available(const Megrendeles & m) const
{
	return getIsEmpty();
}

int Teherauto::preference(const Megrendeles & m) const
{
	int pref=0;
	if (this->getDistance(m)>15)
	{
		pref++;
	}
	if (this->getDestDistance(m)>60)
	{
		pref += 2;

	}
	return pref;
}



bool Szemelygepjarmu::available(const Megrendeles & m) const
{
	return (m.getSize() == 1 && getIsEmpty());
}

int Szemelygepjarmu::preference(const Megrendeles & m) const
{
	int pref = 0;
	if (this->getDistance(m) > 15)pref++;
	if (this->getDestDistance(m) < 60)pref += 2;
	return pref;
}



bool Bicikli::available(const Megrendeles & m) const
{
	return (m.getSize() == 1 && getDistance(m) <= 15 && getIsEmpty() == true && getDestDistance(m) <= 15);
}

int Bicikli::preference(const Megrendeles & m) const
{
	int pref = 1;
	if (getDestDistance(m) < 30)pref += 3;
	return pref;
}

ofstream & operator<<(ofstream & o, const Futar &a)
{
	o << "............................................." << endl;
	o << "Azonosito: " << a.getAzonosito() << endl;
	o << "Pozicio: (" << a.getX() << "," << a.getY() << ")" << endl;
	if (a.getIsEmpty())
		o << "Ures" << endl;
	else {
		o << "Tele" << endl;
	}
	o << "............................................." << endl;
	return o;
}
