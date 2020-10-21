#include "base.h"

base::base(unsigned int a, char b, unsigned int o) :ID(0)
{

	setid(a);
	setnumpipe(b);
	setorientatio(o);
}
void base::setid(unsigned int a)
{
	ID = a;
}
unsigned int base::getid()
{
	return ID;
}


void base::setorientatio(unsigned int a)
{
	orientation = a;
}
unsigned int base::getorientatio()
{
	return orientation;
}


void base::setnumpipe(char a)
{
	numpipe = a;
}
void base::settexture(std::string dir)
{
	texture.loadFromFile(dir);
	if (!texture.loadFromFile(dir))
	{
		std::cerr << "error";
	}
}
char base::getnumpipe()
{
	return numpipe;
}
void base::draw(sf::RenderWindow &window, unsigned int i, unsigned int j)
{
	int ts = 60;
	sf::Vector2f offect(120, 120);
	sf::RectangleShape player(sf::Vector2f(60, 60));
	player.setTexture(&texture);
	player.setPosition(ts*j, ts*i);
	player.move(offect);
	window.draw(player);
}
/*void  base::addrotate()
{
	if ((*this).getnumpipe() == '1')
	{
		unsigned int ori = getorientatio();
		setorientatio(++ori);
		if (getorientatio() > 2)
			setorientatio(1);
	}
	if ((*this).getnumpipe() == '2')
	{
		unsigned int ori = getorientatio();
		setorientatio(++ori);
		if (getorientatio() > 4)
			setorientatio(1);
	}
 }
 */