#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "base.h"
class lolesaff
	:public base
{
public:
	lolesaff(unsigned int, char, unsigned int);
	 virtual ~lolesaff(){}
	//void drawh(sf::RenderWindow &window, unsigned int, unsigned int);
	virtual void addrotate() override;
	//void settexture(std::string);
	//unsigned int getorientatio();
	//void setorientatio(unsigned int);



private:
	sf::Texture texture;
	sf::Sprite spr;
	//unsigned int orientation;
};
