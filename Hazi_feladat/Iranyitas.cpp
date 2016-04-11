#include "Iranyitas.h"

void Ceg::init()
{
	
}

Futar * Ceg::getClosest(const Megrendeles & m) const
{
	return nullptr;
}

void Ceg::add(Teherauto & a)
{
}
void Ceg::add(Bicikli &a)
{

}
void Ceg::add(Szemelygepjarmu &a)
{

}

void Ceg::select(Bicikli & a, Megrendeles & m)
{
}

void Ceg::select(Teherauto & a, Megrendeles & m)
{
}

void Ceg::select(Szemelygepjarmu & a, Megrendeles & m)
{
}

int Ceg::track(Megrendeles & m)
{
	return 0;
}

Futar::Futar(int, int, bool, int)
{
}

int Futar::getX() const
{
	return 0;
}

int Futar::getY() const
{
	return 0;
}

bool Futar::getIsEmpty() const
{
	return false;
}

int Futar::getAzonosito() const
{
	return 0;
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

bool Bicikli::inRadius(const Megrendeles & m)
{
	return false;
}

Teherauto::Teherauto(int _posX, int _posY, bool _isEmpty, int _azonosito, int _capacity)
{

}
