#pragma once
#include <iostream>
#include "Header.h"
#include <cmath>
#include <SFML/Graphics.hpp>
#include <vector>

Ball::Ball(float ball_Radius, float x_Initial, float y_Initial, float xi_Velocity,
           float yi_Velocity, float screen_Height, float screen_Width)
{
    x_Position = x_Initial;
    y_Position = y_Initial;
    y_Velocity = yi_Velocity;
    x_Velocity = xi_Velocity;
    height = screen_Height;
    width = screen_Width;
    ball_rad = ball_Radius;
    time_Step = 0.1;
    gravity = -9.81;
    co_Restitution = 1;
    circle.setRadius(ball_rad);
    circle.setFillColor(sf::Color::Red);
}

void Ball::draw(sf::RenderWindow& window)
    {window.draw(circle);}

void Ball::Change_Position()
    {circle.setPosition(Delta_x(), Delta_y(height));}

float Ball::Delta_x()
    {x_Position = x_Position + (x_Velocity * time_Step);    return x_Position;}

float Ball::Delta_y(float height)
    {
        y_Position = y_Position + (y_Velocity * time_Step) + (0.5 * gravity * time_Step * time_Step);
        y_Velocity = y_Velocity + (gravity * time_Step);
        return height - y_Position;
    }

int Ball::x_Collision()
    {
        if (x_Position >= width - ball_rad || x_Position <= ball_rad) {return 1;}
        else {return 0;}
    }

int Ball::y_Collision()
    {
        if (y_Position >= height - ball_rad || y_Position <= ball_rad) {return 1;}
        else {return 0;}
    }

void Ball::y_Collision_Change()
    {
        y_Velocity = -co_Restitution * y_Velocity;
        if (y_Position > height / 2) {y_Position = height - ball_rad;}
        else {y_Position = ball_rad;}
    }

void Ball::x_Collision_Change()
    {
        x_Velocity = -co_Restitution * x_Velocity;
        if (x_Position > width / 2) {x_Position = width - ball_rad;}
        else {x_Position = ball_rad;}
    }

void Ball::Collision()
{
    if      (y_Collision()) {y_Collision_Change();}
    else if (x_Collision()) {x_Collision_Change();}
}


