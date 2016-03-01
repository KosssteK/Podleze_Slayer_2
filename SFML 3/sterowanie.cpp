#include "naglowki.h"
#include "sterowanie.h"

// ==================== MYSZKA =========================

myszka::myszka()
{
	this->x = 0;
	this->y = 0;
}
void myszka::ustaw(double x, double y)
{
	this->x = x;
	this->y = y;

}
void myszka::wypisz()
{
	std::cout << this->x << "    " << this->y << std::endl;

}
double myszka::getX()
{
	return this->x;
}
double myszka::getY()
{
	return this->y;
}