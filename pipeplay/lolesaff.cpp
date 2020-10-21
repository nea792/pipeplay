#include "lolesaff.h"

lolesaff::lolesaff(unsigned int a, char b, unsigned int c)
	:base(a, b, c)
{

	//spr.setTexture(texture);
}
/*void lolesaff::drawh(sf::RenderWindow &window, unsigned int i, unsigned int j)
{
	int ts = 60;
	sf::Vector2f offect(120, 120);
	//window.draw(spr);
	sf::RectangleShape player(sf::Vector2f(60, 60));
	player.setTexture(&texture);
	player.setPosition(ts*j, ts*i);
	player.move(offect);
	window.draw(player);
}*/
void lolesaff::addrotate()
{
	unsigned int ori = getorientatio();
	setorientatio(++ori);
	if (getorientatio() > 2)
		setorientatio(1);
}
/*void lolesaff::settexture(std::string dir)
{
	texture.loadFromFile(dir);

	if (!texture.loadFromFile(dir))
	{
		std::cerr << "error";
	}
}*/
/*void lolesaff::setorientatio(unsigned int a)
{
	orientation = a;
}
unsigned int lolesaff::getorientatio()
{
	return orientation;
}
*/