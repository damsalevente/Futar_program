#include "Iranyitas.h"
#include <iostream>
using namespace std;


void Ceg::printFutarList() const
{
	for (int i = 0; i < num; i++)
	{
			 //át kell írni a futar kiírását
	}
}

Futar * Ceg::getClosest(const Megrendeles & m) const
{
	return NULL;
}

void Ceg::add(Futar & a)
{
}

void Ceg::select(Futar & a, Megrendeles & m)
{
}

int Ceg::track(Megrendeles & m) const
{
	return 0;
}




Futar::Futar(int _posX, int _posY, bool _isEmpty, int _azonosito)
{
	
		posX = _posX+1;
		posY = _posY;
		isEmpty = _isEmpty;
		azonosito = _azonosito;		
}

int Futar::getX() const
{
	return posX;
}

int Futar::getY() const
{
	return posY;
}
void Futar::print()
{
	
	cout << "Futar azonosito:" << getAzonosito() << "Eppen nincs csomagja:" << getIsEmpty() << " X pozicio:" << getX() << " Y pozicio:" << getY();
	
	
}
bool Futar::getIsEmpty() const
{
	return isEmpty;
}

int Futar::getAzonosito() const
{
	return azonosito;
}

void Futar::setX(int)
{
}

void Futar::setY(int)
{
}

void Futar::setIsEmpty(bool)
{
}

void Futar::setAzonosito(int)
{
}

double  Futar::getDistance(const Megrendeles & m) const
{
	return sqrt((m.getPosX() - getX())*(m.getPosX() - getX()) + (m.getPosY() - getY())*(m.getPosY() - getY()));
}

//bool Bicikli::inRadius(const Megrendeles & m)
//{
//	return false;
//}
//


Megrendeles::Megrendeles(int s, int px, int py, int dx, int dy)
{
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
