#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "base.h"
class plus
	:public base
{
public:
	plus(unsigned int, char, unsigned int);
	virtual ~plus() {}
	//void drawha(sf::RenderWindow &window, unsigned int, unsigned int);
	virtual void addrotate() override;
	//void settexture(std::string);
	//unsigned int getorientatio();
	//void setorientatio(unsigned int);



private:
	sf::Texture texture;
	sf::Sprite spr;
	//unsigned int orientation;
};