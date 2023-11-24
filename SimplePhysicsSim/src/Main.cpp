#pragma once
#include <iostream>
#include "Header.h"
#include <random>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

int main(int argc, char** argv)
{
	int ball_Count = 5;
	float ball_Radius = 10;
	float velocity_Range = 0;
	float velocity_Min = 30;
	float screen_Width = 1000;
	float screen_Height = 600;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> rnd_xPosition(ball_Radius, screen_Width - ball_Radius);
	std::uniform_real_distribution<float> rnd_yPosition(ball_Radius, screen_Height - ball_Radius);
	std::uniform_real_distribution<float> rnd_Velocity(-100, 100);

	sf::RenderWindow window(sf::VideoMode(screen_Width, screen_Height), "Ball Physics");

	std::vector<Ball> ball;
	for (int i = 0; i < ball_Count; i++)
	{
		ball.push_back(Ball(ball_Radius, rnd_xPosition(gen), rnd_yPosition(gen), rnd_Velocity(gen),
			                rnd_Velocity(gen), screen_Height, screen_Width));
	}
	
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) 
		{
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

		window.clear();
		for (int i = 0; i < ball_Count; i++)
		{
			ball[i].Collision();
			ball[i].Change_Position();
			ball[i].draw(window);
		}
		window.display();
    }
}


