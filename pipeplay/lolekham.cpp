#include "lolekham.h"

lolekham::lolekham(unsigned int a, char b, unsigned int c)
	:base(a, b, c)
{



}

void lolekham::addrotate()
{
	unsigned int ori = getorientatio();
	setorientatio(++ori);
	if (getorientatio() > 4)
		setorientatio(1);
}

