#pragma once
#include "base.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
class lolekham :
	public base
{
public:
	lolekham(unsigned int, char, unsigned int);

	virtual ~lolekham() {}


	//void drawhh(sf::RenderWindow &window, unsigned int, unsigned int);
	//void settexture(std::string);
	virtual void addrotate() override;
	//unsigned int getorientatio();
	//void setorientatio(unsigned int);

private:
	sf::Texture texture;
	sf::Sprite spr;
	//unsigned int orientation;
};


