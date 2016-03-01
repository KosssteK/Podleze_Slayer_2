#ifndef sterowanie_h
#define sterowanie_h

class myszka
{
	double x;
	double y;


public:
	myszka();
	void ustaw(double x, double y);
	double getX();
	double getY();
	void wypisz();
};


#endif