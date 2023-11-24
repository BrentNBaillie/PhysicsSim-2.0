#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class Ball
{
	public:
		sf::CircleShape circle;
		float
			ball_rad, y_Velocity, x_Velocity,
			y_Position, x_Position,
			time_Step, co_Restitution,
			gravity, height, width;
		Ball(float ball_Radius, float x_Initial, float y_Initial, 
			 float xi_Velocity, float yi_Velocity, float screen_Height, float screen_Width);
		void draw(sf::RenderWindow& window);
		void Change_Position();
		float Delta_x();
		float Delta_y(float height);
		int x_Collision();
		int y_Collision();
		void y_Collision_Change();
		void x_Collision_Change();
		void Collision();
};
