#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\\Window.hpp>
#include "lolesaff.h"
#include "lolekham.h"
#include "plus.h"

#include <iostream>
#include <array>
#include<vector>
#include <string>
#include <new>
#include "base.h"
#include <cstdlib>
#include <iomanip>


struct halat
{
	std::array <std::string, 4> tar = {"1221321231232112212232123" ,"2112121331111131222211111" ,"1212222121123123121121311","3111112211232112121232112" };  //typres for replace pipes
};
struct cell
{
	int num;                        //equal with id pipes
	char noelole;                  // 1 for right pipes ,2 for kham pipes , 3 for plus pipes
	unsigned int rotate;          //rotate pipes
	char inpute;                  //for plus pipe
	char outpute;                 //for plus pipe
	char inpute1;
	char output1;
	char inpute2;
	char output2;


}c[5][5];                    // 25 cell for pipes


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int main()
{

	sf::RenderWindow window(sf::VideoMode(480, 480), "pipe_play", sf::Style::Resize);
	sf::RectangleShape play1(sf::Vector2f(60, 60));
	sf::RectangleShape play2(sf::Vector2f(60, 60));
	sf::RectangleShape play3(sf::Vector2f(60, 60));
	sf::RectangleShape play4(sf::Vector2f(60, 60));
	halat obj;
	int rank = 0;

	std::array<class base*, 25> pipes;             // random
	srand(time(0));
	std::string h = obj.tar.at(rand() % 4);

	sf::Music music;                             //play music
	if (!music.openFromFile("music.ogg"))
		std::cerr << "error" << std::endl;

	music.play();

	sf::Font font;
	if (!font.loadFromFile("ff.ttf"))
		std::cout << "error";
	
	sf::Text text1;                //text for winner
	text1.setFont(font);
	text1.setString("    winner");
	text1.setCharacterSize(50);
	text1.setOrigin(0, 2);
	text1.setFillColor(sf::Color::Green);

	sf::Text text2;                //text for lose
	text2.setFont(font);
	text2.setString("    you lose");
	text2.setCharacterSize(50);
	text2.setOrigin(0, 2);
	text2.setFillColor(sf::Color::Red);

	/*std::string ranking = std::to_string(rank);
	std::string ranking;
	sf::Text text3;
	text3.setFont(font);
	text3.setString(ranking);
	text3.setCharacterSize(30);
	text3.setOrigin(0,7);
	text3.setFillColor(sf::Color::Red);*/

	
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	unsigned int l = 0;   //for id pipes

	for (auto i : h)
	{

		if (i == '1')

		{
			pipes[l] = new lolesaff(l, '1', 1);

		}
		else if (i == '2')
		{

			pipes[l] = new lolekham(l, '2', 2);


		}
		else if (i == '3')
		{
			pipes[l] = new plus(l, '3', 1);
		}
		l++;

	}
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	unsigned int i = 0;
	unsigned int j = 0;

	for (auto lole : pipes)
	{
		//std::cout << lole->getid() << std::endl;
		c[i][j].num = lole->getid();
		c[i][j].noelole = lole->getnumpipe();
		c[i][j].rotate = lole->getorientatio();
		j++;
		if (j == 5)
		{
			i++;
			j = 0;
		}

	}
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	int ts = 60;
	sf::Texture t1, t2, t3, t4, t5;
	t1.loadFromFile("img.jpg");
	t2.loadFromFile("img8.png");
	t3.loadFromFile("img9.png");
	t4.loadFromFile("finish.jpg");
	t5.loadFromFile("start.jpg");


	sf::Sprite s(t1);
	play1.setTexture(&t2);
	play1.setPosition(ts * 2, ts);

	play2.setTexture(&t3);
	play2.setPosition(6 * ts, 7 * ts);

	play3.setTexture(&t4);
	play3.setPosition(0, ts * 3);

	play4.setTexture(&t5);
	play4.setPosition(0, ts * 2);

	sf::Clock clock;                   //time &clock
	std::string exam = "unknown";       //for control time
	//int rank = 0;

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	while (window.isOpen())
	{

		sf::Time elapsed = clock.getElapsedTime();
		if (exam == "true")
		{

			if (elapsed.asSeconds() < 30)

				std::cout << elapsed.asSeconds() << std::endl;
		}

		sf::Vector2i pos = sf::Mouse::getPosition(window);  //position mouse
		int y = pos.x / 60;
		int x = pos.y / 60;
		sf::Event event;
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::MouseButtonPressed:

				if (event.key.code == sf::Mouse::Left)
				{
					unsigned int p = x - 2;
					unsigned int q = y - 2;
					//std::cout << x << y << std::endl;

					if (exam == "true"  &&  elapsed.asSeconds() < 30)

						if (p >= 0 && p < 5 && q >= 0 && q < 5)
						{

							for (auto pip : pipes)
							{
								if (pip->getid() == c[p][q].num)
								{

									pip->addrotate();
									std::cout << pip->getorientatio() << std::endl;
									c[p][q].rotate = pip->getorientatio();
									std::cout << c[p][q].rotate << std::endl;
									//std::cout << c[i][j].rotate << std::endl;
									break;
								}

								//	std::cout << lole.getorientatio();	
							}
						}
					//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
					if (x == 2 && y == 0)            //start button
					{
						exam = "true";
						clock.restart();
					}
					//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++				
					if (x == 3 && y == 0)            //finish button


					{

						rank = 0;
						for (unsigned int i = 0; i < 5; i++)

							for (unsigned int j = 0; j < 5; j++)
							{
								if (c[i][j].noelole == '1' && c[i][j].rotate == 1)
								{
									c[i][j].inpute1 = 'a';
									c[i][j].output1 = 'c';

								}
								if (c[i][j].noelole == '1' && c[i][j].rotate == 2)
								{
									c[i][j].inpute1 = 'b';
									c[i][j].output1 = 'd';

								}
								if (c[i][j].noelole == '2' && c[i][j].rotate == 1)
								{
									c[i][j].inpute1 = 'b';
									c[i][j].output1 = 'a';

								}
								if (c[i][j].noelole == '2' && c[i][j].rotate == 2)
								{
									c[i][j].inpute1 = 'b';
									c[i][j].output1 = 'c';

								}
								if (c[i][j].noelole == '2' && c[i][j].rotate == 3)
								{
									c[i][j].inpute1 = 'd';
									c[i][j].output1 = 'c';

								}
								if (c[i][j].noelole == '2' && c[i][j].rotate == 4)
								{
									c[i][j].inpute1 = 'a';
									c[i][j].output1 = 'd';

								}
								if (c[i][j].noelole == '3')
								{
									c[i][j].inpute = 'b';
									c[i][j].outpute = 'd';
									c[i][j].inpute2 = 'a';
									c[i][j].output2 = 'c';
									if (i == 0 && j == 0)
									{
										c[i][j].output1 = 'd';
									}

								}
								//std::cout << c[i][j].inpute1 << c[i][j].output1 << c[i][j].inpute2 << c[i][j].output2 << c[i][j].inpute << c[i][j].outpute << std::endl;

							}
						//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

						if (c[0][0].inpute1 == 'b' || c[0][0].inpute == 'b')
						{
							int i = 0;
							int j = 0;

							while (1)
							{
								if (c[i][j].output1 == 'c')
								{
									rank += 100;
									j++;
									if (j >= 0 && j < 5)
									{
										if (c[i][j].noelole == '3')
										{
											//if (c[i][j].inpute2 == 'a')
											c[i][j].output1 = 'c';

										}
										else
											if (c[i][j].inpute1 == 'a' || c[i][j].output1 == 'a')
											{
												if (c[i][j].output1 == 'a')
												{
													char temp = c[i][j].inpute1;
													c[i][j].inpute1 = c[i][j].output1;
													c[i][j].output1 = temp;

												}
											}
											else
											{

												std::cout << "----you lose----";
												std::cout << "for cell :" << i << j << std::endl;
												std::cout << "rank is :" << rank << std::endl;
												exam = "false2";
												break;

											}

									}
									else
									{
										j--;
										std::cout << "----you lose----";
										std::cout << "for cell :" << i << j << std::endl;
										std::cout << "rank is :" << rank << std::endl;
										exam = "false2";
										break;

									}

								}
								else if (c[i][j].output1 == 'd')
								{
									rank += 100;
									if (i == 4 && j == 4)
									{
										std::cout << "****you win****" << std::endl;
										std::cout << "rank is :" << rank << std::endl;
										// std::cout << i << j << std::endl;
										exam = "false";

										break;
									}

									i++;
									if (i >= 0 && i < 5)
									{
										if (c[i][j].noelole == '3')
										{
											// if (c[i][j].inpute == 'b')
											c[i][j].output1 = 'd';

										}
										else
											if (c[i][j].inpute1 == 'b' || c[i][j].output1 == 'b')
											{
												if (c[i][j].output1 == 'b')
												{
													char temp = c[i][j].inpute1;
													c[i][j].inpute1 = c[i][j].output1;
													c[i][j].output1 = temp;
												}
											}
											else
											{
												std::cout << "----you lose----";
												std::cout << "for cell :" << i << j << std::endl;
												std::cout << "rank is :" << rank << std::endl;
												exam = "false2";
												break;

											}
									}
									else
									{
										i--;
										std::cout << "----you lose----";
										std::cout << "for cell :" << i << j << std::endl;
										std::cout << "rank is :" << rank << std::endl;
										exam = "false2";
										break;

									}

								}
								else if (c[i][j].output1 == 'a')
								{
									rank += 100;
									j--;
									if (j >= 0 && j < 5)
									{
										if (c[i][j].noelole == '3')
										{
											// if (c[i][j].inpute == 'b')
											c[i][j].output1 = 'a';

										}
										else
											if (c[i][j].inpute1 == 'c' || c[i][j].output1 == 'c')
											{
												if (c[i][j].output1 == 'c')
												{
													char temp = c[i][j].inpute1;
													c[i][j].inpute1 = c[i][j].output1;
													c[i][j].output1 = temp;
												}
											}
											else
											{
												std::cout << "----you lose----";
												std::cout << "for cell :" << i << j << std::endl;
												std::cout << "rank is :" << rank << std::endl;
												exam = "false2";
												break;

											}
									}
									else
									{
										j++;
										std::cout << "----you lose----";
										std::cout << "for cell :" << i << j << std::endl;
										std::cout << "rank is :" << rank << std::endl;
										exam = "false2";
										break;

									}

								}
								else if (c[i][j].output1 == 'b')
								{

									rank += 100;
									i--;
									if (i >= 0 && i < 5)
									{
										if (c[i][j].noelole == '3')
										{
											// if (c[i][j].inpute == 'b')
											c[i][j].output1 = 'b';

										}
										else
											if (c[i][j].inpute1 == 'd' || c[i][j].output1 == 'd')
											{
												if (c[i][j].output1 == 'd')
												{
													char temp = c[i][j].inpute1;
													c[i][j].inpute1 = c[i][j].output1;
													c[i][j].output1 = temp;
												}
											}
											else
											{
												std::cout << "----you lose----";
												std::cout << "for cell :" << i << j << std::endl;
												std::cout << "rank is :" << rank << std::endl;
												exam = "false2";
												break;

											}
									}
									else
									{
										i++;
										std::cout << "----you lose----";
										std::cout << "for cell :" << i << j << std::endl;
										std::cout << "rank is :" << rank << std::endl;
										exam = "false2";
										break;


									}

								}


							}
						}

						else
						{
							std::cout << "----you lose----";
							std::cout << "rank is :" << rank << std::endl;
							exam = "false2";
							break;
						}
					}
				}
				break;

			}
		}
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		window.clear();

		window.draw(s);

		for (unsigned int i = 0; i < 5; i++)

			for (unsigned int j = 0; j < 5; j++)
			{

				for (auto lol : pipes)
				{

					if (c[i][j].num == lol->getid())

					{

						if (lol->getnumpipe() == '1')
						{
							switch (lol->getorientatio())
							{
							case 2:
								lol->settexture("img1.png");
								break;
							case 1:
								lol->settexture("img2.png");
								break;
							}

						}

						else

							if (lol->getnumpipe() == '2')
							{
								switch (lol->getorientatio())
								{
								case 1:
									lol->settexture("img5.png");
									break;
								case 2:
									lol->settexture("img6.png");
									break;
								case 3:
									lol->settexture("img4.png");
									break;
								case 4:
									lol->settexture("img3.png");
									break;
								}

							}
							else

								if (lol->getnumpipe() == '3')
								{
									lol->settexture("img7.png");

								}


						lol->draw(window, i, j);
						break;
					}
				}
			}
		std::string ranking = std::to_string(rank);  //text for rank
		sf::Text text3;
		text3.setFont(font);
		text3.setString(ranking);
		text3.setCharacterSize(30);
		text3.setOrigin(3, 7);
		text3.setFillColor(sf::Color::Red);

		if (exam == "false")
		 
			window.draw(text1);
		if(exam=="false2")
		
			window.draw(text2);
		window.draw(text3);
		window.draw(play1);
		window.draw(play2);
		window.draw(play3);
		window.draw(play4);
		window.display();


	}
	for (auto p : pipes)
	{
		delete p;
	}

}