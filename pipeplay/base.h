#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>

class base
{
public:
	base(unsigned int, char, unsigned int);
	virtual ~base(){}
	void setid(unsigned int a);
	unsigned int getid();
	unsigned int getorientatio();
	void setorientatio(unsigned int);
	void setnumpipe(char);
	char getnumpipe();
	void settexture(std::string);
	void draw(sf::RenderWindow &window, unsigned int, unsigned int);
	virtual void  addrotate() = 0;     //pure visual

private:
	unsigned int ID;
	char numpipe;
	unsigned int orientation;
	sf::Texture texture;

};


